#include <DeepSleep.h>

DeepSleep::DeepSleep(Mensagem *newMensagem)
{
    mensagem = newMensagem;
}

void DeepSleep::setMensagem(Mensagem *newMensagem)
{
    mensagem = newMensagem;
}

void DeepSleep::setup()
{
   mensagem->sleep=false;
}

void DeepSleep::loop()
{
    if (mensagem->sleep)
    {
         ESP.deepSleep(mensagem->sleepTime);//Dorme por 1 Minuto (Deep-Sleep em Micro segundos).
    }
    
}
