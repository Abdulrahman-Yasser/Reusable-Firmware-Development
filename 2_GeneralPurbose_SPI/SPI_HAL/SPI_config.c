/** 
* @file  SPI_config.c
* @brief This file contains all configurations of your SPI
*
* if you are using this module you will need to change this file to your own
* usage and configuration.
*
* @author Abdulrahman Yasser
* @date 12/10/2023
* @version 1.0.0
* @copyright GNU Public License
* @subsection Step1 Cmake
* @subsection Step2 make
* 
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
#include "SPI_config.h"


/**
 * /var const SpiConfig_t SPIConfigs[]
 * 
 * @brief here you can put your custom configurations for SPI module
 * 
 */
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

SpiConfig_t* SPI_getConfig(void){
    return &SPIConfigs[0];
}
