/*
 * 
 */

#include "SevenSegment.h"

sevenSegment::sevenSegment(int clock, int data)
{
  _clock = clock;
  _data = data;
  pinMode(_clock, OUTPUT);
  pinMode(_data, OUTPUT);
}

void sevenSegment::sendByte(byte p)
{
    for (int i = 7; i > -1; i--) {
      boolean state = bitRead(p, i);
      digitalWrite(_data, state);
      digitalWrite(_clock, HIGH);
      digitalWrite(_clock, LOW);
  }
}

void sevenSegment::showHex(byte x)
{  
  static byte digit[] = {
    0x77, // 0
    0x41, // 1
    0x3B, // 2
    0x6B, // 3
    0x4D, // 4
    0x6E, // 5
    0x7E, // 6 
    0x43, // 7
    0x7F, // 8
    0x6F, // 9
    0x5F, // A
    0x7C, // b
    0x38, // c
    0x79, // d
    0x3E, // E
    0x1E, // F
    0x80, // .
    0x00, // [ ] (all segments off)
    0x2A  // =
  };
  if ( x == -1) {
    sendByte(digit[17]); // [ ]
  } else if ( x == -2 ) {
    sendByte(digit[16]); // .
  } else if ( (x > -1) && (x < 16) ) {
    sendByte(digit[x]);
  } else if ( (x > 15) && (x < 32) ) {
    sendByte(digit[(x - 16)] + 0x80);
  } else {
    sendByte(digit[18]);
  }
}
