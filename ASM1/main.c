/*
 */
#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/eeprom.h>


uint8_t cyfra(uint8_t _cyfra);
int main(void)
{
    DDRA = 0xff;  // output
    DDRB = 0xff;

    DDRD = 0x00; //input
    PORTD = 0xff;

    uint8_t value;


    PORTA = 0b01010101;
    _delay_ms(300);
    PORTA = 0b10101010;
    _delay_ms(300);
    PORTA = 0b00000000;

    int i = 0;

    while(1)

    //for ( int i = 0 ; i < 10 ; i++)
    {



        value = (255 - PIND) &0b01111111;
        if (value == 0)
        {
            PORTA = value;
            PORTB = cyfra(value);
            continue;

        }


        PORTA = value;
        PORTB = cyfra(value);


        eeprom_write_byte((uint8_t*) i , value);

        _delay_ms(400);
        i++;
        if ( i == 10)
        {
            i =0;
            break;
        }

    };

    PORTB = 0b11111111;
    PORTA = 0b01010101;
    _delay_ms(300);
    PORTA = 0b10101010;
    _delay_ms(300);
    PORTA = 0b11111111;
    _delay_ms(300);
    PORTA = 0b00000000;
    _delay_ms(300);


    for ( int i = 0 ; i < 10 ; i++)
    {


        value = eeprom_read_byte((uint8_t*) i);
        PORTA = value;
        PORTB = cyfra(value);//cyfra(temp);
       // PORTB = cyfra(cyferka);
        _delay_ms(300);

    }


    PORTA = 0b01010101;
    _delay_ms(300);
    PORTA = 0b10101010;
    _delay_ms(300);
    PORTA = 0b00000000;
    PORTB = 0b11111111;



    return 0;
}

uint8_t cyfra(uint8_t _cyfra)
{

		switch(_cyfra)
		{
		case 0:
		return 0b11000000; //0

		case 1:
		return 0b11111001; //1

		case 2:
		return 0b10100100; //2

		case 3:
		return 0b10110000; //3

		case 4:
		return 0b10011001; //4

		case 5:
		return 0b10010010; //5

		case 6:
		return 0b10000010; //6

		case 7:
		return 0b11111000; //7

		case 8:
		return 0b10000000; //8

		case 9:
		return 0b10010000; //9

        default:
        return 0b10101010; // wszystko

		}
}
