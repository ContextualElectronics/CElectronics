#include <stdio.h>    // used by the printf`
#include <limits.h>    // used for data type constants

// assuming we are working on a 32bit sytem.

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

int main(void)
{
    char Char_Size = sizeof(char);
    char Char_Min = 0x00;
    char Char_Max = 0xFF; // 0xFF is the incorrect value for the max. What should it be?

    // Note: printf is used new line character (\n)
    // to flux your string into the terminal
    printf("\n\n");
    printf("type \t\t\t\tbyte \t\t min \t\t max\n");
    printf("Char_Type \t\t\t%d \t\t %d \t\t %d\n", Char_Size, Char_Min, Char_Max);
    printf("\n\n");



    return 0;
}
