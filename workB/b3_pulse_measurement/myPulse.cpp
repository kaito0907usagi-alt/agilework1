#include "myPulse.h"

# define PIN_IN A0        // アナログ入力PINの設定
# define DELAY_TIME 20    // ディレイ時間(ms)の設定

# define TOP_THRESHOLD 400  // 信号が山の部分にあるかの判定に利用する閾値
# define DOWN_THRESHOLD 2 // 下降傾向にあるかの判定に利用する閾値
# define UP_THRESHOLD 1   // 上昇傾向にあったかの判定に利用する閾値

// アナログ入力で読み込んだ信号からピークを検出する関数
uint16_t top(){
  uint16_t maximum = 0;           // 最大値の保存用
  uint16_t value = 0;             // 読み込んだ信号の保存用    
  uint8_t up_count = 0;           // 上昇回数の保存用
  uint8_t down_count = 0;         // 下降回数の保存用
  uint8_t timeout = 255;         // タイムアウトまでのカウント
  uint32_t time=millis();
  while(timeout--){    
    value = analogRead(PIN_IN);   // アナログ入力で値を読み取る

    if(value >= TOP_THRESHOLD){   // 読み込んだ値が山の閾値以上である場合のみピーク検出の処理を行う
      if(value > maximum){        // 読み込んだ値が最大値より高い場合，maximum, up_count, down_countを更新する
        maximum = value;          // 最高値（maximum）を更新する
        up_count++;               // 最高値が更新されたので，up_countを増やす
        down_count = 0;           // 最高値が更新されたので，down_countを初期化する
      }
      else{
        down_count++;             // 最高値を更新しなかった（下降した）ため，down_countを増やす
      }
    }

    // up_countが上昇判定の閾値より高く，かつ，down_countが減少判定の閾値より高い場合，信号波形が減少に変わったと判断しピーク値を返す
    if(up_count>UP_THRESHOLD && down_count>DOWN_THRESHOLD) {     
      return time;
    }
    
    delay(DELAY_TIME);
  }
  return 0;  // timeout回数までにピークが見つからなかったら0を返す
}
  
// 脈拍を測定し返す関数
uint8_t rate(){  
  //ピークから脈拍を測定する処理を追加すること  
  uint32_t time=millis();
  uint16_t peaktime=top();
  uint16_t firstpeak;
  uint16_t secondpeak;
  uint16_t interval;
  uint8_t bpm;

  if(peaktime>0){
      firstpeak=peaktime;
      secondpeak=top();
      if(secondpeak!=0){
        interval=secondpeak-firstpeak;
        bpm=60000/interval;
        return bpm;  //計算した脈拍を返す
      }
    }
    return 0;
}
