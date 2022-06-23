#define F_CPU 2000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "hd44780.h"

int main(void) {
	
	// konfiguracja przycisku FLIP
	PORTE.DIRCLR	=	PIN5_bm;				// pin E5 jako wej�cie
	PORTE.PIN5CTRL	=	PORT_OPC_PULLUP_gc;		// podci�gni�cie do zasilania
	
	// Inicjalizacja wy�wietlacza
	LcdInit();									// inicjalizacja sterownika LCD
	Lcd("   Kurs XMEGA");						// wy�wietlenie napisu
	Lcd2;										// przej�cie do drugiej linii
	Lcd("Leon Instruments");					// wy�wietlenie napisu
	
	// zmienna s�u��ca jako licznik
	uint8_t licznik = 0;
	
	while(1) {
		if(!(PORTE.IN & PIN5_bm)) {				// je�eli przycisk FLIP jest wci�ni�ty
			licznik++;							// zwi�ksz licznik o 1
			LcdClear();							// wyczy�� wy�wietlacz
			Lcd("Licznik:");					// wy�wietlenie napisu
			Lcd2;								// przej�cie do drugiej linii
			LcdDec(licznik);					// wy�wietlenie zmiennej liczbowej
			_delay_ms(100);						// czekanie 100ms
		}
	}
}