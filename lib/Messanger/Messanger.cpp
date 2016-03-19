/*
  WirelessConnection.cpp - interface library for WirelessConnection
*/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Messanger.h>

void Messanger::sendPirState(bool state, char* secret){
	this->sendMessage(String("GET /entry/put_moving?secret=1&kind=movement&value=") + state);
}

void Messanger::sendMessage(String message){
	WiFiClient client;
	const int httpPort = 80;
	if (!client.connect("104.197.201.95", httpPort)) {
		Serial.println("connection failed");
		return;
	}
	delay(500);
	client.print(message +
		" HTTP/1.1\r\nHost: 104.197.201.95" + "\r\n" + 
		"Connection: close\r\n\r\n");
	client.available();
	client.stop();	
}
