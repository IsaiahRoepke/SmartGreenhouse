#include <msp430.h> 


/**
 * main.c
 */
void resetButtonInit();
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

void resetButtonInit();

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
