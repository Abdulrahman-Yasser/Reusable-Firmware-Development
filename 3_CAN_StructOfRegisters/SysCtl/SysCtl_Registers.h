#ifndef SYSCTL_REGISTERS_H
#define SYSCTL_REGISTERS_H

#include "Std_Types.h"

#define SysCtl_RCGC_Base    0x400FE600

typedef struct {
    volatile uint32 RCGCWD;
    volatile uint32 RCGCTIMER;
    volatile uint32 RCGCGPIO;
    volatile uint32 RCGCDMA;
    volatile uint32 NotUsed;
    volatile uint32 RCGCHIB;
    volatile uint32 RCGCUART;
    volatile uint32 RCGCSSI;
    volatile uint32 RCGCI2C;
    volatile uint32 RCGCUSB;
    volatile uint32 RCGCCAN;
    volatile uint32 RCGCADC;
    volatile uint32 RCGCACMP;
    volatile uint32 RCGCPWM;
    volatile uint32 RCGCQEI;
    volatile uint32 RCGCEEPROM;
    volatile uint32 RCGCWTIMER;
}SysCtl_Module_regs;

volatile SysCtl_Module_regs* const my_SysCtl_RCGC_Registers_g = (SysCtl_Module_regs*)SysCtl_RCGC_Base;

#endif
