#ifndef FILTERMODEL_H
#define FILTERMODEL_H

#include <stdlib.h>
#include <string.h>

#include "../utility/dataType.h"
#include "../utility/logicalExpressions.h"
#include "../lib/utlist.h"

typedef struct Filter
{
    char name[32];
    Operator Operator;
    Data constraintValue;
    struct Filter *next;

} Filter;

typedef struct FilterList
{
    Filter *FilterHead;
    struct FilterList *next;

} FilterList;

Filter *filter_create(void);
void filter_addSubFilterINT64(Filter *filter, char name[TEXT32], Operator constraintOperator, int64_t constraintValue);
void filter_addSubFilterINT32(Filter *filter, char name[TEXT32], Operator constraintOperator, int32_t constraintValue);
void filter_addSubFilterDOUBLE(Filter *filter, char name[TEXT32], Operator constraintOperator, double constraintValue);
void filter_addSubFilterTEXT32(Filter *filter, char name[TEXT32], Operator constraintOperator, char constraintValue[32]);

FilterList *filterList_create(void);
void filterList_addFilter(FilterList *filterList, Filter *filter);

#endif // FILTERMODEL_H
