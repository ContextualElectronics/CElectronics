#include <stdio.h>    // used by the printf`
#include <stdint.h>   // used to bring the standard data types

int8_t                Char_8_Type;      // 1 byte   8bit   -128 to +127
uint8_t       Unsigned_Char_8_Type;     // 1 byte   8bit   +0 to 255

int32_t                 Int_32_Type;     // 4 byte   32bit   -2147483648 to +2147483647
uint32_t       Unsigned_Int_32_Type;     // 4 byte   32bit   0 to +4294967295

int16_t           Long_Int_16_Type;      // 2 byte   16bit   -32768 to 32767
uint16_t  Unsigned_Long_Int_16_Type;     // 2 byte   16bit   0 to 65535

int64_t            Long_Int_64_Type;     // 8 byte   64bit   -9223372036854775808 to +9223372036854775807
uint64_t    Signed_Long_Int_64_Type;     // 8 byte   64bit   0 to +18446744073709551615

float               Float_Type;       // 4 byte   32bit   single precision

// assuming that double is enable in compiler
double              Double_Type;      // 4 or 8 byte      single precision / double precision

// assuming that double is enable in compiler
long double         Long_Double_Type; // 8 byte           double precision

int main(void)
{
    // Note: printf is used new line character (\n)
    // to flux your string into the terminal
    printf("Hello World!\n");

    return 0;
}
