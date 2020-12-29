#ifndef FILTERLIST_H
#define FILTERLIST_H

#include <stdlib.h>
#include <stdbool.h>

#include "filterModel.h"

typedef struct FilterList
{
    Filter *FilterHead;
    struct FilterList *next;

} FilterList;

typedef struct BoolList
{
    bool Booleanvalue;
    struct BoolList *next;
} BoolList;

FilterList *filterList_create(Filter *filter);
void filterList_addFilter(FilterList *filterList, Filter *filter);
BoolList *isFilterListMatching(FilterList *filterList);

#endif // FILTERLIST_H
