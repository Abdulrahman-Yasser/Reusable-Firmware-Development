#include "SPI_HAL/SPI.h"

#include "MCAL_Layer/PORT/Static/inc/PORT.h"
#include "MCAL_Layer/PLL/Static/inc/PLL.h"

//! \addtogroup main_functions
//! @{


void app_SPI_Loop(void);

int main(){
	PLL_Init();
	Port_Init();
	Spi_Init(SPI_getConfig());
	Spi_Transfer(SSI_Channel_2, 0x55, 1);
	app_SPI_Loop();
}


void app_SPI_Loop(void){
	char* msg_1 = 'i   w i l l   k i l l   y o u ';
	char* msg_2 = 'h a h a   j u s t   j o k i n g ';
	while(1){
		Spi_Transfer(SSI_Channel_2, (uint16*)msg_1, 15);
		Delay_ms(10);
		Spi_Transfer(SSI_Channel_2, (uint16*)msg_2, 16);
		Delay_ms(10);
	}
}

//! @}
