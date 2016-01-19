# Set the path to our board's root directory
BOARD_SW_ROOT=../../..

include $(BOARD_SW_ROOT)/Makefile.inc


%.dis: %.elf
	$(Q)$(OR32_OBJDUMP) -dS $< > $@

%.bin: %.elf
	$(Q)$(OR32_OBJCOPY) -O binary $< $@

	
PROG=gpio-simple
PROG_SRC=gpio-simple.c
$(PROG): 
	or32-elf-gcc  -g $(PROG_SRC) -o $@

run: $(PROG) $(PROG).dis $(PROG).vmem $(PROG).bin
	@echo
	@echo "\tRunning in or1ksim with:"
	@echo
	@echo "\tsim "$<
	@echo

	sim -q  $< -f de0_nano-or1ksim.cfg
	
logrun: $(PROG)
	@echo
	@echo "\tRunning in or1ksim with a log:"
	@echo
	@echo "\tsim "$<" --trace > "$<".simtrace"
	@echo

	sim -q  $^ -f de0_nano-or1ksim.cfg --trace > $^.simtrace

compile: clean run

gdb: 
	or32-elf-gdb  -q  $(PROG) 

	
clean:	
	$(Q)rm -f *.elf *.bin *.vmem *.flashin *.dis $(PROG) *.simtrace *_hw
