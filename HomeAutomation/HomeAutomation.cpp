#include "HomeAutomation.h"

HomeAutomation::HomeAutomation(){}

void HomeAutomation::init()
{
	Serial.begin(115200);
	server.reset(new ESP8266WebServer(80));
	pinMode(LIGHT_1, OUTPUT);
	pinMode(LIGHT_2, OUTPUT);
	pinMode(LIGHT_3, OUTPUT);
	pinMode(FAN_1, OUTPUT);
	digitalWrite(LIGHT_1,HIGH);
	digitalWrite(LIGHT_2,HIGH);
	digitalWrite(LIGHT_3,HIGH);
	digitalWrite(FAN_1,HIGH);

	server -> on(String(F("/")).c_str(), std::bind(&HomeAutomation::handleRoot, this));
	server -> on(String(F("/handleClient")).c_str(), std::bind(&HomeAutomation::handleClient, this));
	server -> on(String(F("/on1")).c_str(), std::bind(&HomeAutomation::onLED1, this));
	server -> on(String(F("/off1")).c_str(), std::bind(&HomeAutomation::offLED1, this));
	server -> on(String(F("/on2")).c_str(), std::bind(&HomeAutomation::onLED2, this));
	server -> on(String(F("/off2")).c_str(), std::bind(&HomeAutomation::offLED2, this));
	server -> on(String(F("/on3")).c_str(), std::bind(&HomeAutomation::onLED3, this));
	server -> on(String(F("/off3")).c_str(), std::bind(&HomeAutomation::offLED3, this));
	server -> on(String(F("/onFan")).c_str(), std::bind(&HomeAutomation::onFan1, this));
	server -> on(String(F("/offFan")).c_str(), std::bind(&HomeAutomation::offFan1, this));
	server -> begin();
}

void HomeAutomation::handleRoot()
{
	String page = "";
	page += FPSTR(HTML_HOME);
	server -> sendHeader("Content-Length", String(page.length()));
  	server -> send(200, "text/html", page);
}

void HomeAutomation::onLED1()
{
	digitalWrite(LIGHT_1, LOW);
	//Serial.println("");
}

void HomeAutomation::offLED1()
{
	digitalWrite(LIGHT_1, HIGH);
	//bool L1 = false;
}

void HomeAutomation::onLED2()
{
	digitalWrite(LIGHT_2, LOW);
}

void HomeAutomation::offLED2()
{
	digitalWrite(LIGHT_2, HIGH);
}

void HomeAutomation::onLED3()
{
	digitalWrite(LIGHT_3, LOW);
}

void HomeAutomation::offLED3()
{
	digitalWrite(LIGHT_3, HIGH);
}

void HomeAutomation::onFan1()
{
	digitalWrite(FAN_1, LOW);
}

void HomeAutomation::offFan1()
{
	digitalWrite(FAN_1, HIGH);
}
void HomeAutomation::handleClient()
{
	server -> handleClient();
}
