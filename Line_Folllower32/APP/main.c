#include"util/delay.h"
#include"../MCAL/DIO_V1/DIO_int.h"
#include"../MCAL/DIO_V1/DIO_reg.h"
#include"../LIB/BIT_MATH.h"
#include"../LIB/STD_TYPES.h"
#include"../HAL/DC_Motors_Handler/DC_Motors_int.h"
#include"../HAL/IR_Sensor_Handler/IR_Sensor_int.h"
#include"../HAL/IR_Sensor_Handler/IR_Sensor_CNF.h"
#include"../MCAL/Timer_Counter_V1/Timer_Counter_int.h"
#include"../MCAL/Timer_Counter_V1/Timer_Counter_reg.h"
#include "avr/io.h"

#define training_Count 100
const f32 ALPHA = 0.8;
const f32 GAMMA = 0.8;
u8 Robot_CurrentState;    /*Variable to store the Current state indicator of the robot */
u8 Robot_Action_ToTake;
u8 Next_State;			/*Variable to store the next state of the robot*/
f32 Q_new,Q_old,Q_Max;
#define States_count 8		/*Variable to store the Number of states in the learning problem*/
#define Actions_count 4
f32 Q[States_count][Actions_count]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
u16 Rewards[States_count][Actions_count]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
u8 Actions[4] = {0, 1, 2, 3};



u8 LEFT_SENSOR_;
u8 RIGHT_SENSOR_;
u8 CENTER_SENSOR_;

int Get_stateNumber(void){


	int state_number;


	if ( (LEFT_SENSOR_== LOW) && (CENTER_SENSOR_== LOW) && (RIGHT_SENSOR_== LOW) )
	{
		state_number=0;
	}
	else if ( (LEFT_SENSOR_== LOW) && (CENTER_SENSOR_== LOW) && (RIGHT_SENSOR_== HIGH) )
	{
		state_number=1;
	}
	else if ( (LEFT_SENSOR_== LOW) && (CENTER_SENSOR_== HIGH) && (RIGHT_SENSOR_== LOW) )
	{
		state_number=2;
	}
	else if ( (LEFT_SENSOR_== LOW) && (CENTER_SENSOR_== HIGH) && (RIGHT_SENSOR_== HIGH) )
	{
		state_number=3;
	}
	else if ( (LEFT_SENSOR_== HIGH) && (CENTER_SENSOR_== LOW) && (RIGHT_SENSOR_== LOW) )
	{
		state_number=4;
	}
	else if ( (LEFT_SENSOR_== HIGH) && (CENTER_SENSOR_== LOW) && (RIGHT_SENSOR_== HIGH) )
	{
		state_number=5;
	}
	else if ( (LEFT_SENSOR_== HIGH) && (CENTER_SENSOR_== HIGH) && (RIGHT_SENSOR_== LOW) )
	{
		state_number=6;
	}
	else if ( (LEFT_SENSOR_== HIGH) && (CENTER_SENSOR_== HIGH) && (RIGHT_SENSOR_== HIGH) )
	{
		state_number=7;
	}
	return state_number;
}



float Get_max_Q (int stateNum)
{

	f32 maximum;
	int actionNum;
	maximum=Q[stateNum][0];
	for(actionNum=0; actionNum < 3 ; actionNum++ )
	{
		if(maximum<Q[stateNum][actionNum])
		{
			maximum=Q[stateNum][actionNum];
		}
	}
	return maximum;
}

int Get_max_Q_Index(int stateNum)
{
	int index;
	float max=Q[stateNum][0];
	int actionNum;
	for(actionNum=0;actionNum<3;actionNum++)
	{
		if(max < Q[stateNum][actionNum] )
		{
			max=Q[stateNum][actionNum];
			index=actionNum;
		}
	}
	return index;
}

void Update_Q(int next_state, int Action,  int Reward)
{
	Q_old = Q[Robot_CurrentState][Action];
	Q_Max = Get_max_Q( Get_stateNumber() );
	Q_new = ( ( 1-ALPHA ) * Q_old ) + ( ALPHA * ( Reward + ( GAMMA * Q_Max ) ) );
	Q[Robot_CurrentState][Action] = Q_new;
}

void forward (void){
	INPUTS_vidCommand( HIGH , LOW , HIGH , LOW );
	OCR0 = 150;
}
void stop (void){
	INPUTS_vidCommand( LOW , LOW , LOW , LOW );
	OCR0 = 0;

}
void left (void){
	INPUTS_vidCommand( HIGH , LOW , LOW , LOW );
	OCR0 = 150;

}
void right (void){
	INPUTS_vidCommand( LOW , LOW , HIGH , LOW );
	OCR0 = 150;

}


