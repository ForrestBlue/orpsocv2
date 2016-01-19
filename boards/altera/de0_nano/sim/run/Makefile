include ../bin/Makefile

PROG=gpio-simple
pre-sim:
	make distclean
	#make rtl-test PRELOAD_RAM=1 END_TIME=20000000  TEST=uart-simple		
	make rtl-test TEST=gpio-simple
	#make rtl-test TEST=gpio-simple DISABLE_PROCESSOR_LOGS=1 FSDB=1 PRELOAD_RAM=1 VCD=1 VCD_DELAY_INSNS=10 
	#make rtl-test TEST=uart-echo DISABLE_PROCESSOR_LOGS=1 FSDB=1 PRELOAD_RAM=1 VCD=1   VCD_DELAY_INSNS=1

verdi:	
	verdi   -f modelsim_dut.scr  -f dut.f  -f modelsim_backend.scr  -f modelsim_bench.scr -ssf orpsoc_testbench.fsdb -2001
	
	
#load image and run
load:
	halt; load_image /home/ys/soc-design/orpsocv2/boards/altera/de0_nano/sim/run/$(PROG).elf; reg npc 0x100; resume

#deug usd gdb
gdb:
	or1k-elf-gdb  -q  $(PROG).elf
	
	
	
	
	
lic-verdi:
	$(VERDI_HOME)/bin/lmgrd -C $(VERDI_HOME)/license/license.dat -l $(VERDI_HOME)/license/lic.log&

lic-modelsim:
	/home/ys/EDA/modelsim/modeltech/linux/mgls/bin/lmgrd -c /home/ys/EDA/modelsim/mentor.dat&

lic-syn:
	/home/ys/EDA/scl115/linux/bin/lmgrd -c /home/ys/EDA/synplify/synopsys.dat -l ~/EDA/synplify/syn_lic.log&

lic-vcs:
	/home/ys/EDA/synopsys/scl/linux/bin/lmgrd -c /home/ys/EDA/synopsys/license/synopsys.dat -l ~/EDA/synopsys/license/syn_lic.log&

