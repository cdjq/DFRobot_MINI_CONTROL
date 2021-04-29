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
class DFRobot_IIS2ICLX(object):
IIC_ADDRESS          = 0x84  #I2C地址
MINI_CONTROL_ABCD    = 0xB1  #读取A,B,C,D四个按钮的状态寄存器
MINI_CONTROL_X       = 0xB2  #读取x方向上的模拟值
MINI_CONTROL_Y       = 0xB3  #读取y方向上的模拟值

  def __init__(self ,bus,address):
    self.i2cbus = smbus.SMBus(bus)
    self._addr = address
    
  '''
    @brief Initialize the function
  '''
  def begin(self):
    data = read_reg(MINI_CONTROL_ABCD,1)
  def read_X(self):
    data = read_reg(MINI_CONTROL_X,2)
    x = data[0] << 8 | data[1]
    return x
  def read_Y(self):
    data = read_reg(MINI_CONTROL_Y,2)
    y = data[0] << 8 | data[1]
    return y
 def readBtnABCD(self):
    data = read_reg(MINI_CONTROL_ABCD,1)
    c = data[0] & 0x01
    a = (value & 0x02)>>1
    b = (value & 0x04)>>1
    d = (value & 0x08)>>1
    return a,b,c,d
  def write_data(self, data):
    self.i2cbus.write_byte(self._addr ,data)
    
  def write_reg(self, reg, data):
    self.i2cbus.write_byte(self._addr ,reg)
    self.i2cbus.write_byte(self._addr ,data)

  def read_reg(self, reg ,len):
    self.i2cbus.write_byte(self._addr,reg)
    time.sleep(0.03)
    for i in range(len):
      self.rxbuf[i] = self.i2cbus.read_byte(self._addr)
    return self.rxbuf
