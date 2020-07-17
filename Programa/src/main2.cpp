
/* GoTo
    logger local
    configurar dispositivo na rede local quando ligar
    reduzir consumo de energia;
*/

#include <Arduino.h>
#include <SoundGui.h>
#include <BlinkGui.h>
#include <UltrassomMediana.h>
#include <EnviarFirebase.h>
#include <ConectaWifi.h>
#include <GetDataTime.h>
#include <Giroscopio.h>
#include <Mensagem.h>
#include <Scheduler.h>

Mensagem mensagem; // struct de troca de mensagens entre as tasK
SoundGui soundGuiTask(&mensagem);
BlinkGui blinkGuiTask(&mensagem);
UltrassomMediana ultrassomMedianaTask; //Alan

EnviarFirebase enviarFirebaseTask(&mensagem);
//ConectaWifi conectaWifiTask(&mensagem);
GetDataTime getDataTimeTask(&mensagem);

//Giroscopio giroscopioTask(&mensagem);

//#include <EnviarFirebase2.h>
//EnviarFirebase2 enviarFirebaseTask;
void setup()
{
  //configurações
  Serial.begin(115200);
  mensagem.wifiSsid[0] = "jb1";
  mensagem.wifiPass[0] = "besoente#13";
  mensagem.wifiSsid[1] = "jb2";
  mensagem.wifiPass[1] = "besoente#13";
  mensagem.wifiSsid[2] = "JB3";
  mensagem.wifiPass[2] = "joaofilho9000";
  mensagem.wifiCont = 3;
  mensagem.timeZone = -3; // zona de tempo do brasil é -3*/

  // blinkGuiTask.setMensagem(&mensagem);
  //soundGuiTask.setMensagem(&mensagem);
  //ultrassomMedianaTask.setMensagem(&mensagem);*/
  //conectaWifiTask.setMensagem(&mensagem);
  //getDataTimeTask.setMensagem(&mensagem);
  //enviarFirebaseTask.setMensagem(&mensagem);
  //giroscopioTask.setMensagem(&mensagem);

  Scheduler.start(&soundGuiTask);
  Scheduler.start(&blinkGuiTask);
  //Scheduler.start(&ultrassomMedianaTask);
  Scheduler.start(&enviarFirebaseTask);
  //Scheduler.start(&conectaWifiTask);
  Scheduler.start(&getDataTimeTask);

  // Scheduler.start(&giroscopioTask);
  Scheduler.begin();
}

void loop()
{
}