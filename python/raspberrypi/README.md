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
    @return True(初始化成功)/Fasle(初始化失败)
  '''
  def begin(self):

  '''
    @brief 对传感器进行软件复位
  '''
  def reset(self):
  
  '''
    @brief Get chip id
    @return 8 bit serial number
  '''
  def get_id(self):
    
  '''
    @brief Set the measurement range
    @param range Range
                 RANGE_500MG  #±500mg
                 RANGE_1G     #±1g
                 RANGE_2G     #±2g
                 RANGE_3G     #±3g
  '''
  def set_range(self,range_r):

  '''
    @brief 使能芯片中断
    @param enable True(使能中断)/False(不使能中断)
  '''
  def enable_interrupt(self,enable):

  '''
    @brief 滤波路径选择
    @param  path  滤波路径
            IIS2ICLX_HPF     /<滤波选择为high-pass digital filter，高通滤波>/
            IIS2ICLX_SLOPE   /<滤波选择为slope filter,斜率滤波>/
  '''
  def set_filter_Path(self,path):

  '''
    @brief 设置传感器转换加速度数据的频率
    @param rate,数据输出频率,可取的参数值如下
                 IIS2ICLX_RATE_0HZ      /<shutdown>/
                 IIS2ICLX_RATE_12HZ5    /<12.5hz>/
                 IIS2ICLX_RATE_26HZ     /<26hz>/
                 IIS2ICLX_RATE_52HZ     /<52hz>/
                 IIS2ICLX_RATE_104HZ    /<104hz>/
                 IIS2ICLX_RATE_208HZ    /<208hz>/
                 IIS2ICLX_RATE_416HZ    /<416hz>/
                 IIS2ICLX_RATE_833HZ    /<833hz>/
  '''
  def set_data_rate(self, rate):
  
  '''
    @brief 设置唤醒的持续时间,在此时间后,若两个方向的加速度数据小于唤醒阈值,那么模块会进入睡眠状态
    @param dur  duration time 范围 0 ~ 15
    @n time = dur * (512/rate)(unit:s) 
     |                                  参数与时间之间的线性关系的示例                                     |
     |-----------------------------------------------------------------------------------------------------|
     |                  |                          |                          |                            |
     |  Data rate       |       12.5 Hz            |       26 Hz              |        52 Hz               |
     |-----------------------------------------------------------------------------------------------------|
     |   time           |dur*(512s/12.5)=dur*40s   |dur*(512s/26)=dur*20s  | dur*(3512s/52)= dur*10ms |
     |---------------------------------------------------------------------------------------------------- |
  '''
  def set_wake_up_dur(self,dur):

  '''
    @brief Set the wake-up threshold,某个方向的加速度大于此值时,会触发wake-up事件
    @param th threshold ,unit:mg,数值是在量程之内
  '''
  def set_wakeup_threshold(self,th):

  '''
    @brief lock interrupt Switches between latched ('1'-logic) and pulsed ('0'-logic) mode for 
    @n function source signals and interrupts routed to pins (wakeup, single/double-tap).
    @param enable  true lock interrupt.
                    false pulsed interrupt
  '''
  def lock_interrupt(self,enable):
  
  '''
    @brief Set to detect tap events in the Y direction
    @param enable Ture(使能点击检测\False(禁用点击检测)
  '''
  def __enable_tap_detection_on_y(self, enable):
    
  '''
    @brief Set to detect tap events in the X direction
    @param enable Ture(使能点击检)\False(禁用点击检)
  '''
  def __enable_tap_detection_on_x(self, enable):

  '''
    @brief Set the tap threshold in the X and Y direction
    @param th Threshold(g)
  '''
  def set_tap_threshold(self,th):

  '''
    @brief Set the tap threshold in the X direction
    @param th Threshold(g)
  '''
  def set_tap_threshold_on_x(self,th):
  
  '''
    @brief Set the tap threshold in the Y direction
    @param th Threshold(g)
  '''
  def set_tap_threshold_on_y(self,th):
    
  '''
    @brief 设置双击事件中两次敲击间的时间间隔。
    @param dur  duration time 范围 0 ~ 15
    @n time = dur * (8/rate)(unit:s) 
    |                                  参数与时间之间的线性关系的示例                                    |
    |----------------------------------------------------------------------------------------------------|
    |                  |                         |                          |                            |
    |  Data rate       |       12.5 Hz           |       26 Hz              |        52 Hz               |
    |----------------------------------------------------------------------------------------------------|
    |   time           |dur*(32s/12.5)=dur*2560ms|dur*(32s/26)=dur*1230ms   | dur*(32s/52)= dur*615ms    |
    |--------------------------------------------------------------------------------------------------- |
  '''
  def set_tap_dur(self,dur):
    
  '''
    @brief 设置quiet time,用在双击事件的识别中，当第一个单击事件被识别到后，会有一个quiet time 时间，
    @n 在这个时间后 duration time前产生另外一个单击事件,才会被识别为双击事件。
    @param quiet  quiet time 范围 0 ~ 3
    @n time = quiet * (4/rate)(unit:s) 
     |                                  参数与时间之间的线性关系的示例                                     |
     |-----------------------------------------------------------------------------------------------------|
     |                  |                           |                          |                           |
     |  Data rate       |       12.5 Hz             |       26 Hz              |        52 Hz              |
     |-----------------------------------------------------------------------------------------------------|
     |   time           |quiet*(4s/12.5)=quiet*320ms|quiet*(4s/26)=quiet*153ms | quiet*(4s/52)= quiet*75ms |
     |---------------------------------------------------------------------------------------------------- |
  '''
  def set_tap_quiet(self,quiet):
  
  '''
    @brief 设置shock time,从加速度大于阈值的时候开始计时,在shock time时间后，如果对应方向的加速度回归到小于阈值的水平，
    @n 则被判定为单击事件，若在shock time时间后对应方向的加速度还是大于阈值，则不会被识别为单击事件
    @param shock  shock time 范围 0 ~3
    @n time = shock * (8/rate)(unit:s) 
     |                                  参数与时间之间的线性关系的示例                                     |
     |-----------------------------------------------------------------------------------------------------|
     |                  |                           |                          |                           |
     |  Data rate       |       12.5 Hz             |       26 Hz              |        52 Hz              |
     |-----------------------------------------------------------------------------------------------------|
     |   time           |shock*(8s/12.5)=shock*640ms|shock*(8s/26)=shock*307ms | shock*(8s/52)= shock*153ms|
     |---------------------------------------------------------------------------------------------------- |
  '''
  def set_tap_shock(self,shock):
  
  '''
    @brief Set the tap detection mode,仅检测单击或者仅检测双击
    @param mode 点击检测模式
                     STAP   /<检测单击>/
                     DTAP  /<检测双击>/
  '''
  def set_tap_mode(self,mode):
    
  '''
    @brief 选择在中断1引脚产生的中断事件
    @param event  中断事件,当此事件产生会在中断1引脚产生电平跳变
                  WAKEUP               /<wake up 事件>/
                  SINGLE_TAP            /<单击事件>/
                  DOUBLE_TAP            /<双击事件>/
                  MOTION    /<静止/运动检测>/
  '''
  def set_int1_event(self,event):
    
  '''
    @brief 选择在中断2引脚产生的中断事件
    @param event  中断事件,当此事件产生会在中断2引脚产生电平跳变
                  WAKEUP               /<wake up 事件>/
                  SINGLE_TAP            /<单击事件>/
                  DOUBLE_TAP            /<双击事件>/
                  MOTION    /<静止/运动检测>/
  '''
  def set_int2_event(self,event):

  '''
    @brief Read the acceleration in the x direction
    @return  Acceleration data from x(mg),测量的量程通过setRange()函数设置置
  '''
  def read_acc_x(self):

  '''
    @brief Read the acceleration in the y direction
    @return  Acceleration data from y(mg),测量的量程通过setRange()函数设置
  '''
  def read_acc_y(self):
  
  '''
    @brief 检测是否有运动产生
    @return True(产生运动)/False(传感器未运动)
  '''
  def act_detected(self):
     
  '''
    @brief 检测是否有点击事件产生
    @return true(有点击事件)/false(没有点击事件)
  '''
  def tap_detected(self):

  '''
   @brief 获取敲击的类型,双击或者单击
   @return STAP 单击事件
           DTAP 双击事件
  '''
  def get_tap_type(self):

  '''
    @brief 点击方向的源头检测
    @return    DIR_X_POSITIVE   /<从 X 正方向发生的点击事件>/
               DIR_X_NEGATIVE /<从 X 负方向发生的点击事件>/
               DIR_Y_POSITIVE   /<从 Y 正方向发生的点击事件>/
               DIR_Y_NEGATIVE /<从 Y 负方向发生的点击事件>/
  '''
  def get_tap_direction(self):
     
  '''
    @brief 睡眠唤醒检测
    @return true(模块从睡眠状态唤醒)/false(模块仍处于睡眠状态)
  '''
  def wakeup_detected(self):
  
  '''
    @brief 唤醒的运动方向检测
    @return    DIR_X  #X方向的运动唤醒芯片
               DIR_Y  #Y方向的运动唤醒芯片
               DIR_Z  #Z方向的运动唤醒芯片
               eDirError,
  '''
  def get_wake_up_dir(self):

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
