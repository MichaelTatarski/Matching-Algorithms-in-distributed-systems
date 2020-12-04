#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#include <stdint.h>

#define TEXT32 4
#define TEXT256 32

typedef union Data
{
    int64_t INTEGER64;
    int32_t INTEGER32;
    double DOUBLE;
    char *TEXT[TEXT32];
} Data;

typedef enum DataType
{
    INTEGER64,
    INTEGER32,
    DOUBLE,
    TEXT
} DataType;

#endif //DATA_TYPE_H