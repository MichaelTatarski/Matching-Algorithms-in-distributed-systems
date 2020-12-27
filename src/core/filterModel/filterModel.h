#ifndef FILTERMODEL_H
#define FILTERMODEL_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../../utility/dataType.h"
#include "../../utility/logicalExpressions.h"
#include "../matchingAlgorithms/predicateCountingDataStructure.h"
#include "../../lib/utlist.h"
#include "../dataModel/dataModel.h"

typedef struct Filter
{
    Attribute attribute;
    Operator Operator;
    struct ValueList *predicateCountingReference;
    struct Filter *next;

} Filter;

Filter *createSubFilter(char name[TEXT32], Operator constraintOperator);

Filter *filter_create(void);
bool isFilterMatching(Filter *filter);
void filter_addSubFilterINT64(Filter *filter, char name[TEXT32], Operator constraintOperator, int64_t constraintValue);
void filter_addSubFilterINT32(Filter *filter, char name[TEXT32], Operator constraintOperator, int32_t constraintValue);
void filter_addSubFilterDOUBLE(Filter *filter, char name[TEXT32], Operator constraintOperator, double constraintValue);
void filter_addSubFilterTEXT32(Filter *filter, char name[TEXT32], Operator constraintOperator, char constraintValue[TEXT32]);

#endif // FILTERMODEL_H
