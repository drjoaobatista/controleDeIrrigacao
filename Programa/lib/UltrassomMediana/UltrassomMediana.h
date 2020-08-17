// Instituto Federal de Sergipe - Campus São Cristóvão
// Pesquisa 2019-2 Medição do nível d'água em reservatórios;
#ifndef ultrassomMediana_H
#define ultrassomMediana_H

#include <Scheduler.h>
#include <Mensagem.h>

class UltrassomMediana : public Task
{
public:
    UltrassomMediana(Mensagem *newMensagem);
    void setMensagem(Mensagem *newMensagem);

protected:
    void setup();
    void loop();

private:
    Mensagem *mensagem;
    int echoPin;
    int trigPin;
    long medianaDistancias(int qtAmostras);
    long medirDistancia(int echoPin, int trigPin);
};
#endif