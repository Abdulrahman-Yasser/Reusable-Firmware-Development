#include "Common/Std_Types.h"

typedef struct{
    uint32* GPIODATA;
    uint32* GPIODIR;
    uint32* GPIOIS;
    uint32* GPIOIBE;
    uint32* GPIOIEV;
    uint32* GPIOIM;
    uint32* GPIORIS;
    uint32* GPIOMIS;
    uint32* GPIOICR;
    uint32* GPIOAFSEL;
    uint32* GPIODR2R;
    uint32* GPIODR4R;
    uint32* GPIODR8R;
    uint32* GPIOODR;
    uint32* GPIOPUR;
    uint32* GPIOPDR;
    uint32* GPIOSLR;
    uint32* GPIODEN;
    uint32* GPIOLOCK;
    uint32* GPIOCR;
    uint32* GPIOAMSEL;
    uint32* GPIOPCTL;
    uint32* GPIOADCCTL;
    uint32* GPIODMACTL;
}GPIO_Module_regs;

volatile uint32* GPIO_bases_Regs = {
    0x400043fc,
    0x400053fc,
    0x400063fc,
    0x400073fc,
    0x400243fc,
    0x400253fc
};