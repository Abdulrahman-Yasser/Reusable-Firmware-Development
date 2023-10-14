/*!

    @mainpage SPI module
    @author Abdulrahman Yasser
    @brief reusable, portable and well documented bare-metal driver for SPI module
    @details reusable, portable and well documented bare-metal driver for
    SPI module on Tiva-c (TM4C123GH6PM).

*/

/** 
* @file  SPI.h
* @brief This file contains all APIs of SPI module
*
* for using this driver you should read this file and know how to 
* use it's API in your way
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
* THE POSSIBILITY OF SUCH DAMAGE.<br>
* Compiler              GCC<br>
* Target                TM4C123GH6PM
*
*****************************************************************************/

// * 
// * This is the header file for the SPI module that contains all the shared APIs!
// * this module lays in the MCAL layer.


#ifndef SPI_H_
#define SPI_H_




/******************************************************************************
* Includes
*******************************************************************************/

#include "SPI_config.h"

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
// /**
//  * This constant is an example
//  */

/******************************************************************************
* Configuration Constants
*******************************************************************************/


/******************************************************************************
* Macros
*******************************************************************************/


	
/******************************************************************************
* Typedefs
*******************************************************************************/

// /**
//  * This enumeration is a list of test types
//  */

/******************************************************************************
* Variables
*******************************************************************************/

/** 
 * Defines the number of spi channels on each processor port.
*/
#define NUMBER_OF_SPI_CHANNELS 4U



/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif


/** @defgroup SPI_functions
 *  all the usable functions in SPI module
 *  @{
 */
/*********************************************************************
* Function : Spi_Init()
*//**
* \b Description:
*
* This function is used to initialize the SPI based on the configuration
* table defined in SPI_cfg.c module.
*
* PRE-CONDITION: Port_Init() should be called before any action to initialize the pins on the SoC<br>
* PRE-CONDITION: PLL_Init() should be called before any action to initialize the MCU clock<br>
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0) <br>
* PRE-CONDITION: NUMBER_OF_DEFINED_SPI > 0 <br>
* PRE-CONDITION: NUMBER_OF_BOARD_SPI_CHANNELS > 0 <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: The SPI peripheral is set up with the configuration
* settings.
*
* @param[in] SPIConfigs is a pointer to the configuration table that
* contains the initialization for the
* peripheral.
*
* @return void
*
* \b Example:
* @code
* const SPIConfig_t *SPIConfig_t = SPI_ConfigGet();
*
* Spi_Init(SpiConfig_t);
* @endcode
* @code
* Spi_Init( SPI_ConfigGet() );
* @endcode
*
* @see SPI_getConfig
* @link SPI_Config.c
* @link SPI_Config.h
**********************************************************************/
void Spi_Init(SpiConfig_t const * const SPIConfigs);


/*********************************************************************
* Function : Spi_Transfer()
*//**
* \b Description:
*
* This function transfer the data via SPI module 
*
* PRE-CONDITION: Spi_Init() should be called before using the Spi module to initialize it
*
* POST-CONDITION: The data is transfered from SPI to the Slave
*
* @param[in] channelNumber SPI channel number
* @param[in] data an array of uint16 type that contains data
* @param[in] length the length of the array need to be send
*
* @return void
*
* \b Example:
* @code
*
* const SPIConfig_t *SPIConfig_t = SPI_ConfigGet();
*
* Spi_Init(SpiConfig_t);
*
* char* msg_1 = 'i   w i l l   k i l l   y o u ';
*
* Spi_Transfer(SSI_Channel_2, (uint16*)msg_1, 15);
*
* @endcode
*
*
**********************************************************************/
void Spi_Transfer(SSI_Channel_t channelNumber, uint16 * const data, uint8 length);


/*********************************************************************
* Function : Spi_CallbackRegister()
*//**
* \b Description:
*
* This function is used to register the callBack function for any
* response to a higher layer module
*
* PRE-CONDITION: Spi_Init() should be called before using the Spi module to initialize it
*
* POST-CONDITION: Callback function should be set to it's trigger type.
*
* @param[in] ssi_channel the channel that will call the function when the trigger happens
* @param[in] Trigger the event which the callbackFunction will be called when it happens 
* @param[in] CallbackFunction a pointer to a void function that passed through a higher layer architecture
* to be responsed to when the trigger happens
*
* @return void
*
* \b Example:
* @code
* void HigherLayerFunction(void){
*    
* }
* void main(){
*   const SPIConfig_t *SPIConfig_t = SPI_ConfigGet();
* 
*   Spi_init()
*
*   void Spi_CallbackRegister( SSI_Channel_2,
*                                SSI_transmit_callback, 
*                                HigherLayerFunction );
* }
*
* @endcode
*
*
**********************************************************************/
void Spi_CallbackRegister(SSI_Channel_t const ssi_channel, SSI_Interrupt_Type const Trigger, void (*CallbackFunction)(void));

//! @}
#ifdef __cplusplus
} // extern "C"
#endif

//TODO: UPDATE COMMENT BELOW
#endif /*File_H_*/

/*** End of File **************************************************************/