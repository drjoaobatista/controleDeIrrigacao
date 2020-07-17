#include <BlinkGui.h>
BlinkGui::BlinkGui(Mensagem *newMensagem)
{
    mensagem = newMensagem;
}
void BlinkGui::setMensagem(Mensagem *newMensagem)
{
    mensagem = newMensagem;
}
void BlinkGui::setup()
{
    pinMode(pinLedEsp, OUTPUT);
    pinMode(pinLedMcu, OUTPUT);
}

void BlinkGui::loop()
{
    switch (mensagem->cod)
    {
    case 1:
        blink1();
        break;

    case 2:
        blink2();
        break;

    case 3:
        blink3();
        break;

    default:
        blink1();
        break;
    }
}

void BlinkGui::blink(int time, uint8_t pinLed, uint8_t *state)
{
    *state = *state == HIGH ? LOW : HIGH;
    digitalWrite(pinLed, *state);
    delay(time);
}

void BlinkGui::blink1()
{
    blink(slow, pinLedEsp, &stateEsp);
}

void BlinkGui::blink2()
{
    blink(fast, pinLedEsp, &stateEsp);
    blink(fast, pinLedEsp, &stateEsp);
    blink(slow, pinLedEsp, &stateEsp);
    blink(slow, pinLedEsp, &stateEsp);
}

void BlinkGui::blink3()
{
    blink(fast, pinLedEsp, &stateEsp);
}
