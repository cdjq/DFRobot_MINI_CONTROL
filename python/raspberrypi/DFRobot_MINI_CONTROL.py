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
  IIC_ADDRESS          = 0x84  #I2C��ַ
  MINI_CONTROL_ABCD    = 0xB1  #��ȡA,B,C,D�ĸ���ť��״̬�Ĵ���
  MINI_CONTROL_X       = 0xB2  #��ȡx�����ϵ�ģ��ֵ
  MINI_CONTROL_Y       = 0xB3  #��ȡy�����ϵ�ģ��ֵ
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
    @brief ��ȡmini controlģ�� x�����ģ��ֵ
    @return ����10λADģ��ֵ,��Χ��0~1023
  '''
  def read_X(self):
    data = self.read_reg(self.MINI_CONTROL_X,2)
    x = data[0] << 8 | data[1]
    return x
    
  '''
    @brief ��ȡmini controlģ�� y�����ģ��ֵ
    @return ����10λADģ��ֵ,��Χ��0~1023
  '''
  def read_Y(self):
    data = self.read_reg(self.MINI_CONTROL_Y,2)
    y = data[0] << 8 | data[1]
    return y
    
  '''
    @brief ��ȡ��ťA,B,C,D��״̬
    @param btnA ��ťA��״̬,1:����, 0:�ɿ�
    @param btnB ��ťB��״̬,1:����, 0:�ɿ�
    @param btnC ��ťC��״̬,1:����, 0:�ɿ�
    @param btnD ��ťD��״̬,1:����, 0:�ɿ�
  '''
  def read_btn_ABCD(self):
    data = self.read_reg(self.MINI_CONTROL_ABCD,1)
    b = (data[0] & 0x04)>>2
    d = (data[0] & 0x08)>>3
    c = data[0] & 0x01
    a = (data[0] & 0x02)>>1

    #print(a)
    return a,b,c,d
    
  '''
    @brief ��ȡ�Ĵ���reg��ֵ
    @param reg �Ĵ���
    @param len �������ݵĳɶ�
    @return ��ȡ���ݵ�����
  '''
  def read_reg(self, reg ,len):
    self.i2cbus.write_byte(self._addr,reg)
    time.sleep(0.03)
    for i in range(len):
      self.rxbuf[i] = self.i2cbus.read_byte(self._addr)
    return self.rxbuf