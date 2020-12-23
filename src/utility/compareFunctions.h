#ifndef COMPAREFUNCTIONS_H
#define COMPAREFUNCTIONS_H

#include <stdbool.h>
#include "dataType.h"

bool isGreaterThan(DataType type, Data filterValue, Data notificationValue);
bool isGreaterThanEqual(DataType type, Data filterValue, Data notificationValue);
bool isLesserThan(DataType type, Data filterValue, Data notificationValue);
bool isLesserThanEqual(DataType type, Data filterValue, Data notificationValue);

#endif // COMPAREFUNCTIONS_H
