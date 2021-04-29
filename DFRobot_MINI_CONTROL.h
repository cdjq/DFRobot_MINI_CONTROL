/*!
   @file DFRobot_MINI_CONTROL.h
   @brief DFRobot_MINI_CONTROL 类的基础结构
   @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
   @licence     The MIT License (MIT)
   @author [fengli](li.feng@dfrobot.com)
   @version  V1.0
   @date  2021-04-29
   @get from https://www.dfrobot.com
   @https://github.com/DFRobot/DFRobot_MINI_CONTROL
*/
#ifndef DFRobot_MINI_CONTROL_H
#define DFRobot_MINI_CONTROL_H

#include "Arduino.h"
#include <Wire.h>

//#define ENABLE_DBG
#ifdef ENABLE_DBG
#define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif


#define IIC_ADDRESS          0x84  //I2C地址
#define MINI_CONTROL_ABCD    0xB1  //读取A,B,C,D四个按钮的状态寄存器
#define MINI_CONTROL_X       0xB2  //读取x方向上的模拟值
#define MINI_CONTROL_Y       0xB3  //读取y方向上的模拟值

class DFRobot_MINI_CONTROL
{

public:

  /**
   * @brief 构造函数
   * @param address 7位I2C地址
   * @param pWire I2C总线指针对象，构造设备，可传参数也可不传参数，默认Wire
  */
  DFRobot_MINI_CONTROL( uint8_t address = IIC_ADDRESS,TwoWire *pWire = &Wire);
  
  /**
   * @brief 初始化I2C
  */
  void begin();
  
  /**
   * @brief 读取mini control模块 x方向的模拟值
   * @return 返回10位AD模拟值,范围是0~1023
   */
  uint16_t readX();

  /**
   * @brief 读取mini control模块 y方向的模拟值
   * @return 返回10位AD模拟值,范围是0~1023
   */
  uint16_t readY();
  
  /**
   * @brief 读取按钮A,B,C,D的状态
   * @param btnA 按钮A的状态,1:按下, 0:松开
   * @param btnB 按钮B的状态,1:按下, 0:松开
   * @param btnC 按钮C的状态,1:按下, 0:松开
   * @param btnD 按钮D的状态,1:按下, 0:松开
   */
  void readBtnABCD(uint8_t *btnA,uint8_t *btnB,uint8_t *btnC,uint8_t *btnD);
private:
  uint8_t _deviceAddr;
  TwoWire *_pWire;
  
  /**
   * @brief 写寄存器
   * @param reg  寄存器地址 8bits
   * @param data 要写入数据
   */
  void writeReg(uint8_t reg, uint8_t data);
  
  /**
   * @brief 读取寄存器
   * @param reg  寄存器地址 8bits
   * @param pBuf 要写入数据的存放缓存
   * @param size 要写入数据的长度
   * @return 返回实际读取的长度，返回0表示读取失败
   */
  uint8_t readReg(uint8_t reg, void* pBuf, size_t size);

};

#endif