/**！
 * @file scan.ino
 * @brief 扫描mini control模块x,y方向,和A,B,C,D四个按钮,读取模拟值和状态
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [fengli](li.feng@dfrobot.com)
 * @version  V1.0
 * @date  2021-04-29
 * @get from https://www.dfrobot.com
 * @https://github.com/DFRobot_MINI_CONTROL
 */

#include "DFRobot_MINI_CONTROL.h"

/**
 * @brief 构造函数
 * @param address 7位I2C地址
 * @param pWire I2C总线指针对象，构造设备，可传参数也可不传参数，默认Wire
*/
DFRobot_MINI_CONTROL control;

uint8_t A, B, C, D;
uint16_t scanX = 0;
uint16_t scanY = 0;
void scanC(){

  control.readBtnABCD(&A, &B, &C, &D);
  scanX = control.readX();
  scanY = control.readY();
}
void setup() {
  Serial.begin(9600);  // start serial for output
  control.begin();
}

void loop() {
  scanC();
  if(scanX < 480 || scanX > 530){
    Serial.print("X:");
    Serial.println(scanX);
  }
  if(scanY < 480 || scanY > 530){
    Serial.print("Y:");
    Serial.println(scanY);   
  }
  if(B == 1){
    Serial.println("B");
    }
  if(A == 1){
    Serial.println("A");
   }

  if(C == 1){
    Serial.println("C");
  }
  
  if(D == 1){
    Serial.println("D");
  }
  delay(100);
}