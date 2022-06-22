#include "systick.h"
#include "mcal_reg.h"

#define systk     (reinterpret_cast<mcal::reg::systk_t *>( mcal::reg::systk_base))

void systk_init_1sec(void)
{
	// initalize the load register with value 16_000_000 minus 1 to count 1 sec 
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::systk_load,(16000000-1)>::reg_set();
	
	// clear current value register
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::systk_val,(0U)>::reg_set();

	// configure the systick to enable , use system clock , no interrupt  write 5 = 110 in ctrl 
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::systk_ctrl,(5)>::reg_set();
	

}

 
int get_count_flag(void)
{
	return ( systk->ctrl &0x10000) ;
}

void systick_delayMs(int dly)
{
	// initalize the load register with value 16_000_000 minus 1 to count 1 sec 
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::systk_load,(16000-1)>::reg_set();
	
	// clear current value register
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::systk_val,(0U)>::reg_set();

	// configure the systick to enable , use system clock , no interrupt  write 5 = 110 in ctrl 
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::systk_ctrl,(5)>::reg_set();
	
	for(int i = 0; i < dly ; i++)
	{
		/*wait until count flag is set*/
		while(!( systk->ctrl &0x10000)); 
	
	}
	
	// stop timer by writing 0 to ctrl reg
	
		mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::systk_ctrl,(0)>::reg_set();

	
}

