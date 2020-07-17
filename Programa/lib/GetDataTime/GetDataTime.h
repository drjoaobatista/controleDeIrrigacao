#ifndef GETDATATIME_H
#define GETDATATIME_H

#include <Arduino.h>
#include <ctime>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ESPDateTime.h>
#include <Scheduler.h>
#include <Mensagem.h>

class GetDataTime : public Task
{
public:
  GetDataTime(Mensagem *newMensagem);
  void setMensagem(Mensagem *newMensagem);

protected:
  void setup();
  void loop();

private:
  unsigned long ms = millis();
  Mensagem *mensagem;
  void setupDateTime();
  void update();
  int TIME_ZONE = -3;
};
#endif