#include <msp430.h> 


/**
 * main.c
 */

void gasSensorInit();
void humiditySensorInit();
void tempSensorInit();
void soilSensorInit();
void wifiInit();



int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	gasSensorInit();
	humiditySensorInit();
	tempSensorInit();
	soilSensorInit();
	wifiInit();


	return 0;
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
