#include <msp430.h> 


/**
 * main.c
 */
void resetButtonInit(); //to restart/reset the MSP
void gasSensorInit(); //takes I2C input
void humiditySensorInit(); //takes I2C input
void tempSensorInit(); //uses thermistor as of now. Talk to Trafford to figure out how to implement
void soilSensorInit(); //uses pulsewidth modulation as the output. Ask trafford what the communication type is. Can't find datasheet
void wifiInit(); //Initialize wifi module. How is this done on the MSP430?



int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &= ~LOCKLPM5; //Disable LPM

	__enable_interrupt();
	
	gasSensorInit();
	humiditySensorInit();
	tempSensorInit();
	soilSensorInit();
	wifiInit();

	while(1){


	}


	return 0;
}

void resetButtonInit(){
      P2OUT |= BIT3;                          // Configure P2.3 as pulled-up
      P2REN |= BIT3;                          // P2.3 pull-up register enable
      P2IES |= BIT3;                         // P2.3 High to low edge/active low
      P2IE |= BIT3;                           // P2.3 interrupt enabled

}

void gasSensorInit(){ //takes I2C, use ports 1.2 and 1.3
    UCB0CTLW0 |= UCSSEL_3; //SMCLK
    UCB0BRW = 1; //Divides the clk signal. Configure later

    UCB0CTLW0 |= UCMODE_3; //Put into I2C mode
    UCB0CTLW0 |= UCMST; //Put into master mode. (why?)
    UCB0CTLW0 |= ~UCTR; //Put into Rx mode
    UCB0I2CSA = 0x0068; //Slave address = 0x68

    UCB0CTLW1 |= UCASTP_2; //Auto stop when UCB0TBCNT reached. (What does this do?)

    P1SEL1 &= ~BIT3;
    P1SEL0 |= BIT3;

    P1SEL1 &= ~BIT2;
    P1SEL0 |= BIT2;

    UCB0CTLW0 &= ~UCSWRST //Take eUSCI_B0 out of SW reset

    UB0IE |= UCTXIE0; //enable interrupts

}

void humiditySensorInit(){ //takes I2C, use ports 4.6 and 4.7
    UCB1CTLW0 |= UCSSEL_3; //SMCLK
        UCB0BRW = 1; //Divides the clk signal. Configure later

        UCB1CTLW0 |= UCMODE_3; //Put into I2C mode
        UCB1CTLW0 |= UCMST; //Put into master mode. (why?)
        UCB1CTLW0 |= ~UCTR; //Put into Rx mode
        UCB1I2CSA = 0x0080; //Slave address = 0x80

        UCB1CTLW1 |= UCASTP_2; //Auto stop when UCB1TBCNT reached. (What does this do?)

        P4SEL1 &= ~BIT6;
        P4SEL0 |= BIT6;

        P4SEL1 &= ~BIT7;
        P4SEL0 |= BIT7;

        UCB1CTLW0 &= ~UCSWRST //Take eUSCI_B1 out of SW reset

        UB1IE |= UCTXIE0; //enable interrupts
}

void tempSensorInit(){

}

void soilSensorInit(){

}

void wifiInit(){

}

#pragma vector=PORT2_VECTOR //port 2 interrupt vector
__interrupt void Port_2(void){
    P2IFG &= ~BIT3;
    //Reset for the MSP430 goes here
    //activate watchdog and let it bite

    WDTCTL = WDTPW + WDTCNTCL;

    for(;;);
}
