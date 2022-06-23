/*
 */

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "HD44780.h"
#include <stdlib.h>

int main(void)
{

    DDRD = 0xff;
    PORTD = 0x00;

    char tekst[10] ;
    // Insert code
    LCD_Initalize();
    LCD_GoTo(0, 0);
    LCD_WriteText("UPS :)");
    LCD_GoTo(0, 1);
    LCD_WriteText("Countdown: RUN ! ! !");
    _delay_ms(100);

    int liczba = 10;









    while(1)
    {

    LCD_Home();
    LCD_Clear();

    sprintf(tekst, "%i", liczba);
    LCD_WriteText(tekst);

    _delay_ms(30);

    liczba--;


    if (liczba == 0)
    {

        break;


    }


    };

    LCD_Home();
    LCD_Clear();

    LCD_WriteText("       *    ");

    _delay_ms(50);


    LCD_Home();
    LCD_Clear();

    LCD_WriteText("      (*)  ");

    _delay_ms(50);

    LCD_Home();
    LCD_Clear();

    LCD_WriteText("     ((*)) ");

    _delay_ms(50);

    LCD_Home();
    LCD_Clear();

    LCD_WriteText("    ((   ))");

    _delay_ms(50);


    LCD_Home();
    LCD_Clear();

     LCD_WriteText("   (( BUM )) ");

    _delay_ms(50);


    while(1)
    {


     LCD_Clear();
     LCD_GoTo(0,0);
     LCD_WriteText("  GAME OVER! ! !");

     PORTD= 0b01010101;

     _delay_ms(50);
     LCD_Clear();
     LCD_GoTo(0,1);
     LCD_WriteText("  GAME OVER! ! !");

     PORTD = 0b10101010;
     _delay_ms(50);

    };


    return 0;
}
