void setup() {
  Serial.begin(9600);           //シリアル通信の開始
  Serial.println("time,value");
}

void loop() {
  uint16_t v = analogRead(A0);  // アナログ入力を読み取る
  uint32_t t = millis();        // 起動からの時間(ミリ秒)を計測

if(t<5000){
  float t_second=t/1000.0;
  Serial.print(t_second);            // 計測した時間(秒)をシリアル出力
  Serial.print(",");
  Serial.println(v);            // 読み取った値をシリアル出力

  delay(20);                    // 次のループまで 20 ミリ秒待機
}
}
