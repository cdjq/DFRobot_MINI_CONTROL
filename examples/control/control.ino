/**！
 * @file control.ino
 * @brief 识别mini control module上A,B,C,D四个按钮的单击，双击,长按和摇杆的行为
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
long stamp1;
long stamp2;
long stamp3;
long stamp4;

long stampA;
long stampB;
long stampC;
long stampD;

uint8_t flagA = 0;
uint8_t flagB = 0;
uint8_t flagC = 0;
uint8_t flagD = 0;

uint8_t clickTempA = 0;
uint8_t clickTempB = 0;
uint8_t clickTempC = 0;
uint8_t clickTempD = 0;

uint8_t doubleFlagA = 0;
uint8_t doubleFlagB = 0;
uint8_t doubleFlagC = 0;
uint8_t doubleFlagD = 0;

uint8_t longPressA = 0;
uint8_t longPressB = 0;
uint8_t longPressC = 0;
uint8_t longPressD = 0;

typedef enum
{
 LEFTUP,
 LEFTDOWN,
 RIGHTUP,
 RIGHTDOWN,
 LEFT,
 RIGHT,
 UP,
 DOWN,
 CENTRAL,
}eDir_t;
eDir_t  lastDirection = CENTRAL;
eDir_t  Direction = CENTRAL;
//扫描mini control module上面的控制信息
void scan(){

  control.readBtnABCD(&A, &B, &C, &D);
  scanX = control.readX();
  scanY = control.readY();
}
//识别按钮的单击,双击和长按
void btnControl(){
  if(A && flagA == 0){
    stamp1 = millis();
    flagA = 1;
  }
  
  if(B && flagB == 0){
    stamp2 = millis();
    flagB = 1;
  }
  if(C && flagC == 0){
    stamp3 = millis();
    flagC = 1;
  }
  if(D && flagD == 0){
    stamp4 = millis();
    flagD = 1;
  }

  if(!A && flagA == 1){
    longPressA = 0;
    long over = millis() - stamp1;
    if(over < 500){
      doubleFlagA++;
      if(doubleFlagA == 1){
        stampA = millis();
      }
    }
    flagA = 0;
  }
  if(!B && flagB == 1){
    longPressB = 0;
    long over = millis() - stamp2;
    if(over < 500){
      doubleFlagB++;
      if(doubleFlagB == 1){
        stampB = millis();
      }
    }
    flagB = 0;
  }
  if(!C && flagC == 1){
    longPressC = 0;
    long over = millis() - stamp3;
    if(over < 500){
      doubleFlagC++;
      if(doubleFlagC == 1){
        stampC = millis();
      }
    }
    flagC = 0;
  }
  if(!D && flagD == 1){
    longPressD = 0;
    long over = millis() - stamp4;
    if(over < 500){
      doubleFlagD++;
      if(doubleFlagD == 1){
        stampD = millis();
      }
    }
    flagD = 0;
  }
   
  if(doubleFlagA ==1 && (millis() -stamp1) > 400){
      clickTempA = 1; 
      doubleFlagA = 0;
  }
  if(doubleFlagA ==2 && (millis() -stampA) <500){
      clickTempA = 2; 
      doubleFlagA = 0;
   }
  
  if(A && (millis() - stamp1)>2000 && longPressA ==0){
      clickTempA = 3; 
      longPressA = 1;
    }

  if(doubleFlagB ==1 && (millis() -stamp2) > 400){
      clickTempB = 1; 
      doubleFlagB = 0;
  }
  if(doubleFlagB ==2 && (millis() -stampB) <500){
      clickTempB = 2; 
      doubleFlagB = 0;
   }
  
  if(B&& (millis() - stamp2)>2000 && longPressB ==0){
      clickTempB = 3; 
      longPressB = 1;
    }

   if(doubleFlagC ==1 && (millis() -stamp3) > 400){
      clickTempC = 1; 
      doubleFlagC = 0;
  }
  if(doubleFlagC ==2 && (millis() -stampC) <500){
      clickTempC = 2; 
      doubleFlagC = 0;
   }
  
  if(C && (millis() - stamp3)>2000 && longPressC ==0){
      clickTempC = 3; 
      longPressC = 1;
    }

   if(doubleFlagD ==1 && (millis() -stamp4) > 400){
      clickTempD = 1; 
      doubleFlagD = 0;
  }
  if(doubleFlagD ==2 && (millis() -stampD) <500){
      clickTempD = 2; 
      doubleFlagD = 0;
   }
  
  if(D && (millis() - stamp4)>2000 && longPressD ==0){
      clickTempD = 3; 
      longPressD = 1;
    }

  if(clickTempA == 1){
    Serial.println("click A");
    clickTempA = 0;
  }else if(clickTempA == 2){
    clickTempA = 0;
    Serial.println("double click A");
  }else if(clickTempA == 3){
    clickTempA = 0;
    Serial.println("long press A");
  }

  if(clickTempB == 1){
    Serial.println("click B");
    clickTempB = 0;
  }else if(clickTempB == 2){
    clickTempB = 0;
    Serial.println("double click B");
  }else if(clickTempB == 3){
    clickTempB = 0;
    Serial.println("long press B");
  }

  if(clickTempC == 1){
    Serial.println("click C");
    clickTempC = 0;
  }else if(clickTempC == 2){
    clickTempC = 0;
    Serial.println("double click C");
  }else if(clickTempC == 3){
    clickTempC = 0;
    Serial.println("long press C");
  }
  if(clickTempD == 1){
    Serial.println("click D");
    clickTempD = 0;
  }else if(clickTempD == 2){
    clickTempD = 0;
    Serial.println("double click D");
  }else if(clickTempD == 3){
    clickTempD = 0;
    Serial.println("long press D");
  }
}
//获取摇杆X,Y方向上面的控制信息
void xyContral(){
  
  if(scanX > 700 && scanY > 700){
    if(lastDirection != RIGHTUP){
     Serial.println("右上");
     Direction = RIGHTUP;
    }
  }else if(scanX  > 700 && scanY < 300){
    if(lastDirection != RIGHTDOWN){
   Serial.println("右下");
   Direction = RIGHTDOWN;
    }
  }else if(scanX < 300 && scanY > 700){
   if(lastDirection != LEFTUP){
     Serial.println("左上");
     Direction = LEFTUP;
       }
  }else if(scanX < 300 && scanY < 300){
   if(lastDirection != LEFTDOWN){
     Serial.println("左下");
     Direction = LEFTDOWN;
       }
  }else if(scanY > 700){
    if(lastDirection != UP){
      Serial.println("上");
      Direction = UP;
        }
  }else if(scanY < 300){
   if(lastDirection != DOWN){
     Serial.println("下");
     Direction = DOWN;
       }
  }else if(scanX < 300){
   if(lastDirection != LEFT){
     Serial.println("左");
     Direction = LEFT;
       }
  }else if(scanX > 700){
   if(lastDirection != RIGHT){
     Serial.println("右");
     Direction = RIGHT;
       }
  }else if(scanX < 700 && scanX > 300 && scanY >300 && scanY <700){
   if(lastDirection != CENTRAL){
      Serial.println("中");
      Direction = CENTRAL; 
   }
  }       
  lastDirection = Direction;
 }

void setup() {
  Serial.begin(9600);  // start serial for output
  //模块初始化
  while(!control.begin()){
     Serial.println("I2C 通信失败");
     delay(1000);
  }
}

void loop() {
  scan();
  //识别按钮的单击,双击和长按
  btnControl();
  //获取摇杆X,Y方向上面的控制信息
  xyContral();
  delay(10);
}