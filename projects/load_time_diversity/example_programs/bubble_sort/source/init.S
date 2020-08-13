#include "addresses.h"
.section .kernelTEXT

.global _init
_init:
	@ initialize stackpointers of all modes
	@ reset starts in Supervisor mode
	ldr	sp, =SUPER_SP

	CPS	#23     	@ ABORT
	ldr	sp, =ABORT_SP

	CPS	#17     	@ FIQ
	ldr	sp, =FIQ_SP

	CPS	#18     	@ IRQ
	ldr	sp, =IRQ_SP

	CPS	#27     	@ UDI
	ldr	sp, =UNDEF_SP

	CPS	#31		@ SYSTEM
	ldr	sp, =SYSTEM_SP

@ insert additional startup here
@
@

	mrs r0, cpsr
	bic r0, r0, #0x1F @ clear mode bits
	orr r0, r0, #0x10 @ set mode bits to USER mode
	msr	spsr, r0 @ save r0 to spsr
	ldr	r1, =main	@ set main as first user thread
	ldr r0, start_mis_offset
	add lr, r0, r1
	movs	pc, lr @ movs on pc: Jump to label while changing execution mode to user
start_mis_offset: .word 0x0
