/*
  Messanger.h - interface library for pir 
*/

#ifndef Messanger_h
#define Messanger_h

class Messanger
{
  public:
    void sendPirState(bool state, char* secret);
   private:
   	char* _host;
   	void sendMessage(char* message);

};

#endif
