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
* Defines the number of pins on each processor port.
*/
#define NUMBER_OF_CHANNELS_PER_PORT 8U

/**
* Defines the number of ports on the processor.
*/
#define NUMBER_OF_PORTS 6U

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
    PORT1_0, /**< PORT1_0 */
    PORT1_1, /**< PORT1_1 */
    PORT1_2, /**< PORT1_2 */
    PORT1_3, /**< PORT1_3 */
    PORT1_4, /**< PORT1_4 */
    PORT1_5, /**< PORT1_5 */
    PORT1_6, /**< PORT1_6 */
    PORT1_7, /**< PORT1_7 */
    GPIO_MAX_PIN_NUMBER /**< MAX CHANNELS */ 
}GPIOChannel_t;






/**
* Defines the possible GPIO pin multiplexing values. The datasheet
* should be reviewed for proper muxing options.
*/
typedef enum
{
    /* TODO: Populate with possible mode options */
    GPIO_MAX_MODE  
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

const GPIOConfig_t * const GPIO_ConfigGet(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif
/***End of File****************************************************/