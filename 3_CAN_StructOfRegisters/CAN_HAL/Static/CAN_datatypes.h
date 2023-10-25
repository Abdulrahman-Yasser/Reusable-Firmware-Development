#ifndef CAN_DATATYPES_H
#define CAN_DATATYPES_H


#define CAN_Status_Bus_Off_Bit      1 << 7
#define CAN_Status_Warning_Bit      1 << 6
#define CAN_Status_ErrorPassive_Bit      1 << 5
#define CAN_Status_Rec_Msg_Sucssful_Bit      1 << 4
#define CAN_Status_Trans_Msg_Sucssful_Bit      1 << 3

typedef enum{
    CAN_LEC_No_Error;
    CAN_LEC_StuffError;
    CAN_LEC_FormatError;
    CAN_LEC_ACKError;
    CAN_LEC_Bit_1_Error;
    CAN_LEC_Bit_0_Error;
    CAN_LEC_CRC;
    CAN_LEC_NoEvent;
}CAN_LastErrorCode;

typedef struct{
    BoolType Automatic-Retransmission;
    uint8 InterruptTypes;
    uint8 CAN_BIT_TSEG2;
    uint8 CAN_BIT_TSEG1;
    uint8 CAN_BIT_SJW;
    uint8 CAN_BaudRatePresc;
    uint8 BaudRatePrescaleExtnsion;
}CANConfig_t;

typedef struct{
    BoolType Automatic-Retransmission;
    uint8 InterruptTypes;
    uint8 CAN_BIT_TSEG2;
    uint8 CAN_BIT_TSEG1;
    uint8 CAN_BIT_SJW;
    uint8 CAN_BaudRatePresc;
    BoolType TestLoopbackMode;
    BoolType SilentMode;
    BoolType BasicMode;
    uint8 BaudRatePrescaleExtnsion;
}CANTestingConfig_t;

/**
 * @brief writing to the Command Mask register specifies the transfer direction and selects which
 * buffer registers are the source or target of the data transfer.
 * when a read from the message object buffer occurs when WRNRD is clear, and CLRINTPND and/or NEWDAT are set.
 * 
 */
typedef struct{
    uint8 Data[8];                          /**< The data that will be send*/
    uint8 MassegeNumber;
    BoolType Direct_CAN_IF;                 /**< Either send the data in Message object specified by MNUM to CANIFn or send the data in CANIFn register to CAN messaage object specified by MNUM*/
    BoolType AccessMaskBits;                /**< Transfer IDMASK + DIR + MXTD of message object into Interface register*/
    BoolType AccessArbitrationBits;         /**< Transfer ID + DIR + XTD + MSGVAL of message object into Interface register*/
    BoolType CONTROL;                       /**< Transfer Control bits from CANIFnMCTL into interface register*/
    BoolType CearInterruptPendingBit;       /**< Clear interrupt pending bit*/
    BoolType NEWDAT_TXRQST;                 /**< */
    BoolType DATAA;                         /**< if set, Move data bytes 0-3 CANIFnDA1, CANIFnDA2. Otherwise data bytes 0-3 unchanged*/
    BoolType DATAB;                         /**< if set, Move data bytes 4-7 CANIFnDA1, CANIFnDA2. Otherwise data bytes 4-7 unchanged*/
    uint16 CANIF1MASK1;                     /**< The corresponding identifier field (ID) is used for acceptance filtering.*/
    uint16 CANIF2MASK1;                     /**< The corresponding identifier field (ID) is used for acceptance filtering.*/
    uint16 CANIF1MASK2;
    uint16 CANIF2MASK2;
}CAN_TransmitterContainer;


#endif