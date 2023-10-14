/** 
* @file  SPI_datatypes.h
* @brief This file contains all the dataTypes that is used in that module
*
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


#include "Std_Types.h"


/**
 * @brief Datatype that represent which SPI channel you are using
 * 
 */
typedef enum{
    SSI_Channel_0,          /**< Channel number 0 */
    SSI_Channel_1,          /**< Channel number 1 */
    SSI_Channel_2,          /**< Channel number 2 */
    SSI_Channel_3,          /**< Channel number 3 */
    SSI_Channel_NotUsed     /**< Channel is not used */
}SSI_Channel_t;

/**
 * @brief interrupt trigger type
 * 
 */
typedef enum{
    Rx_OverRun,     /**< SSI Receive Overrun Interrupt Mask */
    Rx_TimeOut,     /**< SSI Receive Time-Out Interrupt Mask */ 
    Rx_IM,          /**< SSI Receive FIFO Interrupt Mask */ 
    Tx_IM           /**< SSI Transmit FIFO Interrupt Mask */
}SSI_Interrupt_Type;

/**
 * @brief SSI chosen frame format (protocol)
 * 
 */
typedef enum{
    SSI_Protocol_SPI,               /**< Freescale SPI Frame Format */
    SSI_Protocol_TISS,              /**< Texas Instruments Synchronous Serial Frame Format  */
    SSI_Protocol_MicroWire,         /**< MICROWIRE Frame Format */
    SSI_Protocol_not_available      /**< Protocol of the channel is SPI */
}SSI_ProtocolMode_t;

/**
 * @brief SSI as a slve or master
 * 
 */
typedef enum{
    SSI_Master,                     /**< The SSI is configured as a master. */
    SSI_SLAVE_OUTPUT_EN = 4,        /**< The SSI is configured as a slave (output enabled). */
    SSI_SLAVE_OUTPUT_DIS = 0xc      /**< slave mode (output disabled) .*/
}SSI_SlaveMaster_t;


/**
 * @brief SSI transmit action (EOT or 1/2 FIFO trigger)
 * 
 */
typedef enum{
    SSI_EOT,                        /**< The End of Transmit interrupt mode for the TXRIS interrupt .*/
    SSI_HALF_FIFO                   /**< The TXRIS interrupt indicates that the transmit FIFO is half full or less. .*/
}SSI_InterruptMode_t;

/**
 * @brief the chosen Clock for the SSI
 * 
 */
typedef enum{
    SSI_SysClk,                     /**< System Control Clock source.*/
    SSI_PIOSC                       /**< PIOSC .*/
}SSI_ClockSrc_t;

/**
 * @brief DMA usage in SSI. Receive, transmit or both
 * 
 */
typedef enum{
    SSI_DMA_Receive,                /**< Receive DMA Enable. */
    SSI_DMA_Transmit,               /**< Transmit DMA Enable. */
    SSI_DMA_ReceiveTransmit         /**< Transmit and Receive DMA Enable. */
    SSI_DMA_NotAvailable,           /**< Transmit DMA Disabled. */
}SSI_DMA_t;

/**
* @brief SPI container that collect all of it's configurations
* 
* \b Example:
* @code
*const SpiConfig_t SPIConfigs[] = {
*            {.channelNumber = SSI_Channel_NotUsed},
*
*            {.channelNumber = SSI_Channel_NotUsed},
*
*           {.BaudRate = 1000, .ClkSrc = SSI_SysClk, .ClockPolarity = E_FALSE,
*           .DMA_State = SSI_DMA_NotAvailable, .DataSize = 8, .Interrupt = SSI_HALF_FIFO,
*            .SlaveOrMaster = SSI_Master, .channelNumber = SSI_Channel_2, .protocolMode = SSI_Protocol_SPI},
*
*            {.channelNumber = SSI_Channel_NotUsed}
*};
* @endcode 
* @see SPIConfigs
*/

typedef struct{
    SSI_Channel_t channelNumber;        /**< SSI channel number .*/
    Std_BoolReturnType ClockPolarity;   /**< Clock polarity */
    uint8 DataSize;                     /**< SSI dataSize 4-bit : 16 .*/
    SSI_ProtocolMode_t protocolMode;    /**< Frame Format. SPI, TISS or microWire .*/
    SSI_InterruptMode_t Interrupt;      /**< Interrupt mode for SSI .*/
    SSI_ClockSrc_t ClkSrc;              /**< Clock source for SSI module.*/
    uint32 BaudRate;                    /**< SSI baudRate .*/
    SSI_DMA_t DMA_State;                /**< DMA usage .*/
    SSI_SlaveMaster_t SlaveOrMaster;    /**< whether it's slave or master .*/
    uint8 InterruptMask;                /**< the interrupt that SSI will react on*/
}SpiConfig_t;
