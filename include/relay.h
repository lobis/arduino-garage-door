#pragma once

#include "configuration.h"

#include <Arduino.h>

namespace relay {
    /*
    Only one relay should be active at once!
    */

    unsigned long startTime = millis();

    void OpenDoor() {
        digitalWrite(configuration::relayClose, false);
        digitalWrite(configuration::relayOpen, false);
        delay(200);

        startTime = millis();

        digitalWrite(configuration::relayOpen, true);
    }

    void CloseDoor() {
        digitalWrite(configuration::relayClose, false);
        digitalWrite(configuration::relayOpen, false);
        delay(200);

        startTime = millis();

        digitalWrite(configuration::relayClose, true);
    }

    void UpdateIdle() {
        unsigned long elapsedTime = millis() - startTime;
        if (elapsedTime > configuration::relayIdleDelayMillis) {
            startTime = millis();
            digitalWrite(configuration::relayClose, false);
            digitalWrite(configuration::relayOpen, false);
        }
    }

} // namespace actuator