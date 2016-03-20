/*
  WirelessConnection.cpp - interface library for WirelessConnection
*/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Messanger.h>

void Messanger::sendPirState(int sensorId, bool state, char* secret){
	this->sendMessage(String("GET /entry/put_pir_state?secret=" + String(secret) + "&sensor_id=" + String(sensorId) + "&value=") + state);
}

void Messanger::sendGasValue(int sensorId, int value, char* secret){
	this->sendMessage(String("GET /entry/put_gas_value?secret=" + String(secret) + "&sensor_id=" + String(sensorId) + "&value=") + value);
}

void Messanger::sendDistance(int sensorId, int distance, char* secret){
	this->sendMessage(String("GET /entry/put_distance?secret=" + String(secret) + "&sensor_id=" + String(sensorId) + "&value=") + distance);
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
