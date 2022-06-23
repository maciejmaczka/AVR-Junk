/*
 */
#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>

    int  shift_enabled = 0;// = false;
    int round_robin = 0;
    int robin2 =0;
    int way = 0;



void clear()
{

     shift_enabled = 0;// = false;
     round_robin = 0;
    way = 0;

robin2 = 0;

}

int main(void)
{
    /* Wszystkie linie portu D będą wyjściami */

    DDRD  = 0xff;

    DDRA  = 0x00;
    /* Linie portu C będą wejściami z podciągnięciem do VCC */

    PORTA = 0xff;


    int seq_a = 0b00001111;
    int seq_b = 0b11110000;



    for(;;)
    {


        PORTD = seq_a;

        _delay_ms(300);

        PORTD = seq_b;

        _delay_ms(300);

        if (shift_enabled == 1)
        {


            if (seq_a == 0b10000000)
            {
                seq_b = 0b10000000;
                seq_a = 0b00000001;
                _delay_ms(300);
            }

            //seq_b = seq_b - 1;
            //seq_a = seq_a + 1;
            seq_a = seq_a << 1;
            seq_b = seq_b >> 1;


        }

        if (round_robin == 1)
        {
         //   seq_a = 0b00000011;
           // seq_b = 0b00000011;

            if (way == 0)
            {
            seq_a = seq_a << 1;
            seq_b = seq_b << 1;
            }
            if (way == 1)
            {
            seq_a = seq_a >> 1;
            seq_b = seq_b >> 1;

            }

            if (seq_a == 0b11000000)
            {

                way = 1;

            }
            if (seq_a ==0b00000011)
            {
                way = 0;
            }

        }


        if (robin2 == 1)
        {


            seq_a  = (seq_a << 1 ) | (seq_a >> 7) & 0b11111111;
            seq_b  = (seq_b << 1 ) | (seq_b >> 7) & 0b11111111;



        }
        if ( ((PINA &0x01) == 0) && !((PINA &0x02) == 0) &&  !((PINA &0x04) == 0))
        {

            seq_a = 0b10101010;
            seq_b = 0b01010101;
            clear();
        }

        if ((PINA &0x02) == 0)
        {

            seq_a = 0b11001100;
            seq_b = 0b00110011;
            clear();

        }


        if ((PINA &0x04) == 0)
        {

            seq_a = 0b00000000;
            seq_b = 0b11111111;
            clear();
        }

        if ((PINA &0x08) == 0)
        {

            seq_a = 0b00001111;
            seq_b = 0b11110000;
           clear();

        }

         if (((PINA &0x01) == 0) && ((PINA &0x02) == 0))
        {

            seq_a = 0b00000000;
            seq_b = 0b00000001;
            clear();
        }

         if (((PINA &0x01) == 0) && ((PINA &0x04) == 0))
        {

            seq_a = 0b00000001;
            seq_b = 0b10000000;
          //  seq_b >> 1;
            clear();
            shift_enabled = 1;
        }

         if (((PINA &0x01) == 0) && ((PINA &0x08) == 0))
        {


            seq_a = 0b00000000;
            seq_b = 0b00000000;
            clear();
        }

         if (((PINA &0x04) == 0) && ((PINA &0x08) == 0))
        {


            seq_a = 0b00000011;
           seq_b = 0b00000011;
           clear();

           round_robin = 1;

        }

          if (((PINA &0x02) == 0) && ((PINA &0x08) == 0))
        {


            seq_a = 0b00000001;
            seq_b = 0b00000001;
            clear();

            robin2 = 1;

        }

        /* Przepisanie zawartości PINC do PORTD */
       // PORTD = PINA;
        //PORTD = ~PINC & 0x0f;
    }
}
