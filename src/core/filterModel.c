#include <stdlib.h>
#include "filterModel.h"
#include "../utility/filterList.h"
#include <stdbool.h>

FilterList *filterList;

bool isFilterListcreated()
{
    return filterList == NULL ? false : true;
}

Filter *make_filter()
{
    Filter *filter = malloc(sizeof(Filter));
    filter->head = NULL;
    return filter;
}

KeyConstraint *createHeadKeyConstrait(Key key, ConstraintOperator constraintOperator, int constraintValue)
{
    KeyConstraint *keyConstraint = malloc(sizeof(KeyConstraint));
    keyConstraint->key = key;
    keyConstraint->constraintOperator = constraintOperator;
    keyConstraint->constraintValue = constraintValue;
    keyConstraint->next = NULL;
    keyConstraint->booleanOperator = FIRST_EXPRESSION;
    return keyConstraint;
}

KeyConstraint *createKeyConstraint(Key key, ConstraintOperator constraintOperator, int constraintValue, BooleanOperator booleanOperator)
{
    KeyConstraint *keyConstraint = malloc(sizeof(KeyConstraint));
    keyConstraint->key = key;
    keyConstraint->constraintOperator = constraintOperator;
    keyConstraint->constraintValue = constraintValue;
    keyConstraint->next = NULL;
    keyConstraint->booleanOperator = booleanOperator;
    return keyConstraint;
}

Filter *filter_Create(Key key, ConstraintOperator constraintOperator, int constraintValue)
{
    if (isFilterListcreated == false)
    {
        FilterList *filterList = make_filterList();
    }

    Filter *newFilter = make_filter();
    KeyConstraint *headKeyConstraint = createHeadKeyConstrait(key, constraintOperator, constraintValue);
    filter_add(*newFilter, filterList);
}

void filter_AddConstraintToFilter(Filter *filter, Key key, ConstraintOperator constraintOperator, int constraintValue, BooleanOperator booleanOperator)
{
    KeyConstraint *current = NULL;
    if (filter->head == NULL)
    {
        filter->head = createKeyConstraint(key, constraintOperator, constraintValue, booleanOperator);
    }
    else
    {
        current = filter->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = createKeyConstraint(key, constraintOperator, constraintValue, booleanOperator);
    }
}
