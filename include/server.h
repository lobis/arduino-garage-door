#pragma once

#include "configuration.h"
#include "relay.h"
#include "secrets.h"

#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WiFi.h>

namespace server {
    AsyncWebServer server(configuration::serverPort);

    const char* inputParameter = "door";

    const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head> <title>%TITLE%</title> <meta name="viewport" content="width=device-width, initial-scale=1"> <style>html{font-family: sans-serif; display: inline-block; text-align: center;}</style></head><body> <h2>%TITLE%</h2> <button onclick="doorUpdate('open')">%BUTTON_OPEN_TEXT%</button> <button onclick="doorUpdate('close')">%BUTTON_CLOSE_TEXT%</button> <script>function doorUpdate(state){if (state !="close" && state !="open"){return;}console.log(state); var xhr=new XMLHttpRequest(); xhr.open("GET", "/update?door=" + state, true); xhr.send();}</script></body></html>
)rawliteral";

    String processor(const String& var) {
        if (var == "TITLE") {
            return configuration::webpageTitle;
        }
        if (var == "BUTTON_OPEN_TEXT") {
            return configuration::webpageButtonOpenText;
        }
        if (var == "BUTTON_CLOSE_TEXT") {
            return configuration::webpageButtonCloseText;
        }
        return {};
    }

    void start() {
        server.begin();

        server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
            if (!request->authenticate(secrets::serverAuthUser, secrets::serverAuthPassword)) { return request->requestAuthentication(); }
            request->send_P(200, "text/html", index_html, processor);
        });

        // /update?door=open or /update?door=close to open or close door
        server.on("/update", HTTP_GET, [](AsyncWebServerRequest* request) {
            if (!request->authenticate(secrets::serverAuthUser, secrets::serverAuthPassword)) { return request->requestAuthentication(); }

            if (request->hasParam(inputParameter)) {
                String inputMessage = request->getParam(inputParameter)->value();
                if (inputMessage == "open") {
                    relay::OpenDoor();
                } else if (inputMessage == "close") {
                    relay::CloseDoor();
                }
            }

            request->send_P(200, "text/html", index_html, processor);
        });
    }

} // namespace server
