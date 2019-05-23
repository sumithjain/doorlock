#include <avr/io.h>

#include<util/delay.h>

#include<avr/interrupt.h>

void InitADC();

uint16_t ReadADC(uint8_t );

 

volatile uint16_t x=0;

 

int main()

{

    DDRD&=~(1<<5);

    PORTD|=(1<<5);

    DDRD|=(1<<7);

 

 

     DDRC&=~(1<<PC0);

 

 

InitADC();

    while(1)

     {

x=ReadADC(2);

 

if(x<500)

{

     if(PIND&(1<<PD5))

 

        PORTD&=~(1<<7);

    else

 

        PORTD|=(1<<7);

     }

     else

        PORTD&=~(1<<7);

 

     }

    return 0;

}

 

 

 

 

/////////////

 

void InitADC()

{

    ADMUX=(1<<REFS0);

    ADCSRA=((1<<ADEN)|(7<<ADPS0));

 

}

    uint16_t ReadADC(uint8_t ch)

    {

        ADMUX&=0xf8;

        ch=ch&0b00000111;

        ADMUX|=ch;

 

        ADCSRA|=(1<<ADSC);

        while(!(ADCSRA&(1<<ADIF)));

        ADCSRA|=(1<<ADIF);

        return (ADC);

    }