void Start_Robot_Testing(void)
{
	Robot_CurrentState = Get_stateNumber();
	Robot_Action_ToTake = Get_max_Q_Index(Robot_CurrentState);
	if(Robot_Action_ToTake==0)
	{
		forward();
		_delay_ms(1500);
		stop();
	}
	else if(Robot_Action_ToTake==1)
	{
		right();
		_delay_ms(1500);
		stop();

	}
	else if(Robot_Action_ToTake==2)
	{
		left();
		_delay_ms(1500);
		stop();
	}
	else if(Robot_Action_ToTake==3)
	{
		stop();
		_delay_ms(1500);
	}
}

void Start_Robot_Trainig(void){

	u8 training_LoopCount;	/*Variable to store the counter value in the training function loop*/

	for( training_LoopCount = 0 ; training_LoopCount < training_Count ; training_LoopCount++ )
	{
		u8 random_action;
		random_action=(u8)rand(); // output 0 , 1, 2, 3

		Robot_CurrentState=  Get_stateNumber();

		if(random_action==0)
		{
           forward();
		   stop();
			if( (LEFT_SENSOR_== LOW ) && (CENTER_SENSOR_== HIGH) && (RIGHT_SENSOR_== LOW) )
			{
				/*means that center reads black while left and right read white*/
				Rewards[Robot_CurrentState][random_action]= 5;
				Next_State= Get_stateNumber();
			Update_Q(Next_State, random_action , Rewards[Robot_CurrentState][random_action]);				}
			else
			{
				Rewards[Robot_CurrentState][random_action]= -1;

			}
		}
		else if(random_action==1)
		{
			right();
			stop();
			if( ( (LEFT_SENSOR_== LOW) && (CENTER_SENSOR_== HIGH) && (RIGHT_SENSOR_== HIGH) )
			||( (LEFT_SENSOR_== LOW) && (CENTER_SENSOR_==LOW) && (RIGHT_SENSOR_==HIGH) ) )
			{
				/*means that right reads black while left and center reads white or right and center read black so it should turn right*/
				Rewards[Robot_CurrentState][random_action]=5;
				Next_State= Get_stateNumber();
				Update_Q(Next_State, random_action , Rewards[Robot_CurrentState][random_action]);
			}
			else
			{
				Rewards[Robot_CurrentState][random_action]= -1;

			}
		}

		else if(random_action==2)
		{
			left();
			stop();
			if( ( (LEFT_SENSOR_== HIGH) && (CENTER_SENSOR_==LOW) && (RIGHT_SENSOR_==LOW) ) ||
			 ( (LEFT_SENSOR_==HIGH) && (CENTER_SENSOR_==HIGH) && (RIGHT_SENSOR_==LOW) ) )
			{
				/*means that left reads black while center and right read white or left and center read black so it should turn left*/
				Rewards[Robot_CurrentState][random_action]= 5;
				Next_State= Get_stateNumber();
				Update_Q(Next_State, random_action , Rewards[Robot_CurrentState][random_action]);
			}
			else
			{
				Rewards[Robot_CurrentState][random_action]= -1;

			}
		}
		else if(random_action==3)
		{
			stop();
			/*means that all sensors read black*/
			if((LEFT_SENSOR_== HIGH) && (CENTER_SENSOR_==HIGH) && (RIGHT_SENSOR_==HIGH))
			{
				Rewards[Robot_CurrentState][random_action]= 5;
				Next_State=Get_stateNumber();
				Update_Q(Next_State, random_action , Rewards[Robot_CurrentState][random_action]);
			}
			else
			{
				Rewards[Robot_CurrentState][random_action]= -1;

			}
		}
	}
}



int main(void)
{

	u8 LEFT_SENSOR_;
	u8 RIGHT_SENSOR_;
	u8 CENTER_SENSOR_;

	DC_MOTORS_vidinit();

	SENSOR_vidinit();


		DIO_u8setPinDirection(PORT_B , PIN_3 , OUTPUT); // output to motor driver

		Timer_Voidinit();
		//select compare o/p Mode ==> clear on compare match and set on top
		TCCR0 |= (1<<COM01);
		//set initial value in OCR0 = 0 (duty cycle = 0%)
		OCR0 = 0;
		Timer_voidON();

	/**********************************************************************************************/
	while(1)
	{

		DIO_u8getPinValue(SENSOR_PORT , LEFT_SENSOR_PIN    , &LEFT_SENSOR_);
		DIO_u8getPinValue(SENSOR_PORT , RIGHT_SENSOR_PIN   , &RIGHT_SENSOR_);
		DIO_u8getPinValue(SENSOR_PORT , CENTER_SENSOR_PIN  , &CENTER_SENSOR_);

		Start_Robot_Trainig();

		Start_Robot_Testing();


	}
}
