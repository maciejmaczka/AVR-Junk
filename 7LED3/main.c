#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL
#define wys1 PORTB = 0b11111110
#define wys2 PORTB = 0b11111101
#define wys3 PORTB = 0b11111011
#define wys4 PORTB = 0b11110111
#define  nic PORTB = 0b11111111
#define puste PORTA = 0b11111111;
int cyfra(int _cyfra);


int main(void)
{
	DDRB = 0xFF;
	DDRA = 0xFF;

    int liczba1 = 0;
    int liczba2 = 0;
    int liczba3 = 0;
    int liczba4 = 0;
    int short_deley = 3;
    int micro = 1;
    PORTA = cyfra(liczba1);
     _delay_us(short_deley);
1;

    int loop_counter = 0;

    while(1)
    {



    loop_counter++;

    if (loop_counter == 10)
    {

        liczba1++;
        loop_counter = 0;

    }

    wys1;
    PORTA = cyfra(liczba1);
    _delay_us(short_deley);



    if ((liczba2 !=0) || (liczba3 != 0) || (liczba4 != 0))
    {
        wys2;
        puste
        _delay_us(micro);

        wys2;
        PORTA = cyfra(liczba2);


    }
    else
    {
    puste
        nic;

    }
  _delay_us(short_deley);


    if ((liczba3 != 0) || (liczba4 !=0))
    {


        wys3;
       puste
        _delay_us(micro);
        wys3;
        PORTA = cyfra(liczba3);


    }
    else
    {
    puste
        nic;

    }
  _delay_us(short_deley);

    if (liczba4 != 0)
    {

        wys4;
        puste
        _delay_us(micro);
        wys4;
        PORTA = cyfra(liczba4);


    }
    else
    {
    puste
        nic;

    }
 _delay_us(short_deley);

// dodawanie 1 i zerowanie pod koniec

{
    if (liczba1 == 10)
    {

        liczba1 = 0;
        liczba2++;

    }

    if (liczba2 == 10)
    {

        liczba2 = 0;
        liczba3++;

    }

    if (liczba3 == 10)
    {

        liczba3 = 0;
        liczba4++;

    }

    if (liczba4 == 10)
    {

        liczba4 = 0;


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
