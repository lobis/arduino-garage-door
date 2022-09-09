
#pragma once

namespace configuration {
    typedef unsigned char pin;

    const pin led = 2;

    const pin relayOpen = 12;
    const pin relayClose = 13;

    const unsigned long relayIdleDelayMillis = 3000;

    const unsigned int serverPort = 50235;

    const char* webpageTitle = "Arduino Garage Door";
    const char* webpageButtonOpenText = "Open";
    const char* webpageButtonCloseText = "Close";

} // namespace configuration
