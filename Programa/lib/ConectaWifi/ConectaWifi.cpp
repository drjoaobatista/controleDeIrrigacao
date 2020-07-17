// salvar todos wifi
// se nenhum wifi funcionar criar um wifi direct com senha para configurarcao manual
#include <ConectaWifi.h>
ConectaWifi::ConectaWifi(Mensagem *newMensagem)
{
  Serial.println("construtor ContectaWifi");
  mensagem = newMensagem;

}
ConectaWifi::ConectaWifi()
{
  Serial.println("construtor ContectaWifi2");
}

void ConectaWifi::setMensagem(Mensagem *newMensagem)
{
  mensagem = newMensagem;
}

void ConectaWifi::setupWiFi()
{
  int cont = 0;
  int cont2 = 50;
  int cont3 = 0;
  int r = 0;
  WiFi.mode(WIFI_STA);
  while (WiFi.status() != WL_CONNECTED)
  {
    if (cont2 > 40)
    {
      Serial.println("");
      Serial.print("conectando a redde ");
      Serial.print(mensagem->wifiSsid[r]);
      WiFi.begin(mensagem->wifiSsid[r], mensagem->wifiPass[r]);
      cont2 = 0;
      cont = cont + 1;
      r = cont % mensagem->wifiCont;
      if (r == 0)
      {
        cont3 = cont3 + 1;
        //depois de n tentativas abrir sistema para configuração de wifi e salvar no disco
      }
    }
    Serial.print(".");
    delay(300);
    cont2 = cont2 + 1;
  }
  mensagem->mac = String(WiFi.macAddress());
  mensagem->ip = WiFi.localIP().toString();
  mensagem->nome = WiFi.hostname();
  mensagem->wifi = true;
  Serial.println("");
  Serial.println("mac : " + mensagem->mac);
  Serial.println("ip : " + mensagem->ip);
  Serial.println("nome : " + mensagem->nome);
}

void ConectaWifi::setup()
{
 Serial.println("setup ContectaWifi");
 setupWiFi();
}

void ConectaWifi::loop()
{
  Serial.println("wifi loop");
  delay(600000);
  if (WiFi.status() == WL_DISCONNECTED)
  {
    mensagem->wifi = false;
    setupWiFi();
  }
}