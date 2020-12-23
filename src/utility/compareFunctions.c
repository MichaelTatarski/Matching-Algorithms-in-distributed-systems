#include "compareFunctions.h"

bool isGreaterThan(DataType type, Data filterValue, Data notificationValue)
{
    if (type == INTEGER64)
        return notificationValue.INTEGER64 > filterValue.INTEGER64;
    if (type == INTEGER32)
        return notificationValue.INTEGER32 > filterValue.INTEGER32;
    if (type == DOUBLE)
        return notificationValue.DOUBLE > filterValue.DOUBLE;
    if (type == TEXT)
        return false;
}

bool isGreaterThanEqual(DataType type, Data filterValue, Data notificationValue)
{
    if (type == INTEGER64)
        return notificationValue.INTEGER64 >= filterValue.INTEGER64;
    if (type == INTEGER32)
        return notificationValue.INTEGER32 >= filterValue.INTEGER32;
    if (type == DOUBLE)
        return notificationValue.DOUBLE >= filterValue.DOUBLE;
    if (type == TEXT)
        return false;
}

bool isLesserThan(DataType type, Data filterValue, Data notificationValue)
{
    if (type == INTEGER64)
        return notificationValue.INTEGER64 < filterValue.INTEGER64;
    if (type == INTEGER32)
        return notificationValue.INTEGER32 < filterValue.INTEGER32;
    if (type == DOUBLE)
        return notificationValue.DOUBLE < filterValue.DOUBLE;
    if (type == TEXT)
        return false;
}

bool isLesserThanEqual(DataType type, Data filterValue, Data notificationValue)
{
    if (type == INTEGER64)
        return notificationValue.INTEGER64 <= filterValue.INTEGER64;
    if (type == INTEGER32)
        return notificationValue.INTEGER32 <= filterValue.INTEGER32;
    if (type == DOUBLE)
        return notificationValue.DOUBLE <= filterValue.DOUBLE;
    if (type == TEXT)
        return false;
}