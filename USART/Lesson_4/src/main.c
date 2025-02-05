/////////////////////////////////////////////////////////////////////////
///	\file main.c
///	\brief This is the main program code.
///
///	Author: Ronald Sousa (Opticalworm)
/////////////////////////////////////////////////////////////////////////
#include "common.h"
#include "MCU/led.h"
#include "MCU/usart2.h"
#include "MCU/tick.h"

/////////////////////////////////////////////////////////////////////////
///	\brief the first user code function to be called after the ARM M0
///	has initial.
/////////////////////////////////////////////////////////////////////////
void main(void)
{
    uint8_t TempData;
    uint32_t DelayCount;


    Led_Init();
    Tick_init();

    SerialPort2.Open(115200);

    for ( ;; )
    {
        if(SerialPort2.GetByte(&TempData))
        {
            SerialPort2.SendByte(TempData);

            // Application
            for(DelayCount = 100; DelayCount ; DelayCount--)
            {
            	Led_Toggle();
            }
        }
    }
}
