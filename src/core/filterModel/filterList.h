#ifndef FILTERLIST_H
#define FILTERLIST_H

#include <stdlib.h>

#include "filterModel.h"

typedef struct FilterList FilterList;

FilterList *filterList_create(void);
void filterList_addFilter(FilterList *filterList, Filter *filter);

#endif // FILTERLIST_H
