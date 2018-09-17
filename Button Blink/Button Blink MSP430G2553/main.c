#include  <msp430.h> // For the M430G2553 chip,

/*
 * @author Nick Setaro
 * @version 9.14.2018
 */

void main(void)
{
        int value = 0;
        WDTCTL = WDTPW + WDTHOLD;               // Stop watchdog timer


        P1DIR &= ~BIT3;                         // Push Port 1 P1.3 (push button) as input
        P1DIR |= BIT6;                          // Set P1.6 (LED) to output direction
        P1SEL &= ~(BIT3 | BIT6);                // Select Port 1 P1.3 (push button)

        P1OUT &= ~BIT6;                         // Set the LED off


        while( 1 ) {
            value = P1IN & BIT3;                //check if button is pressed
                if( value == 0)                 // Push button down when bit 3 == 0
                        P1OUT |= BIT6;          // Set LED on when button down
                else
                        P1OUT &= ~BIT6;         // Set LED off when button off
        }
}
