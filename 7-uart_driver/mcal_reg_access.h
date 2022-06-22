#ifndef _MCAL_REG_ACCESS_H
#define _MCAL_REG_ACCESS_H


namespace mcal{
	
	namespace reg
	{
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
	}


}

#endif
