// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "filterModel.h"

Filter *createSubFilter(char name[TEXT32], Operator constraintOperator)
{
    Filter *newSubFilter = malloc(sizeof(Filter));
    strcpy(newSubFilter->attribute.Name, name);
    newSubFilter->Operator = constraintOperator;
    return newSubFilter;
}

Filter *filter_createINT64(char name[TEXT32], Operator constraintOperator, int64_t constraintValue)
{
    Filter *newFilter = malloc(sizeof(Filter));
    strcpy(newFilter->attribute.Name, name);
    newFilter->Operator = constraintOperator;
    newFilter->attribute.data.INTEGER64 = constraintValue;
    return newFilter;
}

Filter *filter_createINT32(char name[TEXT32], Operator constraintOperator, int32_t constraintValue)
{
    Filter *newFilter = malloc(sizeof(Filter));
    strcpy(newFilter->attribute.Name, name);
    newFilter->Operator = constraintOperator;
    newFilter->attribute.data.INTEGER32 = constraintValue;
    return newFilter;
}

Filter *filter_createDOUBLE(char name[TEXT32], Operator constraintOperator, double constraintValue)
{
    Filter *newFilter = malloc(sizeof(Filter));
    strcpy(newFilter->attribute.Name, name);
    newFilter->Operator = constraintOperator;
    newFilter->attribute.data.DOUBLE = constraintValue;
    return newFilter;
}

Filter *filter_createTEXT(char name[TEXT32], Operator constraintOperator, char constraintValue[TEXT32])
{
    Filter *newFilter = malloc(sizeof(Filter));
    strcpy(newFilter->attribute.Name, name);
    newFilter->Operator = constraintOperator;
    strcpy(newFilter->attribute.data.TEXT, constraintValue);
    return newFilter;
}

void filter_addSubFilterINT64(Filter *filter, char name[TEXT32], Operator constraintOperator, int64_t constraintValue)
{
    Filter *newSubFilter = createSubFilter(name, constraintOperator);
    newSubFilter->attribute.data.INTEGER64 = constraintValue;
    LL_APPEND(filter, newSubFilter);
}

void filter_addSubFilterINT32(Filter *filter, char name[TEXT32], Operator constraintOperator, int32_t constraintValue)
{
    Filter *newSubFilter = createSubFilter(name, constraintOperator);
    newSubFilter->attribute.data.INTEGER32 = constraintValue;
    LL_APPEND(filter, newSubFilter);
}

void filter_addSubFilterDOUBLE(Filter *filter, char name[TEXT32], Operator constraintOperator, double constraintValue)
{
    Filter *newSubFilter = createSubFilter(name, constraintOperator);
    newSubFilter->attribute.data.DOUBLE = constraintValue;
    LL_APPEND(filter, newSubFilter);
}

void filter_addSubFilterTEXT32(Filter *filter, char name[TEXT32], Operator constraintOperator, char constraintValue[TEXT32])
{
    Filter *newSubFilter = createSubFilter(name, constraintOperator);
    strcpy(newSubFilter->attribute.data.TEXT, constraintValue);
    LL_APPEND(filter, newSubFilter);
}

bool isFilterMatching(Filter *filter)
{
    Filter *currentPredicate = filter->next;
    while (currentPredicate != NULL)
    {
        if (currentPredicate->predicateCountingReference->isMatching == false)
            return false;
        else
        {
            currentPredicate->predicateCountingReference->isMatching = false;
            currentPredicate = currentPredicate->next;
        }
    }
    return true;
}
