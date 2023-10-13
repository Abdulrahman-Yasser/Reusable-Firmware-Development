/** @file GPIO_cfg.h
* @brief This module contains interface definitions for the
* GPIO configuration. This is the header file for the definition of the
* interface for retrieving the digital input/output configuration table.
*/

#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

/**********************************************************************
* Includes
**********************************************************************/

/**********************************************************************
* Preprocessor Constants
**********************************************************************/


/**
* Defines the number of all the pins on the processor.
*/
#define NUM_DIGITAL_PINS    43


/**********************************************************************
* Typedefs
**********************************************************************/

/**
* Defines the possible states for a digital output pin.
*/
typedef enum
{
    GPIO_LOW, /** Defines digital state ground */
    GPIO_HIGH, /** Defines digital state power */
    GPIO_PIN_STATE_MAX /** Defines the maximum digital state */
}GPIOPinState_t;


/**
* Defines an enumerated list of all the channels (pins) on the MCU
* device. The last element is used to specify the maximum number of
* enumerated labels.
*/
typedef enum
{
    /* TODO: Populate this list based on available MCU pins */
    PORTa_0, /**< PORTa_0 */ PORTa_1, /**< PORTa_1 */ PORTa_2, /**< PORTa_2 */ PORTa_3, /**< PORTa_3 */
    PORTa_4, /**< PORTa_4 */ PORTa_5, /**< PORTa_5 */ PORTa_6, /**< PORTa_6 */ PORTa_7, /**< PORTa_7 */
    PORTb_0, /**< PORTb_0 */ PORTb_1, /**< PORTb_1 */ PORTb_2, /**< PORTb_2 */ PORTb_3, /**< PORTb_3 */
    PORTb_4, /**< PORTb_4 */ PORTb_5, /**< PORTb_5 */ PORTb_6, /**< PORTb_6 */ PORTb_7, /**< PORTb_7 */
    PORTc_0, /**< PORTc_0 */ PORTc_1, /**< PORTc_1 */ PORTc_2, /**< PORTc_2 */ PORTc_3, /**< PORTc_3 */
    PORTc_4, /**< PORTc_4 */ PORTc_5, /**< PORTc_5 */ PORTc_6, /**< PORTc_6 */ PORTc_7, /**< PORTc_7 */
    PORTd_0, /**< PORTd_0 */ PORTd_1, /**< PORTd_1 */ PORTd_2, /**< PORTd_2 */ PORTd_3, /**< PORTd_3 */
    PORTd_4, /**< PORTd_4 */ PORTd_5, /**< PORTd_5 */ PORTd_6, /**< PORTd_6 */ PORTd_7, /**< PORTd_7 */
    PORTe_0, /**< PORTe_0 */ PORTe_1, /**< PORTe_1 */ PORTe_2, /**< PORTe_2 */ PORTe_3, /**< PORTe_3 */
    PORTe_4, /**< PORTe_4 */ PORTe_5, /**< PORTe_5 */ 
    PORTf_0=40, /**< PORTf_0 */ PORTf_1, /**< PORTf_1 */ PORTf_2, /**< PORTf_2 */ PORTf_3, /**< PORTf_3 */
    PORTf_4, /**< PORTf_4 */
    GPIO_MAX_PIN_NUMBER /**< MAX CHANNELS */ 
}GPIOChannel_t;

/**
* Defines the possible GPIO pin multiplexing values. The datasheet
* should be reviewed for proper muxing options.
*/
typedef enum
{
    /* TODO: Populate with possible mode options */
    OUTPUT,
    INPUT
}GPIODirection_t;


/**
* Defines the possible GPIO pin multiplexing values. The datasheet
* should be reviewed for proper muxing options.
*/
typedef enum
{
    /* TODO: Populate with possible mode options */
    GPIO_MAX_MODE,
    GPIO_Notused_MODE
}GPIOMode_t;

/**
* Defines the possible states of the channel pull-ups
*/
typedef enum
{
    GPIO_PULLUP_DISABLED, /*< Used to disable the internal pull-ups */
    GPIO_PULLUP_ENABLED, /*< Used to enable the internal pull-ups */
    GPIO_MAX_RESISTOR /*< Resistor states should be below this value*/
}GPIOResistor_t;

/**
* Defines the digital input/output configuration table’s elements that are used
* by GPIO_Init to configure the GPIO peripheral.
*/
typedef struct
{
    /* TODO: Add additional members for the MCU peripheral */
    GPIOChannel_t Channel; /**< The I/O pin */
    GPIOResistor_t Resistor; /**< ENABLED or DISABLED */
    GPIODirection_t Direction; /**< OUTPUT or INPUT */
    GPIOPinState_t Data;  /**<HIGH or LOW */
    GPIOMode_t Function; /**< Mux Function - GPIO_Peri_Select*/
}GPIOConfig_t;

/**
* Defines the slew rate settings available
*/
typedef enum
{
    FAST, /**< Fast slew rate is configured on the corresponding pin, */
    SLOW /**< Slow slew rate is configured on the corresponding pin, */
}GPIOSlew_t;

/**********************************************************************
* Function Prototypes
**********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

GPIOConfig_t const* GPIO_ConfigGet(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif
/***End of File****************************************************/
