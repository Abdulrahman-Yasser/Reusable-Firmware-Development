#include "SPI_HAL/SPI.h"

#include "MCAL_Layer/PORT/Static/inc/PORT.h"
#include "MCAL_Layer/PLL/Static/inc/PLL.h"


int main(){
	PLL_Init();
	Port_Init();

}
