#include "GPIO_Cfg.h"
extern GPIO_Cfg_typ GPIO_Cfg [channels_num];
GPIO_Cfg_typ GPIO_arr[channels_num]; // Global array for GPIO
/* ********************** GPIO_API ********************************* */
void Port_Init ( void )
{	  
	uint8 i=0;
  for(i=0 ; i<channels_num ; i++)
     {
			 GPIO_arr[i]= GPIO_Cfg[i]; // take all the configuration from the user to the global pointer
		 }
  for(i=0 ; i<channels_num ; i++)
		 {
			 if(GPIO_arr[i].GPIO_port == PORTA)
			 {
				 GPIO_Lock(PORTA) |= 0x4C4F434B; // Key of GPIO
				 if(GPIO_arr[i].PortPinDirection == pin_OutPut)       // Set the direction as out put for this bit
         SET_BIT(GPIO_DIR(PORTA) , GPIO_arr[i].GPIO_pin);				 
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_2m)   // Set this bit out put as 2mA
				 SET_BIT(GPIODR2R(PORTA) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_4m)   // Set this bit out put as 4mA
				 SET_BIT(GPIODR4R(PORTA) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_8m)   // Set this bit out put as 8mA
				 SET_BIT(GPIODR8R(PORTA) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Pull_Down_Res) // use pull down ressestor
				 SET_BIT(GPIOPDR(PORTA) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Pull_Up_Res) // use pull Up ressestor
				 SET_BIT(GPIOPUR(PORTA) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Drain_Source) // use Drain_Source
				 SET_BIT(GPIOODR(PORTA) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].GPIO_pin == PIN0)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTA) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTA) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTA) |= 1;
					 }
					 else if (GPIO_arr[i].PortPinMode == CAN)
					 {
						 SET_BIT(GPIODEN(PORTA) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTA) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTA) |= 8;
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN1)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 
						 SET_BIT(GPIODEN(PORTA) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTA) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTA) |= (1<<4);
					 }
					 else if (GPIO_arr[i].PortPinMode == CAN)
					 {
						 SET_BIT(GPIODEN(PORTA) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTA) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTA) |= (8<<4);
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN2)
				 {
					 if(GPIO_arr[i].PortPinMode == SSI)
					 {
						 SET_BIT(GPIODEN(PORTA) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTA) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTA) |= (2<<8);
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN3)
				 {
					 if(GPIO_arr[i].PortPinMode == SSI)
					 {
						 SET_BIT(GPIODEN(PORTA) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTA) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTA) |= (2<<12);
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN4)
				 {
					 if(GPIO_arr[i].PortPinMode == SSI)
					 {
						 SET_BIT(GPIODEN(PORTA) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTA) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTA) |= (2<<16);
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN5)
				 {
					 if(GPIO_arr[i].PortPinMode == SSI)
					 {
						 SET_BIT(GPIODEN(PORTA) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTA) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTA) |= (2<<20);
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN6)
				 {
					 if(GPIO_arr[i].PortPinMode == I2C)
					 {
						 SET_BIT(GPIODEN(PORTA) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTA) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTA) |= (3<<24);
					 }
					 else if (GPIO_arr[i].PortPinMode == PWM)
					 {
						 SET_BIT(GPIODEN(PORTA) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTA) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTA) |= (5<<24);
					 }
				 }
				  else if(GPIO_arr[i].GPIO_pin == PIN7)
				 {
					 if(GPIO_arr[i].PortPinMode == I2C)
					 {
						 SET_BIT(GPIODEN(PORTA) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTA) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTA) |= (3<<28);
					 }
					 else if (GPIO_arr[i].PortPinMode == PWM)
					 {
						 SET_BIT(GPIODEN(PORTA) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTA) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTA) |= (5<<28);
					 }
				 }
			 }
			 else if(GPIO_arr[i].GPIO_port == PORTB)
			 {
				 GPIO_Lock(PORTB) |= 0x4C4F434B; // Key of GPIO
				 if(GPIO_arr[i].PortPinDirection == pin_OutPut)       // Set the direction as out put for this bit
         SET_BIT(GPIO_DIR(PORTB) , GPIO_arr[i].GPIO_pin);				 
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_2m)   // Set this bit out put as 2mA
				 SET_BIT(GPIODR2R(PORTB) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_4m)   // Set this bit out put as 4mA
				 SET_BIT(GPIODR4R(PORTB) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_8m)   // Set this bit out put as 8mA
				 SET_BIT(GPIODR8R(PORTB) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Pull_Down_Res) // use pull down ressestor
				 SET_BIT(GPIOPDR(PORTB) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Pull_Up_Res) // use pull Up ressestor
				 SET_BIT(GPIOPUR(PORTB) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Drain_Source) // use Drain_Source
				 SET_BIT(GPIOODR(PORTB) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].GPIO_pin == PIN0)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTB) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTB) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTB) |= 1;
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN1)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 
						 SET_BIT(GPIODEN(PORTB) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTB) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTB) |= (1<<4);
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN2)
				 {
					 if(GPIO_arr[i].PortPinMode == I2C)
					 {
						 SET_BIT(GPIODEN(PORTB) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTB) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTB) |= (3<<8);
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN3)
				 {
					 if(GPIO_arr[i].PortPinMode == I2C)
					 {
						 SET_BIT(GPIODEN(PORTB) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTB) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTB) |= (3<<12);
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN4)
				 {
					 if(GPIO_arr[i].PortPinMode == PWM)
					 {
						 SET_BIT(GPIODEN(PORTB) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTB) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTB) |= (4<<16);
					 }
					 else if(GPIO_arr[i].PortPinMode == CAN)
					 {
						 SET_BIT(GPIODEN(PORTB) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTB) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTB) |= (8<<16);
					 } 
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN5)
				 {
					 if(GPIO_arr[i].PortPinMode == PWM)
					 {
						 SET_BIT(GPIODEN(PORTB) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTB) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTB) |= (4<<20);
					 }
					 else if(GPIO_arr[i].PortPinMode == CAN)
					 {
						 SET_BIT(GPIODEN(PORTB) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTB) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTB) |= (8<<20);
					 } 
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN6)
				 {
					 if(GPIO_arr[i].PortPinMode == PWM)
					 {
						 SET_BIT(GPIODEN(PORTB) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTB) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTB) |= (4<<24);
					 }
				 }
				  else if(GPIO_arr[i].GPIO_pin == PIN7)
				 {
					 if(GPIO_arr[i].PortPinMode == PWM)
					 {
						 SET_BIT(GPIODEN(PORTB) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTB) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTB) |= (4<<28);
					 }
				 }
			 }
	     else if(GPIO_arr[i].GPIO_port == PORTC)
			 {
				 GPIO_Lock(PORTC) |= 0x4C4F434B; // Key of GPIO
				 if(GPIO_arr[i].PortPinDirection == pin_OutPut)       // Set the direction as out put for this bit
         SET_BIT(GPIO_DIR(PORTC) , GPIO_arr[i].GPIO_pin);				 
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_2m)   // Set this bit out put as 2mA
				 SET_BIT(GPIODR2R(PORTC) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_4m)   // Set this bit out put as 4mA
				 SET_BIT(GPIODR4R(PORTC) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_8m)   // Set this bit out put as 8mA
				 SET_BIT(GPIODR8R(PORTC) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Pull_Down_Res) // use pull down ressestor
				 SET_BIT(GPIOPDR(PORTC) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Pull_Up_Res) // use pull Up ressestor
				 SET_BIT(GPIOPUR(PORTC) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Drain_Source) // use Drain_Source
				 SET_BIT(GPIOODR(PORTC) , GPIO_arr[i].GPIO_pin);
				 
			  if(GPIO_arr[i].GPIO_pin == PIN4)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTC) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTC) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTC) |= (1<<16);
					 }
					 else if(GPIO_arr[i].PortPinMode == PWM)
					 {
						 SET_BIT(GPIODEN(PORTC) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTC) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTC) |= (4<<16);
					 } 
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN5)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTC) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTC) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTC) |= (1<<20);
					 }
					 else if(GPIO_arr[i].PortPinMode == PWM)
					 {
						 SET_BIT(GPIODEN(PORTC) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTC) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTC) |= (4<<20);
					 } 
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN6)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTC) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTC) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTC) |= (1<<24);
					 }
				 }
				  else if(GPIO_arr[i].GPIO_pin == PIN7)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTC) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTC) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTC) |= (1<<28);
					 }
				 }
			 }				 
			 else if(GPIO_arr[i].GPIO_port == PORTD)
			 {
				 GPIO_Lock(PORTD) |= 0x4C4F434B; // Key of GPIO
				 if(GPIO_arr[i].PortPinDirection == pin_OutPut)       // Set the direction as out put for this bit
         SET_BIT(GPIO_DIR(PORTD) , GPIO_arr[i].GPIO_pin);				 
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_2m)   // Set this bit out put as 2mA
				 SET_BIT(GPIODR2R(PORTD) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_4m)   // Set this bit out put as 4mA
				 SET_BIT(GPIODR4R(PORTD) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_8m)   // Set this bit out put as 8mA
				 SET_BIT(GPIODR8R(PORTD) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Pull_Down_Res) // use pull down ressestor
				 SET_BIT(GPIOPDR(PORTD) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Pull_Up_Res) // use pull Up ressestor
				 SET_BIT(GPIOPUR(PORTD) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Drain_Source) // use Drain_Source
				 SET_BIT(GPIOODR(PORTD) , GPIO_arr[i].GPIO_pin);
				 
				 if(GPIO_arr[i].GPIO_pin == PIN0)
				 {
					 if(GPIO_arr[i].PortPinMode == I2C)
					 {
						 SET_BIT(GPIODEN(PORTD) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTD) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTD) |= 3;
					 }
					 else if (GPIO_arr[i].PortPinMode == PWM)
					 {
						 SET_BIT(GPIODEN(PORTD) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTD) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTD) |= 4;
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN1)
				 {
					 if(GPIO_arr[i].PortPinMode == I2C)
					 {
						 SET_BIT(GPIODEN(PORTD) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTD) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTD) |= (3<<4);
					 }
					 else if (GPIO_arr[i].PortPinMode == PWM)
					 {
						 SET_BIT(GPIODEN(PORTD) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTD) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTD) |= (4<<4);
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN2)
				 {
					 if(GPIO_arr[i].PortPinMode == I2C)
					 {
						 SET_BIT(GPIODEN(PORTD) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTD) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTD) |= (3<<8);
					 }
				 }
			  else if(GPIO_arr[i].GPIO_pin == PIN4)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTD) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTD) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTD) |= (1<<16);
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN5)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTD) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTD) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTD) |= (1<<20);
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN6)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTD) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTD) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTD) |= (1<<24);
					 }
				 }
				  else if(GPIO_arr[i].GPIO_pin == PIN7)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTD) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTD) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTD) |= (1<<28);
					 }
				 }
			 }
			 else if(GPIO_arr[i].GPIO_port == PORTE)
			 { GPIO_E_Lock(PORTE) |= 0x4C4F434B; // Key of GPIO
				 if(GPIO_arr[i].PortPinDirection == pin_OutPut)       // Set the direction as out put for this bit
         SET_BIT(GPIO_DIR(PORTE) , GPIO_arr[i].GPIO_pin);				 
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_2m)   // Set this bit out put as 2mA
				 SET_BIT(GPIODR2R(PORTE) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_4m)   // Set this bit out put as 4mA
				 SET_BIT(GPIODR4R(PORTE) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_8m)   // Set this bit out put as 8mA
				 SET_BIT(GPIODR8R(PORTE) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Pull_Down_Res) // use pull down ressestor
				 SET_BIT(GPIOPDR(PORTE) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Pull_Up_Res) // use pull Up ressestor
				 SET_BIT(GPIOPUR(PORTE) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Drain_Source) // use Drain_Source
				 SET_BIT(GPIOODR(PORTE) , GPIO_arr[i].GPIO_pin);
				 
				 if(GPIO_arr[i].GPIO_pin == PIN0)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTE) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTE) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTE) |= 1;
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN1)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTE) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTE) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTE) |= (1<<4);
					 }
				 }
			  else if(GPIO_arr[i].GPIO_pin == PIN4)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTE) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTE) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTE) |= (1<<16);
					 }
					 else if(GPIO_arr[i].PortPinMode == I2C)
					 {
						 SET_BIT(GPIODEN(PORTE) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTE) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTE) |= (3<<16);
					 }
					 else if (GPIO_arr[i].PortPinMode == PWM)
					 {
						 SET_BIT(GPIODEN(PORTE) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTE) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTE) |= (4<<16);
					 }
					 else if(GPIO_arr[i].PortPinMode == CAN)
					 {
						 SET_BIT(GPIODEN(PORTE) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTE) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTE) |= (8<<16);
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN5)
				 {
					if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTE) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTE) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTE) |= (1<<20);
					 }
					 else if(GPIO_arr[i].PortPinMode == I2C)
					 {
						 SET_BIT(GPIODEN(PORTE) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTE) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTE) |= (3<<20);
					 }
					 else if (GPIO_arr[i].PortPinMode == PWM)
					 {
						 SET_BIT(GPIODEN(PORTE) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTE) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTE) |= (4<<20);
					 }
					 else if(GPIO_arr[i].PortPinMode == CAN)
					 {
						 SET_BIT(GPIODEN(PORTE) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTE) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTE) |= (8<<20);
					 }
				 }
			 }
			 else if(GPIO_arr[i].GPIO_port == PORTF)
			 {GPIO_E_Lock(PORTF) |= 0x4C4F434B; // Key of GPIO
				 if(GPIO_arr[i].PortPinDirection == pin_OutPut)       // Set the direction as out put for this bit
         SET_BIT(GPIO_DIR(PORTF) , GPIO_arr[i].GPIO_pin);				 
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_2m)   // Set this bit out put as 2mA
				 SET_BIT(GPIODR2R(PORTF) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_4m)   // Set this bit out put as 4mA
				 SET_BIT(GPIODR4R(PORTF) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinOutputCurrent == Current_8m)   // Set this bit out put as 8mA
				 SET_BIT(GPIODR8R(PORTF) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Pull_Down_Res) // use pull down ressestor
				 SET_BIT(GPIOPDR(PORTF) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Pull_Up_Res) // use pull Up ressestor
				 SET_BIT(GPIOPUR(PORTF) , GPIO_arr[i].GPIO_pin);
				 if(GPIO_arr[i].PortPinInternalAttach == Drain_Source) // use Drain_Source
				 SET_BIT(GPIOODR(PORTF) , GPIO_arr[i].GPIO_pin);
				 
				 if(GPIO_arr[i].GPIO_pin == PIN0)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTF) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTF) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTF) |= 1;
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN1)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTF) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTF) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTF) |= (1<<4);
					 }
				 }
			  else if(GPIO_arr[i].GPIO_pin == PIN4)
				 {
					 if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTF) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTF) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTF) |= (1<<16);
					 }
					 else if(GPIO_arr[i].PortPinMode == I2C)
					 {
						 SET_BIT(GPIODEN(PORTF) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTF) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTF) |= (3<<16);
					 }
					 else if (GPIO_arr[i].PortPinMode == PWM)
					 {
						 SET_BIT(GPIODEN(PORTF) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTF) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTF) |= (4<<16);
					 }
					 else if(GPIO_arr[i].PortPinMode == CAN)
					 {
						 SET_BIT(GPIODEN(PORTF) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTF) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTF) |= (8<<16);
					 }
				 }
				 else if(GPIO_arr[i].GPIO_pin == PIN5)
				 {
					if(GPIO_arr[i].PortPinMode == UART)
					 {
						 SET_BIT(GPIODEN(PORTF) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTF) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTF) |= (1<<20);
					 }
					 else if(GPIO_arr[i].PortPinMode == I2C)
					 {
						 SET_BIT(GPIODEN(PORTF) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTF) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTF) |= (3<<20);
					 }
					 else if (GPIO_arr[i].PortPinMode == PWM)
					 {
						 SET_BIT(GPIODEN(PORTF) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTF) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTF) |= (4<<20);
					 }
					 else if(GPIO_arr[i].PortPinMode == CAN)
					 {
						 SET_BIT(GPIODEN(PORTF) , GPIO_arr[i].GPIO_pin);
						 SET_BIT(GPIOAFSEL(PORTF) , GPIO_arr[i].GPIO_pin);
					   GPIOPCTL(PORTF) |= (8<<20);
					 }
}}}}
GPIO_LevelType Dio_ReadChannel (GPIO_ChannelType PORTId ,GPIO_ChannelType ChannelId )
{
	uint8 buffer =0;
	if (PORTId == PORTE || PORTId == PORTF)
		buffer= GET_BIT(GPIOE_DATA(PORTId), ChannelId);
	else
	  buffer=GET_BIT(GPIO_DATA(PORTId), ChannelId);
	return buffer;
}
void Dio_WriteChannel (GPIO_ChannelType PORTId ,GPIO_ChannelType ChannelId , GPIO_LevelType Level)
{ 
	if(Level == Pin_High)
	{
  if (PORTId == PORTE || PORTId == PORTF)
		SET_BIT(GPIOE_DATA(PORTId), ChannelId);
	else
	  SET_BIT(GPIO_DATA(PORTId), ChannelId);
  }
	else
		{
  if (PORTId == PORTE || PORTId == PORTF)
		CLR_BIT(GPIOE_DATA(PORTId), ChannelId);
	else
	  CLR_BIT(GPIO_DATA(PORTId), ChannelId);
    }
}
void Dio_WritePort (GPIO_ChannelType PortId , GPIO_LevelType Level)
{
	if(Level == Pin_High)
	{
  if (PortId == PORTE || PortId == PORTF)
	GPIO_DATA(PortId)=0xFFFFFFFF;
	else
	  GPIOE_DATA(PortId)=0xFFFFFFFF;
  }
	else
		{
  if (PortId == PORTE || PortId == PORTF)
	GPIO_DATA(PortId)=0x00;
	else
	  GPIOE_DATA(PortId)=0x00;
    }
}
void Dio_FlipChannel (GPIO_ChannelType PORTId,GPIO_ChannelType ChannelId)
{
  if (PORTId == PORTE || PORTId == PORTF)
		Toggle_BIT(GPIOE_DATA(PORTId), ChannelId);
	else
	  Toggle_BIT(GPIO_DATA(PORTId), ChannelId);
}
