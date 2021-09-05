#include <xc.h>
#include"libs/LCD.h"
#include <stdio.h>
#include<stdint.h>
#include "libs/ADCPic16f877a.h"
#include "libs/config.h"
#include "libs/PWMPic16f877a.h"
#include "libs/delay.h"
#define Baud 9600
#include "libs/UARTPic16f877a.h"

 


char lambState,fanState;
uint16_t AN0RES=0;
float Voltage;
char* line1 = " Temperature Is ";
char* TempSTR[16];
void getStates(uint8_t,uint8_t);
float print(uint8_t);
void interrupet();
int main()
{
  UART_Init();
 

  
  TRISC3=1;
  TRISC4=0;
  TRISC2=0;
  TRISC1=1;
  TRISC0=0;
  RC2=0;
  RC0=0;
  
  UART_TInit();
  interrupet();
  LCD_Init();
  LCD_Clear();
  ADC_Init();
  char data;
  while(1)
  {
    
    /* code */
  
    if(serialAvailable()){
 data= UART_Read_char();
 UART_Write(data);
  }
  
 AN0RES = analogRead(0); // Read Analog Channel 0
 float temp=print(AN0RES);
 if(RC3==1 || data=='1'){
   RC4=1;
   lambState='1';
 }
 else if(data=='2'){
   RC4=0;
   lambState='0';
 }
 if (temp>=40.0 || data=='3'){
RC2=1;
 fanState=TRUE;
 }
 else if(data=='4'){
   RC2=0;
    fanState=FALSE;
 }
if(INTF){
  RC0=1; 

}
if(RC1==1){
INTF=0;
RC0=0; 
}
if(data=='9')
getStates(fanState,lambState);
}

}



float print(uint8_t AN0RES){
  float Temperature;
     Voltage = AN0RES * 0.0048828;
    Temperature = Voltage / 0.01;
    // Convert The Temperature From Float To String
    sprintf(TempSTR, " %.3fc", Temperature);
    // Print Out The Temperature
    LCD_Set_Cursor(1,1);
    LCD_Write_String(line1);
    LCD_Set_Cursor(2,1);
    LCD_Write_String(TempSTR);
    __delay_ms(10);
    return Temperature;
}
uint8_t mapping(float voltage,uint8_t maxPulse){
float value=(voltage*maxPulse)/5;
return value;
}
void interrupet(){
 GIE=1;      //global interrupt enable
 TRISB0=1;   //setup RB0 as input
 INTF=0;    //clear interrupt flag bit
 INTEDG=1;   //configure detection of interrupt on rising edge
}
void getStates(uint8_t fan,uint8_t lamb){
UART_Write_String("fan : ");
UART_Write(fanState);
newLine();
UART_Write_String("lamb : ");
UART_Write_char(lambState);
newLine();

}

