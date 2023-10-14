/** 
* @file  SPI.c
* @brief This file contains all imlpementation of APIs of SPI module
*
* This is a reusable, portable, readable and well documented implementation for driver for SPI module
* on Tiva-C (TM4C123GH6PM)
*
* @author Abdulrahman Yasser
* @date 12/10/2023
* @version 1.0.0
* @copyright GNU Public License
* @bug it just send uint16 in Transfer function
* @subsection Step1 Cmake
* @subsection Step2 make
* @note                 THIS SOFTWARE IS PROVIDED BY Abdulrahman Yasser : COMPANY "AS IS" AND ANY EXPRESSED
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL BENINGO ENGINEERING OR ITS CONTRIBUTORS BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
* Compiler              GCC
* Target                TM4C123GH6PM
*
*****************************************************************************/


#include "SPI.h"
#include "SPI_registers.h"
#include "CPU_resources.h"
#include "../SysCtl/SysCtl_Registers.h"


/**
 * @brief the ISR function that will be called in Tx Interrupt trigger
 * @details this is what get changed when calling Spi_CallbackRegister function
 * 
 * @see Spi_CallbackRegister
 */
static void (*SPI_Tx_n_handler[])(void) = {
                                 defaultCallback,
                                 defaultCallback,
                                 defaultCallback,
                                 defaultCallback
};

/**
 * @brief the ISR function that will be called in Rx Interrupt trigger
 * @details this is what get changed when calling Spi_CallbackRegister function
 * 
 * @see Spi_CallbackRegister
 * 
 */
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

        mySPI->SSICR0 |= (CPSDVSR - 1) << 8;
        mySPI->SSICPSR |= SCR_Value;

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

void Spi_Transfer(SSI_Channel_t channelNumber, uint16 * const data, uint8 length){
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



void Spi_CallbackRegister(SSI_Channel_t const ssi_channel, SSI_Interrupt_Type const Trigger, void (*CallbackFunction)(void)){
    switch(Trigger){
    case Tx_IM:
        SPI_Tx_n_handler[ssi_channel] = CallbackFunction;
        break;
    case Rx_IM:
        SPI_Rx_n_handler[ssi_channel] = CallbackFunction;
        break;
    case Rx_TimeOut:
        break;
    case Rx_OverRun:
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