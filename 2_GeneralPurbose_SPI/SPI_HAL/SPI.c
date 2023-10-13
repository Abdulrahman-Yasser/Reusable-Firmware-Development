#include "SPI.h"
#include "SPI_registers.h"
#include "CPU_resources.h"
#include "../SysCtl/SysCtl_Registers.h"

static void (*SPI_Tx_n_handler[])(void) = {
                                 defaultCallback,
                                 defaultCallback,
                                 defaultCallback,
                                 defaultCallback
};

static void (*SPI_Rx_n_handler[])(void) = {
                                 defaultCallback,
                                 defaultCallback,
                                 defaultCallback,
                                 defaultCallback
};


void SSI0_Interrupt_Function(void);
void SSI1_Interrupt_Function(void);
void SSI2_Interrupt_Function(void);
void SSI3_Interrupt_Function(void);

static void Spi_Transmit_one_package(SSI_Channel_t const ssi_channel, uint16 const data);


void Spi_Init(SpiConfig_t const * const SPIConfigs){
    uint8 i;
    volatile SPI_Module_regs* mySPI;
    uint8 SCR_Value, CPSDVSR, myClock;
    for(i = 0; i < NUMBER_OF_SPI_CHANNELS; i++){
        if(SPIConfigs[i].channelNumber == SSI_Channel_NotUsed){
            continue;
        }
         /*
         * 1 - Enable the clock for the corresponding SSI channel
         */
        my_SysCtl_RCGC_Registers_g->RCGCSSI |=  1 << SPIConfigs[i].channelNumber ;

        mySPI = (SPI_Module_regs*) SPI_bases_ptr[ SPIConfigs[i].channelNumber ];
        
        /*
        * 2 -Disable the channel before reprogramming it
        */
        mySPI->SSICR1 &= ~0x000002;
         
        /*
         * 3 - Select whether the channel is master or slave.
        */
        mySPI->SSICR1 |= SPIConfigs[i].SlaveOrMaster;

        /*
         * 4 - Select Clock source.
        */

        /*
         * 5 - calculate the baudRate.
        */
        
        if(SPIConfigs[i].ClkSrc == SSI_SysClk){
            myClock = CPU_CLOCK;
        }else{
            myClock = CPU_PIOSC_CLOCK;
            mySPI->SSICC = 0x05;
        }

        myClock = (myClock*1000) / SPIConfigs[i].BaudRate;
        SCR_Value = 1;
        do{
            SCR_Value++;
            CPSDVSR = myClock / SCR_Value;
        }while(((CPSDVSR * SCR_Value != myClock )) && SCR_Value != 255);
        if(SCR_Value == 255){
            while(1);
        }

        mySPI->SSICR0 |= (SCR_Value - 1) << 8;
        mySPI->SSICPSR |= CPSDVSR;

        /*
         * 6 - configure the clockPhase, ProtocolMode and DataSize
        */
        mySPI->SSICR0 |= SPIConfigs[i].ClockPolarity << SSI_SerialClockPolarity_Offset 
                        | SPIConfigs[i].protocolMode << SSI_ProtocolMode_Offset 
                        | (SPIConfigs[i].DataSize - 1) << SSI_DataSize_Offset;

        if(SPIConfigs[i].ClockPolarity == E_TRUE){
            /*
            * Need to set GPIO SSInclk pin into pull-up register
            */
        }

        /*
         * 7 - did you use DMA ?
        */


        /*
         * 8 - interrupt masks you will use
         */
        mySPI->SSIIM |= SPIConfigs[i].InterruptMask;

        /*
         * 9 - Enable the channel
         */
        mySPI->SSICR1 |= 0x02;
    }
}

