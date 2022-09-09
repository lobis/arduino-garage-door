

#include "configuration.h"
#include "networking.h"

#include <Arduino.h>

void setup() {
    Serial.begin(9600);

    pinMode(configuration::led, OUTPUT);
    pinMode(configuration::relayOpen, OUTPUT);
    pinMode(configuration::relayClose, OUTPUT);
}

void loop() {
    while (!IsConnectedToWiFi()) {
        ConnectToWiFi();
    }

    Serial.print("HOLA\n");
}