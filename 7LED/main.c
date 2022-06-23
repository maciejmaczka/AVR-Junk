#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL
#define wys1 PORTB = 0b11111110
#define wys2 PORTB = 0b11111101
#define wys3 PORTB = 0b11111011
#define wys4 PORTB = 0b11110111
#define wyl PORTB = 0xFF;

int cyfra(int _cyfra);



int main(void)
{

//RAND_MAX = 9;
	DDRB = 0xFF;
	DDRA = 0xFF;

    int rand_cyfra1 = 0;
    int rand_cyfra2 = 0;

    int short_deley = 5;
    int current_number = 0;
    int switch_cunter = 0;

	while(1)
	{


		PORTA = cyfra(current_number);
		wys2;

		_delay_us(short_deley);
		wys1;
		PORTA= cyfra(9 - current_number);

	//	wyl;

        _delay_us(short_deley);


        wys3;
        PORTA= cyfra(rand_cyfra1);
        _delay_us(short_deley);

        wys4;
        PORTA= cyfra(rand_cyfra2);
        _delay_us(short_deley);



        switch_cunter++;

        if (switch_cunter == 50)
        {

            current_number++;
            switch_cunter=0;

            rand_cyfra1 =  rand() % 10;
            rand_cyfra2 = rand() % 10;

        }

        if (current_number == 10)
        {

            current_number = 0;

        }
		//}
	}

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
