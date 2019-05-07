#define WIFI_NAME "Nha cua Roy 2Ghz"
#define WIFI_PASSWORD "27071989"
#define DEVICE_ID 1
#define DEVICE_NAME "Google_ESP"
#define TOKEN "~428850_E2e9GL2moYDs"


#include <RemoteMe.h>
#include <RemoteMeSocketConnector.h>
#include <RemoteMeDirectWebSocketConnector.h> // !important library needs WebSockets by Markus Sattler Please install it from Library manager

#include <ESP8266WiFi.h>

#define Relay_1 D1
#define Relay_2 D2
#define Relay_3 D3
#define Relay_4 D4





RemoteMe& remoteMe = RemoteMe::getInstance(TOKEN, DEVICE_ID);

//*************** CODE FOR CONFORTABLE VARIABLE SET *********************

inline void setRelay_1(boolean b) {remoteMe.getVariables()->setBoolean("Relay_1", b); }
inline void setRelay_2(boolean b) {remoteMe.getVariables()->setBoolean("Relay_2", b); }
inline void setRelay_3(boolean b) {remoteMe.getVariables()->setBoolean("Relay_3", b); }
inline void setRelay_4(boolean b) {remoteMe.getVariables()->setBoolean("Relay_4", b); }

//*************** IMPLEMENT FUNCTIONS BELOW *********************


void onRelay_1Change(boolean b) {
    Serial.printf("onRelay_1Change: b: %d\n",b);
    digitalWrite(Relay_1,b? HIGH : LOW);
}

void onRelay_2Change(boolean b) {
    Serial.printf("onRelay_2Change: b: %d\n",b);
}

void onRelay_3Change(boolean b) {
    Serial.printf("onRelay_3Change: b: %d\n",b);
}

void onRelay_4Change(boolean b) {
    Serial.printf("onRelay_4Change: b: %d\n",b);
}




void setup() {
    Serial.begin(9600);
    pinMode(Relay_1, OUTPUT);
    pinMode(Relay_2, OUTPUT);
    pinMode(Relay_3, OUTPUT);
    pinMode(Relay_4, OUTPUT);
    digitalWrite(Relay_1, LOW);
    digitalWrite(Relay_2, LOW);
    digitalWrite(Relay_3, LOW);
    digitalWrite(Relay_4, LOW);
    WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(100);
    }

    remoteMe.getVariables()->observeBoolean("Relay_1" ,onRelay_1Change);
    remoteMe.getVariables()->observeBoolean("Relay_2" ,onRelay_2Change);
    remoteMe.getVariables()->observeBoolean("Relay_3" ,onRelay_3Change);
    remoteMe.getVariables()->observeBoolean("Relay_4" ,onRelay_4Change);

    remoteMe.setConnector(new RemoteMeSocketConnector());
    remoteMe.setDirectConnector(new RemoteMeDirectWebSocketConnector());

    remoteMe.sendRegisterDeviceMessage(DEVICE_NAME);
}


void loop() {
    remoteMe.loop();
}
