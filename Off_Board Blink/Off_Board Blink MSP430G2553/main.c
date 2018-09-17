#include <msp430.h>

/*
 * @author Nick Setaro
 * @version 9.17.2018
 */

void main( void )
{
   WDTCTL = WDTPW + WDTHOLD; // Disable watchdog timer

   P1DIR = BIT1; // P1.0 is an output
   P2DIR = BIT0; // P2.0-7 are inputs


   while(1)
   {
       P1OUT = BIT1;     // LED on - set P1.0 high
       __delay_cycles(100000); // Delay
       P1OUT = BIT0;     // LED off - set P1.0 low
       __delay_cycles(900000); // Delay
   }
}
