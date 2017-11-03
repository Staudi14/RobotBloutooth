#include <avr/io.h>
#include "UART.h"
#include "LCD1zeil.h"
int main(void)
{
    char buff[500] = {0};
    int pos;
    USART_init();
    LCD_init();
    while(1)
    {
        //writeStringUSART("Hello\n");
        for(pos=0; pos<=sizeof(buff); pos++)
        {
            buff[pos] = readUSART();
            if(buff[pos]==0x0D||buff[pos]==0x0A)
            {
                break;
            }
            LCD_send(buff[pos]);
        }
        buff[pos+1]=0;
        writeStringUSART(buff);
        LCD_secCursor(0);
    }
    return 0;
}
