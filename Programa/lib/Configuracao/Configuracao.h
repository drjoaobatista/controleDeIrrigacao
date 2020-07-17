// abrir configuração se não exixtir cria. 
// se hover alteração salva novamente.

#ifndef CONFIGURACAO_H
#define CONFIGURACAO_H

#include <Scheduler.h>
#include <Mensagem.h>
#include"FS.h"

class Configuracao : public Task
{
public:
    void setMensagem(Mensagem *newMensagem);

protected:
    void setup();
    void loop();

private:

    Mensagem *mensagem;
    const char* filename = "/configuracao.txt";
    void formatar()
};
#endif
