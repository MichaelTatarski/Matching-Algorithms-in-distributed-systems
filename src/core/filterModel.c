#include "filterModel.h"

Filter *createSubFilter(char name[32], Operator constraintOperator)
{
    Filter *newSubFilter = malloc(sizeof(Filter));
    strcpy(newSubFilter->name, name);
    newSubFilter->Operator = constraintOperator;
    return newSubFilter;
}

Filter *Filter_create(void)
{
    Filter *newFilter = malloc(sizeof(Filter));
    newFilter = NULL;
    return newFilter;
}

void Filter_addSubFilterINT64(Filter *filter, char name[32], Operator constraintOperator, int64_t constraintValue)
{
    Filter *newSubFilter = createSubFilter(name, constraintOperator);
    newSubFilter->constrainValue.INTEGER64 = constraintValue;
    LL_APPEND(filter, newSubFilter);
}

void Filter_addSubFilterINT32(Filter *filter, char name[32], Operator constraintOperator, int32_t constraintValue)
{
    Filter *newSubFilter = createSubFilter(name, constraintOperator);
    newSubFilter->constrainValue.INTEGER32 = constraintValue;
    LL_APPEND(filter, newSubFilter);
}

void Filter_addSubFilterDOUBLE(Filter *filter, char name[32], Operator constraintOperator, double constraintValue)
{
    Filter *newSubFilter = createSubFilter(name, constraintOperator);
    newSubFilter->constrainValue.DOUBLE = constraintValue;
    LL_APPEND(filter, newSubFilter);
}

void Filter_addSubFilterTEXT32(Filter *filter, char name[32], Operator constraintOperator, char constraintValue[32])
{
    Filter *newSubFilter = createSubFilter(name, constraintOperator);
    strcpy(newSubFilter->constrainValue.TEXT, constraintValue);
    LL_APPEND(filter, newSubFilter);
}

FilterList *FilterList_create(void)
{
    FilterList *newFilterList = malloc(sizeof(FilterList));
    newFilterList = NULL;
    return newFilterList;
}

void FilterList_addFilter(FilterList *filterList, Filter *filter)
{
    FilterList *newFilterListNode = malloc(sizeof(FilterList));
    newFilterListNode->FilterHead = filter;
    LL_APPEND(filterList, newFilterListNode);
}