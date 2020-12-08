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