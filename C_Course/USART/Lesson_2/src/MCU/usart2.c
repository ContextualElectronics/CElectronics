/////////////////////////////////////////////////////////////////////////
///	\file usart2.c
///	\brief STM32 serial2 MCU hardware interface layer. to maintain
///	code portability, the hardware related code is split from the main logic.
///
///	Author: Ronald Sousa (Opticalworm)
/////////////////////////////////////////////////////////////////////////
#include "MCU/usart2.h"

/////////////////////////////////////////////////////////////////////////
/// \brief enable 16x oversampling. Used to reduce the baudrate calculation
/// error.
/////////////////////////////////////////////////////////////////////////
//#define USART_OVER_SAMPLE_16

///////////////////////////////////////////////////////////////////////////////
/// \brief Keeps track if the serial port is configure and opend
///////////////////////////////////////////////////////////////////////////////
static uint_fast8_t IsOpenFlag = FALSE;

///////////////////////////////////////////////////////////////////////////////
/// \brief return the serial open state
///
/// \return true = the serial port is open else false
///////////////////////////////////////////////////////////////////////////////
static uint_fast8_t IsSerialOpen(void)
{
    return IsOpenFlag;
}

/////////////////////////////////////////////////////////////////////////
///	\brief	Set usart baudrate. can be called at any time.
///
///	\param baud the desire baudrate
///
///	\note setting baudrate will effect any data currently been sent.susb
///		make sure that you check that the write buffer is empty
/////////////////////////////////////////////////////////////////////////
static void Setbaudrate(uint32_t baud)
{
    /// \todo Need to implement Usart2 Setbaudrate()
}

/////////////////////////////////////////////////////////////////////////
///	\brief	you can use this function to check if the write buffer is
///	empty and ready for new data
///
///	\param destination pointer to return the read byte
///	\return TRUE = Busy else ready. else false
/////////////////////////////////////////////////////////////////////////
static uint_fast8_t IsWriteBusy(void)
{
    /// \todo Need to implement Usart2 IsWriteBusy()
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Open the serial port.
///
/// \param baudrate set the serial port baud rate
///
/// \return true = success else port is already open
///////////////////////////////////////////////////////////////////////////////
static uint_fast8_t Open(uint32_t baudrate)
{

    /// \todo Need to implement Usart2 Open()

    return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Open the serial port
///
/// \return true = success else port is already open
///////////////////////////////////////////////////////////////////////////////
static void Close(void)
{
    /// \todo Need to implement Usart2 Close()
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Send a single byte
///
/// \return true = success else port is not open
///////////////////////////////////////////////////////////////////////////////
static uint_fast8_t SendByte(uint8_t source)
{
    /// \todo implement USART2 functions that send one byte
    return FALSE;
}
///////////////////////////////////////////////////////////////////////////////
/// \brief return the serial receive byte buffer state
///
/// \return      1 = we have data
///              0 = no data to read
///             -1 = Port is not open
///////////////////////////////////////////////////////////////////////////////
static int_fast8_t DoesReceiveBufferHaveData(void)
{
    /// \todo implement USART2 functions that checks if we have data on the rx buffer.
    return -1;
}
///////////////////////////////////////////////////////////////////////////////
/// \brief serial port for reading serial byte
///
/// \param destination pointer to return the newly read byte.
///
/// \return      1 = success on reading a byte
///              0 = no data to read or
///             -1 = Port is not open or the destination pointer is invalid
///////////////////////////////////////////////////////////////////////////////
static int_fast8_t GetByte(uint8_t *destination)
{
    /// \todo implement USART2 functions that returns one byte.
    return -1;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Write a string
///
/// \param source pointer to the string to write. must end with null
///
/// \return true = success else either the port is not open or the pointer
/// to the array is invalid.
///////////////////////////////////////////////////////////////////////////////
static uint_fast8_t SendString(const uint8_t *source)
{
    if (IsOpenFlag && source)
    {
        while(*source)
        {
            if (!SendByte(*source) )
            {
                return FALSE;
            }
            source++;
        }
        return TRUE;
    }
    return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Write an array of bytes
///
/// \param source pointer to the array to transmit.
/// \param length is the size of the array
///
/// \return true = success else either the port is not open or the pointer
/// to the array is invalid.
///////////////////////////////////////////////////////////////////////////////
static uint_fast8_t SendArray(const uint8_t *source, uint32_t length)
{
    if (IsOpenFlag && source)
    {
        for ( ; length ; length--)
        {
            if ( !SendByte(*source) )
            {
                return FALSE;
            }
            source++;
        }
        return TRUE;
    }
    return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Defines the standard serial functions for usart 2
///
/// /sa SerialInterface
///////////////////////////////////////////////////////////////////////////////
SerialInterface SerialPort2 = {
                                    IsSerialOpen,
                                    Open,
                                    Close,
                                    SendByte,
                                    SendString,
                                    SendArray,
                                    DoesReceiveBufferHaveData,
                                    GetByte
                                };
