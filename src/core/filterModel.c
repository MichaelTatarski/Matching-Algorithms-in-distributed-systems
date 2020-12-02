#include <stdlib.h>

#include "filterModel.h"
#include "../utility/filterList.h"

FilterListNode *filterListHead = NULL;

Filter *make_filter()
{
    Filter *filter = malloc(sizeof(Filter));
    filter->head = NULL;
    return filter;
}

SubFilter *createSubFilter(Key key, ConstraintOperator constraintOperator, int constraintValue)
{
    SubFilter *subFilter = malloc(sizeof(SubFilter));
    subFilter->key = key;
    subFilter->constraintOperator = constraintOperator;
    subFilter->constraintValue = constraintValue;
    subFilter->next = NULL;
    return subFilter;
}

Filter *filter_Create()
{
    Filter *newFilter = make_filter();
    filterList_add(*newFilter, filterListHead);
    return newFilter;
}

void filter_AddConstraintToFilter(Filter *filter, Key key, ConstraintOperator constraintOperator, int constraintValue)
{
    SubFilter *current = NULL;
    if (filter->head == NULL)
    {
        filter->head = createSubFilter(key, constraintOperator, constraintValue);
    }
    else
    {
        current = filter->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = createSubFilter(key, constraintOperator, constraintValue);
    }
}
