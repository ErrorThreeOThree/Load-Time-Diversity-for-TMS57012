 	.cpu cortex-r4
 	.eabi_attribute 28, 1
 	.eabi_attribute 20, 1
 	.eabi_attribute 21, 1
 	.eabi_attribute 23, 3
 	.eabi_attribute 24, 1
 	.eabi_attribute 25, 1
 	.eabi_attribute 26, 1
 	.eabi_attribute 30, 6
 	.eabi_attribute 34, 1
 	.eabi_attribute 18, 4
 	.file	"main.c"
 	.syntax unified
 	.arm
 	.file 1 "main.c"
 	 .section	.text,"ax",%progbits
.Ltext0:
 	.align	2
 	.global	main
 	.fpu vfp
 	.type	main, %function
main:
.LFB0:
 	.loc 1 44 0
 	str	fp, [sp, #-4]!
 	add	fp, sp, #0
 	sub	sp, sp, #20
 	.loc 1 46 0
 	mov	r3, #48128
 	movt	r3, 65527
 	mov	r2, #1
 	str	r2, [r3]
 	.loc 1 47 0
 	mov	r3, #48128
 	movt	r3, 65527
 	mov	r2, #255
 	str	r2, [r3, #20]
 	.loc 1 48 0
 	mov	r3, #48128
 	movt	r3, 65527
 	mov	r2, #255
 	str	r2, [r3, #28]
 	.loc 1 53 0
 	movw	r3, #48180
 	movt	r3, 65527
 	mov	r2, #0
 	str	r2, [r3, #8]
 	.loc 1 63 0
 	movw	r3, #48180
 	movt	r3, 65527
 	mov	r2, #4
 	str	r2, [r3]
 	.loc 1 73 0
 	movw	r3, #48180
 	movt	r3, 65527
 	mov	r2, #0
 	str	r2, [r3, #20]
 	.loc 1 83 0
 	movw	r3, #48180
 	movt	r3, 65527
 	mov	r2, #0
 	str	r2, [r3, #28]
 	.loc 1 93 0
 	movw	r3, #48180
 	movt	r3, 65527
 	mov	r2, #0
 	str	r2, [r3, #24]
 	.loc 1 102 0
 	movw	r3, #48180
 	movt	r3, 65527
 	str	r3, [fp, #-8]
 	.loc 1 103 0
 	mov	r3, #2
 	str	r3, [fp, #-12]
.L6:
 	.loc 1 106 0
 	ldr	r3, [fp, #-8]
 	ldr	r2, [r3, #4]
 	ldr	r3, [fp, #-12]
 	lsr	r3, r2, r3
 	and	r3, r3, #1
 	cmp	r3, #0
 	beq	.L2
 	.loc 1 108 0
 	mov	r2, #1
 	ldr	r3, [fp, #-12]
 	lsl	r2, r2, r3
 	ldr	r3, [fp, #-8]
 	str	r2, [r3, #16]
 	b	.L3
.L2:
 	.loc 1 112 0
 	mov	r2, #1
 	ldr	r3, [fp, #-12]
 	lsl	r2, r2, r3
 	ldr	r3, [fp, #-8]
 	str	r2, [r3, #12]
.L3:
.LBB2:
 	.loc 1 114 0
 	mov	r3, #0
 	str	r3, [fp, #-16]
 	b	.L4
.L5:
 	.loc 1 114 0 is_stmt 0 discriminator 3
 	ldr	r3, [fp, #-16]
 	add	r3, r3, #1
 	str	r3, [fp, #-16]
.L4:
 	.loc 1 114 0 discriminator 1
 	ldr	r2, [fp, #-16]
 	movw	r3, #16959
 	movt	r3, 15
 	cmp	r2, r3
 	ble	.L5
.LBE2:
 	.loc 1 106 0 is_stmt 1
 	b	.L6
.LFE0:
.Letext0:
 

 	.section	.debug_info,"",%progbits
.Ldebug_info0:
 	.4byte	0x1c8
 	.2byte	0x4
 	.4byte	.Ldebug_abbrev0
 	.byte	0x4
 	.uleb128 0x1
 	.4byte	.LASF22
 	.byte	0xc
 	.4byte	.LASF23
 	.4byte	.LASF24
 	.4byte	.Ltext0
 	.4byte	.Letext0-.Ltext0
 	.4byte	.Ldebug_line0
 	.uleb128 0x2
 	.4byte	.LASF11
 	.byte	0x1
 	.byte	0x1
 	.4byte	0x30
 	.uleb128 0x3
 	.byte	0x4
 	.byte	0x7
 	.4byte	.LASF21
 	.uleb128 0x4
 	.4byte	.LASF13
 	.byte	0x34
 	.byte	0x1
 	.byte	0xa
 	.4byte	0xe0
 	.uleb128 0x5
 	.4byte	.LASF0
 	.byte	0x1
 	.byte	0xc
 	.4byte	0x25
 	.byte	0
 	.uleb128 0x5
 	.4byte	.LASF1
 	.byte	0x1
 	.byte	0xd
 	.4byte	0x25
 	.byte	0x4
 	.uleb128 0x5
 	.4byte	.LASF2
 	.byte	0x1
 	.byte	0xe
 	.4byte	0x25
 	.byte	0x8
 	.uleb128 0x6
 	.ascii	"POL\000"
 	.byte	0x1
 	.byte	0xf
 	.4byte	0x25
 	.byte	0xc
 	.uleb128 0x5
 	.4byte	.LASF3
 	.byte	0x1
 	.byte	0x10
 	.4byte	0x25
 	.byte	0x10
 	.uleb128 0x5
 	.4byte	.LASF4
 	.byte	0x1
 	.byte	0x11
 	.4byte	0x25
 	.byte	0x14
 	.uleb128 0x5
 	.4byte	.LASF5
 	.byte	0x1
 	.byte	0x12
 	.4byte	0x25
 	.byte	0x18
 	.uleb128 0x5
 	.4byte	.LASF6
 	.byte	0x1
 	.byte	0x13
 	.4byte	0x25
 	.byte	0x1c
 	.uleb128 0x6
 	.ascii	"FLG\000"
 	.byte	0x1
 	.byte	0x14
 	.4byte	0x25
 	.byte	0x20
 	.uleb128 0x5
 	.4byte	.LASF7
 	.byte	0x1
 	.byte	0x15
 	.4byte	0x25
 	.byte	0x24
 	.uleb128 0x5
 	.4byte	.LASF8
 	.byte	0x1
 	.byte	0x16
 	.4byte	0x25
 	.byte	0x28
 	.uleb128 0x5
 	.4byte	.LASF9
 	.byte	0x1
 	.byte	0x17
 	.4byte	0x25
 	.byte	0x2c
 	.uleb128 0x5
 	.4byte	.LASF10
 	.byte	0x1
 	.byte	0x18
 	.4byte	0x25
 	.byte	0x30
 	.byte	0
 	.uleb128 0x7
 	.4byte	0x37
 	.uleb128 0x2
 	.4byte	.LASF12
 	.byte	0x1
 	.byte	0x19
 	.4byte	0xe0
 	.uleb128 0x4
 	.4byte	.LASF14
 	.byte	0x20
 	.byte	0x1
 	.byte	0x1d
 	.4byte	0x15d
 	.uleb128 0x6
 	.ascii	"DIR\000"
 	.byte	0x1
 	.byte	0x1f
 	.4byte	0x25
 	.byte	0
 	.uleb128 0x6
 	.ascii	"DIN\000"
 	.byte	0x1
 	.byte	0x20
 	.4byte	0x25
 	.byte	0x4
 	.uleb128 0x5
 	.4byte	.LASF15
 	.byte	0x1
 	.byte	0x21
 	.4byte	0x25
 	.byte	0x8
 	.uleb128 0x5
 	.4byte	.LASF16
 	.byte	0x1
 	.byte	0x22
 	.4byte	0x25
 	.byte	0xc
 	.uleb128 0x5
 	.4byte	.LASF17
 	.byte	0x1
 	.byte	0x23
 	.4byte	0x25
 	.byte	0x10
 	.uleb128 0x6
 	.ascii	"PDR\000"
 	.byte	0x1
 	.byte	0x24
 	.4byte	0x25
 	.byte	0x14
 	.uleb128 0x5
 	.4byte	.LASF18
 	.byte	0x1
 	.byte	0x25
 	.4byte	0x25
 	.byte	0x18
 	.uleb128 0x6
 	.ascii	"PSL\000"
 	.byte	0x1
 	.byte	0x26
 	.4byte	0x25
 	.byte	0x1c
 	.byte	0
 	.uleb128 0x7
 	.4byte	0xf0
 	.uleb128 0x2
 	.4byte	.LASF19
 	.byte	0x1
 	.byte	0x27
 	.4byte	0x15d
 	.uleb128 0x8
 	.4byte	.LASF25
 	.byte	0x1
 	.byte	0x2c
 	.4byte	0x1b9
 	.4byte	.LFB0
 	.4byte	.LFE0-.LFB0
 	.uleb128 0x1
 	.byte	0x9c
 	.4byte	0x1b9
 	.uleb128 0x9
 	.4byte	.LASF20
 	.byte	0x1
 	.byte	0x66
 	.4byte	0x1c5
 	.uleb128 0x2
 	.byte	0x91
 	.sleb128 -12
 	.uleb128 0xa
 	.ascii	"bit\000"
 	.byte	0x1
 	.byte	0x67
 	.4byte	0x25
 	.uleb128 0x2
 	.byte	0x91
 	.sleb128 -16
 	.uleb128 0xb
 	.4byte	.LBB2
 	.4byte	.LBE2-.LBB2
 	.uleb128 0xa
 	.ascii	"j\000"
 	.byte	0x1
 	.byte	0x72
 	.4byte	0x1c0
 	.uleb128 0x2
 	.byte	0x91
 	.sleb128 -20
 	.byte	0
 	.byte	0
 	.uleb128 0xc
 	.byte	0x4
 	.byte	0x5
 	.ascii	"int\000"
 	.uleb128 0x7
 	.4byte	0x1b9
 	.uleb128 0xd
 	.byte	0x4
 	.4byte	0x162
 	.byte	0
.Ldebug_abbrev0:
 	.uleb128 0x1
 	.uleb128 0x11
 	.byte	0x1
 	.uleb128 0x25
 	.uleb128 0xe
 	.uleb128 0x13
 	.uleb128 0xb
 	.uleb128 0x3
 	.uleb128 0xe
 	.uleb128 0x1b
 	.uleb128 0xe
 	.uleb128 0x11
 	.uleb128 0x1
 	.uleb128 0x12
 	.uleb128 0x6
 	.uleb128 0x10
 	.uleb128 0x17
 	.byte	0
 	.byte	0
 	.uleb128 0x2
 	.uleb128 0x16
 	.byte	0
 	.uleb128 0x3
 	.uleb128 0xe
 	.uleb128 0x3a
 	.uleb128 0xb
 	.uleb128 0x3b
 	.uleb128 0xb
 	.uleb128 0x49
 	.uleb128 0x13
 	.byte	0
 	.byte	0
 	.uleb128 0x3
 	.uleb128 0x24
 	.byte	0
 	.uleb128 0xb
 	.uleb128 0xb
 	.uleb128 0x3e
 	.uleb128 0xb
 	.uleb128 0x3
 	.uleb128 0xe
 	.byte	0
 	.byte	0
 	.uleb128 0x4
 	.uleb128 0x13
 	.byte	0x1
 	.uleb128 0x3
 	.uleb128 0xe
 	.uleb128 0xb
 	.uleb128 0xb
 	.uleb128 0x3a
 	.uleb128 0xb
 	.uleb128 0x3b
 	.uleb128 0xb
 	.uleb128 0x1
 	.uleb128 0x13
 	.byte	0
 	.byte	0
 	.uleb128 0x5
 	.uleb128 0xd
 	.byte	0
 	.uleb128 0x3
 	.uleb128 0xe
 	.uleb128 0x3a
 	.uleb128 0xb
 	.uleb128 0x3b
 	.uleb128 0xb
 	.uleb128 0x49
 	.uleb128 0x13
 	.uleb128 0x38
 	.uleb128 0xb
 	.byte	0
 	.byte	0
 	.uleb128 0x6
 	.uleb128 0xd
 	.byte	0
 	.uleb128 0x3
 	.uleb128 0x8
 	.uleb128 0x3a
 	.uleb128 0xb
 	.uleb128 0x3b
 	.uleb128 0xb
 	.uleb128 0x49
 	.uleb128 0x13
 	.uleb128 0x38
 	.uleb128 0xb
 	.byte	0
 	.byte	0
 	.uleb128 0x7
 	.uleb128 0x35
 	.byte	0
 	.uleb128 0x49
 	.uleb128 0x13
 	.byte	0
 	.byte	0
 	.uleb128 0x8
 	.uleb128 0x2e
 	.byte	0x1
 	.uleb128 0x3f
 	.uleb128 0x19
 	.uleb128 0x3
 	.uleb128 0xe
 	.uleb128 0x3a
 	.uleb128 0xb
 	.uleb128 0x3b
 	.uleb128 0xb
 	.uleb128 0x49
 	.uleb128 0x13
 	.uleb128 0x11
 	.uleb128 0x1
 	.uleb128 0x12
 	.uleb128 0x6
 	.uleb128 0x40
 	.uleb128 0x18
 	.uleb128 0x2117
 	.uleb128 0x19
 	.uleb128 0x1
 	.uleb128 0x13
 	.byte	0
 	.byte	0
 	.uleb128 0x9
 	.uleb128 0x34
 	.byte	0
 	.uleb128 0x3
 	.uleb128 0xe
 	.uleb128 0x3a
 	.uleb128 0xb
 	.uleb128 0x3b
 	.uleb128 0xb
 	.uleb128 0x49
 	.uleb128 0x13
 	.uleb128 0x2
 	.uleb128 0x18
 	.byte	0
 	.byte	0
 	.uleb128 0xa
 	.uleb128 0x34
 	.byte	0
 	.uleb128 0x3
 	.uleb128 0x8
 	.uleb128 0x3a
 	.uleb128 0xb
 	.uleb128 0x3b
 	.uleb128 0xb
 	.uleb128 0x49
 	.uleb128 0x13
 	.uleb128 0x2
 	.uleb128 0x18
 	.byte	0
 	.byte	0
 	.uleb128 0xb
 	.uleb128 0xb
 	.byte	0x1
 	.uleb128 0x11
 	.uleb128 0x1
 	.uleb128 0x12
 	.uleb128 0x6
 	.byte	0
 	.byte	0
 	.uleb128 0xc
 	.uleb128 0x24
 	.byte	0
 	.uleb128 0xb
 	.uleb128 0xb
 	.uleb128 0x3e
 	.uleb128 0xb
 	.uleb128 0x3
 	.uleb128 0x8
 	.byte	0
 	.byte	0
 	.uleb128 0xd
 	.uleb128 0xf
 	.byte	0
 	.uleb128 0xb
 	.uleb128 0xb
 	.uleb128 0x49
 	.uleb128 0x13
 	.byte	0
 	.byte	0
 	.byte	0
 	.4byte	0x1c
 	.2byte	0x2
 	.4byte	.Ldebug_info0
 	.byte	0x4
 	.byte	0
 	.2byte	0
 	.2byte	0
 	.4byte	.Ltext0
 	.4byte	.Letext0-.Ltext0
 	.4byte	0
 	.4byte	0
.Ldebug_line0:
.LASF1:
 	.ascii	"rsvd\000"
.LASF24:
 	.ascii	"/home/jh/Documents/bachelorarbeit/projects/switch_t"
 	.ascii	"o_ram/program\000"
.LASF3:
 	.ascii	"ENASET\000"
.LASF10:
 	.ascii	"EMU2\000"
.LASF23:
 	.ascii	"main.c\000"
.LASF25:
 	.ascii	"main\000"
.LASF9:
 	.ascii	"EMU1\000"
.LASF21:
 	.ascii	"long unsigned int\000"
.LASF13:
 	.ascii	"gioBase\000"
.LASF4:
 	.ascii	"ENACLR\000"
.LASF20:
 	.ascii	"port\000"
.LASF19:
 	.ascii	"gioPORT_t\000"
.LASF16:
 	.ascii	"DSET\000"
.LASF5:
 	.ascii	"LVLSET\000"
.LASF2:
 	.ascii	"INTDET\000"
.LASF15:
 	.ascii	"DOUT\000"
.LASF11:
 	.ascii	"uint32_t\000"
.LASF12:
 	.ascii	"gioBASE_t\000"
.LASF6:
 	.ascii	"LVLCLR\000"
.LASF18:
 	.ascii	"PULDIS\000"
.LASF14:
 	.ascii	"gioPort\000"
.LASF17:
 	.ascii	"DCLR\000"
.LASF7:
 	.ascii	"OFF1\000"
.LASF8:
 	.ascii	"OFF2\000"
.LASF22:
 	.ascii	"GNU C11 6.3.1 20170620 -marm -mcpu=cortex-r4 -mbig-"
 	.ascii	"endian -mfloat-abi=hard -g -O0 -std=c11 -fno-except"
 	.ascii	"ions\000"
.LASF0:
 	.ascii	"GCR0\000"
 	.ident	"GCC: (15:6.3.1+svn253039-1build1) 6.3.1 20170620"
