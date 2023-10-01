/** @file GPIO_cfg.c
* @brief This module contains the implementation for the digital
* input/output peripheral configuration
*/
/**********************************************************************
* Includes
**********************************************************************/

#include "GPIO_config.h" /* For this modules definitions */

/**********************************************************************
* Module Preprocessor Constants
**********************************************************************/
/**********************************************************************
* Module Preprocessor Macros
**********************************************************************/
/**********************************************************************
* Module Typedefs
**********************************************************************/
/*********************************************************************
* Module Variable Definitions
**********************************************************************/

/**
* The following array contains the configuration data for each
* digital input/output peripheral channel (pin). Each row represents a *
single pin. Each column is representing a member of the GPIOConfig_t
* structure. This table is read in by GPIO_Init, where each channel is then
* set up based on this table.
*/
const GPIOConfig_t GPIOConfig[] =
{
    /* Resistor Initial */
    /* Channel Enabled Direction Pin Function */
    /* */
    { PORT1_0, DISABLED, OUTPUT, HIGH, FCN_GPIO },
    { PORT1_1, DISABLED, OUTPUT, HIGH, FCN_GPIO },
    { PORT1_2, DISABLED, OUTPUT, HIGH, FCN_GPIO },
    { PORT1_3, DISABLED, OUTPUT, HIGH, FCN_GPIO },
    { PORT1_4, DISABLED, OUTPUT, HIGH, FCN_GPIO },
    { PORT1_5, DISABLED, OUTPUT, HIGH, FCN_GPIO },
    { PORT1_6, DISABLED, OUTPUT, HIGH, FCN_GPIO },
    { PORT1_7, DISABLED, OUTPUT, HIGH, FCN_GPIO },
};
/**********************************************************************
* Function Prototypes
**********************************************************************/

/**********************************************************************
* Function Definitions
**********************************************************************/

/**********************************************************************
* Function : GPIO_ConfigGet()
*//**
* \b Description:
*
* This function is used to initialize the GPIO based on the configuration
* table defined in GPIO_cfg module.
*
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
*
* POST-CONDITION: A constant pointer to the first member of the
* configuration table will be returned.
*
* @return A pointer to the configuration table.
*
* \b Example Example:
* @code
* const GPIO_ConfigType *GPIOConfig = GPIO_GetConfig();
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
*
**********************************************************************/
const GPIOConfig_t * const GPIO_ConfigGet(void)
{
    /*
    * The cast is performed to ensure that the address of the first element
    * of configuration table is returned as a constant pointer and NOT a
    * pointer that can be modified.
    */
    return (const *)GPIOConfig[0];
}
/*************** END OF FUNCTIONS ********************************/