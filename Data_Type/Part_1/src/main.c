/////////////////////////////////////////////////////////////////////////
///	\file main.c
///	\brief This is the main program code.
///
///	Author: Ronald Sousa (Opticalworm)
/////////////////////////////////////////////////////////////////////////
#include "common.h"
#include "MCU/led.h"
#include "MCU/tick.h"

// assuming we are working on a 32bit system.

char                Char_Type;              // 1 byte   8bit   -128 to +127
signed char         Signed_Char_Type;       // 1 byte   8bit   -128 to +127
unsigned char       Unsigned_Char_Type;     // 1 byte   8bit   +0 to 255

int                 Int_Type;               // 4 byte   32bit   -2147483648 to +2147483647
signed int          Signed_Int_Type;        // 4 byte   32bit   -2147483648 to +2147483647
unsigned int        Unsigned_Int_Type;      // 4 byte   32bit   0 to +4294967295

short int           Short_Int_Type;          // 2 byte   16bit   -32768 to 32767
short signed int    Signed_Short_Int_Type;   // 2 byte   16bit   -32768 to 32767
short unsigned int  Unsigned_Short_Int_Type; // 2 byte   16bit   0 to 65535

long int            Long_Int_Type;          // 8 byte   64bit   -9223372036854775808 to +9223372036854775807
long unsigned int   Unsigned_Long_Int_Type; // 8 byte   64bit   -9223372036854775808 to +9223372036854775807
long signed int     Signed_Long_Int_Type;   // 8 byte   64bit   0 to +18446744073709551615

float               Float_Type;             // 4 byte   32bit   single precision

// assuming that double is enable in compiler
double              Double_Type;            // 4 or 8 byte      single precision / double precision

// assuming that double is enable in compiler
long double         Long_Double_Type;       // 8 byte           double precision


/////////////////////////////////////////////////////////////////////////
///	\brief the first user code function to be called after the ARM M0
///	has initial.
/////////////////////////////////////////////////////////////////////////
void main(void)
{
    Led_Init();
    Tick_init();

    for ( ;; )
    {
    	Led_Toggle();
    	Tick_DelayMs(1000);
    }
}
