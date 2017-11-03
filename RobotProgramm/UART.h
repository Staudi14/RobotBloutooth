#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED

#define UART_BAUD_RATE 9600L
#define UART_BAUD ((F_CPU / UART_BAUD_RATE / 16L) - 1)


void USART_init(void);
void writeStringUSART(char *s);
void readStringUSART(char *s, int l);
void writeUSART(char c);
char readUSART(void);



#endif // UART_H_INCLUDED
