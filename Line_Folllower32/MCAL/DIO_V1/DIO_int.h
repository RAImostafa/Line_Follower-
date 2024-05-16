#ifndef LIB_DIO_INT_H_
#define LIB_DIO_INT_H_
#include"../../LIB/STD_TYPES.h"
/* NOTE ALT+ Shift + a to select and write for the whole column*/
#define PORT_A         		(u8)0
#define PORT_B         		(u8)1
#define PORT_C         		(u8)2
#define PORT_D         		(u8)3
//***************************************************************************************//
#define PIN_0          		(u8)0
#define PIN_1          		(u8)1
#define PIN_2          		(u8)2
#define PIN_3          		(u8)3
#define PIN_4          		(u8)4
#define PIN_5          		(u8)5
#define PIN_6          		(u8)6
#define PIN_7          		(u8)7
//***************************************************************************************//
//For 1 pin
#define INPUT          		(u8)0
#define OUTPUT         		(u8)1
//***************************************************************************************//
//For 1 pin
#define LOW                 (u8)0
#define HIGH                (u8)1
//***************************************************************************************//
//for the whole Port
#define FULL_INPUT          (u8)0X00
#define FULL_OUTPUT         (u8)0xff
//***************************************************************************************//
//for the whole Port
#define FULL_LOW            (u8)0X00
#define FULL_HIGH           (u8)0xff
//***************************************************************************************//

//Pin by pin
u8 DIO_u8setPinDirection(u8 Copy_u8port , u8 Copy_u8pin , u8 Copy_u8direction);
u8 DIO_u8setPinValue(u8 Copy_u8port , u8 Copy_u8pin , u8 Copy_u8value);
u8 DIO_u8getPinValue(u8 Copy_u8port , u8 Copy_u8pin , u8 * Copy_u8pValue);

#endif /* LIB_DIO_INT_H_ */
