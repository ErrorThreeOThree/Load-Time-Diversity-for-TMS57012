#ifndef ESM_DEMO_H_
#define ESM_DEMO_H_

#include "esm.h"
#include "system.h"
#include "sci.h"
#include "ftu.h"
#include "dma.h"
#include "esm.h"
#include "adc.h"
#include "can.h"
#include "ccmr4.h"
#include "fray.h"
#include "gio.h"
#include "htu.h"
#include "het.h"
#include "spi.h"
#include "sys_vim.h"


unsigned esmStartSelfTest();
void     esmDisableSelfTest();
void     esm_test(void);
void     esmClearErrPin(void);
void     esmCheckstatus(unsigned int channel);



#define MibADC2_parity_ESM_Channel				1
#define DMA_MPU_ESM_Channel						2
#define DMA_parity_ESM_Channel					3
#define ATCM_correctable_error_ESM_Channel		6
#define NHET_parity_ESM_Channel					7
#define HETTU_parity_ESM_Channel				8
#define HETTU_MPU_ESM_Channel					9
#define Flexray_parity_ESM_Channel				12
#define FTU_parity_ESM_Channel					14
#define VIM_RAM_parity_ESM_Channel				15
#define FTU_MPU_ESM_Channel						16
#define MibSPI1_parity_ESM_Channel				17
#define MibSPI3_parity_ESM_Channel				18
#define MibADC1_parity_ESM_Channel				19
#define DCAN1_parity_ESM_Channel				21
#define DCAN3_parity_ESM_Channel				22
#define DCAN2_parity_ESM_Channel				23
#define MibSPIP5_parity_ESM_Channel				24
#define CCM_R4_compare_ESM_Channel				2


#endif /*ESM_DEMO_H_*/
