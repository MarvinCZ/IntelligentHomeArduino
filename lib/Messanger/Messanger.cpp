/*
  WirelessConnection.cpp - interface library for WirelessConnection
*/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Messanger.h>

void Messanger::sendPirState(int id, bool state, int secret){
	this->sendMessage(String("GET /entry/put_moving?secret=" + String(secret) + "&id=" + String(id) + "&value=") + String(state));
}

void Messanger::sendGasValue(int id, int value, int secret){
	this->sendMessage(String("GET /entry/put_gas_value?secret=" + String(secret) + "&id=" + String(id) + "&value=") + String(value));
}

void Messanger::sendDistance(int id, int distance, int secret){
	this->sendMessage(String("GET /entry/put_distance?secret=" + String(secret) + "&id=" + String(id) + "&value=") + String(distance));
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
