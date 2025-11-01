void setup() {
  Serial.begin(9600);           //シリアル通信の開始
}

void loop() {
  uint16_t v = analogRead(A0);  // アナログ入力を読み取る
  uint32_t t = millis();        // 起動からの時間(ミリ秒)を計測

  Serial.println(t);            // 計測した時間(ミリ秒)をシリアル出力
  Serial.println(v);            // 読み取った値をシリアル出力

  delay(20);                    // 次のループまで 20 ミリ秒待機
}
