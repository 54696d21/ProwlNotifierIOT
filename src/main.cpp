// modified based on https://github.com/marcos69/EspProwl
// created by https://github.com/54696d21

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "EspProwl.h"
#include "credentials.h" // see the README.md to instructions how to create this file

#ifndef WIFI_SSID // wifi credentials can be set here or in credentials.h
#define WIFI_SSID "SSID"
#define WIFI_PWD "password"
#endif

#define DEBUG 1

void setup() {
  Serial.begin(115200);
  if (DEBUG) Serial.println("Connecting to Wifi...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PWD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  EspProwl.begin();
  delay(1000);
  EspProwl.setApiKey(PROWL_KEY); //has to be set in credentials.h
  EspProwl.setApplicationName("doorBell");
  delay(1000);
    Serial.println("start transmission");
    int returnCode = EspProwl.push("MeineEventID", "Nachrichtentext", 0);
    if (returnCode == 200) {
    if (DEBUG) Serial.println("OK.");
  } else {
    if (DEBUG) Serial.print("Error. Server returned: ");
    if (DEBUG) Serial.print(returnCode);
  }
}

void loop() {}
