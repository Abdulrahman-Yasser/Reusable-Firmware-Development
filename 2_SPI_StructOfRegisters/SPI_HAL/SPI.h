/****************************************************************************
* Title                 :   SPI module
* Filename              :   SPI.h
* Author                :   Abdulrahman Yasser
* Origin Date           :   12/10/2023
* Version               :   1.0.0
* Compiler              :   GCC
* Target                :   TM4C123GH6PM
* Notes                 :   None
*
* THIS SOFTWARE IS PROVIDED BY Abdulrahman Yasser : COMPANY "AS IS" AND ANY EXPRESSED
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
*
*****************************************************************************/

/** @file: SPI.h
 *  @brief This module contains all APIs of SPI module
 * 
 *  This is the header file for the SPI module that contains all the shared APIs!
 *  this module lays in the MCAL layer.
 */

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

/*********************************************************************
* Function : Spi_Init()
*//**
* \b Description:
*
* This function is used to initialize the SPI based on the configuration
* table defined in SPI_cfg module.
*
* PRE-CONDITION: Port_Init() should be called before any action
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0) <br>
* PRE-CONDITION: NUMBER_OF_DEFINED_SPI > 0 <br>
* PRE-CONDITION: NUMBER_OF_BOARD_SPI_CHANNELS > 0 <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
** POST-CONDITION: The SPI peripheral is set up with the configuration
* settings.
*
* @param[in] Config is a pointer to the configuration table that
* contains the initialization for the
peripheral.
*
* @return void
*
* \b Example:
* @code
* const SPIConfig_t *SPIConfig_t = SPI_ConfigGet();
*
* Spi_Init(SpiConfig_t);
* @endcode
*
* @see Spi_Init
* @see Spi_Transfer
* @see Spi_RegisterWrite
* @see Spi_RegisterWrite
* @see Spi_RegisterRead
* @see Spi_CallbackRegister
*
**********************************************************************/
void Spi_Init(SpiConfig_t const * const SPIConfigs);


/*********************************************************************
* Function : Spi_Transfer()
*//**
* \b Description:
*
* This function transfer the data via SPI module 
*
* PRE-CONDITION: Port_Init() should be called before any action
* PRE-CONDITION: Spi_Init() should be called before using the Spi module
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0) <br>
* PRE-CONDITION: NUMBER_OF_DEFINED_SPI > 0 <br>
* PRE-CONDITION: NUMBER_OF_BOARD_SPI_CHANNELS > 0 <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
** POST-CONDITION: The SPI peripheral is set up with the configuration
* settings.
*
* @param[in] SPIConfigs is a transmission way, either in or out
*
* @return void
*
* \b Example:
* @code
* const SPIConfig_t *SPIConfig_t = SPI_ConfigGet();
*
* Spi_Init(SpiConfig_t);
* 
* Spi_Transfer(SpiTransfer_t);
* @endcode
*
* @see Spi_Init
* @see Spi_Transfer
* @see Spi_RegisterWrite
* @see Spi_RegisterWrite
* @see Spi_RegisterRead
* @see Spi_CallbackRegister
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
* PRE-CONDITION: Port_Init() should be called before any action
* PRE-CONDITION: Spi_Init() should be called before using the Spi module
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0) <br>
* PRE-CONDITION: NUMBER_OF_DEFINED_SPI > 0 <br>
* PRE-CONDITION: NUMBER_OF_BOARD_SPI_CHANNELS > 0 <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
** POST-CONDITION: The SPI peripheral is set up with the configuration
* settings.
*
* @param[in] Function the event which the callbackFunction will be called when it happens 
* @param[in] CallbackFunction the function that will be called when (Function) event
* get trigger
*
* @return void
*
* \b Example:
* @code
* const SPIConfig_t *SPIConfig_t = SPI_ConfigGet();
* 
* Spi_init()
*
* Spi_CallbackRegister(Spi_Callback_t const Function,
*                         void (*CallbackFunction)(void));
* @endcode
*
* @see Spi_Init
* @see Spi_Transfer
* @see Spi_RegisterWrite
* @see Spi_RegisterWrite
* @see Spi_RegisterRead
* @see Spi_CallbackRegister
*
**********************************************************************/
void Spi_CallbackRegister(Spi_Callback_t const Function, void (*CallbackFunction)(void));

#ifdef __cplusplus
} // extern "C"
#endif

//TODO: UPDATE COMMENT BELOW
#endif /*File_H_*/

/*** End of File **************************************************************/