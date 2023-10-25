#ifndef CAN_REGGS_H
#define CAN_REGS_H


#include "Std_Types.h"


#define CAN0_BASE_ADDRESS   0x4004000
#define CAN1_BASE_ADDRESS   0x4004100

typedef struct{
uint32 CAN_CTL;
uint32 CAN_STS;
uint32 CAN_ERR;
uint32 CAN_BIT;
uint32 CAN_INT;
uint32 CAN_TST;
uint32 CAN_BRPE;
uint32 CAN_IF1CRQ;
uint32 CAN_IF1CMSK;
uint32 CAN_IF1MSK1;
uint32 CAN_IF1MSK2;
uint32 CAN_IF1ARB1;
uint32 CAN_IF1ARB2;
uint32 CAN_IF1MCTL;
uint32 CAN_IF1DA1;
uint32 CAN_IF1DA2;
uint32 CAN_IF1DB1;
uint32 CAN_IF1DB2;
uint32 CAN_IF2CRQ;
uint32 CAN_IF2CMSK;
uint32 CAN_IF2MSK1;
uint32 CAN_IF2MSK2;
uint32 CAN_IF2ARB1;
uint32 CAN_IF2ARB2;
uint32 CAN_IF2MCTL;
uint32 CAN_IF2DA1;
uint32 CAN_IF2DA2;
uint32 CAN_IF2DB1;
uint32 CAN_IF2DB2;
uint32 CAN_TXRQ1;
uint32 CAN_TXRQ2;
uint32 CAN_NWDA1;
uint32 CAN_NWDA2;
uint32 CAN_MSG1INT;
uint32 CAN_MSG2INT;
uint32 CAN_MSG1VAL;
uint32 CAN_MSG2VAL;
}CAN_Module_regs;

#endif