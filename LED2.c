/*
 * File:   LED2.c
 * Author: EYC
 *
 * Created on 15 de septiembre de 2024, 10:00 AM
 */
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
//CÓDIGO QUE ACTIVA LA SAIDA 3 DEL PUERTO C(LED ON) SI ES QUE SE PRESIONA EL PUSADOR (ESTADO BAJO)
//DE LO CONTRARIO LA SALIDA 3 DEL PUERTO C ESTARÁ APAGADO.
int main(void)
{
	DDRB &= ~(1<<2);		// Configuro el bit 2 del regitro DDRB como entrada(0).
	PORTB |= (1<<PB2);		//Ya que, DDRB(bit2) está en alto, entonces puedo activar pull up
                            //Activo Pull up del PIN 2 del puerto B.
	
	DDRC |= (1<<3);			//Configuro el bit 3 del puerto C como salida(1).
	PORTC &= ~(1<<PC3);		//Coloco nivel en bajo el bit 3(0) del puerto C 

    while (1) 
    {
		if((PINB&(1<<2)) == 0) // ¿ El BIT 2 del PINB es igual a 0 ?
		{
			PORTC |= (1<<PC3);	// si es igual, entonces el bit 3 del registro PORTC estará en alto.
		}
		else
		{
			PORTC &= ~(1<<PC3);	// de locontrario el bit 3 del registro PORTC estará en bajo.
		}
    }
}
