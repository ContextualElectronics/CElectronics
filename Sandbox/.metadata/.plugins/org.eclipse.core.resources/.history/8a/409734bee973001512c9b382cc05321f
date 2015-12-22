//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------
#include "common.h"
#include "MCU/led.h"
#include "MCU/usart2.h"
#include "MCU/tick.h"

typedef union{
struct {
		uint8_t time;
		uint8_t location;
		uint8_t name;
		uint8_t Dummy;
		uint32_t index;
	} Data;

	uint8_t myArray[3];

} DataLogPointType;


void main(void)
{
	DataLogPointType DataPoint;
	DataConverter Data;
    uint8_t TempData;

    Data.f32_t[0] = 1.2;

    Led_Init();
    Tick_init();

    SerialPort2.Open(9600);

    SerialPort2.SendByte(Data.ui8_t[0]);
    SerialPort2.SendByte(Data.ui8_t[1]);
    SerialPort2.SendByte(Data.ui8_t[2]);
    SerialPort2.SendByte(Data.ui8_t[3]);

    for ( ;; )
    {
    }
}
