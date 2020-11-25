#include <stdlib.h>
#include "filterModel.h"
#include "../utility/filterList.h"

FilterList *filterList;

void *filter_Create(Key key, ConstraintOperator constrainOperator, int constrainValue, BooleanOperator booleanOperator)
{
    if (filterList == NULL)
    {
        FilterList *filterList = make_filterList();
    }

    KeyFilter *newKeyFilter = malloc(sizeof(KeyFilter));
    newKeyFilter->key = key;
    newKeyFilter->constraintOperator = constrainOperator;
    newKeyFilter->constraintValue = constrainValue;
    newKeyFilter->next = NULL;
    newKeyFilter->booleanOperator = booleanOperator;
    List_add(*newKeyFilter, filterList);
}