void Spi_Transfer(SSI_Channel_t channelNumber, uint16 *data, uint8 length){
    volatile uint8 status;
    uint8 i ;
    volatile SPI_Module_regs* mySPI;
    uint16 dataFrame;
    if(channelNumber == SSI_Channel_NotUsed){
        return;
    }
    mySPI = (SPI_Module_regs*) SPI_bases_ptr[ channelNumber ];
    status = mySPI->SSICR0;
    status &= 0x0f;
    while(status--){
        dataFrame = ( dataFrame << 1 ) | 1;
    }
    for(i = 0; i < length; i++){
        Spi_Transmit_one_package(channelNumber, data[i] & dataFrame);
    }
}

static void Spi_Transmit_one_package(SSI_Channel_t const ssi_channel, uint16 const data){
    volatile SPI_Module_regs* mySPI = (SPI_Module_regs*) SPI_bases_ptr[ ssi_channel ];
    volatile uint8 status;
    do{
        status = mySPI->SSISR;
    }while( (status & (1 << SSI_BSY_FLAGG)) & !(status & (1 << SSI_TNF_FLAGG) ) );
    /* if the transmit FIFO is not full and the flag is not busy, break the loop */
    mySPI->SSIDR = data;
}



void Spi_CallbackRegister(Spi_Callback_t const Function, void (*CallbackFunction)(void)){
    switch(Function){
    case SSI_transmit_callback:
        SPI_Tx_n_handler[Function] = CallbackFunction;
        break;
    case SSI_receive_callback:
        SPI_Rx_n_handler[Function] = CallbackFunction;
        break;
    case SSI_timeout_callback:
        break;
    case SSI_overrun_callback:
        break;
    default:
        break;
    }
}

void SSI0_Interrupt_Function(void){
    volatile SPI_Module_regs* mySPI = (SPI_Module_regs*) SPI_bases_ptr[ SSI_Channel_0 ];
    uint8 status = mySPI->SSIMIS;
    switch(status){
        case SSI_IM_TX:
            SPI_Tx_n_handler[SSI_Channel_0]();
            break;
        case SSI_IM_RX:
            SPI_Rx_n_handler[SSI_Channel_0]();
            break;
        case SSI_IM_RT:
            break;
        case SSI_IM_POR:
            break;
        default:
            break;
    }
}

void SSI1_Interrupt_Function(void){
    volatile SPI_Module_regs* mySPI = (SPI_Module_regs*) SPI_bases_ptr[ SSI_Channel_1 ];
    uint8 status = mySPI->SSIMIS;
    switch(status){
        case SSI_IM_TX:
            SPI_Tx_n_handler[ SSI_Channel_1 ]();
            break;
        case SSI_IM_RX:
            SPI_Rx_n_handler[ SSI_Channel_1 ]();
            break;
        case SSI_IM_RT:
            break;
        case SSI_IM_POR:
            break;
        default:
            break;
    }
}

void SSI2_Interrupt_Function(void){
    volatile SPI_Module_regs* mySPI = (SPI_Module_regs*) SPI_bases_ptr[ SSI_Channel_2 ];
    uint8 status = mySPI->SSIMIS;
    switch(status){
        case SSI_IM_TX:
            SPI_Tx_n_handler[SSI_Channel_2]();
            break;
        case SSI_IM_RX:
            SPI_Rx_n_handler[SSI_Channel_2]();
            break;
        case SSI_IM_RT:
            break;
        case SSI_IM_POR:
            break;
        default:
            break;
    }
}

void SSI3_Interrupt_Function(void){
    volatile SPI_Module_regs* mySPI = (SPI_Module_regs*) SPI_bases_ptr[ SSI_Channel_3 ];
    uint8 status = mySPI->SSIMIS;
    switch(status){
        case SSI_IM_TX:
            SPI_Tx_n_handler[SSI_Channel_3]();
            break;
        case SSI_IM_RX:
            SPI_Rx_n_handler[SSI_Channel_3]();
            break;
        case SSI_IM_RT:
            break;
        case SSI_IM_POR:
            break;
        default:
            break;
    }
}