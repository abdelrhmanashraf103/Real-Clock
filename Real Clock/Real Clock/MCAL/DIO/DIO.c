/*
 * DIO.C
 *
 * Created: 3/3/2021 5:00:21 PM
 *  Author: sharasa
 */ 

#include <avr/io.h>

#include "DIO.h"
void DIO_vsetPINDir(uint8 portname,uint8 pinnumber,uint8 direction)
{
	switch(portname)
	{
		
		
		case PORT_A:
		if(direction==HIGH)
		{
			SET_BIT(DDRA,pinnumber);//Set the direction of the given pin in port A as output
		}
		else
		{
			CLR_BIT(DDRA,pinnumber);//Set the direction of the given pin in port A as input
		}
		break;
		case PORT_B:
		if(direction==HIGH)
		{
			SET_BIT(DDRB,pinnumber);//Set the direction of the given pin in port B as output
		}
		else
		{
			CLR_BIT(DDRB,pinnumber);//Set the direction of the given pin in port B as input
		}
		break;
		case PORT_C:
		if(direction==HIGH)
		{
			SET_BIT(DDRC,pinnumber);//Set the direction of the given pin in port C as output
		}
		else
		{
			CLR_BIT(DDRC,pinnumber);//Set the direction of the given pin in port C as input
		}
		break;
		case PORT_D:
		if(direction==HIGH)
		{
			SET_BIT(DDRD,pinnumber);//Set the direction of the given pin in port D as output
		}
		else
		{
			CLR_BIT(DDRD,pinnumber);//Set the direction of the given pin in port D as input
		}
		break;
		default: 
		break;
	}
}


void DIO_write(uint8 portname,uint8 pinnumber,uint8 outputvalue)
{
	switch(portname)
	{
		case PORT_A :
		
		if(outputvalue==HIGH)
		{
			SET_BIT(PORTA,pinnumber);//Set the value of the given pin in port A as High
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);//Set the value of the given pin in port A as Low
		}
		break ;
		case PORT_B:
		
		if(outputvalue==HIGH)
		{
			SET_BIT(PORTB,pinnumber);//Set the value of the given pin in port B as High
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);//Set the value of the given pin in port B as Low
		}
		break ;
		case PORT_C :
		
		if(outputvalue==HIGH)
		{
			SET_BIT(PORTC,pinnumber);//Set the value of the given pin in port C as High
		}
		else
		{
			CLR_BIT(PORTC,pinnumber);//Set the value of the given pin in port C as Low
		}
		break ;
		case PORT_D:
		
		if(outputvalue==HIGH)
		{
			SET_BIT(PORTD,pinnumber);//Set the value of the given pin in port D as High
		}
		else
		{
			CLR_BIT(PORTD,pinnumber);//Set the value of the given pin in port D as Low
		}
		break ;
		default: break ;
	}
}


