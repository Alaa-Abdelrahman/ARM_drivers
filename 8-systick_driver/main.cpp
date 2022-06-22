#include "uart.h"
#include "systick.h"
#include "mcal_reg.h"


/***
*@program : systick and delay    
*/



int main()
{
	uart2_init();
	
	/*enable clock for GPIOA */
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::ahb1enr,0x01>::reg_or();
	
	/*set PA5 to output */
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_moder,(1u<<10)>::reg_or();

	
	while(1)
{
	
		mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_odr,5>::bit_not();

	  systick_delayMs(1000);

}

}

