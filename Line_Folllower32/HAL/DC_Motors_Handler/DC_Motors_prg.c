
#include"../../MCAL/DIO_V1/DIO_int.h"
#include"util/delay.h"
#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DC_Motors_CNF.h"
#include "DC_Motors_int.h"

/***************************************************************************************/

void DC_MOTORS_vidinit(void)
{
	//to make the pins output
	DIO_u8setPinDirection(DC_MOTORS_INPUT_PORT , INPUT_1 , OUTPUT);
	DIO_u8setPinDirection(DC_MOTORS_INPUT_PORT , INPUT_2 , OUTPUT);
	DIO_u8setPinDirection(DC_MOTORS_INPUT_PORT , INPUT_3 , OUTPUT);
	DIO_u8setPinDirection(DC_MOTORS_INPUT_PORT , INPUT_4 , OUTPUT);
}

/***************************************************************************************/

void INPUTS_vidCommand(u8 Copy_u8cmd1,u8 Copy_u8cmd2,u8 Copy_u8cmd3,u8 Copy_u8cmd4 )
{
	DIO_u8setPinValue(DC_MOTORS_INPUT_PORT , INPUT_1 , Copy_u8cmd1);
	DIO_u8setPinValue(DC_MOTORS_INPUT_PORT , INPUT_2 , Copy_u8cmd2);
	DIO_u8setPinValue(DC_MOTORS_INPUT_PORT , INPUT_3 , Copy_u8cmd3);
	DIO_u8setPinValue(DC_MOTORS_INPUT_PORT , INPUT_4 , Copy_u8cmd4);

}

/***************************************************************************************/
