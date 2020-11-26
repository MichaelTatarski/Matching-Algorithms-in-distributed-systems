#include <stdlib.h>
#include "filterModel.h"
#include "../utility/filterList.h"
#include <stdbool.h>

FilterList *filterList;

bool isFilterListcreated()
{
    return filterList = NULL ? false : true;
}

Filter *make_filter()
{
    Filter *filter = malloc(sizeof(Filter));
    filter->head = NULL;
    return filter;
}

KeyConstraint *createHeadKeyConstrait(Key key, ConstraintOperator constrainOperator, int constrainValue)
{
    KeyConstraint *keyConstraint = malloc(sizeof(KeyConstraint));
    keyConstraint->key = key;
    keyConstraint->constraintOperator = constrainOperator;
    keyConstraint->constraintValue = constrainValue;
    keyConstraint->next = NULL;
    keyConstraint->booleanOperator = FIRST_EXPRESSION;
    return keyConstraint;
}

Filter *filter_Create(Key key, ConstraintOperator constrainOperator, int constrainValue)
{
    if (isFilterListcreated == false)
    {
        FilterList *filterList = make_filterList();
    }

    Filter *newFilter = make_filter();
    KeyConstraint *headKeyConstraint = createHeadKeyConstrait(key, constrainOperator, constrainValue);
    filter_add(*newFilter, filterList);
}
