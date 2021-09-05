#ifndef _ADCPIC16F877A_H
#define _ADCPIC16F877A_H
#include "config.h"
#include <xc.h>
#include <stdint.h>
void ADC_Init();
uint16_t analogRead(uint8_t);
#include "ADCPic16f877a.c"
#endif