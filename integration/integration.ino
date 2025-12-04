#include "myPulse.h"   //myPulse.hをインクルードする
#include "myLEDMatrix.h"
#include "myServer.h"
#include "config.h"

void setup() {
  Serial.begin(9600);  //シリアル通信の開始
  initLEDMatrix();
  initServer();
}

void loop() {
    uint8_t bpm = rate();
    updateDisplay(bpm);
    handleClientRequest((double)bpm);
    delay(100);
}