# DFRobot_MINI_CONTROL
  mini control module,该模块带有一个摇杆,通过摇杆上面的两路ADC数值,计算出摇杆在360°范围内的方向变化，并带有四个数字按钮,模块通过I2C与主控通信





## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#Methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

Provide an Arduino library to drive the mini control module

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```python

  '''
    @brief Initialize the function
  '''
  def begin(self):

  '''
    @brief 读取mini control模块 x方向的模拟值
    @return 返回10位AD模拟值,范围是0~1023
  '''
  def read_X(self):
    
  '''
    @brief 读取mini control模块 y方向的模拟值
    @return 返回10位AD模拟值,范围是0~1023
  '''
  def read_Y(self):

  '''
    @brief 读取按钮A,B,C,D的状态
    @param btnA 按钮A的状态,1:按下, 0:松开
    @param btnB 按钮B的状态,1:按下, 0:松开
    @param btnC 按钮C的状态,1:按下, 0:松开
    @param btnD 按钮D的状态,1:按下, 0:松开
  '''
 def readBtnABCD(self):

```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
raspberry pi 3             |      √         |            |             | 




## History

- data 2021-4-29
- version V1.0


## Credits

Written by(li.feng@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
