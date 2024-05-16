
#include"../../MCAL/DIO_V1/DIO_int.h"
#include"util/delay.h"
#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "IR_Sensor_CNF.h"
#include "IR_Sensor_int.h"

/***************************************************************************************/

void SENSOR_vidinit(void)
{
	//to make the pins output
	DIO_u8setPinDirection(SENSOR_PORT , LEFT_SENSOR_PIN   , INPUT);
	DIO_u8setPinDirection(SENSOR_PORT , RIGHT_SENSOR_PIN  , INPUT);
	DIO_u8setPinDirection(SENSOR_PORT , CENTER_SENSOR_PIN , INPUT);
}

/***************************************************************************************/
