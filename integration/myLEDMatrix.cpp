#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

int c;
int r;

byte frame[8][12]={
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

byte digits[5][30]{
  { 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
  { 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1 },
  { 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
};

void initLEDMatrix(){
  matrix.begin();
  matrix.renderBitmap(frame,8,12);
}

void displayDigit(int d,int s_r,int s_c){
  for (r=0; r<5; r++){
    for (c=0; c<3; c++){
          frame[r+s_r][c+s_c]=digits[r][d*3+c];
        }
      }
    matrix.renderBitmap(frame, 8, 12);
    delay(10);
}

void updateDisplay(int v){
  displayDigit(v%10,2,9);
  displayDigit((v/10)%10,2,5);
  displayDigit((v/100)%10,2,1);
}

void displayDigitC1(int d,int s_r,int s_c){
  for (r=0; r<5; r++){
    for (c=0; c<3; c++){
          frame[r+s_r][c+s_c]=digits[r][d*3+c];
        }
      }
      frame[7][4]=1;
    matrix.renderBitmap(frame, 8, 12);
    delay(10);
}

void updateDisplayC1(double v){
  int V=v*100;
  displayDigitC1(V%10,2,9);
  displayDigitC1((V/10)%10,2,5);
  displayDigitC1((V/100)%10,2,1);
}

void updateDisplay_integrate(double v){
  int V=v;
  displayDigitC1(V%10,2,9);
  displayDigitC1((V/10)%10,2,5);
  displayDigitC1((V/100)%10,2,1);
}