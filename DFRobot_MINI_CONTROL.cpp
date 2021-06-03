/*!
   @file DFRobot_MINI_CONTROL.cpp
   @brief DFRobot_MINI_CONTROL 类的实现
   @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
   @licence     The MIT License (MIT)
   @author [fengli](li.feng@dfrobot.com)
   @version  V1.0
   @date  2021-04-29
   @get from https://www.dfrobot.com
   @https://github.com/DFRobot/DFRobot_MINI_CONTROL
*/
#include "DFRobot_MINI_CONTROL.h"
DFRobot_MINI_CONTROL::DFRobot_MINI_CONTROL(uint8_t address,TwoWire *pWire){

  _deviceAddr = address;
  _pWire = pWire;

}

bool DFRobot_MINI_CONTROL::begin(){
  uint8_t value;
  uint8_t ret;
  _pWire->begin();
  ret = readReg(MINI_CONTROL_ABCD,&value,1);
  if(ret == 0){
     return false;
  } else {
     return true;
  }
}
uint16_t DFRobot_MINI_CONTROL::readX(){
  
  uint8_t value[2];
  uint16_t x = 0;
  readReg(MINI_CONTROL_X,value,2);
  //Serial.println(value[0]);
  //Serial.println(value[1]);
  x = value[0] << 8 | value[1];
  return x;
}
uint16_t DFRobot_MINI_CONTROL::readY()
{
  uint8_t value[2];
  uint16_t y = 0;
  readReg(MINI_CONTROL_Y,value,2);
  y = value[0] << 8 | value[1];
  return y;
}
bool DFRobot_MINI_CONTROL::readBtnABCD(uint8_t *A,uint8_t *B,uint8_t *C,uint8_t *D){
  
  uint8_t value;
  uint8_t ret = readReg(MINI_CONTROL_ABCD,&value,1);
  *C = value & 0X1;
  *A = (value & 0X02)>>1;
  *B = (value & 0X04)>>2;
  *D = (value & 0X08)>>3;
  if(ret == 0){
     return false;
   }else{
     return true;
   }
}
void DFRobot_MINI_CONTROL::writeReg(uint8_t reg, uint8_t data)
{
  _pWire->beginTransmission(_deviceAddr);
  _pWire->write(reg);
  _pWire->write(data);
  _pWire->endTransmission();
}

uint8_t DFRobot_MINI_CONTROL::readReg(uint8_t reg, void* pBuf, size_t size)
{
  if(pBuf == NULL){
    DBG("pBuf ERROR!! : null pointer");
  }
  uint8_t * _pBuf = (uint8_t *)pBuf;
  unsigned char i = 0;  
  _pWire->beginTransmission(_deviceAddr);
  _pWire->write(reg);
  if( _pWire->endTransmission() != 0 ) {
      return 0;
  }

  _pWire->requestFrom(_deviceAddr, size);
  for(i = 0 ;i < size ; i++){
      _pBuf[i] = _pWire->read();
  }
  /* Read block data */    
  return i;

}