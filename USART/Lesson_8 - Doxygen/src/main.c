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
#include "FIFO.h"


/////////////////////////////////////////////////////////////////////////
///	\brief the first user code function to be called after the ARM M0
///	has initial.
/////////////////////////////////////////////////////////////////////////
void main(void)
{
	uint_fast8_t FifoReadReturnValue;

    uint8_t TempData;

    FIFO_Initialiser();
    Led_Init();
    Tick_init();

    SerialPort2.Open(115200);

    for ( ;; )
    {
        if(SerialPort2.GetByte(&TempData))
        {
        	if( FALSE == FIFO_Write(TempData) )
        	{

        		FifoReadReturnValue = TRUE;

        		for( ; FifoReadReturnValue; )
        		{
        			FifoReadReturnValue	= FIFO_Read(&TempData);


        			if( ERROR == FifoReadReturnValue )
        			{

        				break;
        			}
        			else if( TRUE == FifoReadReturnValue )
        			{
        				SerialPort2.SendByte(TempData);
        			}


        		}

        	}



            Led_Toggle();
        }
    }
}
