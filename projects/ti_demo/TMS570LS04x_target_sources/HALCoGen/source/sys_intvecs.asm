;-------------------------------------------------------------------------------
; sys_intvecs.asm
;
; (c) Texas Instruments 2009-2012, All rights reserved.
;

    .sect ".intvecs"


;-------------------------------------------------------------------------------
; import reference for interrupt routines

    .ref _c_int00
    .ref _svc
    .ref _dabort


;-------------------------------------------------------------------------------
; interrupt vectors

        b   _c_int00
undefEntry
        b   undefEntry
        b   _svc
prefetchEntry
        b   prefetchEntry
        b   _dabort
reservedEntry
        b   reservedEntry
        ldr pc,[pc,#-0x1b0]
        ldr pc,[pc,#-0x1b0]

    
;-------------------------------------------------------------------------------
