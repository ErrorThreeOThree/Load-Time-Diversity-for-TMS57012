	.text
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
	.file	1 "program/source/main.c"
	.globl	main
	.p2align	2
	.type	main,%function
	.code	32
main:
.Lfunc_begin0:
	.loc	1 44 0
	.fnstart
	.cfi_sections .debug_frame
	.cfi_startproc
	.pad	#16
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	mov	r0, #0
	str	r0, [sp, #12]
.Ltmp0:
	.loc	1 46 17 prologue_end
	movw	r1, #48128
	movt	r1, #65527
	mov	r2, #1
	str	r2, [r1]
	.loc	1 47 17
	movw	r1, #48148
	movt	r1, #65527
	mov	r2, #255
	str	r2, [r1]
	.loc	1 48 17
	movw	r1, #48156
	movt	r1, #65527
	str	r2, [r1]
	.loc	1 53 17
	movw	r1, #48188
	movt	r1, #65527
	str	r0, [r1]
	movw	r1, #48180
	movt	r1, #65527
	.loc	1 63 17
	mov	r2, #4
	str	r2, [r1]
	.loc	1 73 17
	movw	r2, #48200
	movt	r2, #65527
	str	r0, [r2]
	.loc	1 83 17
	movw	r2, #48208
	movt	r2, #65527
	str	r0, [r2]
	.loc	1 93 20
	movw	r2, #48204
	movt	r2, #65527
	str	r0, [r2]
	.loc	1 102 24
	str	r1, [sp, #8]
	.loc	1 103 12
	mov	r0, #2
	str	r0, [sp, #4]
	.loc	1 105 2
	b	.LBB0_1
.LBB0_1:
.Ltmp1:
	.loc	1 106 8
	ldr	r0, [sp, #8]
	.loc	1 106 14 is_stmt 0
	ldr	r0, [r0, #4]
	.loc	1 106 47
	ldr	r1, [sp, #4]
	.loc	1 106 44
	mov	r2, #1
.Ltmp2:
	.loc	1 106 7
	tst	r0, r2, lsl r1
	beq	.LBB0_3
	b	.LBB0_2
.LBB0_2:
.Ltmp3:
	.loc	1 108 33 is_stmt 1
	ldr	r0, [sp, #4]
	.loc	1 108 30 is_stmt 0
	mov	r1, #1
	lsl	r0, r1, r0
	.loc	1 108 4
	ldr	r1, [sp, #8]
	.loc	1 108 15
	str	r0, [r1, #16]
	.loc	1 109 3 is_stmt 1
	b	.LBB0_4
.Ltmp4:
.LBB0_3:
	.loc	1 112 33
	ldr	r0, [sp, #4]
	.loc	1 112 30 is_stmt 0
	mov	r1, #1
	lsl	r0, r1, r0
	.loc	1 112 4
	ldr	r1, [sp, #8]
	.loc	1 112 15
	str	r0, [r1, #12]
	b	.LBB0_4
.Ltmp5:
.LBB0_4:
	.loc	1 114 21 is_stmt 1
	mov	r0, #0
	str	r0, [sp]
	.loc	1 114 8 is_stmt 0
	b	.LBB0_5
.LBB0_5:
.Ltmp6:
	.loc	1 114 28
	ldr	r0, [sp]
.Ltmp7:
	.loc	1 114 3
	movw	r1, #16959
	movt	r1, #15
	cmp	r0, r1
	bgt	.LBB0_8
	b	.LBB0_6
.LBB0_6:
	b	.LBB0_7
.LBB0_7:
.Ltmp8:
	.loc	1 114 40
	ldr	r0, [sp]
	add	r0, r0, #1
	str	r0, [sp]
	.loc	1 114 3
	b	.LBB0_5
.Ltmp9:
.LBB0_8:
	.loc	1 105 2 is_stmt 1
	b	.LBB0_1
.Ltmp10:
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
	.cantunwind
	.fnend

	.section	.debug_str,"MS",%progbits,1
.Linfo_string0:
	.asciz	"clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)"
.Linfo_string1:
	.asciz	"program/source/main.c"
.Linfo_string2:
	.asciz	"/home/jh/Documents/bachelorarbeit/projects/switch_to_ram"
.Linfo_string3:
	.asciz	"GCR0"
.Linfo_string4:
	.asciz	"long unsigned int"
.Linfo_string5:
	.asciz	"uint32_t"
.Linfo_string6:
	.asciz	"rsvd"
.Linfo_string7:
	.asciz	"INTDET"
.Linfo_string8:
	.asciz	"POL"
.Linfo_string9:
	.asciz	"ENASET"
.Linfo_string10:
	.asciz	"ENACLR"
.Linfo_string11:
	.asciz	"LVLSET"
.Linfo_string12:
	.asciz	"LVLCLR"
.Linfo_string13:
	.asciz	"FLG"
.Linfo_string14:
	.asciz	"OFF1"
.Linfo_string15:
	.asciz	"OFF2"
.Linfo_string16:
	.asciz	"EMU1"
.Linfo_string17:
	.asciz	"EMU2"
.Linfo_string18:
	.asciz	"gioBase"
.Linfo_string19:
	.asciz	"gioBASE_t"
.Linfo_string20:
	.asciz	"DIR"
.Linfo_string21:
	.asciz	"DIN"
.Linfo_string22:
	.asciz	"DOUT"
.Linfo_string23:
	.asciz	"DSET"
.Linfo_string24:
	.asciz	"DCLR"
.Linfo_string25:
	.asciz	"PDR"
.Linfo_string26:
	.asciz	"PULDIS"
.Linfo_string27:
	.asciz	"PSL"
.Linfo_string28:
	.asciz	"gioPort"
.Linfo_string29:
	.asciz	"gioPORT_t"
.Linfo_string30:
	.asciz	"main"
.Linfo_string31:
	.asciz	"int"
.Linfo_string32:
	.asciz	"port"
.Linfo_string33:
	.asciz	"bit"
.Linfo_string34:
	.asciz	"j"
	.section	.debug_abbrev,"",%progbits
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
	.byte	15
	.byte	0
	.byte	73
	.byte	19
	.byte	0
	.byte	0
	.byte	3
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
	.byte	4
	.byte	53
	.byte	0
	.byte	73
	.byte	19
	.byte	0
	.byte	0
	.byte	5
	.byte	19
	.byte	1
	.byte	3
	.byte	14
	.byte	11
	.byte	11
	.byte	58
	.byte	11
	.byte	59
	.byte	11
	.byte	0
	.byte	0
	.byte	6
	.byte	13
	.byte	0
	.byte	3
	.byte	14
	.byte	73
	.byte	19
	.byte	58
	.byte	11
	.byte	59
	.byte	11
	.byte	56
	.byte	11
	.byte	0
	.byte	0
	.byte	7
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
	.byte	8
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
	.byte	9
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
	.byte	10
	.byte	11
	.byte	1
	.byte	17
	.byte	1
	.byte	18
	.byte	6
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_info,"",%progbits
.Lcu_begin0:
	.long	461
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
	.long	.Lfunc_end0-.Lfunc_begin0
	.byte	2
	.long	43
	.byte	3
	.long	54
	.long	.Linfo_string19
	.byte	1
	.byte	25
	.byte	4
	.long	59
	.byte	5
	.long	.Linfo_string18
	.byte	52
	.byte	1
	.byte	10
	.byte	6
	.long	.Linfo_string3
	.long	224
	.byte	1
	.byte	12
	.byte	0
	.byte	6
	.long	.Linfo_string6
	.long	224
	.byte	1
	.byte	13
	.byte	4
	.byte	6
	.long	.Linfo_string7
	.long	224
	.byte	1
	.byte	14
	.byte	8
	.byte	6
	.long	.Linfo_string8
	.long	224
	.byte	1
	.byte	15
	.byte	12
	.byte	6
	.long	.Linfo_string9
	.long	224
	.byte	1
	.byte	16
	.byte	16
	.byte	6
	.long	.Linfo_string10
	.long	224
	.byte	1
	.byte	17
	.byte	20
	.byte	6
	.long	.Linfo_string11
	.long	224
	.byte	1
	.byte	18
	.byte	24
	.byte	6
	.long	.Linfo_string12
	.long	224
	.byte	1
	.byte	19
	.byte	28
	.byte	6
	.long	.Linfo_string13
	.long	224
	.byte	1
	.byte	20
	.byte	32
	.byte	6
	.long	.Linfo_string14
	.long	224
	.byte	1
	.byte	21
	.byte	36
	.byte	6
	.long	.Linfo_string15
	.long	224
	.byte	1
	.byte	22
	.byte	40
	.byte	6
	.long	.Linfo_string16
	.long	224
	.byte	1
	.byte	23
	.byte	44
	.byte	6
	.long	.Linfo_string17
	.long	224
	.byte	1
	.byte	24
	.byte	48
	.byte	0
	.byte	3
	.long	235
	.long	.Linfo_string5
	.byte	1
	.byte	1
	.byte	7
	.long	.Linfo_string4
	.byte	7
	.byte	4
	.byte	2
	.long	247
	.byte	3
	.long	258
	.long	.Linfo_string29
	.byte	1
	.byte	39
	.byte	4
	.long	263
	.byte	5
	.long	.Linfo_string28
	.byte	32
	.byte	1
	.byte	29
	.byte	6
	.long	.Linfo_string20
	.long	224
	.byte	1
	.byte	31
	.byte	0
	.byte	6
	.long	.Linfo_string21
	.long	224
	.byte	1
	.byte	32
	.byte	4
	.byte	6
	.long	.Linfo_string22
	.long	224
	.byte	1
	.byte	33
	.byte	8
	.byte	6
	.long	.Linfo_string23
	.long	224
	.byte	1
	.byte	34
	.byte	12
	.byte	6
	.long	.Linfo_string24
	.long	224
	.byte	1
	.byte	35
	.byte	16
	.byte	6
	.long	.Linfo_string25
	.long	224
	.byte	1
	.byte	36
	.byte	20
	.byte	6
	.long	.Linfo_string26
	.long	224
	.byte	1
	.byte	37
	.byte	24
	.byte	6
	.long	.Linfo_string27
	.long	224
	.byte	1
	.byte	38
	.byte	28
	.byte	0
	.byte	8
	.long	.Lfunc_begin0
	.long	.Lfunc_end0-.Lfunc_begin0
	.byte	1
	.byte	91
	.long	.Linfo_string30
	.byte	1
	.byte	44
	.long	442

	.byte	9
	.byte	2
	.byte	125
	.byte	8
	.long	.Linfo_string32
	.byte	1
	.byte	102
	.long	449
	.byte	9
	.byte	2
	.byte	125
	.byte	4
	.long	.Linfo_string33
	.byte	1
	.byte	103
	.long	224
	.byte	10
	.long	.Ltmp5
	.long	.Ltmp9-.Ltmp5
	.byte	9
	.byte	2
	.byte	125
	.byte	0
	.long	.Linfo_string34
	.byte	1
	.byte	114
	.long	459
	.byte	0
	.byte	0
	.byte	7
	.long	.Linfo_string31
	.byte	5
	.byte	4
	.byte	2
	.long	454
	.byte	4
	.long	247
	.byte	4
	.long	442
	.byte	0
	.section	.debug_ranges,"",%progbits
	.section	.debug_macinfo,"",%progbits
.Lcu_macro_begin0:
	.byte	0
	.section	.debug_pubnames,"",%progbits
	.long	.LpubNames_end0-.LpubNames_begin0
.LpubNames_begin0:
	.short	2
	.long	.Lcu_begin0
	.long	465
	.long	368
	.asciz	"main"
	.long	0
.LpubNames_end0:
	.section	.debug_pubtypes,"",%progbits
	.long	.LpubTypes_end0-.LpubTypes_begin0
.LpubTypes_begin0:
	.short	2
	.long	.Lcu_begin0
	.long	465
	.long	263
	.asciz	"gioPort"
	.long	247
	.asciz	"gioPORT_t"
	.long	224
	.asciz	"uint32_t"
	.long	235
	.asciz	"long unsigned int"
	.long	59
	.asciz	"gioBase"
	.long	442
	.asciz	"int"
	.long	43
	.asciz	"gioBASE_t"
	.long	0
.LpubTypes_end0:

	.ident	"clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)"
	.section	".note.GNU-stack","",%progbits
	.eabi_attribute	30, 6
	.section	.debug_line,"",%progbits
.Lline_table_start0:
