#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "index.h"      //file html


#define dhtPin D1
#define lightPin A0


#define button1_pin 14 //D5
#define button2_pin 12 //D6

const char* ssid = "AnhTrangBond";    
const char* password = "huyanh308";

ESP8266WebServer server(80);

void handle_root() {                                                                   //tao ra 1 giao dien web
  String s = html_page;                                                               //gia tri thu vien index.h tra ve
  server.send(200, "text/html", s);                                                   //gui web
}


void handle_button() {                                                                                        //tao ra 2 nut bam
  String button_state = server.arg("button_state");//chuỗi giá trị trả về từ javascript
  String curr_state = "OFF";
  
  if(button_state == "led1ON"){           
    digitalWrite(button1_pin, HIGH);
    Serial.println(button_state);
  }
  if(button_state == "led1OFF"){
    digitalWrite(button1_pin, LOW);
    Serial.println(button_state);
  }

  if(button_state == "led2ON"){
    digitalWrite(button2_pin, HIGH);
  }
  if(button_state == "led2OFF"){
    digitalWrite(button2_pin, LOW);
  }
  server.send(200, "text/plane", curr_state); 
}

void handle_pwm() {                                     
  String pwm_pin = server.arg("PWNPin");     
  //nhận tín hiệu chuỗi send từ javascript,sử dụng PWM1 hay PWM2
  
  String pwm_val = server.arg("PWNval");     
  //nhận tín hiệu xung để tăng giảm từ javascript
  
  int val = pwm_val.toInt();  //băm xung sang kiểu int 
  
  if(pwm_pin == "PWM1"){                     
    analogWrite(button1_pin, val);        
    Serial.println(val);
  }
  
  if(pwm_pin == "PWM2"){
    analogWrite(button2_pin, val);
    Serial.println(val);
  }
  server.send(200,"text/plane","0");    
}



void setup(void){
  Serial.begin(115200);
  WiFi.begin(ssid, password);   //bat dau ket noi
  pinMode(button1_pin,OUTPUT);      
  pinMode(button2_pin,OUTPUT); 

  while (WiFi.status() != WL_CONNECTED) {   //loading connect to wifi.
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());       //In ra địa chỉ chỉ IP để truy cập web
 
  server.on("/", handle_root);
  server.on("/setPWM", handle_pwm);
  server.on("/setButton", handle_button);
  server.begin();
}

void loop(void){
  server.handleClient();   
}
