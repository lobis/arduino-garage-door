#pragma once

#include "configuration.h"

#include <Arduino.h>

namespace relay {
    /*
    Only one relay should be active at once!
    */

    unsigned long startTime = millis();

    const unsigned char stateOff = HIGH;
    const unsigned char stateOn = LOW;

    void OpenDoor() {
        digitalWrite(configuration::relayClose, stateOff);
        digitalWrite(configuration::relayOpen, stateOff);
        delay(200);

        startTime = millis();

        digitalWrite(configuration::relayOpen, stateOn);
    }

    void CloseDoor() {
        digitalWrite(configuration::relayClose, stateOff);
        digitalWrite(configuration::relayOpen, stateOff);
        delay(200);

        startTime = millis();

        digitalWrite(configuration::relayClose, stateOn);
    }

    void UpdateIdle() {
        unsigned long elapsedTime = millis() - startTime;
        if (elapsedTime > configuration::relayIdleDelayMillis) {
            startTime = millis();
            digitalWrite(configuration::relayClose, stateOff);
            digitalWrite(configuration::relayOpen, stateOff);
        }
    }

    void Stop(){
        startTime = millis();
        digitalWrite(configuration::relayClose, stateOff);
        digitalWrite(configuration::relayOpen, stateOff);
        delay(200);
    }

} // namespace actuator