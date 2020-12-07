#include <Arduino.h>

#include <ESP8266WiFi.h>

#include <SocketIoClient.h>

SocketIoClient webSocket;


void setup() {
    Serial.begin(115200);

    WiFi.mode(WIFI_STA);
    WiFi.begin("Kat","katc6719");

    while(WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(100);
    }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  webSocket.on("message", event);
  webSocket.begin("192.168.43.121",5000);
  //webSocket.begin("intense-dawn-90546.herokuapp.com");
  
  webSocket.emit("message","\"hello\"");
}

void loop() {
    webSocket.emit("message","\"hello\"");
    webSocket.loop(); 
    delay(1000);
}

void event(const char * payload, size_t length) {
  // do stuff
  Serial.println(payload);
}
