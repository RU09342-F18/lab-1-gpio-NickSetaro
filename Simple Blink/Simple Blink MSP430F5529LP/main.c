#include <msp430.h>

/*
 * @author Nick Setaro
 * @version 9.14.2018
 */

int main (void) {
    WDTCTL = WDTPW | WDTHOLD; //stop watchdog timer
    P1SEL &= ~BIT0; //set path to LED
    P2SEL &= ~BIT0;
    P1DIR |= BIT0;  //set pin direction to output
    while (1) {
        P1OUT ^= BIT0; //toggle least significant bit
        __delay_cycles(200000); //delay
    }
    return 0;
}
