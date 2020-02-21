#include <Arduino.h>
#include <unity.h>

#include "sunset.h"

/* I'm in the midwest, so this is what I use for my home */
#define LATITUDE        42.340118
#define LONGITUDE       -7.864690
#define CST_OFFSET      +1


SunSet sun;

void setup()
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(5000);

    UNITY_BEGIN();    // IMPORTANT LINE!

	/* Set our position and a default timezone value */
	sun.setPosition(LATITUDE, LONGITUDE, CST_OFFSET);
}

void loop()
{
    double sunrise;
	double sunset;
    sun.setCurrentDate(2020, 02, 20);

    sunrise = sun.calcSunrise();
	sunset = sun.calcSunset();
    Serial.print("Sunrise is ");
	Serial.print(sunrise);
	Serial.println(" minutes past midnight. ");
	Serial.print(sunrise/60);
	Serial.println(" hours past midnight.");
	Serial.print("Sunset is ");
	Serial.print(sunset);
	Serial.println(" minutes past midnight. ");
    Serial.print(sunset/60);
	Serial.println(" hours past midnight.");
	delay(1000);
      
    UNITY_END(); // stop unit testing
}