uint8 DIO_u8read(uint8 portname,uint8 pinnumber)
{
	uint8 return_value=LOW;
	switch(portname)
	{
		case PORT_A :
		return_value=READ_BIT(PINA,pinnumber);//Read the value from the given pin in port A
		break;
		
		case PORT_B :
		return_value=READ_BIT(PINB,pinnumber);//Read the value from the given pin in port B
		break;
		
		case PORT_C :
		return_value=READ_BIT(PINC,pinnumber);//Read the value from the given pin in port C
		break;
		
		case PORT_D :
		return_value=READ_BIT(PIND,pinnumber);//Read the value from the given pin in port D
		break;
		default: 
		break;
	}
	return return_value ;
}
void DIO_toggle(uint8 portname,uint8 pinnumber)
{
	switch(portname)
	{
		case PORT_A:
		TOG_BIT(PORTA,pinnumber);//Toggle the value of the given pin in port A
		break;
		case PORT_B:
		TOG_BIT(PORTB,pinnumber);//Toggle the value of the given pin in port B
		break;
		case PORT_C:
		TOG_BIT(PORTC,pinnumber);//Toggle the value of the given pin in port C
		break;
		case PORT_D:
		TOG_BIT(PORTD,pinnumber);//Toggle the value of the given pin in port D
		break;
		default: break;
	}
}
void DIO_set_port_direction(uint8 portname,uint8 direction)
{
	switch(portname)
	{
		case PORT_A :
		DDRA=direction; //set the direction of port A
		break ;
		case PORT_B:
		DDRB=direction; //set the direction of port B
		break ;
		case PORT_C :
		DDRC=direction; //set the direction of port C
		break ;
		case PORT_D:
		DDRD=direction; //set the direction of port D
		break ;
		default:
		break ;
	}
	
}
void DIO_write_port(uint8 portname,uint8 portvalue)
{
	switch(portname)
	{
		case PORT_A :
		PORTA=portvalue; //Write the given value to the port A
		break ;
		case PORT_B:
		PORTB=portvalue; //Write the given value to the port B
		break ;
		case PORT_C:
		PORTC=portvalue; //Write the given value to the port C
		break ;
		case PORT_D:
		PORTD=portvalue; //Write the given value to the port D
		break ;
		default:
		 break ;
	}
}

uint8 DIO_read_port(uint8 portname)
{
	uint8 return_val=LOW;
	switch(portname)
	{
		case PORT_A :
		return_val=PINA; // read the value of port A 
		break ;
		case PORT_B:
		return_val=PINB; // read the value of port B 
		break ;
		case PORT_C:
		return_val=PINC; // read the value of port C 
		break ;
		case PORT_D:
		return_val=PIND; // read the value of port D 
		break ;
		default:
		break ;
	}
	return return_val;
}

void DIO_vconnectpullup(uint8 portname ,uint8 pinnumber, uint8 connect_pullup)
{
	switch(portname)
	{
		case PORT_A:
		if(connect_pullup==HIGH)
		{
			SET_BIT(PORTA,pinnumber);
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);
		}
		break;
		case PORT_B:
		if(connect_pullup==HIGH)
		{
			SET_BIT(PORTB,pinnumber);
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);
		}
		break;
		case PORT_C:
		if(connect_pullup==HIGH)
		{
			SET_BIT(PORTC,pinnumber);
			
		}
		else
		{
			CLR_BIT(PORTC,pinnumber);
		}
		break;
		case PORT_D:
		if(connect_pullup==HIGH)
		{
			SET_BIT(PORTD,pinnumber);
			
		}
		else
		{
			CLR_BIT(PORTD,pinnumber);
		}
		break;
		
	}
}

void write_low_nibble(uint8 portname,uint8 value)
{
	value&=0x0f;
	switch(portname)
	{
		case PORT_A:
		PORTA&=0xf0;
		PORTA|=value;
		case PORT_B:
		PORTB&=0xf0;
		PORTB|=value;
		case PORT_C:
		PORTC&=0xf0;
		PORTC|=value;
		case PORT_D:
		PORTD&=0xf0;
		PORTD|=value;
	}
}

void write_high_nibble(uint8 portname,uint8 value)
{
	value<<=4;
	switch(portname)
	{
		case PORT_A:
		PORTA&=0x0f;
		PORTA|=value;
		case PORT_B:
		PORTB&=0x0f;
		PORTB|=value;
		case PORT_C:
		PORTC&=0x0f;
		PORTC|=value;
		case PORT_D:
		PORTD&=0x0f;
		PORTD|=value;
	}
}

void clear_high_nibble(uint8 portname)
{
	switch(portname)
	{
		case 'A' :
		PORTA&=0x0f;//set the value of the high nibble of the port A as low
		break ;
		case 'B':
		PORTB&=0x0f;//set the value of the high nibble of the port B as low
		break ;
		case 'C' :
		PORTC&=0x0f;//set the value of the high nibble of the port C as low
		break ;
		case 'D':
		PORTD&=0x0f;//set the value of the high nibble of the port D as low
		break ;
		default: break ;
		
	}
}

