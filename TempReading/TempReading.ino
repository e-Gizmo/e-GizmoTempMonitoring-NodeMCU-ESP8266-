#include "DHT.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>


/* Set these to your desired credentials. */
const char *ssid = "MYHOMEAUTOMATION";
const char *password = "123456789";

#define DHTPIN 14    // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11  (AM2302)
DHT dht(DHTPIN, DHTTYPE);

float c,f,h;
String dhtData;
boolean sensorError = false;

ESP8266WebServer server(80);

void handleRoot() {
  // Sending sample message if you try to open configured IP Address
  server.send(200, "text/html", "<h1>You are connected</h1>");
}

void setup() {
  Serial.begin(9600);
  //Trying to connect to the WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("*");
  }

  WiFi.mode(WIFI_STA);
  IPAddress ip(192, 168, 0, 200);
  IPAddress gateway(192, 168, 0, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.config(ip, gateway, subnet);
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.on("/dht", sendDhtData);
  server.begin();
  Serial.println("HTTP server started");
  Serial.println("DHT11 Sensor");
  dht.begin();
}

void sendDhtData() {
  server.send(200, "text/plain", dhtData);
}

void loop() {
  server.handleClient();
  c = dht.readTemperature();
  f = dht.readTemperature(true);
  h = dht.readHumidity();
  delay(500);
  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(c) || isnan(h) || isnan(f)) {
    Serial.print("Sensor Not Connected");
    sensorError=true;
  } else {
    Serial.println("Temperature In Celcius: ");
    Serial.print(c);
    Serial.println(" *C");
    Serial.println("Humidity: ");
    Serial.println(h);
    Serial.println(" %");
  }
  // If there is any issue in sensor connections, it will send 000 as String.
  if(sensorError) {
    dhtData = "sensorError";
  }
  else {
    dhtData = String(c) + ' ' + String(f) + ' ' + String(h);
  }
  delay(2000);
}
