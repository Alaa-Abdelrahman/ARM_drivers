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
		
		static void set_pin_out()
		{
			*reinterpret_cast<volatile addr_type *>(addr)|= static_cast<reg_type>(1U<< (val*2) );
		}
		
		static void set_pin_in()
		{
			*reinterpret_cast<volatile addr_type *>(addr)|= static_cast<reg_type>(0U<< (val*2) );
		  *reinterpret_cast<volatile addr_type *>(addr)|= static_cast<reg_type>(0U<< (+(val*2) ));
		}
		static void set_pin_in_analog()
		{
			*reinterpret_cast<volatile addr_type *>(addr)|= static_cast<reg_type>(1U<< (val*2) );
		  *reinterpret_cast<volatile addr_type *>(addr)|= static_cast<reg_type>(1U<< (+(val*2) ));
		}
		
		static void set_pin_alt()
		{
			*reinterpret_cast<volatile addr_type *>(addr)|= static_cast<reg_type>(0U<< (val*2) );
		  *reinterpret_cast<volatile addr_type *>(addr)|= static_cast<reg_type>(1U<< (+(val*2) ));
		}
		
		
};	


/**************************************************************
create port template for access gpio port
*/

template <typename addr_type, typename reg_type, const addr_type port, const reg_type bpos>

class port_pin{
	
	public:
		static void set_dir_out()
		{
			port_dir_type::set_pin_out();
		}
		
		static void set_dir_in()
		{
			port_dir_type::set_pin_in();
		}
		
		static void set_pin_high()
		{
			port_pin_type::bit_set();
		}
		
		static void set_pin_low()
		{
			port_pin_type::bit_clr();
		}
		
		static bool read_in_val()
		{
			return port_in_type::bit_get();
		
		}
   static  void toggle(){
			
			port_pin_type::bit_not();
		}
		
	private:
		
		static const std::uint32_t odr_offset =(0x14); 
	  static const  std::uint32_t idr_offset  =(0x10);
	
    static const addr_type p_odr = port + odr_offset;
		static const addr_type p_idr = port + idr_offset;
	
		typedef reg_access<addr_type,reg_type,p_odr,bpos> port_pin_type;
		typedef reg_access<addr_type,reg_type,port,bpos> port_dir_type;
 		typedef reg_access<addr_type,reg_type,p_idr,bpos> port_in_type;

	

	
	

};


int main()
{
	const std:: uint32_t ahb1enr = mcal::reg::rcc::ahb1enr;
	const std:: uint32_t gpio =  mcal::reg::gpio::gpioa;
	/*enable clock for port b*/
	
	typedef reg_access<std::uint32_t,std::uint32_t,ahb1enr,0U>ahb1enr_gpioa;
	
	ahb1enr_gpioa::bit_set();
	

	
	/*
	set first 0 pins of gpioa to high
	*/
	typedef port_pin<std::uint32_t,std::uint32_t,gpio,0U>pa5_t;
	pa5_t::set_dir_out();

	
	while(1)
	{
		
		pa5_t::toggle();
		for(int i = 0; i<180000; i++)
		{
			
		}
		
	}
	
}

