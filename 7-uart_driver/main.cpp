#include "uart.h"
#include<stdio.h>


/***
*@program : systick and uart
*/
/*
Procedure:
1. Enable the USART by writing the UE bit in USART_CR1 register to 1.
2. Program the M bit in USART_CR1 to define the word length.
3. Program the number of stop bits in USART_CR2.
4. Select DMA enable (DMAR) in USART_CR3 if multibuffer communication is to take
place. Configure the DMA register as explained in multibuffer communication. STEP 3
5. Select the desired baud rate using the baud rate register USART_BRR
6. Set the RE bit USART_CR1. This enables the receiver which begins searching for a
start bit.
*/


int main()
{
	uart2_init();
	
	printf(" hell \n\r");
	
while(1)
{
	
	
}

}

