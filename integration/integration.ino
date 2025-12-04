#include "myPulse.h"   //myPulse.hをインクルードする
#include "myLEDMatrix.h"
#include "myServer.h"
#include "config.h"

int analogvalue=0;
double measuredVoltage=0;

void setup() {
  Serial.begin(9600);  //シリアル通信の開始
  initLEDMatrix();
  initServer();
  Serial.println("time,pulse");
}

void loop() {
    uint8_t bpm = rate();
    updateDisplay(bpm);
    handleClientRequest((double)bpm);
    delay(100);
}