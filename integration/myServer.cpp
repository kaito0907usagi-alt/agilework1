#include "myServer.h"

char ssid[] = SECRET_SSID; // WiFiネットワークのSSID
char pass[] = SECRET_PASS; // WiFiネットワークのパスワード

WiFiServer server(80); // ポート80でサーバーを作成

void initServer() {
// IPアドレスの設定（学生IDを適切に代入）
WiFi.config(IPAddress(192, 168, STUDENT_ID, 2));
// アクセスポイントの開始
        if (WiFi.beginAP(ssid, pass) != WL_AP_LISTENING) {
            //Serial.println("Failed to start access point");
            while (true);
        }
// サーバーの開始
    server.begin();
    //Serial.println("Server started");
}

void handleClientRequest(double sensorValue) {
  WiFiClient client = server.available(); // クライアントの接続を待つ

  if (client) {
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        
        // 改行文字を受信＝リクエストの終わり
        if (c == '\n') {
          if (currentLine.length() == 0) {
            // HTTPレスポンスヘッダを送信
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: application/json");
            client.println("Connection: close");
            client.println();

            // JSONデータを送信 {"value": 3.45} のような形式
            client.println("{\"value\": " + String(sensorValue) + "}");
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    client.stop(); // クライアントとの接続を終了
  }
}