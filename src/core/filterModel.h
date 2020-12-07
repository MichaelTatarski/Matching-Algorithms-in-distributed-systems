#ifndef FILTERMODEL_H
#define FILTERMODEL_H

#include <stdlib.h>
#include <string.h>

#include "../utility/dataType.h"
#include "../utility/logicalExpressions.h"
#include "../utility/utlist.h"

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

Filter *Filter_create(void);
void Filter_addSubFilterINT64(Filter *filter, char name[32], Operator constraintOperator, int64_t constraintValue);
void Filter_addSubFilterINT32(Filter *filter, char name[32], Operator constraintOperator, int32_t constraintValue);
void Filter_addSubFilterDOUBLE(Filter *filter, char name[32], Operator constraintOperator, double constraintValue);
void Filter_addSubFilterTEXT32(Filter *filter, char name[32], Operator constraintOperator, char constraintValue[32]);

FilterList *FilterList_create(void);
void FilterList_addFilter(FilterList *filterList, Filter *filter);

#endif // FILTERMODEL_H
