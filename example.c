#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "print.h"

int main(void)
{
    print_sep = " ";

    char char1 = 'A';
    char char2 = 'b';
    char char3 = 0x39;

    print("char char1 'A' =", char1);
    print("char char2 'b' =", char2);
    print("char char3 0x39 =", char3);
    print("");

    unsigned char char4 = 'A';
    unsigned char char5 = 'b';
    unsigned char char6 = 0x35;

    print("unsigned char char4 'A' =", char4);
    print("unsigned char char5 'b' =", char5);
    print("unsigned char char6 0x35 =", char6);
    print("");

    signed char char7 = 'A';
    signed char char8 = 'b';
    signed char char9 = 0x34;

    print("signed char char7 'A' =", char7);
    print("signed char char8 'b' =", char8);
    print("signed char char9 0x34 =", char9);
    print("");

    int8_t i81 = 'A';
    int8_t i82 = 'b';
    int8_t i83 = 0x39;

    print("int8_t i81 'A' =", i81);
    print("int8_t i82 'b' =", i82);
    print("int8_t i83  0x39 =", i83);
    print("");

    uint8_t ui81 = 'A';
    uint8_t ui82 = 'b';
    uint8_t ui83 = 0x37;

    print("uint8_t ui81 'A' =", ui81);
    print("uint8_t ui82 'b' =", ui82);
    print("uint8_t ui83  0x37 =", ui83);
    print("\n");


    char* string_1 = "loooooooooong string";
    char* string_2 = "another string";

    print("char* string_1 \"loooooooooong string\" =", string_1);
    print("char* string_2 \"another string\" =", string_2);
    print("");

    char* part1 = "Hello";
    char* part2 = ", World!";

    print("char* part1 \"Hello\" = ", part1);
    print("char* part2 \", World!\" = ", part2);
    print("\n");


    short sh = 100;
    signed short s_sh = -4200;
    unsigned short us_sh = 9203;

    print("short sh 100 =", sh);
    print("signed short s_sh -4200 =", s_sh);
    print("unsigned short us_sh 9203 =", us_sh);
    print("");

    int i = 1300;
    signed int s_i = -94200;
    unsigned int us_i = 92031;

    print("int i 1300 =", i);
    print("signed int s_i -94200 =", s_i);
    print("unsigned int us_i 92031 =", us_i);
    print("");

    long l = 130330L;
    signed long s_l = -19420L;
    unsigned long us_l = 19231UL;

    print("long l 130330L =", l);
    print("signed long s_l -19420L =", s_l);
    print("unsigned long us_l 19231UL =", us_l);
    print("\n");

    float d1 = 3.14159265368979f;
    double d2 = 3.14159265368979;

    print("float d1 3.14159265368979 = ", d1);
    print("double d2 3.14159265368979 = ", d2);
    print("\n");

    int16_t i16 = -2364;
    int32_t i32 = -235344;
    int64_t i64 = -23403234LL;

    print("int16_t i16 -2364 = ", i16);
    print("int32_t i32 -235344 = ", i32);
    print("int64_t i64 -23403234LL = ", i64);
    print("");

    uint16_t ui16 = 2364;
    uint32_t ui32 = 235344;
    uint64_t ui64 = 23403234LL;

    print("uint16_t ui16 2364 = ", ui16);
    print("uint32_t ui32 235344 = ", ui32);
    print("uint64_t ui64 23403234LL = ", ui64);

    return EXIT_SUCCESS;
}
