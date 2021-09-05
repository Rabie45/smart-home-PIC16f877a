#ifndef _UARTPIC16F877A_H
#define _UARTPIC16F877A_H
#include <xc.h> 
uint8_t TRUE=1,FALSE=0;
#include "config.h"
void UART_TInit(void);
void UART_Write(uint8_t);
void UART_Write_char(char *);
void UART_Write_String(char *);
char  serialAvailable();
void UART_RInit(void);
char UART_Read_char(void);
void UART_Read_String(uint8_t *Output, uint16_t length);
void newLine();
#include "UARTPIC16f877a.c"
#endif