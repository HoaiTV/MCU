#define WIFI_NAME "Nha cua Roy 2Ghz"
#define WIFI_PASSWORD "27071989"
#define DEVICE_ID 3
#define DEVICE_NAME "Entertainment"
#define TOKEN "~428850_E2e9GL2moYDs"


#include <RemoteMe.h>
#include <RemoteMeSocketConnector.h>
#include <ESP8266WiFi.h>
/* Bo sung source Remote Tivi*/

#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t kIrLed = 14;  // ESP8266 GPIO pin to use. Recommended: 14 (D5).

IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.

#define POWER_SAMSUNG         0xE0E040BF

#define SAMSUNG_BITS  32 


RemoteMe& remoteMe = RemoteMe::getInstance(TOKEN, DEVICE_ID);

//*************** CODE FOR CONFORTABLE VARIABLE SET *********************

inline void setChanel(boolean b) {remoteMe.getVariables()->setBoolean("Chanel", b); }
inline void setMenu(boolean b) {remoteMe.getVariables()->setBoolean("Menu", b); }
inline void setOK_button(boolean b) {remoteMe.getVariables()->setBoolean("OK button", b); }
inline void setPower(boolean b) {remoteMe.getVariables()->setBoolean("Power", b); }
inline void setVolume(boolean b) {remoteMe.getVariables()->setBoolean("Volume", b); }

//*************** IMPLEMENT FUNCTIONS BELOW *********************


void onChanelChange(boolean b) {
    Serial.printf("onChanelChange: b: %d\n",b);
    if (b == true )
    {
        Serial.println("Chanel UP");
        irsend.sendNEC(0xFD609FUL)
        delay(2000);
    }

    else 
    {
       Serial.println("Chanel DOWN");
       irsend.sendNEC(0xFD6897UL);   
    }

}

void onMenuChange(boolean b) {
    Serial.printf("onMenuChange: b: %d\n",b);
        if (b == true )
    {
       irsend.sendNEC(0x00FFE01FUL);
       delay(2000);
    }

}

void onOK_buttonChange(boolean b) {
    Serial.printf("onOK_buttonChange: b: %d\n",b);
            if (b == true )
    {
       irsend.sendNEC(0x00FFE01FUL);
       delay(2000);
    }
}

void onPowerChange(boolean b) {
    Serial.printf("onPowerChange: b: %d\n",b);
        if (b == true )
    {
       irsend.sendSAMSUNG(POWER_SAMSUNG, SAMSUNG_BITS); 
       //irsend.sendSAMSUNG(0xE0E048B7, 32);
       delay(2000);
    }

    else 
    {
       irsend.sendNEC(0x00FFE01FUL);
       delay(2000);    
    }
}

void onVolumeChange(boolean b) {
    Serial.printf("onVolumeChange: b: %d\n",b);
        if (b == true )
    {
      Serial.println("Volume up");
      for(int i = 0;i <3;i++)
      {
        irsend.sendNEC(0xFDD827UL);
      }
       
       delay(2000);
    }

    else 
    {
      Serial.println("Volume down");
       for(int i = 0;i <3;i++)
      {
        irsend.sendNEC(0xFD5AA5UL);
      }
       delay(2000);    
    }
}




void setup() {
  
    irsend.begin();
    Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);

    WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(100);
    }

    remoteMe.getVariables()->observeBoolean("Chanel" ,onChanelChange);
    remoteMe.getVariables()->observeBoolean("Menu" ,onMenuChange);
    remoteMe.getVariables()->observeBoolean("OK button" ,onOK_buttonChange);
    remoteMe.getVariables()->observeBoolean("Power" ,onPowerChange);
    remoteMe.getVariables()->observeBoolean("Volume" ,onVolumeChange);

    remoteMe.setConnector(new RemoteMeSocketConnector());

    remoteMe.sendRegisterDeviceMessage(DEVICE_NAME);
}


void loop() {
    remoteMe.loop();
}
