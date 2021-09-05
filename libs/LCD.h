#ifndef _LCD_H
#define _LCD_H
#include <xc.h>
#warning library included

#define _XTAL_FREQ 48000000
#define LCD_EN_Delay 500
#define LCD_DATA_PORT_D TRISD
#define LCD_EN_Delay 500
#define LCD_DATA_PORT_D TRISB
#define LCD_RS_D TRISB5
#define LCD_EN_D TRISB4
#define RS RB5
#define EN RB4
#define D4 RB6
#define D5 RB1
#define D6 RB2
#define D7 RB3
void LCD_Init();
void LCD_Clear();
void LCD_SL();
void LCD_SR();
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void LCD_Set_Cursor(unsigned char, unsigned char);
void LCD_Write_Char(char);
void LCD_Write_String(char*);
#warning c d7k included
#endif