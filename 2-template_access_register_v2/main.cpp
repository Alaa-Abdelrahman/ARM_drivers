#include "mcal_reg.h"

/***********************************************************
write a template class for access the registers
of microcontroller dynamic method throgh passing a parameters 
to function 

***********************************************************/

template<typename addr_type,
				 typename reg_type>
		
/**************************************************
				 this class has four template parameters
				 tp specify the characteristics of 
				 the microcontroller register
***************************************************/
				 
class reg_access_dynamic{
	public:
		static void reg_set(addr_type addr ,reg_type val)
		{
			*reinterpret_cast<volatile addr_type *>(addr) = static_cast<reg_type> (val);
		}
		
		static void reg_or(addr_type addr ,reg_type val)
		{
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type> (val);
		}
		
		static void reg_and(addr_type addr ,reg_type val)
		{
			*reinterpret_cast<volatile addr_type *>(addr) &= static_cast<reg_type> (val);
		}
		
		static void reg_not(addr_type addr ,reg_type val)
		{
			
			*reinterpret_cast<volatile addr_type *>(addr) &= static_cast<reg_type> (val);
		}
		
		static void bit_set(addr_type addr ,reg_type val)
		{
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type> (1U<<val);
		}
		static void bit_clr(addr_type addr ,reg_type val)
		{
			*reinterpret_cast<volatile addr_type *>(addr) &= static_cast<reg_type>(~(1U<<val));
		}
		static void bit_not(addr_type addr ,reg_type val)
		{
			*reinterpret_cast<volatile addr_type *>(addr) ^= static_cast<reg_type> (1U<<val);
		}
		
		static reg_type reg_get(addr_type addr) 
		{
			return (*reinterpret_cast<volatile addr_type *>(addr));
		}
		
		static bool bit_get(addr_type addr ,reg_type val)
		{
			return ((reg_get(addr)& static_cast<reg_type>(1U << val)) != static_cast<reg_type>(0U));
		}
		
};			 
int main()
{
	/*enable clock for port b*/
	reg_access_dynamic<std::uint32_t,
	            std::uint32_t>::reg_set(mcal::reg::rcc::ahb1enr,(1u<<1));

	/*
	set first 8 pins of gpiob to high
	*/
	reg_access_dynamic<std::uint32_t,
						 std::uint32_t>::reg_set(mcal::reg::gpio::cfg_regs::gpiob_cfg::gpiob_odr,0xff);
	while(1)
	{
	}
	
}

