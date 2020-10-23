#ifndef HOMEAUTOMATION_H
#define HOMEAUTOMATION_H

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "html.h"

//#ifndef LED_OUT
#define LIGHT_1 D0
#define LIGHT_2 D6
#define LIGHT_3 D7
#define FAN_1 D8
//#endif


class HomeAutomation
{
	private:
		std::unique_ptr<ESP8266WebServer> server;
	
	public:
		HomeAutomation();
		void init();
		void handleRoot();
		void handleClient();
		void onLED1();
		void offLED1();
		void onLED2();
		void offLED2();
		void onLED3();
		void offLED3();
		void onFan1();
		void offFan1();
};

#endif
