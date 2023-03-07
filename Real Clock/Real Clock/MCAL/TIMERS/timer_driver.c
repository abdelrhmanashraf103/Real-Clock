/*
 * timer_driver.c
 *
 * Created: 3/2/2022 :44:59 PM
 *  Author: sharasa
 */
#include "timer_driver.h"


void timer2_overflow_init_interrupt(void)
{
	/* select timer clock */
	SET_BIT(ASSR,AS2);
	/* select timer pre scalar */
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	/* enable interrupt*/
	sei();
	SET_BIT(TIMSK,TOIE2);
}

void timer0_initializeCTC(void)
{
	//Config OCR0
	//OCR0 = the value to compare with
	OCR0 = 78; //to achieve tick equal to 10 msec
	
	//Set timer mode
	//Set the mode as Compare match
	SET_BIT(TCCR0, WGM01);
	CLR_BIT(TCCR0, WGM00);
	
	//Configure clock
	//set as clk/1024
	SET_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
	
	//Enable global interrupts
	sei();
	
	//Enable timer 0 interrupt for compare match
	SET_BIT(TIMSK, OCIE0);
}

void timer0_stop(void)
{
	//disable the clock to stop the counter
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
}
void timer_initializefastpwm(void)
{
	//Config OCR0
	//OCR0 = the value to compare with
	OCR0 = 128;
	
	//Set timer mode
	//adjust fast pulse width modulation mode
	SET_BIT(TCCR0, WGM00); 
	SET_BIT(TCCR0, WGM01);
	
	//Enable global interrupts
	sei();
	
	SET_BIT(TCCR0, COM01); //adjust non inverting mode
	
	//Enable timer0 interrupt for overflow mode
	SET_BIT(TIMSK,TOIE0);
	
	//Configure clock
	//set as clk/1024
	SET_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
}
void change_dutycycle(float64 duty)
{
	OCR0 = (duty / 100) * 256;//Set the OCR0 depending on the duty percentage
}

