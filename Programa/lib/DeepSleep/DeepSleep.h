#ifndef DEEPSLEEP_H
#define DEEPSLEEP_H

#include <Scheduler.h>
#include <Mensagem.h>

class DeepSleep : public Task
{
public:
    DeepSleep(Mensagem *newMensagem);
    void setMensagem(Mensagem *newMensagem);

protected:
    void setup();
    void loop();

private:
    Mensagem *mensagem;
};
#endif
