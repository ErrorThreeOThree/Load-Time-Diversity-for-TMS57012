 	.syntax unified
 	.eabi_attribute	67, "2.09"
 	.cpu	cortex-r4
 	.eabi_attribute	6, 10
 	.eabi_attribute	7, 82
 	.eabi_attribute	8, 1
 	.eabi_attribute	9, 2
 	.eabi_attribute	34, 0
 	.eabi_attribute	17, 1
 	.eabi_attribute	20, 1
 	.eabi_attribute	21, 1
 	.eabi_attribute	23, 3
 	.eabi_attribute	24, 1
 	.eabi_attribute	25, 1
 	.eabi_attribute	38, 1
 	.eabi_attribute	18, 4
 	.eabi_attribute	26, 2
 	.eabi_attribute	14, 0
 	.file	"llvm-link"
 	.file	1 "example_programs/sort/source/main.c"
 	.eabi_attribute	30, 6
 	 .section	.text,"ax",%progbits
 	.globl	main
 	.p2align	2
 	.type	main,%function
 	.code	32
main:
.Lfunc_begin0:
 	.loc	1 24 0
 	push	{r4, r5, r11, lr}
 	add	r11, sp, #8
 	sub	sp, sp, #472
 	mov	r0, #0
 	str	r0, [r11, #-12]
.Ltmp0:
 	.loc	1 30 2 prologue_end
 	movw	r0, :lower16:main.array
 	movt	r0, :upper16:main.array
 	add	r1, sp, #68
 	mov	r2, #100
 	str	r0, [sp, #60]
 	str	r1, [sp, #56]
 	str	r2, [sp, #52]
 	bl	array_copy
 	.loc	1 31 9
 	ldr	r0, [sp, #56]
 	ldr	r1, [sp, #60]
 	ldr	r2, [sp, #52]
 	bl	array_eq
 	.loc	1 31 7 is_stmt 0
 	str	r0, [sp, #64]
.Ltmp1:
 	.loc	1 32 20 is_stmt 1
 	ldr	r0, [sp, #64]
.Ltmp2:
 	.loc	1 32 6 is_stmt 0
 	cmp	r0, #100
 	beq	.LBB0_2
 	b	.LBB0_1
.LBB0_1:
.Ltmp3:
 	.loc	1 33 12 is_stmt 1
 	ldr	r0, [sp, #64]
 	add	r1, sp, #68
 	.loc	1 33 30 is_stmt 0
 	ldr	r2, [r1, r0, lsl #2]
 	.loc	1 33 42
 	movw	r1, :lower16:main.array
 	movt	r1, :upper16:main.array
 	ldr	r3, [r1, r0, lsl #2]
 	.loc	1 33 3
 	mov	r1, #31
 	bl	sys_exit
 	.loc	1 34 2 is_stmt 1
 	b	.LBB0_2
.Ltmp4:
.LBB0_2:
 	.loc	1 0 2 is_stmt 0
 	add	r0, sp, #68
 	.loc	1 36 2 is_stmt 1
 	mov	r1, #100
 	str	r0, [sp, #48]
 	str	r1, [sp, #44]
 	bl	bubble_sort
 	.loc	1 37 9
 	movw	r1, :lower16:main.solution
 	movt	r1, :upper16:main.solution
 	ldr	r0, [sp, #48]
 	ldr	r2, [sp, #44]
 	bl	array_eq
 	.loc	1 37 7 is_stmt 0
 	str	r0, [sp, #64]
.Ltmp5:
 	.loc	1 38 20 is_stmt 1
 	ldr	r0, [sp, #64]
.Ltmp6:
 	.loc	1 38 6 is_stmt 0
 	cmp	r0, #100
 	beq	.LBB0_4
 	b	.LBB0_3
.LBB0_3:
.Ltmp7:
 	.loc	1 39 12 is_stmt 1
 	ldr	r0, [sp, #64]
 	add	r1, sp, #68
 	.loc	1 39 42 is_stmt 0
 	ldr	r2, [r1, r0, lsl #2]
 	.loc	1 39 54
 	movw	r1, :lower16:main.solution
 	movt	r1, :upper16:main.solution
 	ldr	r3, [r1, r0, lsl #2]
 	.loc	1 39 3
 	mov	r1, #11
 	bl	sys_exit
 	.loc	1 40 2 is_stmt 1
 	b	.LBB0_4
.Ltmp8:
.LBB0_4:
 	.loc	1 45 2
 	movw	r0, :lower16:main.array
 	movt	r0, :upper16:main.array
 	add	r1, sp, #68
 	mov	r2, #100
 	str	r0, [sp, #40]
 	str	r1, [sp, #36]
 	str	r2, [sp, #32]
 	bl	array_copy
 	.loc	1 46 9
 	ldr	r0, [sp, #36]
 	ldr	r1, [sp, #40]
 	ldr	r2, [sp, #32]
 	bl	array_eq
 	.loc	1 46 7 is_stmt 0
 	str	r0, [sp, #64]
.Ltmp9:
 	.loc	1 47 20 is_stmt 1
 	ldr	r0, [sp, #64]
.Ltmp10:
 	.loc	1 47 6 is_stmt 0
 	cmp	r0, #100
 	beq	.LBB0_6
 	b	.LBB0_5
.LBB0_5:
.Ltmp11:
 	.loc	1 48 12 is_stmt 1
 	ldr	r0, [sp, #64]
 	add	r1, sp, #68
 	.loc	1 48 30 is_stmt 0
 	ldr	r2, [r1, r0, lsl #2]
 	.loc	1 48 42
 	movw	r1, :lower16:main.array
 	movt	r1, :upper16:main.array
 	ldr	r3, [r1, r0, lsl #2]
 	.loc	1 48 3
 	mov	r1, #47
 	bl	sys_exit
 	.loc	1 49 2 is_stmt 1
 	b	.LBB0_6
.Ltmp12:
.LBB0_6:
 	.loc	1 0 2 is_stmt 0
 	add	r0, sp, #68
 	.loc	1 51 2 is_stmt 1
 	mov	r1, #100
 	str	r0, [sp, #28]
 	str	r1, [sp, #24]
 	bl	insertion_sort
 	.loc	1 52 9
 	movw	r1, :lower16:main.solution
 	movt	r1, :upper16:main.solution
 	ldr	r0, [sp, #28]
 	ldr	r2, [sp, #24]
 	bl	array_eq
 	.loc	1 52 7 is_stmt 0
 	str	r0, [sp, #64]
.Ltmp13:
 	.loc	1 53 20 is_stmt 1
 	ldr	r0, [sp, #64]
.Ltmp14:
 	.loc	1 53 6 is_stmt 0
 	cmp	r0, #100
 	beq	.LBB0_8
 	b	.LBB0_7
.LBB0_7:
.Ltmp15:
 	.loc	1 54 12 is_stmt 1
 	ldr	r0, [sp, #64]
 	add	r1, sp, #68
 	.loc	1 54 45 is_stmt 0
 	ldr	r2, [r1, r0, lsl #2]
 	.loc	1 54 57
 	movw	r1, :lower16:main.solution
 	movt	r1, :upper16:main.solution
 	ldr	r3, [r1, r0, lsl #2]
 	.loc	1 54 3
 	mov	r1, #12
 	bl	sys_exit
 	.loc	1 55 2 is_stmt 1
 	b	.LBB0_8
.Ltmp16:
.LBB0_8:
 	.loc	1 59 2
 	movw	r0, :lower16:main.array
 	movt	r0, :upper16:main.array
 	add	r1, sp, #68
 	mov	r2, #100
 	str	r0, [sp, #20]
 	str	r1, [sp, #16]
 	str	r2, [sp, #12]
 	bl	array_copy
 	.loc	1 60 9
 	ldr	r0, [sp, #16]
 	ldr	r1, [sp, #20]
 	ldr	r2, [sp, #12]
 	bl	array_eq
 	.loc	1 60 7 is_stmt 0
 	str	r0, [sp, #64]
.Ltmp17:
 	.loc	1 61 20 is_stmt 1
 	ldr	r0, [sp, #64]
.Ltmp18:
 	.loc	1 61 6 is_stmt 0
 	cmp	r0, #100
 	beq	.LBB0_10
 	b	.LBB0_9
.LBB0_9:
.Ltmp19:
 	.loc	1 62 12 is_stmt 1
 	ldr	r0, [sp, #64]
 	add	r1, sp, #68
 	.loc	1 62 30 is_stmt 0
 	ldr	r2, [r1, r0, lsl #2]
 	.loc	1 62 42
 	movw	r1, :lower16:main.array
 	movt	r1, :upper16:main.array
 	ldr	r3, [r1, r0, lsl #2]
 	.loc	1 62 3
 	mov	r1, #79
 	bl	sys_exit
 	.loc	1 63 2 is_stmt 1
 	b	.LBB0_10
.Ltmp20:
.LBB0_10:
 	.loc	1 0 2 is_stmt 0
 	add	r0, sp, #68
 	.loc	1 65 2 is_stmt 1
 	mov	r1, #100
 	str	r0, [sp, #8]
 	str	r1, [sp, #4]
 	bl	selection_sort
 	.loc	1 66 9
 	movw	r1, :lower16:main.solution
 	movt	r1, :upper16:main.solution
 	ldr	r0, [sp, #8]
 	ldr	r2, [sp, #4]
 	bl	array_eq
 	.loc	1 66 7 is_stmt 0
 	str	r0, [sp, #64]
.Ltmp21:
 	.loc	1 67 20 is_stmt 1
 	ldr	r0, [sp, #64]
.Ltmp22:
 	.loc	1 67 6 is_stmt 0
 	cmp	r0, #100
 	beq	.LBB0_12
 	b	.LBB0_11
.LBB0_11:
.Ltmp23:
 	.loc	1 68 12 is_stmt 1
 	ldr	r0, [sp, #64]
 	add	r1, sp, #68
 	.loc	1 68 45 is_stmt 0
 	ldr	r2, [r1, r0, lsl #2]
 	.loc	1 68 57
 	movw	r1, :lower16:main.solution
 	movt	r1, :upper16:main.solution
 	ldr	r3, [r1, r0, lsl #2]
 	.loc	1 68 3
 	mov	r1, #10
 	bl	sys_exit
 	.loc	1 69 2 is_stmt 1
 	b	.LBB0_12
.Ltmp24:
.LBB0_12:
 	.loc	1 71 2
 	movw	r0, #65535
 	mov	r1, #255
 	movw	r2, #2748
 	str	r2, [sp]
 	ldr	r3, [sp]
 	bl	sys_exit
 	.loc	1 72 1
 	ldr	r0, [r11, #-12]
 	sub	sp, r11, #8
 	pop	{r4, r5, r11, pc}
.Ltmp25:
.Lfunc_end0:
 	.globl	array_copy
 	.p2align	2
 	.type	array_copy,%function
 	.code	32
array_copy:
.Lfunc_begin1:
 	.loc	1 74 0
 	push	{r11, lr}
 	mov	r11, sp
 	sub	sp, sp, #28
 	mov	r3, r2
 	mov	r12, r1
 	mov	lr, r0
 	str	r0, [r11, #-4]
 	str	r1, [r11, #-8]
 	str	r2, [r11, #-12]
 	mov	r0, #0
.Ltmp26:
 	.loc	1 76 9 prologue_end
 	str	r0, [sp, #12]
 	.loc	1 76 7 is_stmt 0
 	str	r3, [sp, #8]
 	str	r12, [sp, #4]
 	str	lr, [sp]
 	b	.LBB1_1
.LBB1_1:
.Ltmp27:
 	.loc	1 76 14
 	ldr	r0, [sp, #12]
 	.loc	1 76 18
 	ldr	r1, [r11, #-12]
.Ltmp28:
 	.loc	1 76 2
 	cmp	r0, r1
 	bhs	.LBB1_4
 	b	.LBB1_2
.LBB1_2:
.Ltmp29:
 	.loc	1 77 12 is_stmt 1
 	ldr	r0, [r11, #-4]
 	.loc	1 77 16 is_stmt 0
 	ldr	r1, [sp, #12]
 	.loc	1 77 12
 	ldr	r0, [r0, r1, lsl #2]
 	.loc	1 77 3
 	ldr	r2, [r11, #-8]
 	.loc	1 77 10
 	str	r0, [r2, r1, lsl #2]
 	.loc	1 78 2 is_stmt 1
 	b	.LBB1_3
.Ltmp30:
.LBB1_3:
 	.loc	1 76 25
 	ldr	r0, [sp, #12]
 	add	r0, r0, #1
 	str	r0, [sp, #12]
 	.loc	1 76 2 is_stmt 0
 	b	.LBB1_1
.Ltmp31:
.LBB1_4:
 	.loc	1 79 1 is_stmt 1
 	mov	sp, r11
 	pop	{r11, pc}
.Ltmp32:
.Lfunc_end1:
 	.globl	array_eq
 	.p2align	2
 	.type	array_eq,%function
 	.code	32
array_eq:
.Lfunc_begin2:
 	.loc	1 128 0
 	push	{r11, lr}
 	mov	r11, sp
 	sub	sp, sp, #32
 	mov	r3, r2
 	mov	r12, r1
 	mov	lr, r0
 	str	r0, [r11, #-8]
 	str	r1, [r11, #-12]
 	str	r2, [sp, #16]
 	mov	r0, #0
.Ltmp33:
 	.loc	1 130 9 prologue_end
 	str	r0, [sp, #12]
 	.loc	1 130 7 is_stmt 0
 	str	r3, [sp, #8]
 	str	r12, [sp, #4]
 	str	lr, [sp]
 	b	.LBB2_1
.LBB2_1:
.Ltmp34:
 	.loc	1 130 14
 	ldr	r0, [sp, #12]
 	.loc	1 130 18
 	ldr	r1, [sp, #16]
.Ltmp35:
 	.loc	1 130 2
 	cmp	r0, r1
 	bhs	.LBB2_6
 	b	.LBB2_2
.LBB2_2:
.Ltmp36:
 	.loc	1 131 7 is_stmt 1
 	ldr	r0, [r11, #-8]
 	.loc	1 131 10 is_stmt 0
 	ldr	r1, [sp, #12]
 	.loc	1 131 7
 	ldr	r0, [r0, r1, lsl #2]
 	.loc	1 131 16
 	ldr	r2, [r11, #-12]
 	ldr	r1, [r2, r1, lsl #2]
.Ltmp37:
 	.loc	1 131 7
 	cmp	r0, r1
 	beq	.LBB2_4
 	b	.LBB2_3
.LBB2_3:
.Ltmp38:
 	.loc	1 132 11 is_stmt 1
 	ldr	r0, [sp, #12]
 	.loc	1 132 4 is_stmt 0
 	str	r0, [r11, #-4]
 	b	.LBB2_7
.Ltmp39:
.LBB2_4:
 	.loc	1 133 2 is_stmt 1
 	b	.LBB2_5
.Ltmp40:
.LBB2_5:
 	.loc	1 130 25
 	ldr	r0, [sp, #12]
 	add	r0, r0, #1
 	str	r0, [sp, #12]
 	.loc	1 130 2 is_stmt 0
 	b	.LBB2_1
.Ltmp41:
.LBB2_6:
 	.loc	1 134 9 is_stmt 1
 	ldr	r0, [sp, #16]
 	.loc	1 134 2 is_stmt 0
 	str	r0, [r11, #-4]
 	b	.LBB2_7
.LBB2_7:
 	.loc	1 135 1 is_stmt 1
 	ldr	r0, [r11, #-4]
 	mov	sp, r11
 	pop	{r11, pc}
.Ltmp42:
.Lfunc_end2:
 	.globl	sys_exit
 	.p2align	2
 	.type	sys_exit,%function
 	.code	32
sys_exit:
.Lfunc_begin3:
 	.loc	1 137 0
 	push	{r4, r5, r11, lr}
 	add	r11, sp, #8
 	sub	sp, sp, #32
 	mov	r12, r3
 	mov	lr, r2
 	mov	r4, r1
 	mov	r5, r0
 	str	r0, [r11, #-12]
 	str	r1, [r11, #-16]
 	str	r2, [sp, #20]
 	str	r3, [sp, #16]
.Ltmp43:
 	.loc	1 138 2 prologue_end
 	str	r12, [sp, #12]
 	str	lr, [sp, #8]
 	str	r4, [sp, #4]
 	str	r5, [sp]
 	b	.LBB3_1
.LBB3_1:
 	b	.LBB3_1
.Ltmp44:
.Lfunc_end3:
 	.globl	bubble_sort
 	.p2align	2
 	.type	bubble_sort,%function
 	.code	32
bubble_sort:
.Lfunc_begin4:
 	.loc	1 81 0
 	sub	sp, sp, #28
 	mov	r2, r1
 	mov	r3, r0
 	str	r0, [sp, #24]
 	str	r1, [sp, #20]
.Ltmp45:
 	.loc	1 83 2 prologue_end
 	str	r2, [sp, #4]
 	str	r3, [sp]
 	b	.LBB4_1
.LBB4_1:
 	.loc	1 0 2 is_stmt 0
 	mov	r0, #0
.Ltmp46:
 	.loc	1 84 11 is_stmt 1
 	str	r0, [sp, #8]
.Ltmp47:
 	.loc	1 85 10
 	mov	r0, #1
 	str	r0, [sp, #12]
 	.loc	1 85 8 is_stmt 0
 	b	.LBB4_2
.LBB4_2:
.Ltmp48:
 	.loc	1 85 15
 	ldr	r0, [sp, #12]
 	.loc	1 85 19
 	ldr	r1, [sp, #20]
.Ltmp49:
 	.loc	1 85 3
 	cmp	r0, r1
 	bhs	.LBB4_7
 	b	.LBB4_3
.LBB4_3:
.Ltmp50:
 	.loc	1 86 8 is_stmt 1
 	ldr	r0, [sp, #24]
 	.loc	1 86 14 is_stmt 0
 	ldr	r1, [sp, #12]
 	.loc	1 86 21
 	ldr	r1, [r0, r1, lsl #2]!
 	.loc	1 86 8
 	ldr	r0, [r0, #-4]
.Ltmp51:
 	.loc	1 86 8
 	cmp	r0, r1
 	bls	.LBB4_5
 	b	.LBB4_4
.LBB4_4:
.Ltmp52:
 	.loc	1 87 11 is_stmt 1
 	ldr	r0, [sp, #24]
 	.loc	1 87 17 is_stmt 0
 	ldr	r1, [sp, #12]
 	.loc	1 87 11
 	ldr	r0, [r0, r1, lsl #2]
 	.loc	1 87 9
 	str	r0, [sp, #16]
 	.loc	1 88 16 is_stmt 1
 	ldr	r0, [sp, #24]
 	.loc	1 88 22 is_stmt 0
 	ldr	r1, [sp, #12]
 	.loc	1 88 16
 	add	r2, r0, r1, lsl #2
 	ldr	r2, [r2, #-4]
 	.loc	1 88 14
 	str	r2, [r0, r1, lsl #2]
 	.loc	1 89 18 is_stmt 1
 	ldr	r0, [sp, #16]
 	.loc	1 89 5 is_stmt 0
 	ldr	r1, [sp, #24]
 	.loc	1 89 11
 	ldr	r2, [sp, #12]
 	.loc	1 89 5
 	add	r1, r1, r2, lsl #2
 	.loc	1 89 16
 	str	r0, [r1, #-4]
 	.loc	1 88 23 is_stmt 1
 	mov	r0, #1
 	.loc	1 90 13
 	str	r0, [sp, #8]
 	.loc	1 91 4
 	b	.LBB4_5
.Ltmp53:
.LBB4_5:
 	.loc	1 92 3
 	b	.LBB4_6
.Ltmp54:
.LBB4_6:
 	.loc	1 85 26
 	ldr	r0, [sp, #12]
 	add	r0, r0, #1
 	str	r0, [sp, #12]
 	.loc	1 85 3 is_stmt 0
 	b	.LBB4_2
.Ltmp55:
.LBB4_7:
 	.loc	1 93 7 is_stmt 1
 	ldr	r0, [sp, #20]
 	sub	r0, r0, #1
 	str	r0, [sp, #20]
 	.loc	1 94 2
 	b	.LBB4_8
.Ltmp56:
.LBB4_8:
 	.loc	1 94 16 is_stmt 0
 	ldr	r0, [sp, #8]
.Ltmp57:
 	.loc	1 94 2
 	cmp	r0, #1
 	beq	.LBB4_1
 	b	.LBB4_9
.Ltmp58:
.LBB4_9:
 	.loc	1 95 1 is_stmt 1
 	add	sp, sp, #28
 	bx	lr
.Ltmp59:
.Lfunc_end4:
 	.globl	insertion_sort
 	.p2align	2
 	.type	insertion_sort,%function
 	.code	32
insertion_sort:
.Lfunc_begin5:
 	.loc	1 97 0
 	sub	sp, sp, #32
 	mov	r2, r1
 	mov	r3, r0
 	str	r0, [sp, #28]
 	str	r1, [sp, #24]
.Ltmp60:
 	.loc	1 100 4 prologue_end
 	mov	r0, #1
 	str	r0, [sp, #12]
 	.loc	1 101 2
 	str	r2, [sp, #8]
 	str	r3, [sp, #4]
 	b	.LBB5_1
.LBB5_1:
 	.loc	1 101 9 is_stmt 0
 	ldr	r0, [sp, #12]
 	.loc	1 101 13
 	ldr	r1, [sp, #24]
 	.loc	1 101 2
 	cmp	r0, r1
 	bhs	.LBB5_8
 	b	.LBB5_2
.LBB5_2:
.Ltmp61:
 	.loc	1 102 7 is_stmt 1
 	ldr	r0, [sp, #28]
 	.loc	1 102 13 is_stmt 0
 	ldr	r1, [sp, #12]
 	.loc	1 102 7
 	ldr	r0, [r0, r1, lsl #2]
 	.loc	1 102 5
 	str	r0, [sp, #20]
 	.loc	1 103 7 is_stmt 1
 	ldr	r0, [sp, #12]
 	.loc	1 103 9 is_stmt 0
 	sub	r0, r0, #1
 	.loc	1 103 5
 	str	r0, [sp, #16]
 	.loc	1 104 3 is_stmt 1
 	b	.LBB5_3
.LBB5_3:
 	.loc	1 104 10 is_stmt 0
 	ldr	r0, [sp, #16]
 	mov	r1, #0
 	.loc	1 104 18
 	cmp	r0, #0
 	str	r1, [sp]
 	blt	.LBB5_5
 	b	.LBB5_4
.LBB5_4:
 	.loc	1 104 22
 	ldr	r0, [sp, #28]
 	.loc	1 104 28
 	ldr	r1, [sp, #16]
 	.loc	1 104 22
 	ldr	r0, [r0, r1, lsl #2]
 	.loc	1 104 33
 	ldr	r1, [sp, #20]
 	.loc	1 104 31
 	mov	r2, #0
 	cmp	r0, r1
 	movwhi	r2, #1
 	str	r2, [sp]
 	b	.LBB5_5
.LBB5_5:
 	.loc	1 0 31
 	ldr	r0, [sp]
 	.loc	1 104 3
 	tst	r0, #1
 	beq	.LBB5_7
 	b	.LBB5_6
.LBB5_6:
.Ltmp62:
 	.loc	1 105 19 is_stmt 1
 	ldr	r0, [sp, #28]
 	.loc	1 105 25 is_stmt 0
 	ldr	r1, [sp, #16]
 	.loc	1 105 19
 	ldr	r1, [r0, r1, lsl #2]!
 	.loc	1 105 17
 	str	r1, [r0, #4]
 	.loc	1 106 8 is_stmt 1
 	ldr	r0, [sp, #16]
 	.loc	1 106 10 is_stmt 0
 	sub	r0, r0, #1
 	.loc	1 106 6
 	str	r0, [sp, #16]
.Ltmp63:
 	.loc	1 104 3 is_stmt 1
 	b	.LBB5_3
.LBB5_7:
 	.loc	1 108 18
 	ldr	r0, [sp, #20]
 	.loc	1 108 3 is_stmt 0
 	ldr	r1, [sp, #28]
 	.loc	1 108 9
 	ldr	r2, [sp, #16]
 	.loc	1 108 3
 	add	r1, r1, r2, lsl #2
 	.loc	1 108 16
 	str	r0, [r1, #4]
 	.loc	1 109 4 is_stmt 1
 	ldr	r0, [sp, #12]
 	add	r0, r0, #1
 	str	r0, [sp, #12]
.Ltmp64:
 	.loc	1 101 2
 	b	.LBB5_1
.LBB5_8:
 	.loc	1 111 1
 	add	sp, sp, #32
 	bx	lr
.Ltmp65:
.Lfunc_end5:
 	.globl	selection_sort
 	.p2align	2
 	.type	selection_sort,%function
 	.code	32
selection_sort:
.Lfunc_begin6:
 	.loc	1 113 0
 	sub	sp, sp, #36
 	mov	r2, r1
 	mov	r3, r0
 	str	r0, [sp, #32]
 	str	r1, [sp, #28]
 	mov	r0, #0
.Ltmp66:
 	.loc	1 115 9 prologue_end
 	str	r0, [sp, #16]
 	.loc	1 115 7 is_stmt 0
 	str	r2, [sp, #4]
 	str	r3, [sp]
 	b	.LBB6_1
.LBB6_1:
.Ltmp67:
 	.loc	1 115 14
 	ldr	r0, [sp, #16]
 	.loc	1 115 15
 	add	r0, r0, #1
 	.loc	1 115 20
 	ldr	r1, [sp, #28]
 	.loc	1 115 24
 	add	r1, r1, #1
.Ltmp68:
 	.loc	1 115 2
 	cmp	r0, r1
 	bhs	.LBB6_10
 	b	.LBB6_2
.LBB6_2:
.Ltmp69:
 	.loc	1 116 18 is_stmt 1
 	ldr	r0, [sp, #16]
 	.loc	1 116 12 is_stmt 0
 	str	r0, [sp, #8]
.Ltmp70:
 	.loc	1 117 12 is_stmt 1
 	ldr	r0, [sp, #16]
 	.loc	1 117 13 is_stmt 0
 	add	r0, r0, #1
 	.loc	1 117 10
 	str	r0, [sp, #12]
 	.loc	1 117 8
 	b	.LBB6_3
.LBB6_3:
.Ltmp71:
 	.loc	1 117 17
 	ldr	r0, [sp, #12]
 	.loc	1 117 21
 	ldr	r1, [sp, #28]
.Ltmp72:
 	.loc	1 117 3
 	cmp	r0, r1
 	bhs	.LBB6_8
 	b	.LBB6_4
.LBB6_4:
.Ltmp73:
 	.loc	1 118 8 is_stmt 1
 	ldr	r0, [sp, #32]
 	.loc	1 118 14 is_stmt 0
 	ldr	r1, [sp, #12]
 	.loc	1 118 8
 	ldr	r1, [r0, r1, lsl #2]
 	.loc	1 118 25
 	ldr	r2, [sp, #8]
 	.loc	1 118 19
 	ldr	r0, [r0, r2, lsl #2]
.Ltmp74:
 	.loc	1 118 8
 	cmp	r1, r0
 	bhs	.LBB6_6
 	b	.LBB6_5
.LBB6_5:
.Ltmp75:
 	.loc	1 119 11 is_stmt 1
 	ldr	r0, [sp, #12]
 	.loc	1 119 9 is_stmt 0
 	str	r0, [sp, #8]
 	.loc	1 120 4 is_stmt 1
 	b	.LBB6_6
.Ltmp76:
.LBB6_6:
 	.loc	1 121 3
 	b	.LBB6_7
.Ltmp77:
.LBB6_7:
 	.loc	1 117 28
 	ldr	r0, [sp, #12]
 	add	r0, r0, #1
 	str	r0, [sp, #12]
 	.loc	1 117 3 is_stmt 0
 	b	.LBB6_3
.Ltmp78:
.LBB6_8:
 	.loc	1 122 9 is_stmt 1
 	ldr	r0, [sp, #32]
 	.loc	1 122 15 is_stmt 0
 	ldr	r1, [sp, #8]
 	.loc	1 122 9
 	ldr	r0, [r0, r1, lsl #2]
 	.loc	1 122 7
 	str	r0, [sp, #20]
 	.loc	1 123 16 is_stmt 1
 	ldr	r0, [sp, #32]
 	.loc	1 123 22 is_stmt 0
 	ldr	r1, [sp, #16]
 	.loc	1 123 16
 	ldr	r1, [r0, r1, lsl #2]
 	.loc	1 123 9
 	ldr	r2, [sp, #8]
 	.loc	1 123 14
 	str	r1, [r0, r2, lsl #2]
 	.loc	1 124 14 is_stmt 1
 	ldr	r0, [sp, #20]
 	.loc	1 124 3 is_stmt 0
 	ldr	r1, [sp, #32]
 	.loc	1 124 9
 	ldr	r2, [sp, #16]
 	.loc	1 124 12
 	str	r0, [r1, r2, lsl #2]
 	.loc	1 125 2 is_stmt 1
 	b	.LBB6_9
.Ltmp79:
.LBB6_9:
 	.loc	1 115 29
 	ldr	r0, [sp, #16]
 	add	r0, r0, #1
 	str	r0, [sp, #16]
 	.loc	1 115 2 is_stmt 0
 	b	.LBB6_1
.Ltmp80:
.LBB6_10:
 	.loc	1 126 1 is_stmt 1
 	add	sp, sp, #36
 	bx	lr
.Ltmp81:
.Lfunc_end6:
 	.type	main.array,%object

 	.section	.rodata,"a",%progbits
 	.p2align	2
main.array:
 	.long	89
 	.long	26
 	.long	37
 	.long	24
 	.long	34
 	.long	29
 	.long	1
 	.long	47
 	.long	97
 	.long	30
 	.long	27
 	.long	48
 	.long	73
 	.long	16
 	.long	67
 	.long	61
 	.long	74
 	.long	20
 	.long	84
 	.long	53
 	.long	46
 	.long	10
 	.long	69
 	.long	93
 	.long	31
 	.long	87
 	.long	13
 	.long	23
 	.long	82
 	.long	99
 	.long	38
 	.long	4
 	.long	100
 	.long	92
 	.long	85
 	.long	43
 	.long	58
 	.long	78
 	.long	88
 	.long	54
 	.long	72
 	.long	64
 	.long	95
 	.long	18
 	.long	6
 	.long	65
 	.long	39
 	.long	14
 	.long	76
 	.long	40
 	.long	59
 	.long	36
 	.long	79
 	.long	96
 	.long	2
 	.long	15
 	.long	80
 	.long	62
 	.long	63
 	.long	90
 	.long	52
 	.long	71
 	.long	17
 	.long	50
 	.long	86
 	.long	91
 	.long	33
 	.long	98
 	.long	42
 	.long	11
 	.long	68
 	.long	9
 	.long	19
 	.long	28
 	.long	12
 	.long	51
 	.long	56
 	.long	66
 	.long	21
 	.long	44
 	.long	35
 	.long	57
 	.long	55
 	.long	75
 	.long	3
 	.long	7
 	.long	77
 	.long	81
 	.long	5
 	.long	22
 	.long	41
 	.long	25
 	.long	60
 	.long	45
 	.long	83
 	.long	70
 	.long	94
 	.long	32
 	.long	49
 	.long	8
 	.type	main.solution,%object
 	.p2align	2
main.solution:
 	.long	1
 	.long	2
 	.long	3
 	.long	4
 	.long	5
 	.long	6
 	.long	7
 	.long	8
 	.long	9
 	.long	10
 	.long	11
 	.long	12
 	.long	13
 	.long	14
 	.long	15
 	.long	16
 	.long	17
 	.long	18
 	.long	19
 	.long	20
 	.long	21
 	.long	22
 	.long	23
 	.long	24
 	.long	25
 	.long	26
 	.long	27
 	.long	28
 	.long	29
 	.long	30
 	.long	31
 	.long	32
 	.long	33
 	.long	34
 	.long	35
 	.long	36
 	.long	37
 	.long	38
 	.long	39
 	.long	40
 	.long	41
 	.long	42
 	.long	43
 	.long	44
 	.long	45
 	.long	46
 	.long	47
 	.long	48
 	.long	49
 	.long	50
 	.long	51
 	.long	52
 	.long	53
 	.long	54
 	.long	55
 	.long	56
 	.long	57
 	.long	58
 	.long	59
 	.long	60
 	.long	61
 	.long	62
 	.long	63
 	.long	64
 	.long	65
 	.long	66
 	.long	67
 	.long	68
 	.long	69
 	.long	70
 	.long	71
 	.long	72
 	.long	73
 	.long	74
 	.long	75
 	.long	76
 	.long	77
 	.long	78
 	.long	79
 	.long	80
 	.long	81
 	.long	82
 	.long	83
 	.long	84
 	.long	85
 	.long	86
 	.long	87
 	.long	88
 	.long	89
 	.long	90
 	.long	91
 	.long	92
 	.long	93
 	.long	94
 	.long	95
 	.long	96
 	.long	97
 	.long	98
 	.long	99
 	.long	100
 	.section	.debug_str,"MS",%progbits,1
.Linfo_string0:
 	.asciz	"clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)"
.Linfo_string1:
 	.asciz	"example_programs/sort/source/main.c"
.Linfo_string2:
 	.asciz	"/home/jh/Documents/bachelorarbeit/projects/load_time_diversity_tms57012"
.Linfo_string3:
 	.asciz	"array"
.Linfo_string4:
 	.asciz	"long unsigned int"
.Linfo_string5:
 	.asciz	"uint32_t"
.Linfo_string6:
 	.asciz	"sizetype"
.Linfo_string7:
 	.asciz	"solution"
.Linfo_string8:
 	.asciz	"main"
.Linfo_string9:
 	.asciz	"int"
.Linfo_string10:
 	.asciz	"array_copy"
.Linfo_string11:
 	.asciz	"array_eq"
.Linfo_string12:
 	.asciz	"sys_exit"
.Linfo_string13:
 	.asciz	"bubble_sort"
.Linfo_string14:
 	.asciz	"insertion_sort"
.Linfo_string15:
 	.asciz	"selection_sort"
.Linfo_string16:
 	.asciz	"algo"
.Linfo_string17:
 	.asciz	"code"
.Linfo_string18:
 	.asciz	"src"
.Linfo_string19:
 	.asciz	"dst"
.Linfo_string20:
 	.asciz	"size"
.Linfo_string21:
 	.asciz	"i"
.Linfo_string22:
 	.asciz	"a1"
.Linfo_string23:
 	.asciz	"a2"
.Linfo_string24:
 	.asciz	"error_code"
.Linfo_string25:
 	.asciz	"val_a"
.Linfo_string26:
 	.asciz	"val_b"
.Linfo_string27:
 	.asciz	"tmp"
.Linfo_string28:
 	.asciz	"swapped"
.Linfo_string29:
 	.asciz	"x"
.Linfo_string30:
 	.asciz	"j"
.Linfo_string31:
 	.asciz	"min"
 	.byte	1
 	.byte	17
 	.byte	1
 	.byte	37
 	.byte	14
 	.byte	19
 	.byte	5
 	.byte	3
 	.byte	14
 	.byte	16
 	.byte	23
 	.byte	27
 	.byte	14
 	.ascii	"\264B"
 	.byte	25
 	.byte	17
 	.byte	1
 	.byte	18
 	.byte	6
 	.byte	0
 	.byte	0
 	.byte	2
 	.byte	46
 	.byte	1
 	.byte	17
 	.byte	1
 	.byte	18
 	.byte	6
 	.byte	64
 	.byte	24
 	.byte	3
 	.byte	14
 	.byte	58
 	.byte	11
 	.byte	59
 	.byte	11
 	.byte	73
 	.byte	19
 	.byte	63
 	.byte	25
 	.byte	0
 	.byte	0
 	.byte	3
 	.byte	52
 	.byte	0
 	.byte	3
 	.byte	14
 	.byte	73
 	.byte	19
 	.byte	58
 	.byte	11
 	.byte	59
 	.byte	11
 	.byte	2
 	.byte	24
 	.byte	0
 	.byte	0
 	.byte	4
 	.byte	52
 	.byte	0
 	.byte	2
 	.byte	24
 	.byte	3
 	.byte	14
 	.byte	58
 	.byte	11
 	.byte	59
 	.byte	11
 	.byte	73
 	.byte	19
 	.byte	0
 	.byte	0
 	.byte	5
 	.byte	1
 	.byte	1
 	.byte	73
 	.byte	19
 	.byte	0
 	.byte	0
 	.byte	6
 	.byte	33
 	.byte	0
 	.byte	73
 	.byte	19
 	.byte	55
 	.byte	11
 	.byte	0
 	.byte	0
 	.byte	7
 	.byte	38
 	.byte	0
 	.byte	73
 	.byte	19
 	.byte	0
 	.byte	0
 	.byte	8
 	.byte	22
 	.byte	0
 	.byte	73
 	.byte	19
 	.byte	3
 	.byte	14
 	.byte	58
 	.byte	11
 	.byte	59
 	.byte	11
 	.byte	0
 	.byte	0
 	.byte	9
 	.byte	36
 	.byte	0
 	.byte	3
 	.byte	14
 	.byte	62
 	.byte	11
 	.byte	11
 	.byte	11
 	.byte	0
 	.byte	0
 	.byte	10
 	.byte	36
 	.byte	0
 	.byte	3
 	.byte	14
 	.byte	11
 	.byte	11
 	.byte	62
 	.byte	11
 	.byte	0
 	.byte	0
 	.byte	11
 	.byte	15
 	.byte	0
 	.byte	73
 	.byte	19
 	.byte	0
 	.byte	0
 	.byte	12
 	.byte	46
 	.byte	1
 	.byte	17
 	.byte	1
 	.byte	18
 	.byte	6
 	.byte	64
 	.byte	24
 	.byte	3
 	.byte	14
 	.byte	58
 	.byte	11
 	.byte	59
 	.byte	11
 	.byte	39
 	.byte	25
 	.byte	63
 	.byte	25
 	.byte	0
 	.byte	0
 	.byte	13
 	.byte	5
 	.byte	0
 	.byte	2
 	.byte	24
 	.byte	3
 	.byte	14
 	.byte	58
 	.byte	11
 	.byte	59
 	.byte	11
 	.byte	73
 	.byte	19
 	.byte	0
 	.byte	0
 	.byte	14
 	.byte	46
 	.byte	1
 	.byte	17
 	.byte	1
 	.byte	18
 	.byte	6
 	.byte	64
 	.byte	24
 	.byte	3
 	.byte	14
 	.byte	58
 	.byte	11
 	.byte	59
 	.byte	11
 	.byte	39
 	.byte	25
 	.byte	73
 	.byte	19
 	.byte	63
 	.byte	25
 	.byte	0
 	.byte	0
 	.byte	15
 	.byte	11
 	.byte	1
 	.byte	17
 	.byte	1
 	.byte	18
 	.byte	6
 	.byte	0
 	.byte	0
 	.byte	0
.Lcu_begin0:
 	.long	720
 	.short	4
 	.long	.debug_abbrev
 	.byte	4
 	.byte	1
 	.long	.Linfo_string0
 	.short	12
 	.long	.Linfo_string1
 	.long	.Lline_table_start0
 	.long	.Linfo_string2
 	.long	.Lfunc_begin0
 	.long	.Lfunc_end6-.Lfunc_begin0
 	.byte	2
 	.long	.Lfunc_begin0
 	.long	.Lfunc_end0-.Lfunc_begin0
 	.byte	1
 	.byte	91
 	.long	.Linfo_string8
 	.byte	1
 	.byte	24
 	.long	699
 	.byte	3
 	.long	.Linfo_string3
 	.long	124
 	.byte	1
 	.byte	26
 	.byte	5
 	.byte	3
 	.long	main.array
 	.byte	3
 	.long	.Linfo_string7
 	.long	124
 	.byte	1
 	.byte	27
 	.byte	5
 	.byte	3
 	.long	main.solution
 	.byte	4
 	.byte	3
 	.byte	125
 	.asciz	"\304"
 	.long	.Linfo_string16
 	.byte	1
 	.byte	25
 	.long	706
 	.byte	4
 	.byte	3
 	.byte	125
 	.asciz	"\300"
 	.long	.Linfo_string17
 	.byte	1
 	.byte	25
 	.long	141
 	.byte	0
 	.byte	5
 	.long	136
 	.byte	6
 	.long	159
 	.byte	100
 	.byte	0
 	.byte	7
 	.long	141
 	.byte	8
 	.long	152
 	.long	.Linfo_string5
 	.byte	1
 	.byte	1
 	.byte	9
 	.long	.Linfo_string4
 	.byte	7
 	.byte	4
 	.byte	10
 	.long	.Linfo_string6
 	.byte	8
 	.byte	7
 	.byte	11
 	.long	141
 	.byte	12
 	.long	.Lfunc_begin1
 	.long	.Lfunc_end1-.Lfunc_begin1
 	.byte	1
 	.byte	91
 	.long	.Linfo_string10
 	.byte	1
 	.byte	74
 	.byte	13
 	.byte	2
 	.byte	145
 	.byte	124
 	.long	.Linfo_string18
 	.byte	1
 	.byte	74
 	.long	718
 	.byte	13
 	.byte	2
 	.byte	145
 	.byte	120
 	.long	.Linfo_string19
 	.byte	1
 	.byte	74
 	.long	166
 	.byte	13
 	.byte	2
 	.byte	145
 	.byte	116
 	.long	.Linfo_string20
 	.byte	1
 	.byte	74
 	.long	141
 	.byte	4
 	.byte	2
 	.byte	125
 	.byte	12
 	.long	.Linfo_string21
 	.byte	1
 	.byte	75
 	.long	699
 	.byte	0
 	.byte	14
 	.long	.Lfunc_begin2
 	.long	.Lfunc_end2-.Lfunc_begin2
 	.byte	1
 	.byte	91
 	.long	.Linfo_string11
 	.byte	1
 	.byte	128
 	.long	699
 	.byte	13
 	.byte	2
 	.byte	145
 	.byte	120
 	.long	.Linfo_string22
 	.byte	1
 	.byte	128
 	.long	718
 	.byte	13
 	.byte	2
 	.byte	145
 	.byte	116
 	.long	.Linfo_string23
 	.byte	1
 	.byte	128
 	.long	718
 	.byte	13
 	.byte	2
 	.byte	125
 	.byte	16
 	.long	.Linfo_string20
 	.byte	1
 	.byte	128
 	.long	141
 	.byte	4
 	.byte	2
 	.byte	125
 	.byte	12
 	.long	.Linfo_string21
 	.byte	1
 	.byte	129
 	.long	699
 	.byte	0
 	.byte	12
 	.long	.Lfunc_begin3
 	.long	.Lfunc_end3-.Lfunc_begin3
 	.byte	1
 	.byte	91
 	.long	.Linfo_string12
 	.byte	1
 	.byte	137
 	.byte	13
 	.byte	2
 	.byte	145
 	.byte	116
 	.long	.Linfo_string17
 	.byte	1
 	.byte	137
 	.long	141
 	.byte	13
 	.byte	2
 	.byte	145
 	.byte	112
 	.long	.Linfo_string24
 	.byte	1
 	.byte	137
 	.long	141
 	.byte	13
 	.byte	2
 	.byte	125
 	.byte	20
 	.long	.Linfo_string25
 	.byte	1
 	.byte	137
 	.long	141
 	.byte	13
 	.byte	2
 	.byte	125
 	.byte	16
 	.long	.Linfo_string26
 	.byte	1
 	.byte	137
 	.long	141
 	.byte	0
 	.byte	12
 	.long	.Lfunc_begin4
 	.long	.Lfunc_end4-.Lfunc_begin4
 	.byte	1
 	.byte	91
 	.long	.Linfo_string13
 	.byte	1
 	.byte	81
 	.byte	13
 	.byte	2
 	.byte	125
 	.byte	24
 	.long	.Linfo_string3
 	.byte	1
 	.byte	81
 	.long	166
 	.byte	13
 	.byte	2
 	.byte	125
 	.byte	20
 	.long	.Linfo_string20
 	.byte	1
 	.byte	81
 	.long	141
 	.byte	4
 	.byte	2
 	.byte	125
 	.byte	16
 	.long	.Linfo_string27
 	.byte	1
 	.byte	82
 	.long	141
 	.byte	4
 	.byte	2
 	.byte	125
 	.byte	12
 	.long	.Linfo_string21
 	.byte	1
 	.byte	82
 	.long	141
 	.byte	4
 	.byte	2
 	.byte	125
 	.byte	8
 	.long	.Linfo_string28
 	.byte	1
 	.byte	82
 	.long	141
 	.byte	0
 	.byte	12
 	.long	.Lfunc_begin5
 	.long	.Lfunc_end5-.Lfunc_begin5
 	.byte	1
 	.byte	91
 	.long	.Linfo_string14
 	.byte	1
 	.byte	97
 	.byte	13
 	.byte	2
 	.byte	125
 	.byte	28
 	.long	.Linfo_string3
 	.byte	1
 	.byte	97
 	.long	166
 	.byte	13
 	.byte	2
 	.byte	125
 	.byte	24
 	.long	.Linfo_string20
 	.byte	1
 	.byte	97
 	.long	141
 	.byte	4
 	.byte	2
 	.byte	125
 	.byte	20
 	.long	.Linfo_string29
 	.byte	1
 	.byte	98
 	.long	141
 	.byte	4
 	.byte	2
 	.byte	125
 	.byte	16
 	.long	.Linfo_string30
 	.byte	1
 	.byte	99
 	.long	699
 	.byte	4
 	.byte	2
 	.byte	125
 	.byte	12
 	.long	.Linfo_string21
 	.byte	1
 	.byte	99
 	.long	699
 	.byte	0
 	.byte	12
 	.long	.Lfunc_begin6
 	.long	.Lfunc_end6-.Lfunc_begin6
 	.byte	1
 	.byte	91
 	.long	.Linfo_string15
 	.byte	1
 	.byte	113
 	.byte	13
 	.byte	2
 	.byte	125
 	.byte	32
 	.long	.Linfo_string3
 	.byte	1
 	.byte	113
 	.long	166
 	.byte	13
 	.byte	2
 	.byte	125
 	.byte	28
 	.long	.Linfo_string20
 	.byte	1
 	.byte	113
 	.long	141
 	.byte	4
 	.byte	2
 	.byte	125
 	.byte	24
 	.long	.Linfo_string31
 	.byte	1
 	.byte	114
 	.long	141
 	.byte	4
 	.byte	2
 	.byte	125
 	.byte	20
 	.long	.Linfo_string27
 	.byte	1
 	.byte	114
 	.long	141
 	.byte	4
 	.byte	2
 	.byte	125
 	.byte	16
 	.long	.Linfo_string21
 	.byte	1
 	.byte	114
 	.long	141
 	.byte	4
 	.byte	2
 	.byte	125
 	.byte	12
 	.long	.Linfo_string30
 	.byte	1
 	.byte	114
 	.long	141
 	.byte	15
 	.long	.Ltmp69
 	.long	.Ltmp79-.Ltmp69
 	.byte	4
 	.byte	2
 	.byte	125
 	.byte	8
 	.long	.Linfo_string31
 	.byte	1
 	.byte	116
 	.long	141
 	.byte	0
 	.byte	0
 	.byte	9
 	.long	.Linfo_string9
 	.byte	5
 	.byte	4
 	.byte	5
 	.long	141
 	.byte	6
 	.long	159
 	.byte	100
 	.byte	0
 	.byte	11
 	.long	136
 	.byte	0
.Lcu_macro_begin0:
 	.byte	0
 	.long	.LpubNames_end0-.LpubNames_begin0
.LpubNames_begin0:
 	.short	2
 	.long	.Lcu_begin0
 	.long	724
 	.long	485
 	.asciz	"insertion_sort"
 	.long	397
 	.asciz	"bubble_sort"
 	.long	245
 	.asciz	"array_eq"
 	.long	38
 	.asciz	"main"
 	.long	323
 	.asciz	"sys_exit"
 	.long	171
 	.asciz	"array_copy"
 	.long	76
 	.asciz	"solution"
 	.long	573
 	.asciz	"selection_sort"
 	.long	59
 	.asciz	"array"
 	.long	0
.LpubNames_end0:
 	.long	.LpubTypes_end0-.LpubTypes_begin0
.LpubTypes_begin0:
 	.short	2
 	.long	.Lcu_begin0
 	.long	724
 	.long	141
 	.asciz	"uint32_t"
 	.long	152
 	.asciz	"long unsigned int"
 	.long	699
 	.asciz	"int"
 	.long	0
.LpubTypes_end0:
 	.ident	"clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)"
 	.section	".note.GNU-stack","",%progbits
 	.section	.debug_line,"",%progbits
.Lline_table_start0:
 
