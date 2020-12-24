#ifndef LOGIC_EXPRESSIONS_H
#define LOGIC_EXPRESSIONS_H

#include <stdbool.h>

#include "dataType.h"

typedef enum Operator
{
    GREATER_THAN,
    GREATER_THAN_EQUAL,
    LESSER_THAN,
    LESSER_THAN_EQUAL,
    EQUALS

} Operator;

static bool isGreaterThan(DataType type, Data filterValue, Data notificationValue)
{
    if (type == INTEGER64)
        return notificationValue.INTEGER64 > filterValue.INTEGER64;
    if (type == INTEGER32)
        return notificationValue.INTEGER32 > filterValue.INTEGER32;
    if (type == DOUBLE)
        return notificationValue.DOUBLE > filterValue.DOUBLE;
    if (type == TEXT)
        return false;
    else
        return false;
}

static bool isGreaterThanEqual(DataType type, Data filterValue, Data notificationValue)
{
    if (type == INTEGER64)
        return notificationValue.INTEGER64 >= filterValue.INTEGER64;
    if (type == INTEGER32)
        return notificationValue.INTEGER32 >= filterValue.INTEGER32;
    if (type == DOUBLE)
        return notificationValue.DOUBLE >= filterValue.DOUBLE;
    if (type == TEXT)
        return false;
    else
        return false;
}

static bool isLesserThan(DataType type, Data filterValue, Data notificationValue)
{
    if (type == INTEGER64)
        return notificationValue.INTEGER64 < filterValue.INTEGER64;
    if (type == INTEGER32)
        return notificationValue.INTEGER32 < filterValue.INTEGER32;
    if (type == DOUBLE)
        return notificationValue.DOUBLE < filterValue.DOUBLE;
    if (type == TEXT)
        return false;
    else
        return false;
}

static bool isLesserThanEqual(DataType type, Data filterValue, Data notificationValue)
{
    if (type == INTEGER64)
        return notificationValue.INTEGER64 <= filterValue.INTEGER64;
    if (type == INTEGER32)
        return notificationValue.INTEGER32 <= filterValue.INTEGER32;
    if (type == DOUBLE)
        return notificationValue.DOUBLE <= filterValue.DOUBLE;
    if (type == TEXT)
        return false;
    else
        return false;
}

#endif // LOGIC_EXPRESSIONS_H
