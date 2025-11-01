#include "myPulse.h"   //myPulse.hをインクルードする

void setup() {
  Serial.begin(115200);  //シリアル通信の開始
}

void loop() {
    rate();           //myPulse.hのrate関数を呼び出しを繰り返す

    //rate関数でreturnされた心拍数はloop関数内で出力すること
}
