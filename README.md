# DFRobot_MINI_CONTROL
  mini control module,该模块带有一个摇杆,通过摇杆上面的两路ADC数值,计算出摇杆在360°范围内的方向变化，并带有四个数字按钮,模块通过I2C与主控通信

![正反面svg效果图](https://github.com/cdjq/DFRobot_IIS/raw/master/resources/images/SEN0245svg1.png)
![正反面svg效果图](https://github.com/cdjq/DFRobot_IIS/raw/master/resources/images/SEN0245svg2.png)
## 产品链接（链接到英文商城）
    SKU：产品名称
## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary


Provide an Arduino library to drive the mini control module

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## methods

```C++

  /**
   * @brief 初始化I2C
   * @return true(初始化成功)/false(初始化失败)
  */
  bool begin();
  
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
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno        |      √       |              |             | 
FireBeetle-ESP8266        |      √       |              |             | 
FireBeetle-ESP32        |      √       |              |             | 
Arduino MEGA2560        |      √       |              |             | 
Arduino Leonardo|      √       |              |             | 
Micro:bit        |      √       |              |             | 
FireBeetle-M0        |      √       |              |             | 
Raspberry Pi      |      √       |              |             | 

## History

- data 2021-4-29
- version V1.0


## Credits

Written by(li.feng@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
