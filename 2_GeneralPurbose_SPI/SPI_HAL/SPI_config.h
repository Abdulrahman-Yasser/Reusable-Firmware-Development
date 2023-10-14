/** 
* @file  SPI_config.h
* @brief include this file to access your SPI configurations
*
* if you didn't include that file you wont be able to read your SPI module configuration.
* this file contains only one function, which is the function that allows you to read the configurations
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

#include "SPI_datatypes.h"

/**
 *\addtogroup SPI_functions
 * @{
 */


/**
* @brief the function returns your SPI module configurations
*
* @details the function returns your SPI module configurations<br>
* The function must be used to initialize SPI<br>
* The function should be called when you need to use your configuration<br>
*
* PRE-CONDITION: Port_Init() should be called before any action to initialize the pins on the SoC<br>
* PRE-CONDITION: PLL_Init() should be called before any action to initialize the MCU clock<br>
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0) <br>
* PRE-CONDITION: NUMBER_OF_DEFINED_SPI > 0 <br>
* PRE-CONDITION: NUMBER_OF_BOARD_SPI_CHANNELS > 0 <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* @param[in] void
*
* @return SpiConfig_t* 
* 
* \b Example:
* @code
* const SPIConfig_t *SPIConfig_t = SPI_ConfigGet();
*
* Spi_Init(SpiConfig_t);
* @endcode
* 
*
* @see SPI_getConfig
* @link SPI_Config.c
* @link SPI_Config.h
*/


SpiConfig_t* SPI_getConfig(void);

/**
 @}
*/
