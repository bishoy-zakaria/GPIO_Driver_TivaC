
#include "GPIO.h"
int main()
{
while (1)
{
Port_Init ( );	
Dio_WriteChannel (PORTB , PIN0, Pin_High);
Dio_WriteChannel (PORTB , PIN1, Pin_High);
}
}
