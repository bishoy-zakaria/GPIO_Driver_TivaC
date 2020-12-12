#ifndef GPIO_H
#define GPIO_H
#include "MCU.h"

typedef uint8 GPIO_ChannelType;
typedef uint8 GPIO_PortType;
typedef uint8 GPIO_LevelType;
typedef uint8 Port_PinDirectionType;
typedef uint8 Port_PinModeType;
typedef uint8 Port_PinInternalAttachType;
typedef uint8 Port_PinOutputCurrentType;
typedef uint8 Port_ConfigType;
/* **************************************************** */
typedef struct
{
 GPIO_PortType GPIO_port;
 GPIO_ChannelType GPIO_pin;
 Port_PinDirectionType PortPinDirection;
 Port_PinModeType PortPinMode;
 GPIO_LevelType PortPinLevelValue;
 Port_PinInternalAttachType PortPinInternalAttach;
 Port_PinOutputCurrentType PortPinOutputCurrent;
}GPIO_Cfg_typ;

/* **************************************************** */
#define PORTA  0
#define PORTB  1
#define PORTC  2
#define PORTD  3
#define PORTE  4
#define PORTF  5
/* **************************************************** */
#define PIN0   0   
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7
/* ***************************************************** */
#define pin_OutPut        0
#define Pin_InPut         1
/* ***************************************************** */
#define Pin_Low           0
#define Pin_High          1
/* ***************************************************** */
#define Port_Low          0
#define Port_High         0xFF
/* ****************** Current types ******************* */
#define Current_2m          0
#define Current_4m          1
#define Current_8m          2
/* **************************************************** */
#define Pull_Down_Res              1
#define Pull_Up_Res                2
#define Drain_Source               3
/* ***************************************************** */
void Port_Init ( void );
GPIO_LevelType Dio_ReadChannel (GPIO_ChannelType PORTId ,GPIO_ChannelType ChannelId );
void Dio_WriteChannel (GPIO_ChannelType PORTId ,GPIO_ChannelType ChannelId , GPIO_LevelType Level);
void Dio_WritePort (GPIO_ChannelType PortId , GPIO_LevelType Level);
void Dio_FlipChannel (GPIO_ChannelType PORTId,GPIO_ChannelType ChannelId);

#endif
