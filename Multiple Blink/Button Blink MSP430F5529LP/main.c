#include  <msp430.h> //

/*
 * @author Nick Setaro
 * @version 9.14.2018
 */

void main(void)
{
        unsigned int value = 0;
        WDTCTL = WDTPW + WDTHOLD;   // Stop watchdog timer

        P1REN |= BIT1;              //enable resistor on P1.1
        P1OUT = BIT1;               //set resistor to pull-up, set P1.0 low
        P1DIR = BIT0;               //set P1.0 as output and P1.1 as input
        P4OUT = BIT7;               //set P4.7 high
        while (1) {
            if (!(P1IN &BIT1)) {    //if button is pressed
                P1OUT |= BIT0;      //turn LED on
            } else {                //if button is not pressed
                P1OUT &= ~BIT0;      //turn LED off
            }
        }
}
