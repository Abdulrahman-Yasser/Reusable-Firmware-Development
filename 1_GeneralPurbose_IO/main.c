#include "GPIO_HAL/GPIO.h"

#include "MCAL_Layer/PORT/Static/inc/PORT.h"
#include "MCAL_Layer/PLL/Static/inc/PLL.h"


int main(){
	PLL_Init();
	Port_Init();

	GPIO_Init(GPIO_ConfigGet());

	while(1){
		Delay_ms(1000);
		GPIO_ChannelToggle(PORTf_1);
	}
}
