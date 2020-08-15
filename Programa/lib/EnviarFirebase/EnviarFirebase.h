#ifndef ENVIARFIREBASE_H
#define ENVIARFIREBASE_H
#include <FirebaseESP8266.h> //include first
#include <ESP8266WiFi.h>     //the second
#include <Arduino.h>
#include <Scheduler.h>
#include <Mensagem.h>
#include <ArduinoJson.h>
#define FIREBASE_HOST "pibic-43c92.firebaseio.com"
#define FIREBASE_AUTH "XsbVOsAdrorLm60qJuZeQpI2ddCQjqtbTW5Xnntf" //#TODO Mascará informação
class EnviarFirebase : public Task
{
public:
    EnviarFirebase(Mensagem *newMensagem);
    void setMensagem(Mensagem *newMensagem);

protected:
    void setup();
    void loop();
    FirebaseData firebaseData;

private:
    void enviar(String tag, String dado);
    Mensagem *mensagem;
    String path = "/agua";
    int tempoEspera = 1000;
    void setupWiFi();
};
#endif