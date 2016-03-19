#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <Messanger.h>

ESP8266WiFiMulti WiFiMulti;
Messanger ms;

void setup() {
	Serial.begin(115200);
    delay(10);

	WiFiMulti.addAP("AndroidAP", "AimtecHackaton");
  
  	while(WiFiMulti.run() != WL_CONNECTED) {
    	delay(500);
    	Serial.print(".");
  	}
}

void loop() {
	Serial.println("Request");
	ms.sendPirState(true, "1");
	delay(5000);
}
