/*
  Messanger.h - interface library for pir 
*/

#ifndef Messanger_h
#define Messanger_h

class Messanger
{
  public:
    void sendPirState(int id, bool state, int secret);
    void sendGasValue(int id, int value, int secret);
    void sendDistance(int id, int distance, int secret);
   private:
   	char* _host;
   	void sendMessage(String message);

};

#endif
