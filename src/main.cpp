

#include "configuration.h"
#include "networking.h"
#include "server.h"

#include <Arduino.h>

void setup() {
    Serial.begin(9600);

    pinMode(configuration::led, OUTPUT);
    pinMode(configuration::relayOpen, OUTPUT);
    pinMode(configuration::relayClose, OUTPUT);

    Serial.println("Start");
    ConnectToWiFi();
    Serial.println("Connected");
    Serial.println(GetLocalIP());

    server::start();
}

void loop() {
    while (!IsConnectedToWiFi()) { ConnectToWiFi(); }
}