/*
  Messanger.h - interface library for pir 
*/

#ifndef Messanger_h
#define Messanger_h

class Messanger
{
  public:
    void sendPirState(int sensorId, bool state, char* secret);
    void sendGasValue(int sensorId, int value, char* secret);
    void sendDistance(int sensorId, int distance, char* secret);
   private:
   	char* _host;
   	void sendMessage(String message);

};

#endif
