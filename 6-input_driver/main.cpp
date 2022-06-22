#include "mcal_reg.h"

/***
*@program : control led connected to PA5 with switch connected to c13
*/

std::uint32_t bt_st;
int main()
{
	/**1.Enable clock access to GPIOA */
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::ahb1enr,(1U<<0)>::reg_or();
	 /**1.Enable clock access to GPIOC */
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::ahb1enr,(1U<<2)>::reg_or();
	
	
		/**2.set PA5 as output pin */
		mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_moder,(1U<<10)>::reg_or();
  		/**2.set PA5 as output pin */
		mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioc_moder,(0U<<26)>::reg_or();
   		mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioc_moder,(0U<<27)>::reg_or();

while(1)
{
	
	/** read the value */
	bt_st = mcal::reg::reg_access<std::int32_t,std::uint32_t,mcal::reg::gpioc_idr,0u>::reg_get();
	if(bt_st&0x2000)
	{
			mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_bsrr,21>::bit_clr();

			mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_bsrr,5>::bit_set();

	}
	else{
		mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_bsrr,5>::bit_clr();

	   mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_bsrr,21>::bit_set();

	}
	
	  
	

}

}