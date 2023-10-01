/** @file GPIO.c
* @brief The implementation for the GPIO.
*/
/**********************************************************************
* Includes
**********************************************************************/

#include "GPIO.h" /* For this modules definitions */
#include "Std_Types.h"
#include "Common/Mcu_Hw.h" /* For Hardware definitions */
#include "MCAL_Layer/PORT/Static/inc/PORT.h"

/**********************************************************************
* Module Preprocessor Constants
**********************************************************************/
/*********************************************************************
* Module Preprocessor Macros
**********************************************************************/
/**********************************************************************
* Module Typedefs
**********************************************************************/
/**********************************************************************
* Module Variable Definitions
**********************************************************************/
/**
* Defines a table of pointers to the peripheral input register on the
* microcontroller.
*/
static TYPE* volatile * const DataIn[NUM_PORTS] =
{
    (TYPE*)&REGISTER0, (TYPE*)&REGISTER1,
    (TYPE*)&REGISTER2, (TYPE*)&REGISTER3,
    (TYPE*)&REGISTER4, (TYPE*)&REGISTER5,
    (TYPE*)&REGISTER6, (TYPEv*)&REGISTER7
};
/**
* Defines a table of pointers to the peripheral data direction register
on
* the microcontroller.
*/
static TYPE volatile * const DataDirectin[NUM_PORTS] =
{
(TYPE*)&REGISTER1, (TYPE*)&REGISTER2,
};
/**
* Defines a table of pointers to the peripheral latch register on the
* microcontroller
*/
static TYPE volatile * const DataOut[NUM_PORTS] =
{
(TYPE*)&REGISTER1, (TYPE*)&REGISTER2,
};
/**
 ** Defines a table of pointers to the peripheral resistor enable register
* on the microcontroller
*/
static TYPE volatile * const Resistor[NUM_PORTS] =
{
(TYPE*)&REGISTER1, (TYPE*)&REGISTER2,
};
/**
* Defines a table of pointers to the port’s function select register
* on the microcontroller
*/
static TYPE volatile * const Function[NUM_PORTS] =
{
(TYPE*)&REGISTER1, (TYPE*)&REGISTER2,
};
/**********************************************************************
* Function Prototypes
**********************************************************************/
/**********************************************************************
* Function Definitions
**********************************************************************/
/*********************************************************************
* Function : GPIO_Init()
*//**
* \b Description:
*
* This function is used to initialize the GPIO based on the configuration
* table defined in GPIO_cfg module.
*
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0) <br>
* PRE-CONDITION: NUMBER_OF_CHANNELS_PER_PORT > 0 <br>
* PRE-CONDITION: NUMBER_OF_PORTS > 0 <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
** POST-CONDITION: The GPIO peripheral is set up with the configuration
* settings.
*
* @param Config is a pointer to the configuration table that
* contains the initialization for the
peripheral.
*
* @return void
*
* \b Example:
* @code
* const GPIOConfig_t *GPIOConfig = GPIO_ConfigGet();
*
* GPIO_Init(GPIOConfig);
* @endcode
*
* @see GPIO_Init
* @see GPIO_ChannelRead
* @see GPIO_ChannelWrite
* @see GPIO_ChannelToggle
* @see GPIO_RegisterWrite
* @see GPIO_RegisterRead
* @see GPIO_CallbackRegister
*
**********************************************************************/
void GPIO_Init(const GPIOConfig_t * Config)
{
/* TODO: Define implementation */
}
/**********************************************************************
* Function : GPIO_ChannelRead()
*//**
* \b Description:
** This function is used to read the state of a GPIO channel (pin)
*
* PRE-CONDITION: The channel is configured as INPUT <br>
* PRE-CONDITION: The channel is configured as GPIO <br>
* PRE-CONDITION: The channel is within the maximum GPIOChannel_t
* definition
*
* POST-CONDITION: The channel state is returned.
*
* @param Channel is the GPIOChannel_t that represents a pin
*
* @return The state of the channel as HIGH or LOW
*
* \b Example:
* @code
* uint8_t pin = GPIO_ReadChannel(PORT1_0);
* @endcode
*
* @see GPIO_Init
* @see GPIO_ChannelRead
* @see GPIO_ChannelWrite
* @see GPIO_ChannelToggle
* @see GPIO_RegisterWrite
* @see GPIO_RegisterRead
* @see GPIO_CallbackRegister
*
**********************************************************************/
GPIOPinState_t GPIO_ChannelRead(GPIOChannel_t Channel)
{
}
/**********************************************************************
* Function : GPIO_ChannelWrite()
*//*** \b Description:
*
* This function is used to write the state of a channel (pin) as either
* logic high or low through the use of the GPIOChannel_t enum to select
* the channel and the GPIOPinState_t to define the desired state.
*
* PRE-CONDITION: The channel is configured as OUTPUT <br>
* PRE-CONDITION: The channel is configured as GPIO <br>
* PRE-CONDITION: The channel is within the maximum GPIOChannel_t definition
*
* POST-CONDITION: The channel state will be State
*
* @param Channel is the pin to write using the GPIOChannel_t
* enum definition
* @param State is HIGH or LOW as defined in the
* GPIOPinState_t enum
*
* @return void
*
* \b Example:
* @code
* GPIO_WriteChannel(PORT1_0, LOW); // Set the PORT1_0 pin low
* GPIO_WriteChannel(PORT1_0, HIGH); // Set the PORT1_0 pin high
* @endcode
*
* @see GPIO_Init
* @see GPIO_ChannelRead
* @see GPIO_ChannelWrite
* @see GPIO_ChannelToggle
* @see GPIO_RegisterWrite
* @see GPIO_RegisterRead
* @see GPIO_CallbackRegister
***********************************************************************/
void GPIO_ChannelWrite(GPIOChannel_t Channel, GPIOPinState_t State)
{
}
/**************************************************************************
* Function : GPIO_ChannelToggle()
*//**
* \b Description:
*
* This function is used to toggle the current state of a channel (pin).
*
* PRE-CONDITION: The channel is configured as OUTPUT <br>
* PRE-CONDITION: The channel is configured as GPIO <br>
* PRE-CONDITION: The channel is within the maximum GPIOChannel_t definition
*
* POST-CONDITION:
*
* @param Channel is the pin from the GPIOChannel_t that is
* to be modified.
*
* @return void
*
* \b Example:
* @code
* GPIO_ChannelToggle(PORTA_1);
* @endcode
*
* @see GPIO_Init
* @see GPIO_ChannelRead
* @see GPIO_ChannelWrite
* @see GPIO_ChannelToggle
* @see GPIO_RegisterWrite
* @see GPIO_RegisterRead
* @see GPIO_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*
**********************************************************************/
void GPIO_ChannelToggle(GPIOChannel_t Channel)
{
}
/**************************************************************************
* Function : GPIO_RegisterWrite()
*//**
* \b Description:
*
* This function is used to directly address and modify a GPIO register.
* The function should be used to access specialied functionality in the
* GPIO peripheral that is not exposed by any other function of the
* interface.
*
* PRE-CONDITION: Address is within the boundaries of the GPIO register
* addresss space
*
* POST-CONDITION: The register located at Address with be updated
* with Value
*
* @param Address is a register address within the GPIO
* peripheral map
* @param Value is the value to set the GPIO register to
*
* @return void
*
* \b Example:
* @code
* GPIO_RegisterWrite(0x1000, 0x15);
* @endcode
*
* @see GPIO_Init
* @see GPIO_ChannelRead
* @see GPIO_ChannelWrite
* @see GPIO_ChannelToggle
* @see GPIO_RegisterWrite
* @see GPIO_RegisterRead
* @see GPIO_CallbackRegister
*
**********************************************************************/
void GPIO_RegisterWrite(uint32_t Address, TYPE Value)
{
}
/**********************************************************************
* Function : GPIO_RegisterRead()
*//**
* \b Description:
*
* This function is used to directly address a GPIO register. The function
* should be used to access specialied functionality in the GPIO peripheral
* that is not exposed by any other function of the interface.
*
* PRE-CONDITION: Address is within the boundaries of the GPIO register
* addresss space
*
* POST-CONDITION: The value stored in the register is returned to the
* caller
*
* @param Address is the address of the GPIO register to read
*
* @return The current value of the GPIO register.
*
* \b Example:
* @code
** GPIOValue = GPIO_RegisterRead(0x1000);
* @endcode
*
* @see GPIO_Init
* @see GPIO_ChannelRead
* @see GPIO_ChannelWrite
* @see GPIO_ChannelToggle
* @see GPIO_RegisterWrite
* @see GPIO_RegisterRead
* @see GPIO_CallbackRegister
*
*
**********************************************************************/
TYPE GPIO_RegisterRead(uint32_t Address)
{
}
/**********************************************************************
* Function : GPIO_CallbackRegister()
*//**
* \b Description:
*
* This function is used to set the callback functions of the GPIO driver. By
* default, the callbacks are initialized to a NULL pointer. The driver may
* contain more than one possible callback, so the function will take a
* parameter to configure the specified callback.
*
* PRE-CONDITION: The GPIOCallback_t has been populated
* PRE-CONDITION: The callback function exists within memory.
*
* POST-CONDITION: The specified callback function will be registered
* with the driver.
*
** @param Function is the callback function that will be registered
* @param CallbackFunction is a function pointer to the desired
* function
*
* @return None.
*
* \b Example:
* @code
* GPIOCallback_t GPIO_Function = GPIO_SAMPLE_COMPLETE;
*
* GPIO_CallbackRegister(GPIO_Function, GPIO_SampleAverage);
* @endcode
*
* @see GPIO_Init
* @see GPIO_ChannelRead
* @see GPIO_ChannelWrite
* @see GPIO_ChannelToggle
* @see GPIO_RegisterWrite
* @see GPIO_RegisterRead
* @see GPIO_CallbackRegister
*
**********************************************************************/
void GPIO_CallbackRegister(GPIOCallback_t Function,
TYPE (*CallbackFunction)(type))
{
}
/*************** END OF FUNCTIONS ********************************/ 