target remote  :3333 
load
layout split
b main 
set $pc=0x100
set disassemble-next-line on
disas /m main
c
