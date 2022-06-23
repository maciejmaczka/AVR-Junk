/*
 */

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>


int liczba = 0;

int check_number(int _cyfra);
int cyfra(int _cyfra);


int int_1_handler = 0;  // semafor - jak 0 to mozna przerywac


#define INT_0  2;
#define INT_1  3;

int main(void)
{



    DDRD = 0x00;            // port D jako wejscie

     // przerwania int 0

    PORTD |= 1<<INT_0 ;          // wl. rezystor

    MCUCR |= (0<<ISC00);    // przerwanie zbocze opadajace
    MCUCR |= (0<<ISC01);
    GICR |= (1<<INT0);      // przerwanie int0

    // przerwanie int 1

    PORTD |= 1<<INT_1;

    MCUCR |= (0<<ISC00);    // przerwanie zbocze opadajace
    MCUCR |= (0<<ISC11);
    GICR |= (1<<INT1);      // przerwanie int1

    sei();

    // Port B wyjscie

    DDRB = 0xff;


    // poczatkowy licznik




    // Insert code

    while(1)
    {


      //  liczba++;
     //   liczba = check_number(liczba);


        PORTB = cyfra(liczba);
        _delay_ms(50);

        PORTB = 0xff;
         _delay_ms(50);

    };

    return 0;
}

SIGNAL(SIG_INTERRUPT0)

{

    liczba = 0;
    PORTB = cyfra(liczba);

}



SIGNAL(SIG_INTERRUPT1)

{
    cli();

    if (int_1_handler==1)
    {

        return;

    }

    int_1_handler = 1;
    liczba++;
    PORTB = cyfra(liczba);

    _delay_ms(50);

  //  liczba = check_number(liczba);
   // PORTB = cyfra(liczba);

    int_1_handler = 0;

    sei();

}


int check_number(_cyfra)
{

    if (_cyfra == 10)
    {

        return 0;

    }
    else
    {

        return _cyfra;

    }


}


int cyfra(int _cyfra)
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



		}

    return 0b00000000;

}
