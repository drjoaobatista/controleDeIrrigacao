#ifndef GIROSCOPIO_H
#define GIROSCOPIO_H

#include <Arduino.h>
#include <Wire.h>
#include <Mensagem.h>
#include <Scheduler.h>
//Direccion I2C de la IMU
#define MPU 0x68

//Ratios de conversion
#define A_R 16384.0 // 32768/2
#define G_R 131.0   // 32768/250

//Conversion de radianes a grados 180/PI
#define RAD_A_DEG = 57.295779
class Giroscopio : public Task
{
public:
    Giroscopio(Mensagem *newMensagem);
    void setMensagem(Mensagem *newMensagem);

protected:
    void setup();
    void loop();

private:
    void lerValores();
    Mensagem *mensagem;
    int pinSda = D2;
    int pinScl = D1;
    //MPU-6050 da los valores en enteros de 16 bits
    //Valores RAW
    int16_t AcX, AcY, AcZ, GyX, GyY, GyZ;

    //Angulos
    float Acc[2];
    float Gy[3];
    float Angle[3];

    String valores;

    long tiempo_prev;
    float dt;
};
#endif