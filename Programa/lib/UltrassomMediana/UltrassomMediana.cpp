// Instituto Federal de Sergipe - Campus São Cristóvão
// Pesquisa 2019-2 Medição do nível d'água em reservatórios;
#include <UltrassomMediana.h>
UltrassomMediana::UltrassomMediana(Mensagem *newMensagem)
{
    mensagem = newMensagem;
}

void UltrassomMediana::setMensagem(Mensagem *newMensagem)
{
    mensagem = newMensagem;
}

void UltrassomMediana::setup()
{
    pinMode(echoPin, INPUT);  // define o pino 5 como entrada (recebe)
    pinMode(trigPin, OUTPUT); // define o pino 3 como saida (envia)
}

void UltrassomMediana::loop()
{
    // Medir Distância
    //Serial.print("Distancia em CM: ");
    //Serial.println(medirDistancia(echoPin,trigPin));

    // Medir 10 distâncias e usar o valor central;
    Serial.println("----- ----- ----- ----- -----");
    Serial.println("Iniciando rajada de medição.");
    Serial.println("----- ----- ----- ----- -----");
    long distCentral = medianaDistancias(24);
    Serial.print("O valor central medido foi: ");
    Serial.println(distCentral);
    mensagem->volume = distCentral; //criar função que calcula volume
    delay(10000);                   //espera 1 segundo para fazer a leitura novamente
}

/*
 * Função que mede a distância em centímetros
 * utilizando a técnica da mediana
 */
long UltrassomMediana::medianaDistancias(int qtAmostras)
{
    long amostras[qtAmostras];
    long mediana = 0;

    // Realizando a medição das amostras
    Serial.println("Realizando as medições: ");
    for (int i = 0; i < qtAmostras; i++)
    {
        amostras[i] = medirDistancia(echoPin, trigPin);
        Serial.print("Medida ");
        Serial.print(i);
        Serial.print(":\t");
        Serial.println(amostras[i]);
    }

    // Ordenando o vetor de amostras
    for (int i = 0; i < (qtAmostras - 1); i++)
    {
        for (int o = 0; o < (qtAmostras - (i + 1)); o++)
        {
            if (amostras[o] > amostras[o + 1])
            {
                long t = amostras[o];
                amostras[o] = amostras[o + 1];
                amostras[o + 1] = t;
            }
        }
    }

    // Imprimindo o vetor ordenado
    Serial.println("Exibindo as medições ordenadas: ");
    for (int i = 0; i < qtAmostras; i++)
    {
        Serial.print("Posicao ");
        Serial.print(i);
        Serial.print(":\t");
        Serial.println(amostras[i]);
    }

    // Retornando a mediana
    return amostras[int(floor(qtAmostras / 2))];
}

/*
 * Função que mede a distância em centímetros
 */
long UltrassomMediana::medirDistancia(int echoPin, int trigPin)
{
    //seta o pino com um pulso baixo "LOW" ou desligado ou ainda 0
    digitalWrite(trigPin, LOW);
    // delay de 2 microssegundos
    delayMicroseconds(2);
    //seta o pino com pulso alto "HIGH" ou ligado ou ainda 1
    digitalWrite(trigPin, HIGH);
    //delay de 10 microssegundos
    delayMicroseconds(10);
    //seta o pino com pulso baixo novamente
    digitalWrite(trigPin, LOW);
    //pulseInt lê o tempo entre a chamada e o pino entrar em high
    long duration = pulseIn(echoPin, HIGH);
    //Esse calculo é baseado em s = v . t, lembrando que o tempo vem dobrado
    //porque é o tempo de ida e volta do ultrassom
    long distancia = duration / 29 / 2;
    return distancia;
}