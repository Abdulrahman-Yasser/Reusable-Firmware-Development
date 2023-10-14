/** 
* @file  SPI_registers.h
* @brief This file contains all the register of SPI in TIVA-C (TM4C123GH6PM)
*
* The registers here represented as a struct of registers. which is the most reusable
* way to represent your registers in your code.
* This file contains all the registers that TIVA-C SPI module have.
* porting this module to another SoC will need to check the arrengement of the registers
* to fit your Soc.
*
*
* @author Abdulrahman Yasser
* @date 12/10/2023
* @version 1.0.0
* @copyright GNU Public License
* @subsection Step1 Cmake
* @subsection Step2 make
* @
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

#include "SPI_datatypes.h"


#define SSI0_BASE_ADDERSS       0x40008000      /**< Base address of SPI channel 0*/
#define SSI1_BASE_ADDERSS       0x40009000      /**< Base address of SPI channel 1*/
#define SSI2_BASE_ADDERSS       0x4000A000      /**< Base address of SPI channel 2*/
#define SSI3_BASE_ADDERSS       0x4000B000      /**< Base address of SPI channel 3*/

#define SSI_IM_TX   (1 << Tx_IM)                /**< representing 1 in place of Tx flag.*/
#define SSI_IM_RX   (1 << Rx_IM)                /**< representing 1 in place of Rx_IM flag.*/
#define SSI_IM_RT   (1 << Rx_TimeOut)           /**< representing 1 in place of Rx_TimeOut flag.*/
#define SSI_IM_POR  (1 << Rx_OverRun)           /**< representing 1 in place of Rx_OverRun flag.*/

#define SSI_BSY_FLAGG 4                         /**< SSI Busy Bit.*/
#define SSI_RFF_FLAGG 3                         /**< SSI Receive FIFO Full.*/
#define SSI_RNE_FLAGG 2                         /**< SSI Receive FIFO Not Empty.*/
#define SSI_TNF_FLAGG 1                         /**< SSI Transmit FIFO Not Full.*/
#define SSI_TFE_FLAGG 0                         /**< SSI Transmit FIFO Empty.*/
#define SSI_CR1_SSE_bitOFFSET 1                 /**< SSI Synchronous Serial Port Enable bit for disabling and enabling SPI channel.*/

/* CR0 register */
#define SSI_SerialClockPolarity_Offset 6        /**< SSI Serial Clock Polarity offset in SSI Control 0 register.*/
#define SSI_ProtocolMode_Offset 4               /**< SSI Frame Format Select offset in SSI Control 0 register.*/
#define SSI_DataSize_Offset 0                   /**< SSI Data Size Select offset in SSI Control 0 register.*/

/**
* @brief a typedef for all the register in SPI module
* \b Example:
* @code
*    volatile SPI_Module_regs* mySPI = (SPI_Module_regs*) SPI_bases_ptr[ ssi_channel ];
*    mySPI->SSICR0 |= (CPSDVSR - 1) << 8;
*    mySPI->SSICPSR |= SCR_Value;
* @endcode
* @see SPI_bases_ptr
 */

typedef struct {
    uint32 SSICR0;              /**< SSI Control 0.*/
    uint32 SSICR1;              /**< SSI Control 1.*/
    uint32 SSIDR;               /**< SSI Data.*/
    uint32 SSISR;               /**< SSI Status.*/
    uint32 SSICPSR;             /**< SSI Clock Prescale.*/
    uint32 SSIIM;               /**< SSI Interrupt Mask.*/
    uint32 SSIRIS;              /**< SSI Raw Interrupt Status.*/
    uint32 SSIMIS;              /**< SSI Masked Interrupt Status.*/
    uint32 SSIICR;              /**< SSI Interrupt Clear.*/
    uint32 SSIDMACTL;           /**< SSI DMA Control.*/
    uint32 SSICC;               /**< SSI Clock Configuration.*/
}SPI_Module_regs;


<<<<<<< HEAD:2_GeneralPurbose_SPI/SPI_HAL/SPI_registers.h
/**
* @brief a typedef for all the base addresses of SPI module channels
* \b Example:
* @code
*    volatile SPI_Module_regs* mySPI = (SPI_Module_regs*) SPI_bases_ptr[ ssi_channel ];
*    mySPI->SSICR0 |= (CPSDVSR - 1) << 8;
*    mySPI->SSICPSR |= SCR_Value;
* @endcode
* \var volatile uint32* SPI_bases_ptr
* @see SPI_Module_regs
 */
volatile uint32* SPI_bases_ptr = {
    (uint32*)0x40008000,        /**< .*/
    (uint32*)0x40009000,        /**< .*/
    (uint32*)0x4000A000,        /**< .*/
    (uint32*)0x4000B000         /**< .*/
};
=======
volatile uint32* SPI_bases_ptr[] = {
    (uint32*)0x40008000, 
    (uint32*)0x40009000, 
    (uint32*)0x4000A000, 
    (uint32*)0x4000B000
};
>>>>>>> 38b88471b5ad1f6321d8aafe8222274af556859e:2_SPI_StructOfRegisters/SPI_HAL/SPI_registers.h
