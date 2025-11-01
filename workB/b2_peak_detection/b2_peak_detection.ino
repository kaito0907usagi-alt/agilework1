#include "myPulse.h"  //myPulse.hをインクルードする

void setup() {
  Serial.begin(115200);  //シリアル通信の開始
  Serial.println("time,value,peak");
}

void loop() {
  uint32_t t = millis();
  if (t < 5000) {
    top();  //myPulse.hのtop関数を呼び出しを繰り返す
  }
}
