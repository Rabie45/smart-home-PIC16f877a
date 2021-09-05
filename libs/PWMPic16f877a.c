/*
 * File:   PWMPic16f877a.c
 * Author: abdal
 *
 * Created on August 31, 2021, 4:58 PM
 */


#include <xc.h>
#include <stdint.h>

void PWM1Write(uint16_t Value)
{
  // Check The DC Value To Make Sure it's Within 10-Bit Range
  if(Value<1024)
  {
    CCP1Y = Value & 1;
    CCP1X = Value & 2;
    CCPR1L = Value >> 2;
  }
}
void PWM1_Init(){
      CCP1M3 = 1;
  CCP1M2 = 1;
  TRISC2 = 0; // The CCP1 Output Pin (PWM)
  // Set The PWM Frequency
  PR2 = 5000;
  // Set The PS For Timer2 (1:4 Ratio)
  T2CKPS0 = 1;
  T2CKPS1 = 0;
  // Start CCP1 PWM !
  TMR2ON = 1;
 
}
void PWM2_Init(){
      CCP2M3 = 1;
  CCP2M2 = 1;
  TRISC1 = 0; // The CCP1 Output Pin (PWM)
  // Set The PWM Frequency
  PR2 = 255;
  // Set The PS For Timer2 (1:4 Ratio)
  T1CKPS0 = 1;
  T1CKPS1 = 0;
  // Start CCP1 PWM !
  TMR2ON = 1;
 
}
void PWM2Write(uint16_t Value)
{
  // Check The DC Value To Make Sure it's Within 10-Bit Range
  if(Value<1024)
  {
    CCP2Y = Value & 1;
    CCP2X = Value & 2;
    CCPR2L = Value >> 2;
  }
}
