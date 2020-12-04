#ifndef FILTERMODEL_H
#define FILTERMODEL_H

#include "../utility/dataType.h"
#include "../utility/logicalExpressions.h"
#include "../utility/utlist.h"

typedef struct SubFilter
{
    char name[32];
    ConstraintOperator constraintOperator;
    Data constrainValue;
    struct SubFilter *next;

} SubFilter;

typedef struct Filter
{
    SubFilter *SubFilterHead;
    struct Filter *next

} Filter;

Filter *CreateFilter();
void AddSubFilterINT64(Filter *filter, char name[32], ConstraintOperator constraintOperator, int64_t constraintValue);
void AddSubFilterINT32(Filter *filter, char name[32], ConstraintOperator constraintOperator, int32_t constraintValue);
void AddSubFilterDOUBLE(Filter *filter, char name[32], ConstraintOperator constraintOperator, double constraintValue);
void AddSubFilterTEXT32(Filter *filter, char name[32], ConstraintOperator constraintOperator, char constraintValue[32]);

#endif // FILTERMODEL_H
