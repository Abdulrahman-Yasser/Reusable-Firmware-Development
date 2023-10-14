#include "Common/Std_Types.h"

#define SSI0_BASE_ADDERSS       0x40008000
#define SSI1_BASE_ADDERSS       0x40009000
#define SSI2_BASE_ADDERSS       0x4000A000
#define SSI3_BASE_ADDERSS       0x4000B000

#define SYSCTL_RCGCSSI          0x400FE61C

#define SSI_IM_TX   (1 << 3)
#define SSI_IM_RX   (1 << 2)
#define SSI_IM_RT   (1 << 1)
#define SSI_IM_POR  (1 << 0)

#define SSI_BSY_FLAGG 4
#define SSI_RFF_FLAGG 3
#define SSI_RNE_FLAGG 2
#define SSI_TNF_FLAGG 1
#define SSI_TFE_FLAGG 0
#define SSI_CR1_SSE_bitOFFSET 1

/* CR0 register */
#define SSI_SerialClockPolarity_Offset 6
#define SSI_ProtocolMode_Offset 4
#define SSI_DataSize_Offset 0


typedef struct {
    uint32 SSICR0;
    uint32 SSICR1;
    uint32 SSIDR;
    uint32 SSISR;
    uint32 SSICPSR;
    uint32 SSIIM;
    uint32 SSIRIS;
    uint32 SSIMIS;
    uint32 SSIICR;
    uint32 SSIDMACTL;
    uint32 SSICC;
}SPI_Module_regs;


volatile uint32* SPI_bases_ptr[] = {
    (uint32*)0x40008000, 
    (uint32*)0x40009000, 
    (uint32*)0x4000A000, 
    (uint32*)0x4000B000
};
