#include <Giroscopio.h>

Giroscopio::Giroscopio(Mensagem *newMensagem)
{
    mensagem = newMensagem;
}

void Giroscopio::setMensagem(Mensagem *newMensagem)
{
    mensagem = newMensagem;
}

void Giroscopio::setup()
{
  /*  Wire.begin(pinSda, pinScl); // D2 4 (GPIO4)=SDA / D1(GPIO5)=SCL
    Wire.beginTransmission(MPU);
    Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission(true);*/
}

void Giroscopio::loop()
{
  //  lerValores();
    delay(10000);
}

void Giroscopio::lerValores()
{
    for (size_t i = 0; i < 20; i++)
    {
        //Leer los valores del Acelerometro de la IMU
        Wire.beginTransmission(MPU);
        Wire.write(0x3B); //Pedir el registro 0x3B - corresponde al AcX
        Wire.endTransmission(false);
        Wire.requestFrom(MPU, 6, true);       //A partir del 0x3B, se piden 6 registros
        AcX = Wire.read() << 8 | Wire.read(); //Cada valor ocupa 2 registros
        AcY = Wire.read() << 8 | Wire.read();
        AcZ = Wire.read() << 8 | Wire.read();

        //A partir de los valores del acelerometro, se calculan los angulos Y, X
        //respectivamente, con la formula de la tangente.
        Acc[1] = atan(-1 * (AcX / A_R) / sqrt(pow((AcY / A_R), 2) + pow((AcZ / A_R), 2))) * RAD_TO_DEG;
        Acc[0] = atan((AcY / A_R) / sqrt(pow((AcX / A_R), 2) + pow((AcZ / A_R), 2))) * RAD_TO_DEG;

        //Leer los valores del Giroscopio
        Wire.beginTransmission(MPU);
        Wire.write(0x43);
        Wire.endTransmission(false);
        Wire.requestFrom(MPU, 6, true);       //A partir del 0x43, se piden 6 registros
        GyX = Wire.read() << 8 | Wire.read(); //Cada valor ocupa 2 registros
        GyY = Wire.read() << 8 | Wire.read();
        GyZ = Wire.read() << 8 | Wire.read();

        //Calculo del angulo del Giroscopio
        Gy[0] = GyX / G_R;
        Gy[1] = GyY / G_R;
        Gy[2] = GyZ / G_R;

        dt = (millis() - tiempo_prev) / 1000.0;
        tiempo_prev = millis();

        //Aplicar el Filtro Complementario
        Angle[0] = 0.98 * (Angle[0] + Gy[0] * dt) + 0.02 * Acc[0];
        Angle[1] = 0.98 * (Angle[1] + Gy[1] * dt) + 0.02 * Acc[1];

        //Integración respecto del tiempo paras calcular el YAW
        Angle[2] = Angle[2] + Gy[2] * dt;

        //Mostrar los valores por consola
        valores = "90, " + String(Angle[0]) + "," + String(Angle[1]) + "," + String(Angle[2]) + ", -90";
        Serial.println(valores);

        delay(10);
    }
}