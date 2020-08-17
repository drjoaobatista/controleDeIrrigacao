#include <Arduino.h>
#include <BlinkGui.h>
#include <UltrassomMediana.h>
#include <EnviarFirebase.h>
#include <GetDataTime.h>
#include <Mensagem.h>
#include <Scheduler.h>

Mensagem mensagem; // struct de troca de mensagens entre as tasK
BlinkGui blinkGuiTask(&mensagem);
UltrassomMediana ultrassomMedianaTask(&mensagem); //Alan
EnviarFirebase enviarFirebaseTask(&mensagem);
GetDataTime getDataTimeTask(&mensagem);


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
  //loop's
  Scheduler.begin();
}

void loop()
{
}