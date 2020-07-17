#include <EnviarFirebase2.h>

void EnviarFirebase2::setup()
{
  
   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
   while (WiFi.status() != WL_CONNECTED)
   {
      delay(300);
   }
   
   Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
   Firebase.reconnectWiFi(true);
   Firebase.setReadTimeout(firebaseData, 1000 * 60);
   Firebase.setwriteSizeLimit(firebaseData, "tiny");
   Firebase.setString(firebaseData, "/ok ", "ok");
}

void EnviarFirebase2::loop()
{
}
