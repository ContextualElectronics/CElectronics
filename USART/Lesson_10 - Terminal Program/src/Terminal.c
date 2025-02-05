///////////////////////////////////////////////////////////////////////////////
/// \file Terminal.c
///
///	\author Ronald Sousa @Opticalworm
///////////////////////////////////////////////////////////////////////////////
#include "common.h"
#include "MCU/led.h"
#include "MCU/usart2.h"
#include "MCU/tick.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Defines our terminal buffer size which in turn set the longest command
///////////////////////////////////////////////////////////////////////////////
#define TERMINALD_BUFFER_SIZE 5

///////////////////////////////////////////////////////////////////////////////
/// \brief Keep track of the number of bytes we received from the computer
///////////////////////////////////////////////////////////////////////////////
static uint32_t NumberOfByteReceived;

///////////////////////////////////////////////////////////////////////////////
/// \brief The terminal data buffer
///////////////////////////////////////////////////////////////////////////////
static uint8_t Buffer[TERMINALD_BUFFER_SIZE];

///////////////////////////////////////////////////////////////////////////////
/// \brief Init the terminal program
///////////////////////////////////////////////////////////////////////////////
void Terminal_Init(void)
{
    Led_Init();
    Tick_init();
    SerialPort2.Open(57600);

    NumberOfByteReceived = 0;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief process the buffer data and extract the commands
///
///	\return TRUE success
///
///	\todo update the document return state value. need to implement
///////////////////////////////////////////////////////////////////////////////
static int_fast8_t ProcessData(void)
{

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief run the terminal command
///
///	\return TRUE success
///
///	\todo update the document return state value. need to implement
///////////////////////////////////////////////////////////////////////////////
static int_fast8_t RunCommand(void)
{

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief process the buffer data and extract the commands
///
///	\return TRUE success. FALSE no error
///
///	\todo update the document return state value. need to implement
///////////////////////////////////////////////////////////////////////////////
int_fast8_t Terminal_Process(void)
{
	uint8_t SerialTempData = 0; // hold the new byte from the serial fifo
	int_fast8_t Result = FALSE;

	Result = SerialPort2.GetByte(&SerialTempData);

	if ( TRUE != Result )
	{
		return Result;
	}

	if ('\r' == SerialTempData)
	{
		if (NumberOfByteReceived)
		{
			/// \todo call the process data
			if ( TRUE == ProcessData() )
			{
				if(  TRUE == RunCommand() )
				{
					Result =  TRUE;
				}

			}
		}
		else
		{
			Result =  FALSE;
		}
	}
	else if ( (SerialTempData >= '0' && SerialTempData <= '9') ||
			(SerialTempData >= 'A' && SerialTempData <= 'Z') ||
			(SerialTempData >= 'a' && SerialTempData <= 'z') )

	{
		if ( NumberOfByteReceived < TERMINALD_BUFFER_SIZE )
		{
			Buffer[NumberOfByteReceived] = SerialTempData;
			NumberOfByteReceived++;
			return FALSE;
		}

	}

	// reset buffer by reseting the counter
	NumberOfByteReceived = 0;
	return Result;


}









