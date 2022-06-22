#ifndef _MCAL_REG_H
#define _MCAL_REG_H

#include <cstdint>
#include "mcal_reg_access.h"
#include "mcal_reg_dynamic_access.h"

namespace mcal{
	
	namespace reg{
		// global base address
		const std::uint32_t periph_base =0x40000000U ;
		
		// Individual base addresses
		const std::uint32_t ahb1_periph_base = periph_base + 0x00020000U ;
		const std::uint32_t rcc_base = ahb1_periph_base+ 0x3800U ;
			
		/***************************************************************************************************************************/
		/********************     RCC addresses and registers  *******************************************************************/
		/***************************************************************************************************************************/
		
		// ahb register addresses
			const std::uint32_t ahb1enr = rcc_base + 0x30;
			const std::uint32_t ahb2enr = rcc_base + 0x34;
			const std::uint32_t ahb3enr = rcc_base + 0x38;
		
		// APB 
		const std::uint32_t apb1enr = rcc_base + 0x40;

		
		
		/***************************************************************************************************************************/
		/********************      GPIO addresses and registers  *******************************************************************/
		/***************************************************************************************************************************/
		// addresses of gpio ports
			
			const std:: uint32_t gpioa = ahb1_periph_base + 0x0000U;
			const std:: uint32_t gpiob = ahb1_periph_base + 0x0400U;
      const std:: uint32_t gpioc = ahb1_periph_base + 0x0800U;
      const std:: uint32_t gpiod = ahb1_periph_base + 0x0c00U;
			const std:: uint32_t gpioe = ahb1_periph_base + 0x1000U;
			
			// offests of registers of gpio
				
				const std:: uint32_t moder_offset   = 0x00;
				const std:: uint32_t otyper_offset  = 0x04;
				const std:: uint32_t ospeedr_offset = 0x08;
				const std:: uint32_t pupdr_offset 	= 0x0c;
				const std:: uint32_t idr_offset   	= 0x10;
				const std:: uint32_t odr_offset			= 0x14;
				const std:: uint32_t bsrr_offset		= 0x18;
				const std:: uint32_t lckr_offset	  = 0x1c;
				const std:: uint32_t afrl_offset	  = 0x20;
				const std:: uint32_t afrh_offset	  = 0x24;
				
				// gpio a registers addresses
					
					const std:: uint32_t gpioa_moder = gpioa + moder_offset;
					const std:: uint32_t gpioa_idr   = gpioa + idr_offset;
					const std:: uint32_t gpioa_odr   = gpioa + odr_offset;
					const std:: uint32_t gpioa_bsrr  = gpioa + bsrr_offset;
			   	const std:: uint32_t gpioa_afrl  = gpioa + afrl_offset;
			   	const std:: uint32_t gpioa_afrh  = gpioa + afrh_offset;

				
				// gpio b registers addresses
					
					const std:: uint32_t gpiob_moder = gpiob + moder_offset;
					const std:: uint32_t gpiob_idr   = gpiob + idr_offset;
					const std:: uint32_t gpiob_odr   = gpiob + odr_offset;
					const std:: uint32_t gpiob_bsrr  = gpiob + bsrr_offset;
				
			  	// gpio c registers addresses
					
					const std:: uint32_t gpioc_moder = gpioc + moder_offset;
					const std:: uint32_t gpioc_idr   = gpioc + idr_offset;
					const std:: uint32_t gpioc_odr   = gpioc + odr_offset;
					const std:: uint32_t gpioc_bsrr  = gpioc + bsrr_offset;
				
		/***************************************************************************************************************************/
		/********************      UART addresses and registers  *******************************************************************/
		/***************************************************************************************************************************/
		
					// uarts base address
					const std::uint32_t uart1_base = 0x40011000;
					const std::uint32_t uart2_base = 0x40004400;
					const std::uint32_t uart6_base = 0x40011400;
					
					// uart registers name and offsets
					const std::uint32_t sr_offset  = 0x00;
					const std::uint32_t dr_offset  = 0x04;
					const std::uint32_t brr_offset = 0x08;
					const std::uint32_t cr1_offset = 0x0c;
					const std::uint32_t cr2_offset = 0x10;
					const std::uint32_t cr3_offset = 0x14;
					
					// uart2 registers 
					const std::uint32_t uart2_sr  = uart2_base + sr_offset ;
					const std::uint32_t uart2_dr  = uart2_base + dr_offset ;
					const std::uint32_t uart2_brr = uart2_base + brr_offset;
					const std::uint32_t uart2_cr1 = uart2_base + cr1_offset;
					const std::uint32_t uart2_cr2 = uart2_base + cr2_offset;
					const std::uint32_t uart2_cr3 = uart2_base + cr3_offset;
					
					/********************************************
					* another way groub the registers in struct 
					*********************************************/
					
					typedef struct{
					volatile std::uint32_t sr  ;   // address offset: 0x00
					volatile std::uint32_t dr  ;   // address offset: 0x04
					volatile std::uint32_t brr ;   // address offset: 0x08
					volatile std::uint32_t cr1 ;   // address offset: 0x0c
					volatile std::uint32_t cr2 ;   // address offset: 0x10
					volatile std::uint32_t cr3 ;   // address offset: 0x14
					}UART_t;
					
	      
					
					/******************************************************************
					**************************** SYSTICK register and address
					************************************************************/
			      
					const std::uint32_t scb_base =0xE000E000u ;
					const std::uint32_t systk_base =scb_base + 0x10u;
					
					// registers offset
					const std::uint32_t ctrl_offset   = 0x000;
					const std::uint32_t load_offset   = 0x004;
					const std::uint32_t val_offset    = 0x008;
					const std::uint32_t calib_offset  = 0x00C;
					
					const std::uint32_t systk_ctrl   =systk_base + ctrl_offset ;
          const std::uint32_t systk_load   =systk_base + load_offset ;
					const std::uint32_t systk_val    =systk_base + val_offset  ;
					const std::uint32_t systk_calib  =systk_base + calib_offset;
					
           // struct for registers of systick
					 
		      typedef struct
					{
						volatile std::uint32_t ctrl ;
					  volatile std::uint32_t load ;
					  volatile std::uint32_t val  ; 
					  volatile std::uint32_t calib;
					
					}systk_t;	


		
		}
			
	}
#endif
		