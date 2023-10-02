/****************************************************************************
* Title                 :   SPI module
* Filename              :   SPI.h
* Author                :   Abdulrahman Yasser
* Origin Date           :   04/01/2015
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

/** @file TODO: SPI.h
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


/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
/**
 * This constant is an example
 */
#define Example 			32

/******************************************************************************
* Configuration Constants
*******************************************************************************/


/******************************************************************************
* Macros
*******************************************************************************/


	
/******************************************************************************
* Typedefs
*******************************************************************************/

/**
 * This enumeration is a list of test types
 */

typedef enum
{
	TEST_TEST1,			/**< Test Type 1 */
	TEST_TEST2,			/**< Test Type 2 */
}Test_t;

/******************************************************************************
* Variables
*******************************************************************************/


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
void Spi_Init(SpiConfig_t const * const Config);


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
* @param[in] Config is a transmission way, either in or out
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
void Spi_Transfer(SpiTransfer_t const * const Config);


/*********************************************************************
* Function : Spi_RegisterWrite()
*//**
* \b Description:
*
* This function is used to write any value into a specific register address
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
* @param[in] Address is a hardware register that need to be written
* @param[in] Value is the value that will be written in the rigster
* 
* @return void
*
* \b Example:
* @code
* const SPIConfig_t *SPIConfig_t = SPI_ConfigGet();
*
* Spi_Init(SpiConfig_t);
* 
* Spi_RegisterWrite(SPI_DATA_REGISTER_ADDRESS,
*                      0x01);
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
void Spi_RegisterWrite(uint32 const Address,
                       uint32 const Value);


/*********************************************************************
* Function : Spi_RegisterRead()
*//**
* \b Description:
*
* This function is used to read any given register and return it's content
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
* @param[in] Address is a hardware register that need to be written
*
* @return void
*
* \b Example:
* @code
* const SPIConfig_t *SPIConfig_t = SPI_ConfigGet();
*
* Spi_Init(SpiConfig_t);
* 
* uint32 x = Spi_RegisterRead(SPI_DATA_REGISTER_ADDRESS);
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
uint32 Spi_RegisterRead(uint32 const Address);


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
void Spi_CallbackRegister(Spi_Callback_t const Function,
                          void (*CallbackFunction)(void));

#ifdef __cplusplus
} // extern "C"
#endif

//TODO: UPDATE COMMENT BELOW
#endif /*File_H_*/

/*** End of File **************************************************************/