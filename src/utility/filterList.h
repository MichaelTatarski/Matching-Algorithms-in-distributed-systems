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

FilterList *make_filterList();
void filter_add(Filter filter, FilterList *filterList);
void filter_delete(Filter filter, FilterList *filterList);

#endif // FILTER_LIST_H
