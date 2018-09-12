#include <msp430.h> 



/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1SEL &= ~(BIT0 + BIT6);
	P1SEL2 &= ~(BIT0 + BIT6);
	P1DIR |= (BIT0 + BIT6);
	
	P1OUT |= BIT0;
	P1OUT &= ~BIT6;

	while (1) {
	    P1OUT ^= BIT0; //toggle bit 0 to turn on/off LED
	    __delay_cycles(200000); //delay for second LED

	    P1OUT ^= BIT6; //toggle bit 6 to turn on/off LED
	    __delay_cycles(50000); //delay for first LED
	}
	return 0;
}
