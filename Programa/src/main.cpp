
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
UltrassomMediana ultrassomMedianaTask(&mensagem); //Alan
EnviarFirebase enviarFirebaseTask(&mensagem);
//ConectaWifi conectaWifiTask(&mensagem); // erro no enviar no firebase 
GetDataTime getDataTimeTask(&mensagem);
Giroscopio giroscopioTask(&mensagem);

void setup()
{ // TODO ler e gravar dados no file sistem:  se iniciando agora ler incrementa o numero de inicializações e em seguida 
// grava de volta a mensagem. modifica a varialvel iniciando para false.
// se a variavel false ativada verifica a variavel ateração se hove alteração grava a mensagem. modifica depois a 
// variavel aletracao para false.
// se ouver erro para gravar tentar depois. 
// gravar um arquivo de log e disponibilizar por wifi, enviar para o firebase quando pedido. 

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

  //setup's
  Scheduler.start(&soundGuiTask);
  Scheduler.start(&blinkGuiTask);
  Scheduler.start(&ultrassomMedianaTask);
  Scheduler.start(&enviarFirebaseTask);
  //Scheduler.start(&conectaWifiTask); // erro
  Scheduler.start(&getDataTimeTask);
  Scheduler.start(&giroscopioTask);
  //loop's
  Scheduler.begin();
}

void loop()
{
}