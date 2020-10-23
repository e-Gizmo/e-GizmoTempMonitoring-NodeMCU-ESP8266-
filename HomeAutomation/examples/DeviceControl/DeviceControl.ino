/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com
*********/
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <HomeAutomation.h>

HomeAutomation DEVICE;

/* Set these to your desired credentials. */
const char *ssid = "MYHOMEAUTOMATION";
const char *password = "123456789";

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN 14     // Digital pin connected to the DHT sensor

// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

float c, f, h;

ESP8266WebServer server(80);

void handleRoot() {
  // Sending sample message if you try to open configured IP Address
  server.send(200, "text/html", "<h1>You are connected</h1>");
}

void setup() {
  Serial.begin(115200);

  //Trying to connect to the WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("*");
  }

  // Setting IP Address to 192.168.1.200, you can change it as per your need, you also need to change IP in Flutter app too.
  WiFi.mode(WIFI_STA);
  IPAddress ip(192, 168, 0, 200);
  IPAddress gateway(192, 168, 0, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.config(ip, gateway, subnet);
  Serial.println(WiFi.localIP());
  DEVICE.init();
  server.begin();


  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {

  DEVICE.handleClient();
  c = dht.readTemperature();
  f = dht.readTemperature(true);
  h = dht.readHumidity();
  delay(500);

  //read temperature and humidity
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    // sensorError = true;
  }
  // clear display
  display.clearDisplay();

  // display temperature
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Light 1:  ");
  display.setTextSize(1);
  display.setCursor(50, 0);
  if (digitalRead(LIGHT_1) == true) {
    display.print("OFF          ");
  }
  if (digitalRead(LIGHT_1) == false) {
    display.print("           ON");
  }

  display.setTextSize(1);
  display.setCursor(0, 10);
  display.print("Light 2:  ");
  display.setTextSize(1);
  display.setCursor(50, 10);
  if (digitalRead(LIGHT_2) == true) {
    display.print("OFF          ");
  }
  if (digitalRead(LIGHT_2) == false) {
    display.print("           ON");
  }

  display.setTextSize(1);
  display.setCursor(0, 20);
  display.print("Light 3:  ");
  display.setTextSize(1);
  display.setCursor(50, 20);
  if (digitalRead(LIGHT_3) == true) {
    display.print("OFF          ");
  }
  if (digitalRead(LIGHT_3) == false) {
    display.print("           ON");
  }

  display.setTextSize(1);
  display.setCursor(0, 30);
  display.print("Fan:  ");
  display.setTextSize(1);
  display.setCursor(50, 30);
  if (digitalRead(FAN_1) == true) {
    display.print("OFF          ");
  }
  if (digitalRead(FAN_1) == false) {
    display.print("           ON");
  }

  // display temperature
  display.setTextSize(1);
  display.setCursor(0, 40);
  display.print("Temp: ");
  display.setTextSize(1);
  display.setCursor(50, 40);
  display.print(t);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(1);
  display.print("C");

  // display humidity
  display.setTextSize(1);
  display.setCursor(0, 50);
  display.print("Humid: ");
  display.setTextSize(1);
  display.setCursor(50, 50);
  display.print(h);
  display.print(" %");

  display.display();


}
