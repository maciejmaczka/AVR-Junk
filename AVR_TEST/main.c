/*
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;
    DDRC = 0xff;
    DDRD = 0xff;
    // Insert code

    while(1)
    {
    PORTA = 0xff;
    PORTB = 0xff;
    PORTC = 0xff;
    PORTD = 0xff;
     _delay_ms(25);

     PORTA = 0x00;
     PORTB = 0x00;
     PORTC = 0x00;
     PORTD = 0x00;
     _delay_ms(25);
     }
    ;

    return 0;
}
