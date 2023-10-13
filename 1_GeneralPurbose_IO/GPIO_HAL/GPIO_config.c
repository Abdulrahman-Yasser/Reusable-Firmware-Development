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
GPIOConfig_t const GPIOConfig[] =
{
    /* Resistor Initial */
    /* Channel Enabled Direction Pin Function */
    /* */
    { PORTa_0, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTa_1, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTa_2, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTa_3, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTa_4, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTa_5, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTa_6, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTa_7, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTb_0, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTb_1, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTb_2, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTb_3, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTb_4, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTb_5, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTb_6, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTb_7, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTc_0, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTc_1, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTc_2, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTc_3, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTc_4, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTc_5, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTc_6, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTc_7, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTd_0, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTd_1, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTd_2, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTd_3, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTd_4, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTd_5, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTd_6, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTd_7, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTe_0, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTe_1, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTe_2, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTe_3, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTe_4, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTe_5, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTf_0, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTf_1, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_MAX_MODE },
    { PORTf_2, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTf_3, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
    { PORTf_4, GPIO_PULLUP_DISABLED, OUTPUT, GPIO_HIGH, GPIO_Notused_MODE },
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
GPIOConfig_t const* GPIO_ConfigGet(void)
{
    /*
    * The cast is performed to ensure that the address of the first element
    * of configuration table is returned as a constant pointer and NOT a
    * pointer that can be modified.
    */
    return (GPIOConfig_t const*)&GPIOConfig[0];
}
/*************** END OF FUNCTIONS ********************************/