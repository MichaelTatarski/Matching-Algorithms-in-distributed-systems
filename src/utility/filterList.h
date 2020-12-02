#ifndef FILTER_LIST_H
#define FILTER_LIST_H

#include "../core/filterModel.h"

typedef struct FilterListNode
{
    Filter *filter;
    struct FilterListNode *next;

} FilterListNode;

void filterList_add(Filter filter, FilterListNode *filterList);
void filterList_delete(Filter filter, FilterListNode *filterList);

#endif // FILTER_LIST_H
