#ifndef SOUNDGUI_H
#define SOUNDGUI_H
#include <Scheduler.h>
#include <Mensagem.h>
#include <Arduino.h>

class SoundGui : public Task
{
public:
    SoundGui(Mensagem *newMensagem);
    void setMensagem(Mensagem *newMensagem);

protected:
    void setup();
    void loop();

private:
    Mensagem *mensagem;
    int pinBuzz = D3;
};

#endif