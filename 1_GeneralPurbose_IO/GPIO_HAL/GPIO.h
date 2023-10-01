/** @file GPIO.h
* @brief The interface definition for the GPIO.
*
* This is the header file for the definition of the interface for a digital
* input/output peripheral on a standard microcontroller.
*/
#ifndef GPIO_H_
#define GPIO_H_
/**********************************************************************
* Includes
**********************************************************************/
#include "GPIO_config.h" /* For GPIO configuration */

/**********************************************************************
* Preprocessor Constants
**********************************************************************/

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

void GPIO_RegisterWrite(uint32_t Address, TYPE Value);

TYPE GPIO_RegisterRead(uint32_t Address);

void GPIO_CallbackRegister(GPIOCallback_t Function,

TYPE (*CallbackFunction)(type));

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*GPIO_H_*/
/*** End of File ******************************************************/