#ifndef FILTER_LIST_H
#define FILTER_LIST_H

#include "../core/filterModel.h"

typedef struct Node
{
    Filter *filter;
    struct Node *next;

} Node;

typedef struct FilterList
{
    Node *head;

} FilterList;

FilterList *make_filterList();
void filterList_add(Filter filter, FilterList *filterList);
void filterList_delete(Filter filter, FilterList *filterList);

#endif // FILTER_LIST_H
