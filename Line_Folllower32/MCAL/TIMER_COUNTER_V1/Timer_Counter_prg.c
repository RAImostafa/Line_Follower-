
#include "Timer_Counter_reg.h"
#include "Timer_Counter_int.h"
#include"../../LIB/STD_TYPES.h"


#define BIT_0          	    	(u8)0
#define BIT_1          	    	(u8)1
#define BIT_2          	    	(u8)2
#define BIT_3          	    	(u8)3
#define BIT_4          	    	(u8)4
#define BIT_5          	    	(u8)5
#define BIT_6          	    	(u8)6
#define BIT_7          	    	(u8)7

#define OPERATION_MODE_TIMER0_CLR_MSK  (u8)0b10110111
#define PRESCALER_TIMER0_CLR_MSK       (u8)0b11111000
#define Interrupt_TIMER0_CLR_MSK       (u8)0b11111100

typedef enum {
	Normal_op = 0b10000000,
	PWM_op = 0b00001000,
	CTC_op = 0b01000000,
	Fast_PWM_op = 0b01001000
}Timer_Counter_Mode_of_Operation_e;

typedef enum {
	No_clock =0, //(Timer/Counter stopped)
	No_Prescaler,
	Prescaler_8,
	Prescaler_64,
	Prescaler_256,
	Prescaler_1024,
	Ext_clk_falling_edge,
	Ext_clk_rising_edge,
}Timer_Counter_Clock_select_e;

typedef enum {
	Overflow_Interrupt_Enable = 1,
	Output_Compare_Match_Interrupt_Enable
}Timer_Counter_Interrupt_e;


void Timer_Voidinit(void)
{
	/*For setting Mode of operation*/
	//READ
	volatile u8 CPY_REG = TCCR0_REG ;
	//Modify For Mode
	CPY_REG &= OPERATION_MODE_TIMER0_CLR_MSK;
	CPY_REG |= Fast_PWM_op;
	//Write For Mode
	TCCR0_REG = CPY_REG;
	/*Interrupt enable*/
	/*
	CPY_REG = TIMSK_REG;
	CPY_REG &= Interrupt_TIMER0_CLR_MSK;
	CPY_REG |= Overflow_Interrupt_Enable;
	TIMSK_REG = CPY_REG;
	*/
}

void Timer_voidON(void)
{
	//READ
	volatile u8 CPY_REG = TCCR0_REG ;
	//Modify For pre-scaler
	CPY_REG &= PRESCALER_TIMER0_CLR_MSK;
	CPY_REG |= No_Prescaler;
	//Write For Mode and pre_scaler
	TCCR0_REG = CPY_REG;
}


