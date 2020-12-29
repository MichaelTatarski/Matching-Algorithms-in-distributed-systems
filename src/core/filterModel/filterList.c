// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "filterList.h"

FilterList *filterList_create(Filter *filter)
{
    FilterList *newFilterList = malloc(sizeof(FilterList));
    newFilterList->FilterHead = filter;
    return newFilterList;
}

void filterList_addFilter(FilterList *filterList, Filter *filter)
{
    FilterList *newFilterListNode = malloc(sizeof(FilterList));
    newFilterListNode->FilterHead = filter;
    LL_APPEND(filterList, newFilterListNode);
}

BoolList *isFilterListMatching(FilterList *filterList)
{
    BoolList *boolListHeader = NULL;
    FilterList *currentFilterList = filterList;
    while (currentFilterList != NULL)
    {
        Filter *tempFilter = currentFilterList->FilterHead;
        BoolList *newBoolNode = malloc(sizeof(BoolList));
        newBoolNode->Booleanvalue = isFilterMatching(tempFilter);
        currentFilterList = currentFilterList->next;
        LL_APPEND(boolListHeader, newBoolNode);
    }
    return boolListHeader;
}