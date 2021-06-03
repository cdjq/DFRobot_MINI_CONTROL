/**！
 * @file scan.ino
 * @brief 扫描mini control模块x,y方向,和A,B,C,D四个按钮,读取模拟值和状态
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [fengli](li.feng@dfrobot.com)
 * @version  V1.0
 * @date  2021-04-29
 * @get from https://www.dfrobot.com
 * @https://github.com/DFRobot/DFRobot_MINI_CONTROL
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
//扫描mini control module上面的控制信息
bool scanC(){

  bool ret = control.readBtnABCD(&A, &B, &C, &D);
  scanX = control.readX();
  scanY = control.readY();
  return ret;
}
void setup() {
  Serial.begin(9600);  // start serial for output
  //模块初始化
  while(!control.begin()){
     Serial.println("I2C 通信失败");
     delay(1000);
  }
  Serial.println("模块初始化成功");
}

void loop() {
  bool ret = scanC();
  if(ret){
    //当摇杆运动时打印摇杆 X方向的AD值
    if(scanX < 480 || scanX > 530){
      Serial.print("X:");
      Serial.println(scanX);
    }
    //当摇杆运动时打印摇杆 Y方向的AD值
    if(scanY < 480 || scanY > 530){
      Serial.print("Y:");
      Serial.println(scanY);   
    }
    //当按钮B被按下
    if(B == 1){
      Serial.println("B");
      }
    //当按钮A被按下
    if(A == 1){
      Serial.println("A");
     }
    //当按钮C被按下
    if(C == 1){
      Serial.println("C");
    }
    //当按钮D被按下
    if(D == 1){
      Serial.println("D");
    }
    delay(100);
  }else{
    Serial.println("I2C 通信失败");
    delay(2000);
  }
}