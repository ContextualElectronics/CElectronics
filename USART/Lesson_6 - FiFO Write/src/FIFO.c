///////////////////////////////////////////////////////////////////////////////
/// \file FIFO.c
///
///	\brief This is our FIFO library
///
///	\author Ronald Sousa @Opticalworm
///////////////////////////////////////////////////////////////////////////////
#include "common.h"

////////////////////////////////////////////////////////
///	\brief defines the fifo buffer max size.
////////////////////////////////////////////////////////
#define FIFO_BUFFER_MAX_SIZE 3

////////////////////////////////////////////////////////
///	\brief Is our fifo buffer.
///
///	\note The fifo data type is unsigned 8bit
////////////////////////////////////////////////////////
static uint8_t Buffer[FIFO_BUFFER_MAX_SIZE];

////////////////////////////////////////////////////////
///	\brief keep track of the number of data in buffer
///
///	\sa Buffer[]
////////////////////////////////////////////////////////
static uint32_t BufferCurrentSize = 0;

////////////////////////////////////////////////////////
///	\brief keep track of the write buffer position
///
///	\sa Buffer[] BufferCurrentSize FIFO_BUFFER_MAX_SIZE
////////////////////////////////////////////////////////
static uint32_t WritePosition = 0;


////////////////////////////////////////////////////////
///	\brief This will init the fifo variables and
///	clear the buffer
////////////////////////////////////////////////////////
void FIFO_Initialiser(void)
{
	uint32_t BufferIndex;

	WritePosition = 0;
	BufferCurrentSize = 0;

	for( BufferIndex = 0 ; BufferIndex < FIFO_BUFFER_MAX_SIZE; BufferIndex++ )
	{
		Buffer[BufferIndex] = 0;
	}
}

////////////////////////////////////////////////////////
///	\brief Write inputData into our buffer.
///
///	\param inputData copy of the data we want to store
///
///	\return TRUE = successfully writing data to our buffer
///			FALSE = No space in buffer
////////////////////////////////////////////////////////
uint_fast8_t FIFO_Write(uint8_t inputData)
{
	uint_fast8_t Result = FALSE;


	if( BufferCurrentSize < FIFO_BUFFER_MAX_SIZE )
	{
		// We have space

		Buffer[WritePosition] = inputData;

		BufferCurrentSize++;

		WritePosition++;

		// check to see if we need to reset the write position index counter.
		// this will ensure that the buffer is circulating
		if ( FIFO_BUFFER_MAX_SIZE == WritePosition )
		{
			WritePosition = 0;
		}

		Result = TRUE;
	}

	return Result;
}





