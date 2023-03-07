/*
 * DIO.h
 *
 * Created: 3/3/2021 5:00:21 PM
 *  Author: sharasa
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "std_macros.h"
#include "dio_configuration.h"
#include "std_types.h"
/*
	Function Name        : DIO_vsetPINDir
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber,unsigned char direction
	Function Description : Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
*/
void DIO_vsetPINDir(uint8 portname,uint8 pinnumber,uint8 direction);

/*
	Function Name        : DIO_write
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber,unsigned char outputvalue
	Function Description : Set the value of the given pin in the given port (outputvalue 0 = low : 1 = high) 
*/
void DIO_write(uint8 portname,uint8 pinnumber,uint8 outputvalue);

/*
	Function Name        : DIO_u8read
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
*/
uint8 DIO_u8read(uint8 portname,uint8 pinnumber);

/*
	Function Name        : DIO_toggle
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Reverse the value of the given pin in the given port.
*/
void DIO_toggle(uint8 portname,uint8 pinnumber);

/*
	Function Name        : DIO_set_port_direction
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char direction
	Function Description : set the direction of whole port .
*/

void DIO_set_port_direction(uint8 portname,uint8 direction);


/*
	Function Name        : DIO_write_port
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char portvalue
	Function Description : Write the value to all port pins.
*/

void DIO_write_port(uint8 portname,uint8 portvalue);

/*
	Function Name        : DIO_read_port
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portname
	Function Description : read the value of the port .
*/
uint8 DIO_read_port(uint8 portname);

/*
	Function Name        : DIO_vconnectpullup
	Function Returns     : void
	Function Arguments   : char portname ,char pinnumber, char connect_pullup
	Function Description : Connect and disconnect pull up resistor to the given pin at the given port 
*/
void DIO_vconnectpullup(uint8 portname ,uint8 pinnumber, uint8 connect_pullup);
/*
	Function Name        : write_low_nibble
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char value
	Function Description : write a value to the low nibble of the port 
*/
void write_low_nibble(uint8 portname,uint8 value);
/*
	Function Name        : write_high_nibble
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char value
	Function Description : write a value to the high nibble of the port 
*/
void write_high_nibble(uint8 portname,uint8 value);

void clear_high_nibble(uint8 portname);

void write_high_nibble(unsigned char portname,unsigned char value);
#endif

