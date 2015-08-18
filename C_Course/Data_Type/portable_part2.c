#include <stdio.h>    // used by the printf`
#include <stdint.h>   // used to bring the standard data types


// there will be at least 1 byte
uint_least8_t      poss_least_8_Type;
uint_least16_t     poss_least_16_Type;
uint_least32_t     poss_least_32_Type;
uint_least64_t     poss_least_64_Type;

int_least8_t      least_8_Type;
int_least16_t     least_16_Type;
int_least32_t     least_32_Type;
int_least64_t     least_64_Type;

// it will uses what data size hardware can execute the quickest
// if its a 32bit system then it will likely use 32bit data size
uint_fast8_t      poss_fast_8_Type;
uint_fast16_t     poss_fast_16_Type;
uint_fast32_t     poss_fast_32_Type;
uint_fast64_t     poss_fast_64_Type;

int_fast8_t       fast_8_Type;
int_fast16_t      fast_16_Type;
int_fast32_t      fast_32_Type;
int_fast64_t      fast_64_Type;


int main(void)
{
    // Note: printf is used new line character (\n)
    // to flux your string into the terminal
    printf("Hello World!\n");    

    return 0;
}
