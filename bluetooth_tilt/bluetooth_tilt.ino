#include "BluetoothSerial.h"


BluetoothSerial ESP_BT;

int sensor2 = 13;
int count_bad =0;
int count_good=0;
int led_red =5;
int led_green = 23;

unsigned long previousMillis=0;
unsigned long moment=0;
const long interval = 5000;
const long minterval = 1000;

void setup (){
  
  Serial.begin(115200);
  ESP_BT.begin("ESP32_TILT_SENSOR");
  pinMode (sensor2, INPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);

}

void loop (){
  unsigned long currentMillis = millis();

  if(currentMillis - moment >= minterval){
    moment = currentMillis;
    int val2 = digitalRead(sensor2);
  
    if (val2 == HIGH){ 
      
      Serial.println("sensor2 = 기울어짐");
      count_bad++;
      ESP_BT.println('1');
      //ESP_BT.println(count_bad);
      digitalWrite(led_red, HIGH);
      digitalWrite(led_green, LOW);
    }
    else if(val2 == LOW){
      
      Serial.println("sensor2 = 평평함");
      count_good++;
      ESP_BT.println('0');
      //ESP_BT.println(count_good);
      digitalWrite(led_red, LOW);
      digitalWrite(led_green, HIGH);
    }
  }
  
