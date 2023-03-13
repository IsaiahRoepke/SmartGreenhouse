#include <msp430.h> 


/**
 * main.c
 */
void resetButtonInit(); //to restart/reset the MSP
void gasSensorInit(); //takes I2C input
void humiditySensorInit();
void tempSensorInit(); //uses thermistor as of now. Talk to Trafford to figure out how to implement
void soilSensorInit(); //uses pulsewidth modulation as the output. Ask trafford what the communication type is. Can't find datasheet
void wifiInit(); //Initialize wifi module. How is this done on the MSP430?



int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
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

void gasSensorInit(){

}

void humiditySensorInit(){

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

}
