target remote:3333
load 
set $pc=0x100
layout regs
layout asm
layout split
info spr sys
list