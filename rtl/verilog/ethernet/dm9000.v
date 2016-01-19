 /*********************************************************************
  To Do:  
  	enhance this module
*******************************************************************/

module dm9000(
	//wishbone interface
	wb_clk_i ,wb_rst_i, 

	wb_dat_i, wb_dat_o, wb_adr_i, wb_sel_i, wb_we_i, wb_cyc_i,
 	wb_stb_i, wb_ack_o, wb_err_o,wb_inta_o,
	
	//extren sram interface
	dm9000_cs_n,
	dm9000_rst_n,
	dm9000_iow_n,
	dm9000_ior_n,
	dm9000_cmd, 
	dm9000_indata,
	dm9000_outdata,
	dm9000_intr
	);
	
parameter		WB_DW = 32;
parameter		WB_AW = 32;
parameter		WB_SELW = 4;
parameter		SRAM_DW = 16;
parameter		STATE_W = 5;	
parameter		DM9000_DW = 16;

//
// State Machine Parameter
//
parameter		IDLE = 'b10000;
parameter		READ = 'b01000;
parameter		WRITE = 'b00100;
parameter		ACK = 'b00010;
parameter		READ1 = 'b00001;
				
			
//
// I/O Ports
//
input			wb_clk_i;
input			wb_rst_i;

//
// WB slave i/f
//
input	[WB_DW-1:0]		wb_dat_i;
output	[WB_DW-1:0]		wb_dat_o;
input	[WB_AW-1:0]		wb_adr_i;
input	[WB_SELW-1 : 0]	wb_sel_i;
input			wb_we_i;
input			wb_cyc_i;
input			wb_stb_i;
output			wb_ack_o;
output			wb_err_o;
output          wb_inta_o;

//
// DM9000 I/O Ports
//
output	dm9000_cs_n;
output	dm9000_rst_n;
output	dm9000_iow_n;
output	dm9000_ior_n;
output	dm9000_cmd;
input[DM9000_DW-1:0]	dm9000_indata;
output[DM9000_DW-1:0]	dm9000_outdata;
input	dm9000_intr;
reg    wb_inta_o;


//
// Internal regs and wires 
//
reg [WB_DW-1:0]	data_save;
reg [WB_AW-1:0]	addr_save;
reg dm9000_cmd_r;
reg dm9000_ior_n_r, dm9000_iow_n_r;
reg dm9000_rst_n_r;
reg dm9000_cs_n_r;

reg [STATE_W-1:0]	cstate;
reg [STATE_W-1:0]	nstate;

//
// Use State Machine to acess to dm9000x
//
always @ (posedge wb_clk_i or posedge wb_rst_i)begin
	if (wb_rst_i) begin
		cstate <= IDLE;
	end
	else	begin
		cstate <= nstate;
	end
end

always @ (cstate or nstate or wb_stb_i or wb_we_i or wb_cyc_i or wb_sel_i)begin
	case(cstate)
		IDLE : begin
			nstate = (wb_stb_i & wb_cyc_i & wb_we_i) ? WRITE : (wb_stb_i & wb_cyc_i)? READ : IDLE;
		end
		WRITE : begin
			nstate = ACK;
		end			
		READ : begin
			nstate = READ1;
		end
		READ1 : begin
			nstate = ACK;
		end
		ACK : begin
			nstate = IDLE;
		end
		default : nstate = IDLE;
	endcase
end

always @ (posedge wb_clk_i or posedge wb_rst_i)begin
	if (wb_rst_i) begin
		data_save <= { WB_DW{1'b0} };
		addr_save <= { WB_AW{1'b0} };
		dm9000_cmd_r <= 1'b0;
		dm9000_ior_n_r <= 1'b1;	
		dm9000_iow_n_r <= 1'b1;
		dm9000_rst_n_r <= 1'b0;
		dm9000_cs_n_r <= 1'b1;
	end
	else begin
		case (cstate)
			IDLE : begin
				dm9000_cmd_r <= 1'b1;			
				dm9000_ior_n_r <= 1'b1;	
				dm9000_iow_n_r <= 1'b1;
				dm9000_rst_n_r <= 1'b1;
				dm9000_cs_n_r <= 1'b1;	
				addr_save <= wb_adr_i;
			end			
			WRITE : begin
				dm9000_cmd_r <= addr_save[2];
				dm9000_iow_n_r <= 1'b0;	
				dm9000_cs_n_r <= 1'b0;
				//data_save <= (|wb_sel_i[3:2]) ? { 2{wb_dat_i[31:16]} } : { 2{wb_dat_i[ 15:0 ]} };		
				if(!(&wb_sel_i))begin /* short or byte read */ 
				 	case (wb_sel_i)
				 		4'b0001,
				 		4'b0100:
							data_save <= { 4{wb_dat_i[15:8]} };
						4'b1000,
				     		4'b0010:
							data_save <= { 4{wb_dat_i[7:0]} };
						default:
							data_save <= { 2{wb_dat_i[7:0],wb_dat_i[15:8]} };
					endcase // case (wb_sel_i)				
				end				
			end
			READ : begin
				dm9000_cs_n_r <= 1'b0;
				dm9000_cmd_r <= addr_save[2];	
				dm9000_ior_n_r <= 1'b0;
			end
			READ1 : begin
				if(!(&wb_sel_i))begin /* short or byte read */ 
				 	case (wb_sel_i)
				 		4'b0001,
				 		4'b0100:
							data_save <= { 4{dm9000_indata[15:8]} };
						4'b1000,
				     		4'b0010:
				     			data_save <= { 4{dm9000_indata[7:0]} };
						default:
							data_save <= { 2{dm9000_indata[7:0], dm9000_indata[15:8]} };
					endcase // case (wb_sel_i)				
				end
			end			
			ACK : begin
				if(wb_we_i)begin
				dm9000_iow_n_r <= 1'b1;	
				dm9000_ior_n_r <= 1'b1;	
				end
				else begin
				dm9000_iow_n_r <= 1'b1;	
				dm9000_ior_n_r <= 1'b0;						
				end
			end				
			default : begin
				dm9000_ior_n_r <= 1'b1;	
				dm9000_iow_n_r <= 1'b1;
				dm9000_rst_n_r <= 1'b1;
				dm9000_cs_n_r <= 1'b1;
				dm9000_cmd_r <= addr_save[2];
			end
		endcase 
	end
end    

// generate interrupt request signals
always @(posedge wb_clk_i or negedge wb_rst_i)
 if (!wb_rst_i)
   wb_inta_o <=  1'b0;
 else if (wb_rst_i)
   wb_inta_o <=  1'b0;
 else
   // interrupt signal is only generated when IEN (interrupt enable bit 
   // is set)       
   wb_inta_o <=  dm9000_intr;
	   
	   
//
// Aliases and simple assignments
//
assign wb_err_o = 1'b0;
assign wb_ack_o = (cstate == ACK) ? 1'b1 : 1'b0;

//
// connect to dm9000a
//
assign dm9000_cs_n = dm9000_cs_n_r;
assign dm9000_rst_n = dm9000_rst_n_r;
assign dm9000_iow_n = dm9000_iow_n_r;
assign dm9000_ior_n = dm9000_ior_n_r;
assign dm9000_cmd = dm9000_cmd_r;


// for tri-state
assign dm9000_outdata = data_save;
assign wb_dat_o = data_save;


endmodule