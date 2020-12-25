// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "filterList.h"

typedef struct FilterList
{
    Filter *FilterHead;
    struct FilterList *next;

} FilterList;

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