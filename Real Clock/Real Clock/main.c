/*
 * Real Clock.c
 *
 * Created: 19/02/2023 10:26:56 م
 * Author : Abdelrhman Ashraf
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "MCAL/DIO/DIO.h"
#include "HAL/7 SEGMENT/seven segment.h"
#include "HAL/KEYPAD/keypad_driver.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/TIMERS/timer_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>


volatile uint8 seconds_counter=0;
uint8 minutes_counter=0;
uint8 hours_counter =0;

uint8 key_pressed;
uint8 left_digit;
uint8 right_digit;
int main(void)
{
	LCD_vInit();
	keypad_vInit();
	seven_seg_vinit(PORT_B);
	timer2_overflow_init_interrupt();
	SET_BIT(DDRC,0);
	SET_BIT(DDRC,1);
	SET_BIT(DDRC,2);
	SET_BIT(DDRC,3);
	SET_BIT(DDRC,4);
	SET_BIT(DDRC,5);
	LCD_vSend_string("press ON/C to");
	LCD_movecursor(2,1);
	LCD_vSend_string("set your clock");
	
    
    while (1) 
    {
		key_pressed=keypad_u8check_press();
		if (key_pressed!=NOTPRESSED)
		{
			if (key_pressed=='A')
			{
				LCD_clearscreen();
				LCD_vSend_string("hours=--");
				LCD_movecursor(1,7);
				_delay_ms(500);
				do 
				{
					left_digit=keypad_u8check_press();
				} while (left_digit==NOTPRESSED);
				LCD_vSend_char(left_digit);
				_delay_ms(300);
				do
				{
					right_digit=keypad_u8check_press();
				} while (right_digit==NOTPRESSED);
				LCD_vSend_char(right_digit);
				_delay_ms(300);
				hours_counter = (left_digit-48)*10 +(right_digit-48);
				LCD_clearscreen();
				
				LCD_vSend_string("minutes=--");
				LCD_movecursor(1,9);
				_delay_ms(300);
				do
				{
					left_digit=keypad_u8check_press();
				} while (left_digit==NOTPRESSED);
				LCD_vSend_char(left_digit);
				_delay_ms(300);
				do
				{
					right_digit=keypad_u8check_press();
				} while (right_digit==NOTPRESSED);
				LCD_vSend_char(right_digit);
				_delay_ms(300);
				minutes_counter = (left_digit-48)*10 +(right_digit-48);
				LCD_clearscreen();
				LCD_vSend_string("Second=--");
				LCD_movecursor(1,8);
				_delay_ms(300);
				do
				{
					left_digit=keypad_u8check_press();
				} while (left_digit==NOTPRESSED);
				LCD_vSend_char(left_digit);
				_delay_ms(200);
				do
				{
					right_digit=keypad_u8check_press();
				} while (right_digit==NOTPRESSED);
				LCD_vSend_char(right_digit);
				_delay_ms(200);
				seconds_counter = (left_digit-48)*10 +(right_digit-48);
				LCD_clearscreen();
			}
			else
			{
				LCD_clearscreen();
				LCD_vSend_string("Wrong Input");
				_delay_ms(1000);
				LCD_clearscreen();
				LCD_vSend_string("press ON/C to");
				LCD_movecursor(2,1);
				LCD_vSend_string("set your clock");
			}
		}
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		CLR_BIT(PORTC,0);
		seven_seg_write(PORT_B,seconds_counter%10);
		_delay_ms(5);
		
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		CLR_BIT(PORTC,1);
		seven_seg_write(PORT_B,seconds_counter/10);
		_delay_ms(5);
		
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		CLR_BIT(PORTC,2);
		seven_seg_write(PORT_B,minutes_counter%10);
		_delay_ms(5);
		
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		CLR_BIT(PORTC,3);
		seven_seg_write(PORT_B,minutes_counter/10);
		_delay_ms(5);
		
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,5);
		CLR_BIT(PORTC,4);
		seven_seg_write(PORT_B,hours_counter%10);
		_delay_ms(5);
		
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,0);
		CLR_BIT(PORTC,5);
		seven_seg_write(PORT_B,hours_counter/10);
		_delay_ms(5);
		
		if (seconds_counter=60)
		{
			seconds_counter=0;
			minutes_counter++;
		}
		if (minutes_counter>=60)
		{
			minutes_counter=0;
			hours_counter++;
		}
		if (hours_counter==24)
		{
			hours_counter=0;
		}
    }
}
ISR(TIMER2_OVF_vect)
{
	seconds_counter++;
}
