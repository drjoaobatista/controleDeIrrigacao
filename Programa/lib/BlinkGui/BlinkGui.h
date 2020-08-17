#ifndef BLINKGUI_H
#define BLINKGUI_H

#include <Scheduler.h>
#include <Mensagem.h>
//TODO usar código Morse?
class BlinkGui : public Task
{
public:
    BlinkGui(Mensagem *newMensagem);
    void setMensagem(Mensagem *newMensagem);

protected:
    void setup();
    void loop();

private:
    int pinLedEsp;
    int pinLedMcu;

    uint8_t stateMcu = HIGH;
    uint8_t stateEsp = HIGH;
    int slow = 800;
    int fast = 300;
    Mensagem *mensagem;

    void blink(int time, uint8_t pinLed, uint8_t *state);
    void blink1();
    void blink2();
    void blink3();
};
#endif
