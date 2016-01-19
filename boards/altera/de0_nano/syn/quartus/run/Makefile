include ../bin/Makefile

#setp1 program image
program:
	make pgm

#step2 openocd deamon
openocd:	
	sudo openocd -f /home/ys/soc-design/openocd/tcl/interface/altera-usb-blaster.cfg -f /home/ys/soc-design/openocd/tcl/board/or1k_generic.cfg

#connet telnet
telnet:
	telnet localhost 4444


