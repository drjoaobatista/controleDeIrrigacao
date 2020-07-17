
/* GoTo
    logger local
    configurar dispositivo na rede local quando ligar
    reduzir consumo de energia;
*/

#include <Arduino.h>
//#include <SoundGui.h>
//#include <BlinkGui.h>
//#include <UltrassomMediana.h>
//#include <EnviarFirebase.h>
//#include <ConectaWifi.h>
//#include <GetDataTime.h>
//#include <Giroscopio.h>
//#include <Mensagem.h>
#include <Scheduler.h>

//#include <EnviarFirGetDataTime getDataTimeTask;ebase2.h>
//EnviarFirebase2 enviarFirebaseTask;
void setup()
{
  //Mensagem mensagem; // struct de troca de mensagens entre as tasK
  //configurações
  Serial.begin(115200);
  delay(1000);
  Serial.println("configurações basicas");
  //mensagem.wifiSsid[0] = "jb1";
  //mensagem.wifiPass[0] = "besoente#13";
  //mensagem.wifiSsid[1] = "jb2";
  //mensagem.wifiPass[1] = "besoente#13";
  //mensagem.wifiSsid[2] = "JB3";
  //mensagem.wifiPass[2] = "joaofilho9000";
  //mensagem.wifiCont = 3;
  //mensagem.timeZone = -3; // zona de tempo do brasil é -3*/

  Serial.println("criando objetos");
 // SoundGui soundGuiTask;
 // BlinkGui blinkGuiTask;
  //UltrassomMediana ultrassomMedianaTask; //Alan
  //ConectaWifi conectaWifiTask(&mensagem);
  //ConectaWifi conectaWifiTask();
  // EnviarFirebase enviarFirebaseTask(&mensagem);
  //  GetDataTime getDataTimeTask;
  //Giroscopio giroscopioTask;
  //blinkGuiTask.setMensagem(&mensagem);
  //soundGuiTask.setMensagem(&mensagem);
  //ultrassomMedianaTask.setMensagem(&mensagem);
  //conectaWifiTask.setMensagem(&mensagem);
  //getDataTimeTask.setMensagem(&mensagem);
  //enviarFirebaseTask.setMensagem(&mensagem);
  //giroscopioTask.setMensagem(&mensagem);

  //Serial.println("inanciando objetos");
  //Scheduler.start(&soundGuiTask);
 // Scheduler.start(&blinkGuiTask);
  //Scheduler.start(&ultrassomMedianaTask);
  // Scheduler.start(&conectaWifiTask);
  // Scheduler.start(&enviarFirebaseTask);

  // Scheduler.start(&getDataTimeTask);
  // Scheduler.start(&giroscopioTask);
  Serial.println("comecando loop");
  Scheduler.begin();
}

void loop()
{
}