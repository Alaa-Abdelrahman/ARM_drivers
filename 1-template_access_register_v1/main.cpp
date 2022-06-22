#include "mcal_reg.h"

/***********************************************************
write a template class for access the registers
of microcontroller

***********************************************************/

template<typename addr_type,
				 typename reg_type,
				 const addr_type addr,
				 const reg_type val>
		
/**************************************************
				 this class has four template parameters
				 tp specify the characteristics of 
				 the microcontroller register
***************************************************/
				 
class reg_access{
	public:
		static void reg_set()
		{
			*reinterpret_cast<volatile addr_type *>(addr) = static_cast<reg_type> (val);
		}
		
		static void reg_or()
		{
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type> (val);
		}
		
		static void reg_and()
		{
			*reinterpret_cast<volatile addr_type *>(addr) &= static_cast<reg_type> (val);
		}
		
		static void reg_not()
		{
			
			*reinterpret_cast<volatile addr_type *>(addr) &= static_cast<reg_type> (val);
		}
		
		static void bit_set()
		{
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type> (1U<<val);
		}
		static void bit_clr()
		{
			*reinterpret_cast<volatile addr_type *>(addr) &= static_cast<reg_type>(~(1U<<val));
		}
		static void bit_not()
		{
			*reinterpret_cast<volatile addr_type *>(addr) ^= static_cast<reg_type> (1U<<val);
		}
		
		static reg_type reg_get() 
		{
			return (*reinterpret_cast<volatile addr_type *>(addr));
		}
		
		static bool bit_get()
		{
			return ((reg_get()& static_cast<reg_type>(1U << val)) != static_cast<reg_type>(0U));
		}
		
};			 
int main()
{
	/*enable clock for port b*/
	reg_access<std::uint32_t,
	            std::uint32_t,
							mcal::reg::rcc::ahb1enr,
							(1u<<1)>::reg_set();

	/*
	set first 8 pins of gpiob to high
	*/
	reg_access<std::uint32_t,
						 std::uint32_t,
						 mcal::reg::gpio::cfg_regs::gpiob_cfg::gpiob_odr,
						0xff>::reg_set();
	while(1)
	{
	}
	
}

