#include <EnviarFirebase.h>

EnviarFirebase::EnviarFirebase(Mensagem *newMensagem)
{
    mensagem = newMensagem;
}

void EnviarFirebase::setupWiFi()
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
                //TODO depois de n tentativas abrir sistema para configuração de wifi e salvar no disco
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

void EnviarFirebase::setMensagem(Mensagem *newMensagem)
{
    mensagem = newMensagem;
}

void EnviarFirebase::enviar(String tag, String dado)
{
    if (Firebase.setString(firebaseData, path + "/" + tag, dado))
    {
        delay(500);
    }
    else
    {
        Serial.println("Erro para enviar firebase");
        Serial.println("Motivo: " + firebaseData.errorReason());
        delay(500);
    }
}

void EnviarFirebase::setup()
{
    setupWiFi();
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);
    Firebase.setReadTimeout(firebaseData, 1000 * 60);
    Firebase.setwriteSizeLimit(firebaseData, "tiny");
    path=path+"/"+mensagem->nome;
    enviar("mac", mensagem->mac);
    enviar("ip", mensagem->ip);
    enviar("timeInicial", mensagem->dataTimeInicial);
    enviar("hora", mensagem->hora);
    enviar("data", mensagem->data);
}

void EnviarFirebase::loop()
{
    delay(2000);
    enviar("hora", mensagem->hora);
    enviar("data", mensagem->data);
    enviar("volume", mensagem->volume);
    enviar("dados/" + mensagem->dataTime, mensagem->volume);
    mensagem->sleep = true;
}
