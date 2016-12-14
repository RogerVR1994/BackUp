#include <Arduino.h>

#include "CurieIMU.h"

float caida=1;
int x;
boolean blinkState = false;          // state of the LED

void setup() {
  pinMode(10, INPUT); // Setup for leads off detection LO +
  pinMode(11, INPUT); // Setup for leads off detection LO -
  Serial.begin(9600);

  /* Initialise the IMU */
  CurieIMU.begin();
  CurieIMU.attachInterrupt(eventCallback);

  /* Enable Shock Detection */
  CurieIMU.setDetectionThreshold(CURIE_IMU_SHOCK, 1000); // 1.5g = 1500 mg
  CurieIMU.setDetectionDuration(CURIE_IMU_SHOCK, 50);   // 50ms
  CurieIMU.interrupts(CURIE_IMU_SHOCK);

  Serial.println("IMU initialisation complete, waiting for events...");
}

void loop() {
  if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
    Serial.println('!');
  }
  else{
    // send the value of analog input 0:
      Serial.println(analogRead(A0));
  }
  //Wait for a bit to keep serial data from saturating
  delay(1);
}


static void eventCallback(void){
  if (CurieIMU.getInterruptStatus(CURIE_IMU_SHOCK)) {
    if (CurieIMU.shockDetected(X_AXIS, POSITIVE)){
    //Serial.println("1");
    x=1;}
      //Serial.println("Negative shock detected on X-axis");
    if (CurieIMU.shockDetected(X_AXIS, NEGATIVE)){
    //Serial.println("1");
    x=1;}
     // Serial.println("Positive shock detected on X-axis");
    if (CurieIMU.shockDetected(Y_AXIS, POSITIVE)){
    //Serial.println("1");
    x=1;}
     // Serial.println("Negative shock detected on Y-axis");
    if (CurieIMU.shockDetected(Y_AXIS, NEGATIVE)){
    //Serial.println("1");
    x=1;}
      //Serial.println("Positive shock detected on Y-axis");
    if (CurieIMU.shockDetected(Z_AXIS, POSITIVE)){
    //Serial.println("1");
    x=1;}
      //Serial.println("Negative shock detected on Z-axis");
    if (CurieIMU.shockDetected(Z_AXIS, NEGATIVE)){
    //Serial.println("1");
    x=1;}
     // Serial.println("Positive shock detected on Z-axis");
    if (x==1){
     for (int y=0; y>50; y++){
       Serial.println("hola");
     }
    }
   }
  }

