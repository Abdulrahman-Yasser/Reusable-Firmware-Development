#include "Std_Types.h"

typedef enum{
    SSI_Channel_0,
    SSI_Channel_1,
    SSI_Channel_2,
    SSI_Channel_3,
    SSI_Channel_NotUsed
}SSI_Channel_t;

typedef enum{
    Tx_IM, Rx_IM, Rx_TimeOut, Rx_OverRun
}SSI_Interrupt_Type;

typedef enum{
    SSI_Protocol_SPI,
    SSI_Protocol_TISS,
    SSI_Protocol_MicroWire,
    SSI_Protocol_not_available
}SSI_ProtocolMode_t;

typedef enum{
    SSI_Master, SSI_SLAVE_OUTPUT_EN = 4, SSI_SLAVE_OUTPUT_DIS = 0xc
}SSI_SlaveMaster_t;


typedef enum{
    SSI_EOT, SSI_HALF_FIFO
}SSI_InterruptMode_t;

typedef enum{
    SSI_SysClk, SSI_PIOSC
}SSI_ClockSrc_t;

typedef enum{
    SSI_DMA_NotAvailable,
    SSI_DMA_Receive, SSI_DMA_Transmit,
    SSI_DMA_ReceiveTransmit
}SSI_DMA_t;

typedef enum{
    SSI_transmit_callback,
    SSI_receive_callback,
    SSI_timeout_callback,
    SSI_overrun_callback
}Spi_Callback_t;

typedef struct{
    SSI_Channel_t channelNumber;
    Std_BoolReturnType ClockPolarity;
    uint8 DataSize;
    SSI_ProtocolMode_t protocolMode;
    SSI_InterruptMode_t Interrupt;
    SSI_ClockSrc_t ClkSrc;
    uint32 BaudRate;
    SSI_DMA_t DMA_State;
    SSI_SlaveMaster_t SlaveOrMaster;
    uint8 InterruptMask;
}SpiConfig_t;

SpiConfig_t* SPI_getConfig(void);
