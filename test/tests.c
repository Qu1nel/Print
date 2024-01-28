#include <stdint.h>
#include <stdio.h>
#include "ctestify.h"
#include "print.h"

#define clear() memset(buf, 0x00, strlen(buf))

void test_main(){
    SET_TEST_SUITE_NAME(PRINT_TESTS);
    int8_t t1 = 21;
    uint8_t t2 = 22;
    int16_t t3 = 23;
    uint16_t t4 = 24;
    int32_t t5 = 25;
    uint32_t t6 = 26;
    int64_t t7 = 27;
    uint64_t t8 = 28;
    char* longstr = "looooooooooooooooooooooooooooong string";
    char* str = "string";
    float t9 = 0.666;
    double t10 = 0.666;

    char buf[BUFSIZ];
    memset(buf, 0x00, sizeof(buf));
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, buf);

    print(t1);
    EXPECT_EQ(INT8, buf, "21\n");
    clear();
    fflush(stdout);

    print(t2);
    EXPECT_EQ(UINT8, buf, "22\n");
    clear(); fflush(stdout);

    print(t3);
    EXPECT_EQ(INT16, buf, "23\n");
    clear(); fflush(stdout);

    print(t4);
    EXPECT_EQ(UINT16, buf, "24\n");
    clear(); fflush(stdout);

    print(t5);
    EXPECT_EQ(INT32, buf, "25\n");
    clear(); fflush(stdout);

    print(t6);
    EXPECT_EQ(UINT32, buf, "26\n");
    clear(); fflush(stdout);

    print(t7);
    EXPECT_EQ(INT64, buf, "27\n");
    clear(); fflush(stdout);

    print(t8);
    EXPECT_EQ(UINT64, buf, "28\n");
    clear(); fflush(stdout);

    print(longstr);
    EXPECT_EQ(LONGSTR, buf, "looooooooooooooooooooooooooooong string\n");
    clear(); fflush(stdout);

    print(str);
    EXPECT_EQ(STR, buf, "string\n");
    clear(); fflush(stdout);

    print(t9);
    EXPECT_EQ(FLOAT, buf, "0.666000\n");
    clear(); fflush(stdout);

    print(t10);
    EXPECT_EQ(DOUBLE, buf, "0.666000\n");
    clear(); fflush(stdout);

    print(t1, t1);
    EXPECT_EQ(MULINT8, buf, "21, 21\n");
    clear();
    fflush(stdout);

    print(t2, t2);
    EXPECT_EQ(MULUINT8, buf, "22, 22\n");
    clear(); fflush(stdout);

    print(t3, t3);
    EXPECT_EQ(MULINT16, buf, "23, 23\n");
    clear(); fflush(stdout);

    print(t4, t4);
    EXPECT_EQ(MULUINT16, buf, "24, 24\n");
    clear(); fflush(stdout);

    print(t5, t5);
    EXPECT_EQ(MULINT32, buf, "25, 25\n");
    clear(); fflush(stdout);

    print(t6, t6);
    EXPECT_EQ(MULUINT32, buf, "26, 26\n");
    clear(); fflush(stdout);

    print(t7, t7);
    EXPECT_EQ(MULINT64, buf, "27, 27\n");
    clear(); fflush(stdout);

    print(t8, t8);
    EXPECT_EQ(MULUINT64, buf, "28, 28\n");
    clear(); fflush(stdout);

    print(longstr, longstr);
    EXPECT_EQ(LONGSTR, buf, "looooooooooooooooooooooooooooong string, looooooooooooooooooooooooooooong string\n");
    clear(); fflush(stdout);

    print(str, str);
    EXPECT_EQ(STR, buf, "string, string\n");
    clear(); fflush(stdout);

    print(t9, t9);
    EXPECT_EQ(FLOAT, buf, "0.666000, 0.666000\n");
    clear(); fflush(stdout);

    print(t10, t10);
    EXPECT_EQ(DOUBLE, buf, "0.666000, 0.666000\n");
    clear(); fflush(stdout);

    print(t1, t2);
    EXPECT_EQ(MULDIFTYP1, buf, "21, 22\n");
    clear();
    fflush(stdout);

    print(t2, t3);
    EXPECT_EQ(MULDIFTYP2, buf, "22, 23\n");
    clear(); fflush(stdout);

    print(t3, t4);
    EXPECT_EQ(MULDIFTYP3, buf, "23, 24\n");
    clear(); fflush(stdout);

    print(t4, t5);
    EXPECT_EQ(MULDIFTYP4, buf, "24, 25\n");
    clear(); fflush(stdout);

    print(t5, t6);
    EXPECT_EQ(MULDIFTYP5, buf, "25, 26\n");
    clear(); fflush(stdout);

    print(t6, t7);
    EXPECT_EQ(MULDIFTYP6, buf, "26, 27\n");
    clear(); fflush(stdout);

    print(t7, t8);
    EXPECT_EQ(MULDIFTYP7, buf, "27, 28\n");
    clear(); fflush(stdout);

    print(t8, str);
    EXPECT_EQ(MULDIFTYP8, buf, "28, string\n");
    clear(); fflush(stdout);

    print(str, t9);
    EXPECT_EQ(MULDIFTYP9, buf, "string, 0.666000\n");
    clear(); fflush(stdout);

    print(t9, t10);
    EXPECT_EQ(MULDIFTYP10, buf, "0.666000, 0.666000\n");
    clear(); fflush(stdout);

    freopen("/dev/tty", "a", stdout);
}