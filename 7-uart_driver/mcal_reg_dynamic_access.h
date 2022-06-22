#ifndef _MCAL_REG_DYNAMIC_ACCESS_H
#define _MCAL_REG_DYNAMIC_ACCESS_H

namespace mcal
{
	namespace reg{
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
	}

}


#endif
