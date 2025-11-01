#include "myPulse.h"   //myPulse.hをインクルードする

void setup() {
  Serial.begin(115200);  //シリアル通信の開始
  Serial.println("time,pulse");
}

void loop() {
  uint32_t time=millis();
  if(time<60000){
    uint8_t pulse=rate();           //myPulse.hのrate関数を呼び出しを繰り返す
    float second=time/1000.0;
    Serial.print(second);
    Serial.print(",");
    Serial.println(pulse);
  } //rate関数でreturnされた心拍数はloop関数内で出力すること
}