#include "mcal_reg.h"

/***
*@program : Driver to toggle PA5
*/

int main()
{
	/**1.Enable clock access to GPIOA */
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::ahb1enr,(1U<<0)>::reg_or();
	
	
		/**2.set PA5 as output pin */
		mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_moder,(1U<<10)>::reg_or();

while(1)
{
		//mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_odr,5>::bit_not();
	  
	/* using bsrr to control gpio*/
		mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_bsrr,21>::bit_clr();

			mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_bsrr,5>::bit_set();

	 for(int i = 0 ; i<180000 ;i++);
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_bsrr,5>::bit_clr();

	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_bsrr,21>::bit_set();

	 for(int i = 0 ; i<180000 ;i++);


}

}