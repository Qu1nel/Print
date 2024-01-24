#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


#define FORMAT_SEP(i, N, SEP) (((i) == (N)-1) ? "" : SEP)


typedef enum types { UI8, I8, UI16, I16, UI32, I32, UI64, I64, DOUBLE, STRING, VOID } _Type;


static void append_type(_Type type);

static struct {
    size_t head;
    int hidden_types_stack[64];
    void (*append)(_Type type);
} _TypeStack = {.head = 0, .append = &append_type};

static void append_type(_Type type)
{
    size_t idx = _TypeStack.head++;
    _TypeStack.hidden_types_stack[idx] = type;
}


void type_add_ui8(void)
{
    _TypeStack.append(UI8);
}

void type_add_i8(void)
{
    _TypeStack.append(I8);
}

void type_add_ui16(void)
{
    _TypeStack.append(UI16);
}

void type_add_i16(void)
{
    _TypeStack.append(I16);
}

void type_add_ui32(void)
{
    _TypeStack.append(UI32);
}

void type_add_i32(void)
{
    _TypeStack.append(I32);
}

void type_add_ui64(void)
{
    _TypeStack.append(UI64);
}

void type_add_i64(void)
{
    _TypeStack.append(I64);
}

void type_add_double(void)
{
    _TypeStack.append(DOUBLE);
}

void type_add_str(void)
{
    _TypeStack.append(STRING);
}

void type_add_void(void)
{
    _TypeStack.append(VOID);
}


void _print(const char* restrict sep, const char* restrict end, const size_t n, ...)
{
    va_list argptr;
    va_start(argptr, n);

    for (size_t i = 0; i < n; ++i) {
        switch (_TypeStack.hidden_types_stack[i]) {
            case UI8:
                printf("%" PRIu8 "%s", va_arg(argptr, uint8_t), FORMAT_SEP(i, n, sep));
                break;
            case I8:
                printf("%" PRIi8 "%s", va_arg(argptr, int8_t), FORMAT_SEP(i, n, sep));
                break;
            case UI16:
                printf("%" PRIu16 "%s", va_arg(argptr, uint16_t), FORMAT_SEP(i, n, sep));
                break;
            case I16:
                printf("%" PRIi16 "%s", va_arg(argptr, int16_t), FORMAT_SEP(i, n, sep));
                break;
            case UI32:
                printf("%" PRIu32 "%s", va_arg(argptr, uint32_t), FORMAT_SEP(i, n, sep));
                break;
            case I32:
                printf("%" PRIi32 "%s", va_arg(argptr, int32_t), FORMAT_SEP(i, n, sep));
                break;
            case UI64:
                printf("%" PRIu64 "%s", va_arg(argptr, uint64_t), FORMAT_SEP(i, n, sep));
                break;
            case I64:
                printf("%" PRIi64 "%s", va_arg(argptr, int64_t), FORMAT_SEP(i, n, sep));
                break;
            case DOUBLE:
                printf("%f%s", va_arg(argptr, double), FORMAT_SEP(i, n, sep));
                break;
            case STRING:
                printf("%s%s", va_arg(argptr, char*), FORMAT_SEP(i, n, sep));
                break;
            case VOID:
                printf("0x%p%s", va_arg(argptr, void*), FORMAT_SEP(i, n, sep));
                break;
            default:
                printf("Internal '_print' error line: %d in %s\n", __LINE__, __FILE__);
                abort();
        }
    }

    printf("%s", end);
    va_end(argptr);
    _TypeStack.head = 0;
}
