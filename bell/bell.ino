#include <Arduino.h>

#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>

WiFiMulti wifiMulti;

void setup() {
    wifiMulti.addAP("WIFI SSID", "WIFI PASSWORD");
    pinMode(0, INPUT_PULLUP);
    pinMode(1, OUTPUT);
    digitalWrite(1, HIGH);
}

void loop() {
    if (digitalRead(0) == HIGH) {
    }
    else {
          if((wifiMulti.run() == WL_CONNECTED)) {
            HTTPClient http;
            http.begin("http://bell.php?key=key"); //Only HTTP connections
            int httpCode = http.GET();
            if(httpCode > 0) {
              digitalWrite(1, LOW);
              delay(5000);
              digitalWrite(1, HIGH);
            }
            http.end();
          }
    }
}
