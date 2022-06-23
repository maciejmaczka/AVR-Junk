/*
 */

#include <avr/io.h>
#include <avr/delay.h>


#define wys1 PORTA = 0b11111110
#define wys2 PORTA = 0b11111101
#define wys3 PORTA = 0b10111011
#define wys4 PORTA = 0b01110111

#define wygas PORTA = 0b00000000

#define F_CPU 1000000UL

int cyfra1 = 0b11000000;
int cyfra2 = 0b11000000;
int cyfra3 = 0b11000000;
int cyfra4 = 0b11000000;

int cyfra(int _cyfra);
int cyfra_tok(int _cyfra);

int minuta2 = 0;
int minuta1 = 0;
int godzina2 = 0;
int godzina1 = 0;
int sekundy = 0;

const int led_delay_ms = 25;
const int led_dark_ms = 5;
int time_add = 0;
int tik = 0;


int wejscie = 0b11111111;
int input_discard = 0;

int main(void)
{

    DDRB = 0xff;    // wyjscie
    DDRA = 0xff;
    DDRC = 0xff;

    DDRD = 0x00; //input
    PORTD = 0xff;


    while(1)
    {

        // minuta 2

    wys1;
    PORTB = cyfra1;
    _delay_us(led_delay_ms);
    wygas;


        // minuta 1
    wys2;
    PORTB = cyfra2;
    _delay_us(led_delay_ms);
    wygas;


        // godzina 2
    wys3;
    PORTB = cyfra3;
    _delay_us(led_delay_ms);
    wygas;


    // godzina 1

    wys4;
    PORTB = cyfra4;
    _delay_us(led_delay_ms);
    wygas;


    // ok 25 mikrosekundy



    time_add++;



// czas

    // bylo 3500

   if (time_add == 400)
    {

        if (tik == 0)
        {
            cyfra1 = cyfra(minuta2);
            cyfra2 = cyfra(minuta1);
            cyfra3 = cyfra(godzina2);
            cyfra4 = cyfra(godzina1);

            time_add = 0;
            tik = 1;
            sekundy++;
        }
        else
        {

            cyfra1 = cyfra_tok(minuta2);
            cyfra2 = cyfra(minuta1);
            cyfra3 = cyfra(godzina2);
            cyfra4 = cyfra(godzina1);

            time_add = 0;
            tik = 0;
            sekundy++;

        }

        if (sekundy == 60)
        {
                                // minela minuta
            sekundy = 0;
            minuta2++;

        }

        if (minuta2 == 10)
        {

            minuta2 = 0;
            minuta1++;

        }

        if (minuta1 == 6)
        {

            minuta1 = 0;
            godzina2++;

        }

        if (godzina2 == 10)
        {
            godzina2 = 0;
            godzina1++;


        }

        if ((godzina1 == 2) && (godzina2 == 4))
        {

            godzina1 = 0;
            godzina2 = 0;


        }



    }




// nastawianie godzine

    wejscie = (255 - PIND) &0b01111111;
    PORTC = wejscie;

    if ((wejscie == 0b00000001) && (input_discard == 0))
    {
        input_discard = 1;
        minuta2++;


        if (minuta2 == 10)
        {
            minuta2 = 0;
            minuta1++;


        }

        if (minuta1 == 6)
        {

            minuta1 = 0;

        }


            cyfra1 = cyfra(minuta2);
            cyfra2 = cyfra(minuta1);
            cyfra3 = cyfra(godzina2);
            cyfra4 = cyfra(godzina1);


    }

    if ((wejscie == 0b00000010) && (input_discard == 0))
    {
        input_discard = 1;

        godzina2++;


        if (godzina2 == 10)
        {
            godzina2 = 0;
            godzina1++;


        }

        if ((godzina1 == 2) && (godzina2 == 4))
        {

            godzina1 = 0;
            godzina2 = 0;


        }


            cyfra1 = cyfra(minuta2);
            cyfra2 = cyfra(minuta1);
            cyfra3 = cyfra(godzina2);
            cyfra4 = cyfra(godzina1);


    }


    if ((wejscie == 0b00000000) && (input_discard == 1))
    {

        input_discard =0;

    }


    };

    return 0;
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
}

int cyfra_tok(int _cyfra)
{
		switch(_cyfra)
		{
		case 0:
		return 0b01000000; //0

		case 1:
		return 0b01111001; //1

		case 2:
		return 0b00100100; //2

		case 3:
		return 0b00110000; //3

		case 4:
		return 0b00011001; //4

		case 5:
		return 0b00010010; //5

		case 6:
		return 0b00000010; //6

		case 7:
		return 0b01111000; //7

		case 8:
		return 0b00000000; //8

		case 9:
		return 0b00010000; //9



		}
}

