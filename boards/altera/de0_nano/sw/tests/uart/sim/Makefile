
BOARD_SW_ROOT=../../..

include $(BOARD_SW_ROOT)/Makefile.inc

%.dis: %.elf
	$(Q)$(OR32_OBJDUMP) -dS $< > $@

%.bin: %.elf
	$(Q)$(OR32_OBJCOPY) -O binary $< $@

clean:
	$(Q)rm -f *.elf *.bin *.vmem *.flashin *.dis

