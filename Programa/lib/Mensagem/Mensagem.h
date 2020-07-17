#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <Arduino.h>
struct Mensagem
{
  String wifiSsid[100];
  String wifiPass[100];
  int wifiCont = 0;
  
  // configuração dos pinos
  int pinScl=D1;
  int pinSda=D2;
  int pinBuzz = D3;
  int pinLedEsp = D4; //fixo
  int pinLedMcu = D0; //fixo
  int echoPin = D7;
  int trigPin = D8;

  bool wifi = false;
  bool fomatar = false;
  bool time = false;
  bool erro = false;
  String mac;
  String ip;
  String nome = "none";
  String dataTime = "none";
  String data = "none";
  String hora = "none";
  String volume = "nulo";
  String erroTxt = "erro??";
  String dataTimeInicial="  ";
  int numeroBoot;
  int timeZone=-3;
  unsigned long tempoAtualizar = 24 * 60 * 60 * 1000;
  int cod = 1;

};

#endif