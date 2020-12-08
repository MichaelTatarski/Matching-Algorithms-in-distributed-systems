#ifndef FILTERMODEL_H
#define FILTERMODEL_H

#include <stdlib.h>
#include <string.h>

#include "../utility/dataType.h"
#include "../utility/logicalExpressions.h"
#include "../lib/utlist.h"

typedef struct Filter Filter;

Filter *filter_create(void);
void filter_addSubFilterINT64(Filter *filter, char name[TEXT32], Operator constraintOperator, int64_t constraintValue);
void filter_addSubFilterINT32(Filter *filter, char name[TEXT32], Operator constraintOperator, int32_t constraintValue);
void filter_addSubFilterDOUBLE(Filter *filter, char name[TEXT32], Operator constraintOperator, double constraintValue);
void filter_addSubFilterTEXT32(Filter *filter, char name[TEXT32], Operator constraintOperator, char constraintValue[32]);

#endif // FILTERMODEL_H
