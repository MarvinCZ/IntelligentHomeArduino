
#include <Pir.h>
#include <Ultrasonic.h>
#include <Gas.h>

Gas gas(A0, 350);

void setup() {
  Serial.begin(9600);
}

void loop() {
	while(!gas.exceeds()){
		delay(200);
		Serial.println(gas.getState());
	}
	Serial.println("Limit " + String(gas.getLimit()) + " was exceeded.");
	delay(500);
}
