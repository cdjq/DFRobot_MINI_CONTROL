# -*- coding:utf-8 -*-
"""
  @file scan.py
  @brief 扫描mini control模块x,y方向,和A,B,C,D四个按钮,读取模拟值和状态
  @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @licence     The MIT License (MIT)
  @author [fengli](li.feng@dfrobot.com)
  @version  V1.0
  @date  2021-04-29
  @get from https://www.dfrobot.com
  @https://github.com/DFRobot_MINI_CONTROL
"""

import sys
sys.path.append("../") # set system path to top

from DFRobot_MINI_CONTROL import *
import time

#如果你想要应IIC驱动此模块，打开下面三行的注释，并通过I2C连接好模块和树莓派
I2C_BUS       = 0x01             #default use I2C1
ADDRESS       = 0x84             #传感器地址
control = DFRobot_MINI_CONTROL(I2C_BUS ,ADDRESS)

#Chip initialization
control.begin()

while True:
  A,B,C,D = control.readBtnABCD()
  scanX = control.readX()
  scanY = control.readY()
  if scanX < 480 or scanX > 530:
    print("X:%d",scanX)
  if scanY < 480 or scanY > 530:
    print("Y:%d",scanY)
  if A = 1:
    print("A")
  if A = 1:
    print("B")
  if A = 1:
    print("C")
  if A = 1:
    print("D")
  time.sleep(0.05)