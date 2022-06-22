#include "uart.h"
#include "mcal_reg.h"
#include <stdio.h>


#define uart2   reinterpret_cast< mcal::reg::UART_t *>(mcal::reg::uart2_base)
					
void uart2_init(){
	/**.Enable clock access to GPIOA */
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::ahb1enr,(1U<<0)>::reg_or();
	 
	/**.Enable clock  UART */
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::apb1enr,(1U<<17)>::reg_or();
	 
	/**.Configure PA2 to work as TX as alternative function no GPIO */
		mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_moder,(1U<<4)>::reg_or();
  	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_moder,(1U<<5)>::reg_or();

	/**.Configure PA2 to work as RX as alternative function no GPIO */
		mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_moder,(1U<<6)>::reg_or();
  	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_moder,(1U<<7)>::reg_or();

	/**.Set alternative type of PA2 to USART2 */
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_afrl,0x0700>::reg_or();
	
	/**.Set alternative type of PA3 to USART2 */
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioa_afrl,0x7000>::reg_or();
	
	/**.Configure usart2 baud rate 9600  @16 mhz*/
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::uart2_brr,0x0683>::reg_set();

	/**.Enable TX . 8 bit */
		mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::uart2_cr1,0x8>::reg_set();
  
	/**.Enable RX . 8 bit */
		mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::uart2_cr1,0x4>::reg_set();
  
	/**. 1 stop bit */
		mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::uart2_cr2,0x00>::reg_set();
 
 /**.No flow control */
 	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::uart2_cr3,0x000>::reg_set();
	
	/**.Enable UART */
		mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::uart2_cr1,0x2000>::reg_or();


}

int uart_write(int ch)
{
	std::uint32_t _ch = ch & 0xff;
	
	// wait until TX buffer be empty
	while(!(uart2->sr & 0x0080));
	mcal::reg::reg_access_dynamic<std::uint32_t,std::uint32_t>::reg_set(uart2->dr,_ch);
	return 0;
}



char uart_read()
{
	char rcv_ch;
	/*wait until character arrived */
	while(!(uart2->sr &0x0020));
	rcv_ch = mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::uart2_dr,0>::reg_get();
	return rcv_ch;
}



	
namespace std {
  struct __FILE
  {
    int handle;
    /* Whatever you require here. If the only file you are using is */
    /* standard output using printf() for debugging, no file handling */
    /* is required. */
  };
  FILE __stdout;
  FILE __stdin;
  FILE __stderr;
  int fgetc(FILE *f)
  {
    /* Your implementation of fgetc(). */
		int c;
		c = uart_read();
		
		/* if '\r' after it is echoed , a '\n' is appended*/
		if(c == '\r')
		{
			uart_write(c); /*echo*/
			
			c = '\n';
			
		}
		
		uart_write(c); //echo
    return 0;
  }
  int fputc(int c, FILE *stream)
  {
    /* Your implementation of fputc(). */
		return uart_write(c);
  }
  int ferror(FILE *stream)
  {
    /* Your implementation of ferror(). */
  }
  long int ftell(FILE *stream)
  {
    /* Your implementation of ftell(). */
  }
  int fclose(FILE *f)
  {
    /* Your implementation of fclose(). */
    return 0;
  }
  int fseek(FILE *f, long nPos, int nMode)
  {
    /* Your implementation of fseek(). */
    return 0;
  }
  int fflush(FILE *f)
  {
    /* Your implementation of fflush(). */    
    return 0;
  }
}



