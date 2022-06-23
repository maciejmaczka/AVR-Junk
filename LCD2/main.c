/*
 */
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "HD44780.h"



int lcd_position_h = 0;
int lcd_position_v = 0;


int interrupt = 0;


char alfabet[] = "|abcdefghijklmnopqrstuvwxyz|";
int letter_number = 0;

char imie[20];
int imie_count = 0;


char prompt[2];
char empty[2];

#define INT_0  2;

int main(void)
{
    for (int i = 0 ; i < 20 ;i++)
    {

        imie[0] = NULL;

    }


    // wyjscie na diodze

    DDRB = 0xff;
    PORTB = 0x00;

    // wyjscie na wyswietlaczu

    DDRA = 0xff;
    PORTA = 0x00;


    //przerwanie na D

    DDRD = 0x00;
    PORTD = 0xff;


    PORTD |= 1<<INT_0 ;          // wl. rezystor

    MCUCR |= (0<<ISC00);    // przerwanie zbocze opadajace
    MCUCR |= (0<<ISC01);
    GICR |= (1<<INT0);      // przerwanie int0

    sei();



    prompt[0] = '|';
    empty[0] = ' ';

    DDRA = 0xff;
    PORTA = 0x00;

    LCD_Initalize();
    LCD_Clear();
    LCD_GoTo(0,0);

    LCD_WriteText("Wpisz imie:");

    _delay_ms(75);

    LCD_GoTo(0,1);
    LCD_WriteText("3 ");

    _delay_ms(75);
    LCD_WriteText("2 ");

    _delay_ms(75);
    LCD_WriteText("1 ");

    _delay_ms(75);
    LCD_WriteText("Teraz ");

    _delay_ms(75);

    LCD_Clear();
    LCD_GoTo(0,0);
    _delay_ms(10);




    LCD_Clear();

    LCD_GoTo(0,0);
    LCD_WriteText("Imie:");
    LCD_GoTo(0,1);

    while(1)
    {

        prompt[0] = alfabet[letter_number];

        LCD_WriteText(prompt);
        LCD_GoTo(lcd_position_h , 1);

        _delay_ms(30);

        LCD_WriteText(" ");
         LCD_GoTo(lcd_position_h , 1);
        _delay_ms(30);



    };

    return 0;
}


SIGNAL(SIG_INTERRUPT0)
{

    if (interrupt == 1)
    {


        return;

    }

    interrupt = 1;

    if ((PIND & 0b00010000) == 0)           // nastepna litera
    {


        letter_number++;
        _delay_ms(25);
        check_number();
        show_letter();

    }
    if ((PIND & 0b00100000) == 0)           // poprzednia litera
    {


        letter_number--;
        _delay_ms(25);
        check_number();
        show_letter();

    }


    if ((PIND & 0b01000000) == 0)           // zatwierdz
    {



        show_letter();



        if (letter_number == 0)
        {

            imie[imie_count] = " ";
            LCD_WriteText(" ");

        }
        else
        {
            imie[imie_count] = prompt;
            LCD_WriteText(prompt);
        }

        lcd_position_h++;
        letter_number = 0;
        imie_count++;


        _delay_ms(25);

    }

    if ((PIND & 0b10000000) == 0)
    {

        LCD_Clear();
        LCD_Home();

        LCD_WriteText("Czesc");
        LCD_GoTo(0,1);



        LCD_WriteText("Jak leci? :)");

        exit(0);
    }


    interrupt = 0;

}

void check_number()
{

    if (letter_number <= 0)
    {

        letter_number = 26;

    }
    if (letter_number >= 27)
    {

        letter_number = 1;

    }
}

void show_letter()
{
        prompt[0] = alfabet[letter_number];
        LCD_WriteText(prompt);
        LCD_GoTo(lcd_position_h, 1);


}

