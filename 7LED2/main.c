/*
 */

#include <avr/io.h>
#include <util/delay.h>

#define wys1 PORTB = 0b11111110
#define wys2 PORTB = 0b11111101
#define wys3 PORTB = 0b11111011
#define wys4 PORTB = 0b11110111



int cyfra(int _cyfra);

int main(void)
{
	DDRB = 0xFF;
	DDRA = 0xFF;

    int liczba = 1;
    int liczba1 = 0;
    int liczba2 = 0;
    int liczba3 = 0;
    int liczba4 = 0;

    int short_deley = 20;
    int switch_counter = 0;
    int inc_counter = 0;
    // Insert code

    int sterowanie = 0b11111110;

    while(1)
    {
        for (int i = 0 ; i < 4 ; i++)
        {

            PORTA = cyfra(liczba1);
            wys1;
            _delay_us(short_deley);


            PORTA = cyfra(liczba2);
            wys2;
           _delay_us(short_deley);


            PORTA = cyfra(liczba3);
            wys3;
            _delay_us(short_deley);



            PORTA = cyfra(liczba4);
            wys4;
           _delay_us(short_deley);

            switch_counter++;
            inc_counter++;


            if (inc_counter == 50)
            {


                liczba1 = liczba;
                liczba2 = 0;
                liczba3 = 0;
                liczba4 = 0;

            }

            if (inc_counter == 100)
            {

                liczba1 = 0;
                liczba2 = liczba;
                liczba3 = 0;
                liczba4 = 0;

            }

            if (inc_counter == 150)
            {

                liczba1 = 0;
                liczba2 = 0;
                liczba3 = liczba;
                liczba4 = 0;

            }

            if (inc_counter == 200)
            {
                liczba1 = 0;
                liczba2 = 0;
                liczba3 = 0;
                liczba4 = liczba;


            }

            if (switch_counter == 200)
            {

                switch_counter = 0;
                inc_counter = 0;
                liczba++;


            }



            if (liczba == 10)
            {

                liczba = 0;
            }

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
