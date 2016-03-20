#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <Messanger.h>

#include <Pir.h>
#include <Gas.h>
#include <Ultrasonic.h>

ESP8266WiFiMulti WiFiMulti;
Messanger ms;
int secret = 1;

int maxDistance = 500;

Gas gas0(A0);

Pir pir0(D0);
Pir pir1(D1);
Pir pir2(D2);
Pir pir3(D3);

Ultrasonic dist0(D4, D5, maxDistance * 58);
Ultrasonic dist1(D6, D7, maxDistance * 58);
Ultrasonic dist2(D8, D9, maxDistance * 58);

void initializePirs(){
	Serial.print("Initializing PIRs ");
    
	int startTime = millis();
	while(millis() - startTime < 20000){
		Serial.print(".");
		delay(500);
	}
	if(!pir0.getState())
		pir0.setActive(true);
	if(!pir1.getState())
		pir1.setActive(true);
	if(!pir2.getState())
		pir2.setActive(true);
	if(!pir3.getState())
		pir3.setActive(true);

	Serial.println(" done");
}

void initializeGas(){
	Serial.print("Initializing Gas");

	if(gas0.getValue() > 10)
		gas0.setActive(true);

	Serial.println(" done");
}

void initializeUltrasonic(){
	Serial.print("Initializing Ultrasonic");

	if(dist0.Ranging(CM) > 0 && dist0.Ranging(CM) < maxDistance)
		dist0.setActive(true);
	if(dist1.Ranging(CM) > 0 && dist1.Ranging(CM) < maxDistance)
		dist1.setActive(true);
	if(dist2.Ranging(CM) > 0 && dist2.Ranging(CM) < maxDistance)
		dist2.setActive(true);

	Serial.println(" done");
}


void connectToWiFi(){
	Serial.print("Connecting to WiFi ");
	
	WiFiMulti.addAP("AndroidAP", "AimtecHackaton");
	while(WiFiMulti.run() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}

	Serial.println(" done");
}

void setup() {
	Serial.begin(115200);
	delay(1000);

	initializePirs();
	initializeGas();
	initializeUltrasonic();
	connectToWiFi();

}

void loop() {
	Serial.println("--Request--");

	bool state = false;
	if(pir0.isActive()){
		state = pir0.getState();
		Serial.println("PIR_0: " + String(state));
		ms.sendPirState(0, state, secret);
	}
	if(pir1.isActive()){
		state = pir1.getState();
		Serial.println("PIR_1: " + String(state));
		ms.sendPirState(1, state, secret);
	}
	if(pir2.isActive()){
		state = pir2.getState();
		Serial.println("PIR_2: " + String(state));
		ms.sendPirState(2, state, secret);
	}
	if(pir3.isActive()){
		state = pir3.getState();
		Serial.println("PIR_3: " + String(state));
		ms.sendPirState(3, state, secret);
	}

	int distance = 0;
	if(dist0.isActive()){
		int distance = dist0.Ranging(CM);
		Serial.println("DIST_0: " + String(distance));
		ms.sendDistance(4, distance, secret);
	}
	if(dist1.isActive()){
		int distance = dist1.Ranging(CM);
		Serial.println("DIST_1: " + String(distance));
		ms.sendDistance(5, distance, secret);
	}
	if(dist2.isActive()){
		int distance = dist2.Ranging(CM);
		Serial.println("DIST_2: " + String(distance));
		ms.sendDistance(6, distance, secret);
	}

	int value = 0;
	if(gas0.isActive()){
		value = gas0.getValue();
		Serial.println("GAS_0: " + String(value));
		ms.sendGasValue(4, value, secret);
	}
	delay(9500);
}