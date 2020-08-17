#include <Arduino.h>
#include <BlinkGui.h>
#include <DeepSleep.h>
#include <EnviarFirebase.h>
#include <GetDataTime.h>
#include <Mensagem.h>
#include <Scheduler.h>
#include <UltrassomMediana.h>

Mensagem mensagem; // struct de configuração e troca de mensagens entre as tasK
BlinkGui blinkGuiTask(&mensagem);
EnviarFirebase enviarFirebaseTask(&mensagem);
DeepSleep deepSleep(&mensagem);
GetDataTime getDataTimeTask(&mensagem);
UltrassomMediana ultrassomMedianaTask(&mensagem); //Alan

void setup()
{
  //configurações
  Serial.begin(115200);
  mensagem.wifiSsid[0] = "jb1";
  mensagem.wifiPass[0] = "besoente#13";
  mensagem.wifiCont = 1; //número de redes que ele tenta se conectar 
  mensagem.timeZone = -3; // zona de tempo do brasil é -3*/
  //setup's
  Scheduler.start(&blinkGuiTask);
  Scheduler.start(&ultrassomMedianaTask);
  Scheduler.start(&enviarFirebaseTask);
  Scheduler.start(&getDataTimeTask);
  Scheduler.start(&deepSleep);
  //loop's
  Scheduler.begin();
}

void loop()
{
}