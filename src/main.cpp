

#include "configuration.h"
#include "networking.h"
#include "relay.h"
#include "server.h"

#include <Arduino.h>

void setup() {
    Serial.begin(9600);

    pinMode(configuration::led, OUTPUT);

    pinMode(configuration::relayOpen, OUTPUT);
    pinMode(configuration::relayClose, OUTPUT);

    digitalWrite(configuration::relayOpen, relay::stateOff);
    digitalWrite(configuration::relayClose, relay::stateOff);

    Serial.println("Start");
    ConnectToWiFi();
    Serial.println("Connected");
    Serial.println(GetLocalIP());
    Serial.println(WiFi.macAddress());

    server::start();
}

void loop() {
    while (!IsConnectedToWiFi()) {
        ConnectToWiFi();
    }

    const bool stateOpen = digitalRead(configuration::relayOpen);
    const bool stateClose = digitalRead(configuration::relayClose);

    relay::UpdateIdle();

    delay(100);
}