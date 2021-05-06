# -*- coding: utf-8 -*
""" 
  @file DFRobot_MINI_CONTROL.py
  @brief Define the basic structure of class DFRobot_MINI_CONTROL 
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @licence     The MIT License (MIT)
  @author [fengli](li.feng@dfrobot.com)
  @version  V1.0
  @date  2021-4-29
  @get from https://www.dfrobot.com
  @url https://github.com/DFRobot/DFRobot_MINI_CONTROL
"""
import serial
import time
import smbus
class DFRobot_MINI_CONTROL(object):
  IIC_ADDRESS          = 0x84  #I2C地址
  MINI_CONTROL_ABCD    = 0xB1  #读取A,B,C,D四个按钮的状态寄存器
  MINI_CONTROL_X       = 0xB2  #读取x方向上的模拟�?
  MINI_CONTROL_Y       = 0xB3  #读取y方向上的模拟�?
  rxbuf = [0,0,0,0]
  def __init__(self ,bus,address):
    self.i2cbus = smbus.SMBus(bus)
    self._addr = address
    
  '''
    @brief Initialize the function
  '''
  def begin(self):
    data = self.read_reg(self.MINI_CONTROL_ABCD,1)

  '''
    @brief 读取mini control模块 x方向的模拟�?
    @return 返回10位AD模拟�?范围�?~1023
  '''
  def read_X(self):
    data = self.read_reg(self.MINI_CONTROL_X,2)
    x = data[0] << 8 | data[1]
    return x
    
  '''
    @brief 读取mini control模块 y方向的模拟�?
    @return 返回10位AD模拟�?范围�?~1023
  '''
  def read_Y(self):
    data = self.read_reg(self.MINI_CONTROL_Y,2)
    y = data[0] << 8 | data[1]
    return y
    
  '''
    @brief 读取按钮A,B,C,D的状�?
    @param btnA 按钮A的状�?1:按下, 0:松开
    @param btnB 按钮B的状�?1:按下, 0:松开
    @param btnC 按钮C的状�?1:按下, 0:松开
    @param btnD 按钮D的状�?1:按下, 0:松开
  '''
  def read_btn_ABCD(self):
    data = self.read_reg(self.MINI_CONTROL_ABCD,1)
    b = (data[0] & 0x04)>>2
    d = (data[0] & 0x08)>>3
    c = data[0] & 0x01
    a = (data[0] & 0x02)>>1

    #print(a)
    return a,c,b,d
    
  '''
    @brief 读取寄存器reg的�?
    @param reg 寄存�?
    @param len 所读数据的成都
    @return 读取数据的数�?
  '''
  def read_reg(self, reg ,len):
    self.i2cbus.write_byte(self._addr,reg)
    time.sleep(0.03)
    for i in range(len):
      self.rxbuf[i] = self.i2cbus.read_byte(self._addr)
    return self.rxbuf
