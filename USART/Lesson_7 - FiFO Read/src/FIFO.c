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
///	\brief keep track of the read buffer position
///
///	\sa Buffer[] BufferCurrentSize FIFO_BUFFER_MAX_SIZE
////////////////////////////////////////////////////////
static uint32_t ReadPosition = 0;

////////////////////////////////////////////////////////
///	\brief This will init the fifo variables and
///	clear the buffer
////////////////////////////////////////////////////////
void FIFO_Initialiser(void)
{
	uint32_t BufferIndex;

	WritePosition = 0;
	ReadPosition = 0;
	BufferCurrentSize = 0;

	for( BufferIndex = 0 ; BufferIndex < FIFO_BUFFER_MAX_SIZE; BufferIndex++ )
	{
		Buffer[BufferIndex] = 0;
	}
}


////////////////////////////////////////////////////////
/// \brief Read one bute from the buffer. Return false
///	if we didn't.
///
///	\param outputDataPointer pointer to return the read value.
///
///	\return TRUE = successfully read a byte rom buffer
///			FALSE = no data to read
///			ERROR = Invalid outputDataPointer pointer
////////////////////////////////////////////////////////
uint_fast8_t FIFO_Read(uint8_t *outputDataPointer)
{
	uint_fast8_t Result = FALSE;

	// check pointer is valid and not set to zero
	if ( outputDataPointer )
	{
		if( BufferCurrentSize > 0)
		{
			// we have data to read

			// Pass the data back
			*outputDataPointer = Buffer[ReadPosition];

			ReadPosition++;

			BufferCurrentSize--;

			if( ReadPosition == FIFO_BUFFER_MAX_SIZE )
			{
				ReadPosition = 0;
			}

			Result = TRUE;
		}



	}
	else
	{
		// pointer error
		Result = ERROR;
	}



	return Result;
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





