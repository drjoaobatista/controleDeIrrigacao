#ifndef CONECTAWIFI_H
#define CONECTAWIFI_H
#include <Arduino.h>
#include <FirebaseESP8266.h> //include first
#include <ESP8266WiFi.h>     //the second
#include <WiFiManager.h>
#include <Scheduler.h>
#include <Mensagem.h>

class ConectaWifi : public Task
{
public:
    ConectaWifi(Mensagem *newMensagem);
    ConectaWifi();
    void setMensagem(Mensagem *newMensagem);

protected:
    void setup();
    void loop();

private:
    unsigned long lastMs = 0;
    unsigned long ms = 0;
    void setupWiFi();
    Mensagem *mensagem;
};
#endif