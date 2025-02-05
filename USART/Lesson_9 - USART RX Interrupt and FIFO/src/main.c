/////////////////////////////////////////////////////////////////////////
///	\file main.c
///	\brief This is the main program code.
///
///	\author Ronald Sousa (Opticalworm)
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

    Led_Init();
    Tick_init();

    SerialPort2.Open(57600);

    for ( ;; )
    {
        while ( TRUE == SerialPort2.GetByte(&TempData) )
        {
			SerialPort2.SendByte(TempData);

        }

        // Some code to run
        Tick_DelayMs(500);
		Led_Toggle();


    }
}
