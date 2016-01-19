include ../bin/Makefile

pre-sim:
	make distclean
	#make rtl-test PRELOAD_RAM=1 END_TIME=20000000  TEST=uart-simple		
	#make rtl-test PRELOAD_RAM=1    VCD=1  FSDB=1
	make rtl-test TEST=uart-simple DISABLE_PROCESSOR_LOGS=1 VPI=1

verdi:	
	verdi   -f modelsim_dut.scr  -f dut.f  -f modelsim_backend.scr  -f modelsim_bench.scr -ssf orpsoc_testbench.fsdb -2001

lic-modelsim:
	/home/ys/EDA/modelsim/modeltech/linux/mgls/bin/lmgrd -c /home/ys/EDA/modelsim/mentor.dat&
