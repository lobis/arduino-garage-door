#pragma once

#include <WiFi.h>

#include "configuration.h"
#include "secrets.h"

bool IsConnectedToWiFi() {
    return WiFi.status() == WL_CONNECTED;
}

void ConnectToWiFi() {
    digitalWrite(configuration::led, HIGH);

    WiFi.begin(secrets::ssid, secrets::ssidPassword);

    while (!IsConnectedToWiFi()) {
        delay(400);
        digitalWrite(configuration::led, LOW);
        delay(100);
        digitalWrite(configuration::led, HIGH);
    }

    digitalWrite(configuration::led, LOW);
}

IPAddress GetLocalIP() {
    return WiFi.localIP();
}
