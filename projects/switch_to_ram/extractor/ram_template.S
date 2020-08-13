.section .rawdata
.global user_start
.global user_end
user_start:
	.incbin "ram.bin"
user_end:
