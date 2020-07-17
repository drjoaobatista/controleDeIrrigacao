#include <SoundGui.h>
SoundGui::SoundGui(Mensagem *newMensagem)
{
    mensagem = newMensagem;
}
void SoundGui::setMensagem(Mensagem *newMensagem)
{
    mensagem = newMensagem;
}
void SoundGui::setup()
{
    pinMode(pinBuzz, OUTPUT);
    digitalWrite(pinBuzz, HIGH);
    delay(1000);
    digitalWrite(pinBuzz, LOW);
}
void SoundGui::loop()
{
    delay(5000);
    if (mensagem->erro)
    {
        mensagem->erro = false;
        Serial.println(mensagem->erroTxt);
    }
}
