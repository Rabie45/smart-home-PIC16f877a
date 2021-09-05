#ifndef _PWMPIC18F877A_H
#define _PWMPIC18F877A_H

#include <xc.h>
#include <stdint.h>
#include "config.h"

void PWM1Write(uint16_t);
void PWM1_Init();
void PWM2_Init();
void PWM2Write(uint16_t);
#include "PWMPic16f877a.c"
#endif