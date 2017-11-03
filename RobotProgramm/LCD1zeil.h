#ifndef LCD1ZEIL_H_INCLUDED
#define LCD1ZEIL_H_INCLUDED
//////////////////////////////////////////////////////////////////////////////
//
// Headerfile LCD.h zur LCD Ansteuerung am Port D für das HTL Demoboard
//
// Befehle: LCD_init(), LCD_cmd(char data), LCD_send(char data)
//          LCD_string(char *data)
//
// LCD_init();               initialisiert Port D
//                           und LCD im 4-Bit Mode, 2 Zeilen, 5x7 Dots
//                           Bsp.: LCD_init();
//
// LCD_cmd(char data);       schickt Befehl ans LCD
//                           Bsp.: LCD_cmd(0xC5);  //gehe zu 2. Zeile, 6. Position
//
// LCD_send(char data);      schickt Daten ans LCD
//                           Bsp.: LCD_send(0xEF); //sendet ein ö
//
// LCD_string(char *data);   schickt eine Zeichenkette ans LCD
//                           Bsp.: LCD_string("Hallo");    //sendet Hallo
//
// Pinbelegung am Board:
// LCD | Atmega16 | Bemerkung
// ----|----------|--------------------
// DB7 |    PD3   |
// DB6 |	PD2   |
// DB5 |	PD1   |
// DB4 |	PD0   |
// DB3 |	-     | wird nicht benötigt
// DB2 |	-     | wird nicht benötigt
// DB1 |	-     | wird nicht benötigt
// DB0 |	-     | wird nicht benötigt
// E   |	PD5   |
// R/W |	-     | per HW auf GND gelegt
// RS  |	PD4   |
//
////////////////////////////////////////////////////////////////////////////////

//-- Hier die Pinzuordnung bei Bedarf aendern (siehe Tabelle oben) --//
#define DB7	PB3
#define DB6	PB2
#define DB5	PB1
#define DB4	PB0
#define E	PB5
#define RS	PB4
// PORT Zuordnung muss im gesamten LCD.h angepasst werden!!!
// d.h. PORTD und DDRD durch gewünschten anderen Port ersetzen
//
//------------------- Ende Pinzuordnung ------------------------------//


// prototypen:
void LCD_init(void);
void LCD_send(char data);
void LCD_cmd(char data);
void LCD_string(char *data);
void LCD_secCursor(char n);
void delay_ms (unsigned int ms);

#endif // LCD1ZEIL_H_INCLUDED
