
#include <avr/io.h>

#include "UART.h"

void USART_init(void)
{
    UBRR1H = (uint8_t) UART_BAUD >> 8;
    UBRR1L = (uint8_t) UART_BAUD;

    UCSR1B |= (1<<TXEN1) | (1<<RXEN1);      /// Senden und Empfangen Einschalten
    UCSR1C = (1<<UCSZ10) | (1<<UCSZ11);       /// 8-Bit Modus
}

void writeStringUSART(char *s)
{
    int pos;
    for(pos=0; s[pos] !=0; pos++)
        writeUSART(s[pos]);
}
void readStringUSART(char *s, int l)
{
    int pos;
    for(pos=0; s[pos]!=0 && l<pos; pos++)
        s[pos]=readUSART();
}
void writeUSART(char c)
{
    while(!(UCSR1A & (1 << UDRE1))); ///Warten bis uC bereit auf nächstes byte
    UDR1 = c;
}
char readUSART(void)
{
    while(!(UCSR1A & (1 << RXC1))); ///Waren bis byte ankommt
    return UDR1;
}

