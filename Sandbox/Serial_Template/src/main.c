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
    Led_Init();
    Tick_init();
    SerialPort2.Open(115200);

    SerialPort2.SendString((uint8_t *)"Hello World!\r\n");

    for ( ;; )
    {

    	Tick_DelayMs(500); // Delay for 500ms = 1/2s
    	Led_Toggle(); // Toggle the LED. This should cause the LED to turn on every second
    }
}
