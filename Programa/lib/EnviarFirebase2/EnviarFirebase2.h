
//FirebaseESP8266.h must be included before ESP8266WiFi.h
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "pibic-43c92.firebaseio.com"
#define FIREBASE_AUTH "XsbVOsAdrorLm60qJuZeQpI2ddCQjqtbTW5Xnntf"
#define WIFI_SSID "jb2"
#define WIFI_PASSWORD "besoente#13"

#include <Arduino.h>
#include <Scheduler.h>

class EnviarFirebase2 : public Task
{
public:
FirebaseData firebaseData;
 
protected:
    void setup();
    void loop();

private:
};
