	.cpu arm7tdmi
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"main.c"
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.fpu softvfp
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	ldr	r3, .L7
	mov	r2, #1
	str	r2, [r3]
	ldr	r3, .L7
	mov	r2, #255
	str	r2, [r3, #20]
	ldr	r3, .L7
	mov	r2, #255
	str	r2, [r3, #28]
	ldr	r3, .L7+4
	mov	r2, #0
	str	r2, [r3, #8]
	ldr	r3, .L7+4
	mov	r2, #4
	str	r2, [r3]
	ldr	r3, .L7+4
	mov	r2, #0
	str	r2, [r3, #20]
	ldr	r3, .L7+4
	mov	r2, #0
	str	r2, [r3, #28]
	ldr	r3, .L7+4
	mov	r2, #0
	str	r2, [r3, #24]
	ldr	r3, .L7+4
	str	r3, [fp, #-8]
	mov	r3, #2
	str	r3, [fp, #-12]
.L6:
	ldr	r3, [fp, #-8]
	ldr	r2, [r3, #4]
	ldr	r3, [fp, #-12]
	lsr	r3, r2, r3
	and	r3, r3, #1
	cmp	r3, #0
	beq	.L2
	mov	r2, #1
	ldr	r3, [fp, #-12]
	lsl	r2, r2, r3
	ldr	r3, [fp, #-8]
	str	r2, [r3, #16]
	b	.L3
.L2:
	mov	r2, #1
	ldr	r3, [fp, #-12]
	lsl	r2, r2, r3
	ldr	r3, [fp, #-8]
	str	r2, [r3, #12]
.L3:
	mov	r3, #0
	str	r3, [fp, #-16]
	b	.L4
.L5:
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L4:
	ldr	r3, [fp, #-16]
	ldr	r2, .L7+8
	cmp	r3, r2
	ble	.L5
	b	.L6
.L8:
	.align	2
.L7:
	.word	-541696
	.word	-541644
	.word	999999
	.size	main, .-main
	.ident	"GCC: (15:6.3.1+svn253039-1build1) 6.3.1 20170620"
