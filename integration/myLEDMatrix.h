#ifndef MyLEDMatrix_h
#define MyLEDMatrix_h
#include "Arduino_LED_Matrix.h"
void initLEDMatrix();
void displayDigit(int d,int s_r,int s_c);
void updateDisplay(int v);
void updateDisplayC1(double v);
#endif