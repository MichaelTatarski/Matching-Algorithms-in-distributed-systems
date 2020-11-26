#ifndef FILTER_LIST_H
#define FILTER_LIST_H

#include "../core/filterModel.h"

typedef struct Node
{
    Filter *filter;
    struct Node *next;

} Node;

void filterList_add(Filter filter, Node *filterList);
void filterList_delete(Filter filter, Node *filterList);

#endif // FILTER_LIST_H
