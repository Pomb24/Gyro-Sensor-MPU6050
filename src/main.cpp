#include <Arduino.h>                              // Include the Arduino library
#include "Wire.h"
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

unsigned long lastDataTime = 0;
const int samplingInterval = 1000;

void setup(){
  Serial.begin(115200);

  Wire.begin();
  
  byte status = mpu.begin();
  while(status!=0){};
  mpu.calcOffsets(true,true);
}

void loop() {
  unsigned long currentTime = millis();

  mpu.update();

  if (currentTime - lastDataTime >= samplingInterval) {
    lastDataTime = currentTime;

    Serial.print(F("TEMPERATURE: "));Serial.println(mpu.getTemp());
    Serial.print(F("ACCELERO  X: "));Serial.print(mpu.getAccX());
    Serial.print("\tY: ");Serial.print(mpu.getAccY());
    Serial.print("\tZ: ");Serial.println(mpu.getAccZ());
  
    Serial.print(F("GYRO      X: "));Serial.print(mpu.getGyroX());
    Serial.print("\tY: ");Serial.print(mpu.getGyroY());
    Serial.print("\tZ: ");Serial.println(mpu.getGyroZ());
  
    Serial.print(F("ACC ANGLE X: "));Serial.print(mpu.getAccAngleX());
    Serial.print("\tY: ");Serial.println(mpu.getAccAngleY());
    
    Serial.print(F("ANGLE     X: "));Serial.print(mpu.getAngleX());
    Serial.print("\tY: ");Serial.print(mpu.getAngleY());
    Serial.print("\tZ: ");Serial.println(mpu.getAngleZ());
    Serial.println(F("=====================================================\n"));
  }
}