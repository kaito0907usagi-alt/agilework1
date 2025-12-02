#include "myPulse.h"   //myPulse.hをインクルードする
#include "myLEDMatrix.h"
#include "myServer.h"

int analogvalue=0;
double measuredVoltage=0;

void setup() {
  Serial.begin(115200);  //シリアル通信の開始
  initLEDMatrix();
  initServer();
  Serial.println("time,pulse");
}

void loop() {
  uint32_t time=millis();
  if(time<60000){
    uint8_t bpm = rate();
    updateDisplayC(bpm);
    handleClientRequest((double)bpm);
    delay(100);
  }
}