

/* 
 * File:   
 * Author: abdallah rabie
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _DELAY_H
#define	_DELAY_H
#include <xc.h> // include processor files - each processor file is guarded.  
#include "config.h"
void delay_ms(uint8_t time){
    while(time>0){
        __delay_ms(1);
        time--;
    }
}
void delay_us(uint8_t time){
    while(time>0){
        __delay_ms(1);
        time--;
    }
}

#endif	/* XC_HEADER_TEMPLATE_H */

