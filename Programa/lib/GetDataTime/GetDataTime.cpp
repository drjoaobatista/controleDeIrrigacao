#include <GetDataTime.h>

GetDataTime::GetDataTime(Mensagem *newMensagem)
{
  mensagem = newMensagem;
}

void GetDataTime::setMensagem(Mensagem *newMensagem)
{
  mensagem = newMensagem;
}

void GetDataTime::setupDateTime()
{
  if (mensagem->wifi)
  {
    DateTime.setTimeZone(TIME_ZONE);
    DateTime.begin();
    if (!DateTime.isTimeValid())
    {
      Serial.println("Falha para obter a hora do servidor.");
      mensagem->time = false;
    }
    else
    {
      ms = millis();
      mensagem->time = true;
      time_t t = DateTime.now();
      mensagem->dataTimeInicial = DateFormatter::format("%d/%m/%Y %H:%M:%S", t);
    }
  }
}

void GetDataTime::update()
{
  if (mensagem->time)
  {
    time_t t = DateTime.now();
    mensagem->data = DateFormatter::format("%d/%m/%Y", t);
    mensagem->hora = DateFormatter::format("%H:%M:%S", t);
    mensagem->dataTime = DateFormatter::format("%Y/%m/%d/ %H:%M:%S", t);
    Serial.println("data :" + mensagem->data);
    Serial.println("hora :" + mensagem->hora);
  }
  else
  {
    setupDateTime();
  }
}

void GetDataTime::setup()
{
  while (!mensagem->wifi)
  {
    delay(1000);
  }
  setupDateTime();
  update();
}

void GetDataTime::loop()
{
  delay(1000);
  if ((ms - millis()) > mensagem->tempoAtualizar)
  {
    setupDateTime();
  }
  update();
}
