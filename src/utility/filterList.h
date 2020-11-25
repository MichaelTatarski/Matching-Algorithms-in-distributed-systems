#ifndef FILTER_LIST_H
#define FILTER_LIST_H

#include "../core/filterModel.h"

typedef struct
{
    Filter *filter;
    Filter *next;

} Node;

typedef struct
{
    Node *head;

} FilterList;

void List_add(Filter filter, FilterList *filterList);
void List_delete(Filter filter, FilterList *filterList);

#endif // FILTER_LIST_H
