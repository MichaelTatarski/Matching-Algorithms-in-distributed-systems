#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#include <stdint.h>

typedef union Data
{
    int64_t INTEGER64;
    int32_t INTEGER32;
    double DOUBLE;
    char TEXT32[32];
} Data;

typedef enum DataType
{
    INTEGER64,
    INTEGER32,
    DOUBLE,
    TEXT32
} DataType;

#endif //DATA_TYPE_H