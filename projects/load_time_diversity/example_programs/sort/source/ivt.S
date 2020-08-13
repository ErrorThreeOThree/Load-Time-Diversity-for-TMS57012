.global IVT_START
.balign	32
.section .ivt

.extern _init


IVT_START:
	b	_init
_undef_trampolin:
	b	_undef_trampolin
_svc_trampolin:
	b	_svc_trampolin
_pabort_trampolin:
	b	_pabort_trampolin
_babort_trampolin:
	b	_babort_trampolin
	nop
_irq_trampolin:
	b	_irq_trampolin
_fiq_trampolin:
	b	_fiq_trampolin
