/******************************************************************
* @Title : Digital Input / Output (DIO)
* @Filename : dio.c
* @Author : Jacob W. Beningo
* @Origin Date : 09/01/2015
* @Version : 1.0.0
* @Compiler : TBD
* @Target : TBD
* @Notes : None
*
* THIS SOFTWARE IS PROVIDED BY BENINGO EMBEDDED GROUP
* "AS IS" AND ANY EXPRESSED OR IMPLIED WARRANTIES,
* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL BENINGO
* EMBEDDED GROUP OR ITS CONTRIBUTORS BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
* USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
* WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************/
#ifndef GPIO_H_
#define GPIO_H_
/**********************************************************************
* Includes
**********************************************************************/
#include "GPIO_config.h" /* For GPIO configuration */
#include "Std_Types.h"
/**********************************************************************
* Preprocessor Constants
**********************************************************************/
/** 
 * Defines the number of pins on each processor port.
*/
#define NUMBER_OF_CHANNELS_PER_PORT 8U

/**
* Defines the number of ports on the processor.
*/
#define NUMBER_OF_PORTS 6U

/**********************************************************************
* Configuration Constants
**********************************************************************/

/**********************************************************************
* Macros
**********************************************************************/

/**********************************************************************
* Typedefs
**********************************************************************/

/**********************************************************************
* Variables
**********************************************************************/

/**********************************************************************
* Function Prototypes
**********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

void GPIO_Init(const GPIOConfig_t * const Config);

GPIOPinState_t GPIO_ChannelRead(GPIOChannel_t Channel);

void GPIO_ChannelWrite(GPIOChannel_t Channel, GPIOPinState_t State);

void GPIO_ChannelToggle(GPIOChannel_t Channel);

void GPIO_RegisterWrite(uint32 Address, uint32 Value);

uint32 GPIO_RegisterRead(uint32 Address);

// void GPIO_CallbackRegister(GPIOCallback_t Function,
// TYPE (*CallbackFunction)(type));

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*GPIO_H_*/
/*** End of File ******************************************************/