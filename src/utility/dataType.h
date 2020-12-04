#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#include <stdint.h>

#define TEXT32 4
#define TEXT256 32

typedef enum DataType
{
    INTEGER64,
    INTEGER32,
    DOUBLE,
    TEXT
} DataType;

#endif //DATA_TYPE_H