#include <SPI_HAL/SPI_r_config.h>



const SpiConfig_t SPIConfigs[] = {
            {.BaudRate = 1000, .ClkSrc = SSI_SysClk, .ClockPolarity = E_FALSE,
            .DMA_State = SSI_DMA_NotAvailable, .DataSize = 8, .Interrupt = SSI_HALF_FIFO,
            .SlaveOrMaster = SSI_Master, .channelNumber = SSI_Channel_NotUsed, .protocolMode = SSI_Protocol_SPI},

            {.BaudRate = 1000, .ClkSrc = SSI_SysClk, .ClockPolarity = E_FALSE,
            .DMA_State = SSI_DMA_NotAvailable, .DataSize = 8, .Interrupt = SSI_HALF_FIFO,
            .SlaveOrMaster = SSI_Master, .channelNumber = SSI_Channel_NotUsed, .protocolMode = SSI_Protocol_SPI},

            {.BaudRate = 1000, .ClkSrc = SSI_SysClk, .ClockPolarity = E_FALSE,
            .DMA_State = SSI_DMA_NotAvailable, .DataSize = 8, .Interrupt = SSI_HALF_FIFO,
            .SlaveOrMaster = SSI_Master, .channelNumber = SSI_Channel_2, .protocolMode = SSI_Protocol_SPI},

            {.BaudRate = 1000, .ClkSrc = SSI_SysClk, .ClockPolarity = E_FALSE,
            .DMA_State = SSI_DMA_NotAvailable, .DataSize = 8, .Interrupt = SSI_HALF_FIFO,
            .SlaveOrMaster = SSI_Master, .channelNumber = SSI_Channel_NotUsed, .protocolMode = SSI_Protocol_SPI}
};

SpiConfig_t* SPI_GetConfig(void){
    return &SPIConfigs[0];
}
