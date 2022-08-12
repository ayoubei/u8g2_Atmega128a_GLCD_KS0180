/*
 * u8g2_Atmega128a_GLCD_KS0180.c
 * Using u8g2 with Atmega128A and GLCD with KS0108 driver. 
 * to do before compiling: 
 * 1. Download the u8g2 from "https://github.com/olikraus/u8g2" and save it in C:\Users\USERNAME\Documents\Atmel Studio\7.0
 * 2. Download the project entitled "u8g2_Atmega128a_GLCD_KS0180" from "" or Sisoog web site. 
 * 3. Run the solution titled "u8g2_Atmega128a_GLCD_KS0180.atsln". 
 * 4. Check the configuration of project based on the instruction from Sisoog web site.  
 * 5. build the project and then load it.  
 * Created: 2022-08-11 23:03:55
 * Author : Ayoub
 */ 


#include <u8g2.h>
#include <util/delay.h>
#include <u8x8_avr.h>
#include <avr/power.h>
/************************************************************************/
/* Project definition                                                   */
/************************************************************************/
#define P_CPU_NS (1000000000UL / F_CPU)

/************************************************************************/
/* Functions prototypes                                                  */
/************************************************************************/
uint8_t u8x8_avr_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

/************************************************************************/
/* Global variables declaration.                                         */
/************************************************************************/
u8g2_t u8g2;


int main(void)
{
   
   /************************************************************************/
	/* Initialised the back light for LCD and turn it on.                    */
	/************************************************************************/
	DDRG  |=(1<<DDRG0);
	PORTG |= (1<<PORTG0);
	
	
	/************************************************************************/
	/* Select set up function for driver KS0108.                            */
	/************************************************************************/
	u8g2_Setup_ks0108_128x64_f(&u8g2, U8G2_R0, u8x8_byte_ks0108, u8x8_avr_gpio_and_delay);
	u8g2_InitDisplay(&u8g2);
	u8g2_SetPowerSave(&u8g2, 0);
	/************************************************************************/
	/* full buffer example                                                  */
	/************************************************************************/
	u8g2_ClearBuffer(&u8g2);

	/************************************************************************/
	/* Set the font and clear display screen.                               */
	/************************************************************************/
	u8g2_SetFont(&u8g2,  u8g2_font_ncenB10_te  );
	u8g2_ClearDisplay(&u8g2); 
	
	/************************************************************************/
	/* Write some texts on the display.                                      */
	/************************************************************************/
	u8g2_DrawStr(&u8g2, 0, 15, "www.sisoog.com");
	u8g2_SendBuffer(&u8g2);
	u8g2_SetFont(&u8g2,  u8g2_font_ncenB08_te  );
	u8g2_DrawStr(&u8g2, 0, 32, "u8g2 on Atmega128A");
	u8g2_DrawStr(&u8g2, 0, 49, "with Atmel Studio 7");
	u8g2_SendBuffer(&u8g2);
	_delay_ms(1000);
	
	
	while(1)
	{
	}
}
// the template can be foun from: https://github.com/olikraus/u8g2/wiki/Porting-to-new-MCU-platform
uint8_t u8x8_avr_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
	// Re-use library for delays
	if (u8x8_avr_delay(u8x8, msg, arg_int, arg_ptr))
	return 1;
	
	switch(msg)
	{
		case U8X8_MSG_GPIO_AND_DELAY_INIT:  // called once during init phase of u8g2/u8x8
		DDRB = 0xFF;
		DDRE = 0xFF;
		
		case U8X8_MSG_DELAY_I2C:				  // arg_int is the I2C speed in 100KHz, e.g. 4 = 400 KHz
		break;							         // arg_int=1: delay by 5us, arg_int = 4: delay by 1.25us
		case U8X8_MSG_GPIO_D0:				    // D0 or SPI clock pin: Output level in arg_int
		if(arg_int)
		{
			PORTE |= (1<<PORTE0);
		}
		else
		{
			PORTE &= ~(1<<PORTE0);
		}
		//case U8X8_MSG_GPIO_SPI_CLOCK:
		break;
		case U8X8_MSG_GPIO_D1:				// D1 or SPI data pin: Output level in arg_int
		if(arg_int)
		{
			PORTE |= (1<<PORTE1);
		}
		else
		{
			PORTE &= ~(1<<PORTE1);
		}
		//case U8X8_MSG_GPIO_SPI_DATA:
		break;
		case U8X8_MSG_GPIO_D2:				// D2 pin: Output level in arg_int
		if(arg_int)
		{
			PORTE |= (1<<PORTE2);
		}
		else
		{
			PORTE &= ~(1<<PORTE2);
		}
		break;
		case U8X8_MSG_GPIO_D3:				// D3 pin: Output level in arg_int
		if(arg_int)
		{
			PORTE |= (1<<PORTE3);
		}
		else
		{
			PORTE &= ~(1<<PORTE3);
		}
		break;
		case U8X8_MSG_GPIO_D4:				// D4 pin: Output level in arg_int
		if(arg_int)
		{
			PORTE |= (1<<PORTE4);
		}
		else
		{
			PORTE &= ~(1<<PORTE4);
		}
		break;
		case U8X8_MSG_GPIO_D5:				// D5 pin: Output level in arg_int
		if(arg_int)
		{
			PORTE |= (1<<PORTE5);
		}
		else
		{
			PORTE &= ~(1<<PORTE5);
		}
		break;
		case U8X8_MSG_GPIO_D6:				// D6 pin: Output level in arg_int
		if(arg_int)
		{
			PORTE |= (1<<PORTE6);
		}
		else
		{
			PORTE &= ~(1<<PORTE6);
		}
		break;
		case U8X8_MSG_GPIO_D7:				// D7 pin: Output level in arg_int
		if(arg_int)
		{
			PORTE |= (1<<PORTE7);
		}
		else
		{
			PORTE &= ~(1<<PORTE7);
		}
		break;
		case U8X8_MSG_GPIO_E:				// E/WR pin: Output level in arg_int
		if(arg_int)
		{
			PORTB |= (1<<PORTB0);
		}
		else
		{
			PORTB &= ~(1<<PORTB0);
		}
		break;
		case U8X8_MSG_GPIO_CS:				// CS (chip select) pin: Output level in arg_int
		if(arg_int)
		{
			PORTB |= (1<<PORTB3);
		}
		else
		{
			PORTB &= ~(1<<PORTB3);
		}
		break;
		case U8X8_MSG_GPIO_DC:				// DC (data/cmd, A0, register select) pin: Output level in arg_int
		if(arg_int)
		{
			PORTB |= (1<<PORTB2);
		}
		else
		{
			PORTB &= ~(1<<PORTB2);
		}
		break;
		case U8X8_MSG_GPIO_RESET:			// Reset pin: Output level in arg_int
		break;
		case U8X8_MSG_GPIO_CS1:				// CS1 (chip select) pin: Output level in arg_int
		if(arg_int)
		{
			PORTB |= (1<<PORTB4);
		}
		else
		{
			
			PORTB &= ~(1<<PORTB4);
		}
		break;
		case U8X8_MSG_GPIO_CS2:				// CS2 (chip select) pin: Output level in arg_int
		if(arg_int)
		{
			PORTB |= (1<<PORTB5);
		}
		else
		{
			PORTB &= ~(1<<PORTB5);
		}
		break;
		default:
		u8x8_SetGPIOResult(u8x8, 1);			// default return value
		break;
	}
	return 1;
}
