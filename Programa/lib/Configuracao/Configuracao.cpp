#include <Configuracao.h>
void formatar()
{
    //Format File System
    if (mensagem->formatar)
    {
        if (SPIFFS.format())
        {
            Serial.println("File System Formated");
        }
        else
        {
            Serial.println("File System Formatting Error");
        }
    }
}
void Configuracao::setup()
{
    bool ready = SPIFFS.begin();
    //Initialize File System
    if (SPIFFS.begin())
    {
        Serial.println("SPIFFS Initialize....ok");
    }
    else
    {
        Serial.println("SPIFFS Initialization...failed");
    }

    bool createFile = SPIFFS.exists("/configuracao.txt");
    if (createFile)
    {
        Serial.println("Lendo arquivo...");
        File myFile = SPIFFS.open("/teste.txt", "r");
        if (!myFile)
        {
            Serial.println("Problema ao tentar ler, sorry...");
            exit(0);
        }
        int s = myFile.size();
        Serial.printf("Size=%d\r\n", s);
        String data = myFile.readString();
        Serial.println(data);
        myFile.close();
    }
    else
    {
        //criar arquivo
    }
    SPIFFS.end()
}

void loop()
{
    //verifica alteração e grava se hover
    //
}