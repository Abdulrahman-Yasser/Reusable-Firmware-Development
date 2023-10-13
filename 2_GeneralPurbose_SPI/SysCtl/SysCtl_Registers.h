#include "Std_Types.h"

#define SysCtl_RCGC_Base    0x400FE600

typedef struct {
    uint32 RCGCWD;
    uint32 RCGCTIMER;
    uint32 RCGCGPIO;
    uint32 RCGCDMA;
    uint32 RCGCHIB;
    uint32 RCGCUART;
    uint32 RCGCSSI;
    uint32 RCGCI2C;
    uint32 RCGCUSB;
    uint32 RCGCCAN;
    uint32 RCGCADC;
    uint32 RCGCACMP;
    uint32 RCGCPWM;
    uint32 RCGCQEI;
    uint32 RCGCEEPROM;
    uint32 RCGCWTIMER;
}SysCtl_Module_regs;

volatile SysCtl_Module_regs* const my_SysCtl_RCGC_Registers_g = (SysCtl_Module_regs*)SysCtl_RCGC_Base;