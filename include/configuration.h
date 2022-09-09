
#pragma once

namespace configuration {
    typedef unsigned char pin;

    const pin led = 2;

    const pin relayOpen = 18;
    const pin relayClose = 19;

    const unsigned long relayIdleDelayMillis = 30000;

    const unsigned int serverPort = 50235;

    const char* webpageTitle = "Arduino Garage Door";
    const char* webpageButtonOpenText = "Open";
    const char* webpageButtonCloseText = "Close";

} // namespace configuration
