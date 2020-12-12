#ifndef GPIO_Cfg_H
#define GPIO_Cfg_H
#include "GPIO.h"

#define channels_num 2

GPIO_Cfg_typ GPIO_Cfg [channels_num] = { //{PORT  ,  PIN   ,    DIR     ,   MODE  ,   Level  ,     Internal_RES     ,   OUT_Current}
                                           {PORTB ,  PIN0  , pin_OutPut ,   GPIO   , Pull_Down_Res , Current_4m  },
																					 {PORTB ,  PIN1  , pin_OutPut ,   GPIO  , Pull_Down_Res , Current_4m  }
                                       };	 //this will take from user in the application.


#endif
