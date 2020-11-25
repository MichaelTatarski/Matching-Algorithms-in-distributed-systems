#include <stdlib.h>
#include "filterModel.h"
#include "../utility/filterList.h"

FilterList *filterList;

Filter *make_filter()
{
    Filter *filter = malloc(sizeof(Filter));
    filter->head = NULL;
    return filter;
}

void *filter_Create(Key key, ConstraintOperator constrainOperator, int constrainValue)
{
    if (filterList == NULL)
    {
        FilterList *filterList = make_filterList();
    }

    Filter *newFilter = make_filter();

    KeyConstraint *keyConstraint = malloc(sizeof(KeyConstraint));
    keyConstraint->key = key;
    keyConstraint->constraintOperator = constrainOperator;
    keyConstraint->constraintValue = constrainValue;
    keyConstraint->next = NULL;
    keyConstraint->booleanOperator = FIRST_EXPRESSION;
    filterNode_add(*keyConstraint, filterList);
}
