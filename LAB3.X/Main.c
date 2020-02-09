/*
 * File:   LABORATORIO 3
 * Author: Andrea Marcela Ixquiac Madricales 17285
 *
 * Created on 8 de febrero de 2020, 09:42 PM
 */


#include <xc.h>
#include "ADC.h"

int Channel =0;
int Sensor1=0;
int Sensor2=0; 


void __interrupt() ISR(){
    
    if(ADCON0bits.GO_DONE == 0){
        PORTBbits.RB7 = 1;
        adc = 1;
        PIR1bits.ADIF = 0;
    }
}

void main(void) {
    
    while(1){
        if (adc==1){
           if (Channel==0){
               Channel=1;
               Sensor1=ADRESH;
           }
           if (Channel==1){
               Channel=0;
               Sensor2=ADRESH;
           }
           ADCON0bits.CHS= Channel;
          
        }
    }
    return;
}
