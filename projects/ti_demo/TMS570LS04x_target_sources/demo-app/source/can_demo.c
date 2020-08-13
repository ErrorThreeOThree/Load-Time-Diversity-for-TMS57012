#include "can.h"
#include "sci.h"

#define TO_LITTLE(num) num=(((num)>>24)&0xff)|(((num)<<8)&0xff0000)|(((num)>>8)&0xff00)|(((num)<<24)&0xff000000)

extern void sciSend_32bitdata(sciBASE_t *sci, unsigned int data);
	
extern unsigned int 	SubTask_Number;
extern unsigned int 	Task_Number;

typedef struct can_rx_data
{
	unsigned int data0;
	unsigned int data1;
	unsigned int data2;
}can_rx_data_t;


void CAN_Demo(void)
{
	//Setup data handlers
	can_rx_data_t can_data;
	can_rx_data_t *can_data_ptr = &can_data;
	
	unsigned int DataReady = 0;
	
	switch (SubTask_Number)
	{
		
		case 0:
			if(canIsRxMessageArrived(canREG1, canMESSAGE_BOX1))
			{
				/* - When a message is ready, read it into can_data */
				while(!canGetData(canREG1, canMESSAGE_BOX1, (unsigned char *) can_data_ptr));{}
				
				DataReady = 1;
				
				/* - Send data ready flag */
				sciSend_32bitdata(scilinREG, DataReady);

#ifdef __little_endian__
				/* - Send data out over SCI */
				TO_LITTLE(can_data_ptr->data0);
				TO_LITTLE(can_data_ptr->data1);
				TO_LITTLE(can_data_ptr->data2);
				sciSend_32bitdata(scilinREG, can_data_ptr->data0);
				sciSend_32bitdata(scilinREG, can_data_ptr->data1);
				sciSend_32bitdata(scilinREG, can_data_ptr->data2);
#else
				/* - Send data out over SCI */
				sciSend_32bitdata(scilinREG, can_data_ptr->data0);
				sciSend_32bitdata(scilinREG, can_data_ptr->data1);
				sciSend_32bitdata(scilinREG, can_data_ptr->data2);
#endif
			}
			
			/*- Otherwise, send empty data to labView */
			else
			{
				DataReady = 0;
				sciSend_32bitdata(scilinREG, DataReady);
				sciSend_32bitdata(scilinREG, DataReady);
				sciSend_32bitdata(scilinREG, DataReady);
				sciSend_32bitdata(scilinREG, DataReady);
			}
			break;
			
		/* - Set 125 kBit/s Buad Rate */
		case 1:
			/* - Enter config and init mode */
			canREG1->CTL |= 0x00000041;
			
			/* - Set 125 kBit/s buad rate */
		    canREG1->BTR = (1U << 16U) |
		                   ((3U - 1U) << 12U) |
		                   (((1U + 3U) - 1U) << 8U) |
		                   ((3U - 1U) << 6U) |
		                   15U;
            
            /* - Leave config and init mode */
            canREG1->CTL &= ~0x00000041U;
			break;
			
		/* - Set 500 kBit/s Buad Rate */
		case 2:
			/* - Enter config and init mode */
			canREG1->CTL |= 0x00000041;
			
			/* - Set 500 kBit/s buad rate */
		    canREG1->BTR = (0U << 16U) |
		                   ((2U - 1U) << 12U) |
		                   (((3U + 2U) - 1U) << 8U) |
		                   ((2U - 1U) << 6U) |
		                   19U;
            
            /* - Leave config and init mode */
            canREG1->CTL &= ~0x00000041U;
			break;
		
		/* - Set 750 kBit/s Buad Rate */
		case 3:
			/* - Enter config and init mode */
			canREG1->CTL |= 0x00000041;
			
			/* - Set 750 kBit/s buad rate */
		    canREG1->BTR = (0U << 16U) |
		                   ((2U - 1U) << 12U) |
		                   (((7U + 2U) - 1U) << 8U) |
		                   ((2U - 1U) << 6U) |
		                   8U;
            
            /* - Leave config and init mode */
            canREG1->CTL &= ~0x00000041U;
			break;
			
		/* - Set 1000 kBit/s Buad Rate */
		case 4:
			/* - Enter config and init mode */
			canREG1->CTL |= 0x00000041;
			
			/* - Set 1000 kBit/s buad rate */
		    canREG1->BTR = (0U << 16U) |
		                   ((1U - 1U) << 12U) |
		                   (((7U + 1U) - 1U) << 8U) |
		                   ((1U - 1U) << 6U) |
		                   7U;
            
            /* - Leave config and init mode */
            canREG1->CTL &= ~0x00000041U;
			break;
	}
	
}
