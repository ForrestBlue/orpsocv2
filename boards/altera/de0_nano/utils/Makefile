burn:
	quartus_pgm --mode=jtag -o pi\;de0_nano.jic

jic:
	sh ./flash_helper.sh  ~/soc-design/orpsocv2/boards/altera/de0_nano/syn/quartus/run/orpsoc.sof	 ~/soc-design/orpsocv2/boards/altera/de0_nano/sw/tests/gpio/sim/gpio-simple.bin

clean:
	rm -rf de0_nano.jic de0_nano.map de0_nano.sof sw.*
