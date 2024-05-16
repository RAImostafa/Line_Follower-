
#ifndef MCAL_TIMER_COUNTER_V1_TIMER_COUNTER_REG_H_
#define MCAL_TIMER_COUNTER_V1_TIMER_COUNTER_REG_H_

/*Timer 0*/
/*Timer/Counter Control Register*/
#define TCCR0_REG                *((volatile u8*)0x53)
/*Timer/Counter Register*/
#define TCNT0_REG                *((volatile u8*)0x52)
/*Output Compare Register*/
#define OCR0_REG                 *((volatile u8*)0x5C)

//***************************************************************************************//

/*Timer 1*/
/* Timer/Counter1 Control Register A */
#define TCCR1A_REG               *((volatile u8*)0x4F)
/*Timer/Counter1 Control Register B */
#define TCCR1B_REG               *((volatile u8*)0x4E)
/*Timer/Counter1 */
#define TCNT1H_REG               *((volatile u8*)0x4D)
#define TCNT1L_REG               *((volatile u8*)0x4C)
/*Output Compare Register 1 A*/
#define OCR1AH_REG               *((volatile u8*)0x4B)
#define OCR1AL_REG               *((volatile u8*)0x4A)
/*Output Compare Register 1 B*/
#define OCR1BH_REG               *((volatile u8*)0x49)
#define OCR1BL_REG               *((volatile u8*)0x48)
/*Input Capture Register 1 */
#define ICR1H_REG                *((volatile u8*)0x47)
#define ICR1L_REG                *((volatile u8*)0x46)

//***************************************************************************************//

/*TIMER 2*/
/*Timer/Counter Control Register */
#define TCCR2_REG                *((volatile u8*)0x45)
/*Timer/Counter Register*/
#define TCNT2_REG                *((volatile u8*)0x44)
/*Output Compare Register*/
#define OCR2_REG                 *((volatile u8*)0x43)
/*Asynchronous Status Register */
#define ASSR_REG                 *((volatile u8*)0x42)

//***************************************************************************************//


/*Timer/Counter Interrupt Mask Register */
#define TIMSK_REG                *((volatile u8*)0x59)

/* Timer/Counter Interrupt Flag Register */
#define TIFR_REG                 *((volatile u8*)0x58)

/* Special Function IO Register */
#define SFIOR_REG                *((volatile u8*)0x50)

#endif /* MCAL_TIMER_COUNTER_V1_TIMER_COUNTER_REG_H_ */
