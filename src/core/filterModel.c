#include "filterModel.h"

Filter *createSubFilter(char name[TEXT32], Operator constraintOperator)
{
    Filter *newSubFilter = malloc(sizeof(Filter));
    strcpy(newSubFilter->name, name);
    newSubFilter->Operator = constraintOperator;
    return newSubFilter;
}

Filter *filter_create(void)
{
    Filter *newFilter = malloc(sizeof(Filter));
    newFilter = NULL;
    return newFilter;
}

void filter_addSubFilterINT64(Filter *filter, char name[TEXT32], Operator constraintOperator, int64_t constraintValue)
{
    Filter *newSubFilter = createSubFilter(name, constraintOperator);
    newSubFilter->constraintValue.INTEGER64 = constraintValue;
    LL_APPEND(filter, newSubFilter);
}

void filter_addSubFilterINT32(Filter *filter, char name[TEXT32], Operator constraintOperator, int32_t constraintValue)
{
    Filter *newSubFilter = createSubFilter(name, constraintOperator);
    newSubFilter->constraintValue.INTEGER32 = constraintValue;
    LL_APPEND(filter, newSubFilter);
}

void filter_addSubFilterDOUBLE(Filter *filter, char name[TEXT32], Operator constraintOperator, double constraintValue)
{
    Filter *newSubFilter = createSubFilter(name, constraintOperator);
    newSubFilter->constraintValue.DOUBLE = constraintValue;
    LL_APPEND(filter, newSubFilter);
}

void filter_addSubFilterTEXT32(Filter *filter, char name[TEXT32], Operator constraintOperator, char constraintValue[TEXT32])
{
    Filter *newSubFilter = createSubFilter(name, constraintOperator);
    strcpy(newSubFilter->constraintValue.TEXT, constraintValue);
    LL_APPEND(filter, newSubFilter);
}

FilterList *filterList_create(void)
{
    FilterList *newFilterList = malloc(sizeof(FilterList));
    newFilterList = NULL;
    return newFilterList;
}

void filterList_addFilter(FilterList *filterList, Filter *filter)
{
    FilterList *newFilterListNode = malloc(sizeof(FilterList));
    newFilterListNode->FilterHead = filter;
    LL_APPEND(filterList, newFilterListNode);
}