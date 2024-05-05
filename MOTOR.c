/*
 * File:   MOTOR.c
 * Author: Admin
 *
 * Created on May 6, 2024, 12:14 AM
 */


#include <xc.h>

#pragma config FOSC=HS
#pragma config WDT=OFF
#pragma config LVP=OFF
#pragma config PBADEN=OFF

void msdelay(unsigned int time)
{
    unsigned int i,j;
    for(i=0;i<time;i++)
        for(j=0;j<710;j++);
}
void main(void) {
    TRISCbits.TRISC0=0;
    TRISCbits.TRISC1=0;
    TRISCbits.TRISC2=0;
    PR2=0x4E;
    CCP1CON=0x0C;
    T2CON=0x07;
    PORTCbits.RC0=1;
    PORTCbits.RC1=0;
    
    while(1)
    {
        CCP1CONbits.DC1B0=0;
        CCP1CONbits.DC1B1=1;
        CCPR1L=0x3E;
        msdelay(2000);
        
        CCP1CONbits.DC1B0=1;
        CCP1CONbits.DC1B1=1;
        CCPR1L=0x2E;
        msdelay(2000);
        
        CCP1CONbits.DC1B0=1;
        CCP1CONbits.DC1B1=0;
        CCPR1L=0x1E;
        msdelay(2000);
        
        CCP1CONbits.DC1B0=0;
        CCP1CONbits.DC1B1=1;
        CCPR1L=0x0E;
        msdelay(2000);
        
    }

}
