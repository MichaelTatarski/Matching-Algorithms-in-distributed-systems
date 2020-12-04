#include <stdlib.h>
#include "filterModel.h"

Filter *filterListHead = NULL;

Filter *make_newFilter()
{
    Filter *filter = malloc(sizeof(Filter));
    filter->SubFilterHead = NULL;
    return filter;
}

Filter *CreateFilter()
{
    Filter *newFilter = make_filter();
    LL_APPEND(filterListHead, newFilter);
    return newFilter;
}

SubFilter *createSubFilter(Operator constraintOperator, int constraintValue)
{
    SubFilter *subFilter = malloc(sizeof(SubFilter));
    subFilter->constraintOperator = constraintOperator;
    subFilter->constraintValue = constraintValue;
    subFilter->next = NULL;
    return subFilter;
}

void AddSubFilter(Filter *filter, Operator constraintOperator, int constraintValue)
{
    SubFilter *current = NULL;
    if (filter->head == NULL)
    {
        filter->head = createSubFilter(constraintOperator, constraintValue);
    }
    else
    {
        current = filter->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = createSubFilter(constraintOperator, constraintValue);
    }
}
