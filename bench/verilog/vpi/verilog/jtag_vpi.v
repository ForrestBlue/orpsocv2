/*
 * VPI JTAG master for openOCD.
 * Based on Julius Baxter's work on jp_vpi.c
 *
 * Copyright (C) 2012 Franck JULLIEN, <elec4fun@gmail.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

`timescale 1ns/10ps

`include "vpi_debug_defines.v"

`define CMD_RESET               0
`define CMD_TMS_SEQ             1
`define CMD_SCAN_CHAIN          2
`define CMD_SCAN_CHAIN_FLIP_TMS 3

// uncomment the following line to get more debug output for this module
`define DEBUG_INFO
`define VPI_DEBUG_INFO

module jtag_vpi(tms, tck, tdi, tdo);

output          tms;
output          tck;
output          tdi;
input           tdo;

reg             tms;
reg             tck;
reg             tdi;

integer         cmd;
integer         length;
integer         nb_bits;

reg [31:0]      buffer_out [0:4095];   // Data storage from the jtag server
reg [31:0]      buffer_in  [0:4095];   // Data storage to the jtag server

integer         flip_tms;

reg [31:0]      data_out;
reg [31:0]      data_in;

integer         debug;

parameter       TP = 1;
parameter       TCK_HALF_PERIOD = 50;   // Clock half period (Clok period = 100 ns => 10 MHz)


initial
begin
        $display("JTAG debug module with VPI interface enabled\n");
        tck             <= #TP 1'b0;
        tdi             <= #TP 1'bz;
        tms             <= #TP 1'b0;

        data_out        <= 32'h0;
        data_in         <= 32'h0;

        // Insert a #delay here because we need to
        // wait until the PC isn't pointing to flash anymore
        // (this is around 20k ns if the flash_crash boot code
        // is being booted from, else much bigger, around 10mil ns)
        #2_000 main;
end

task main;
begin

        // execute some cycles
        #50000;

        reset_tap;
        goto_run_test_idle;

        while (1) begin

                // Check for incoming command
                // wait until a command is sent
                // poll with a delay here
                cmd = -1;

                while (cmd == -1)
                begin
                        #1000 $check_for_command(cmd, length, nb_bits, buffer_out);
                end

                // now switch on the command
                case (cmd)

                `CMD_RESET : // reset
                begin
`ifdef DEBUG_INFO
                        $display("%t ----> CMD_RESET %h\n", $time, length);
`endif
                        reset_tap;
                        goto_run_test_idle;
                end

                `CMD_TMS_SEQ : // reset
                begin
`ifdef DEBUG_INFO
                $display("%t ----> CMD_TMS_SEQ\n", $time);
`endif
                        do_tms_seq;
                end

                `CMD_SCAN_CHAIN : // reset
                begin
`ifdef DEBUG_INFO
                        $display("%t ----> CMD_SCAN_CHAIN\n", $time);
`endif
                        flip_tms = 0;
                        do_scan_chain;
                        $send_result_to_server(length, buffer_in);
                end

                `CMD_SCAN_CHAIN_FLIP_TMS : // reset
                begin
`ifdef DEBUG_INFO
                        $display("%t ----> CMD_SCAN_CHAIN\n", $time);
`endif
                        flip_tms = 1;
                        do_scan_chain;
                        $send_result_to_server(length, buffer_in);
                end

                default:
                begin
                        $display("Somehow got to the default case in the command case statement.");
                        $display("Command was: %x", cmd);
                        $display("Exiting...");
                        $finish();
                end

                endcase // case (cmd)

        end // while (1)
end

endtask // main


// Generation of the TCK signal
task gen_clk;

input [31:0] number;
integer i;

begin
        for (i = 0; i < number; i = i + 1)
        begin
                #TCK_HALF_PERIOD tck <= 1;
                #TCK_HALF_PERIOD tck <= 0;
        end
end

endtask

// TAP reset
task reset_tap;

begin
`ifdef DEBUG_INFO
        $display("(%0t) Task reset_tap", $time);
`endif
        tms <= #1 1'b1;
        gen_clk(5);
end

endtask


// Goes to RunTestIdle state
task goto_run_test_idle;

begin
`ifdef DEBUG_INFO
        $display("(%0t) Task goto_run_test_idle", $time);
`endif
        tms <= #1 1'b0;
        gen_clk(1);
end

endtask

// 
task do_tms_seq;

integer         i,j;
reg [31:0]      data;
integer         nb_bits_rem;
integer         nb_bits_in_this_byte;

begin
`ifdef DEBUG_INFO
        $display("(%0t) Task do_tms_seq", $time);
`endif
        // Number of bits to send in the last byte
        nb_bits_rem = nb_bits % 8;

        for (i = 0; i < length; i = i + 1)
        begin
                // If we are in the last byte, we have to send only
                // nb_bits_rem bits. If not, we send the whole byte.
                nb_bits_in_this_byte = (i == (length - 1)) ? nb_bits_rem : 8;

                data = buffer_out[i];
                for (j = 0; j < nb_bits_in_this_byte; j = j + 1)
                begin
                        tms <= #1 1'b0;
                        if (data[j] == 1) begin
                                tms <= #1 1'b1;
                        end
                        gen_clk(1);
                end
        end

        tms <= #1 1'b0;
end

endtask


// 
task do_scan_chain;

integer         bit;
integer         nb_bits_rem;
integer         nb_bits_in_this_byte;
integer         index;

begin
`ifdef DEBUG_INFO
        $display("(%0t) Task do_scan_chain", $time);
`endif
        // Number of bits to send in the last byte
        nb_bits_rem = nb_bits % 8;

        for (index = 0; index < length; index = index + 1)
        begin
                // If we are in the last byte, we have to send only
                // nb_bits_rem bits if it's not zero.
                // If not, we send the whole byte.
                nb_bits_in_this_byte = (index == (length - 1)) ? ((nb_bits_rem == 0) ? 8 : nb_bits_rem) : 8;

                data_out = buffer_out[index];
                for (bit = 0; bit < nb_bits_in_this_byte; bit = bit + 1)
                begin
                        tdi <= 1'b0;
                        if (data_out[bit] == 1'b1) begin
                                tdi <= 1'b1;
                        end

                        // On the last bit, set TMS to '1'
                        if (((bit == (nb_bits_in_this_byte - 1)) && (index == (length - 1))) && (flip_tms == 1)) begin
                                tms <= 1'b1;
                        end

                        #TCK_HALF_PERIOD tck <= 1;
                        data_in[bit] <= tdo;
                        #TCK_HALF_PERIOD tck <= 0;
                end
                buffer_in[index] = data_in;
        end

        tdi <= 1'b0;
        tms <= 1'b0;
end

endtask

endmodule
