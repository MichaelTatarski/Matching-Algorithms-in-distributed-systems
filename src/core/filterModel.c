#include <stdlib.h>

#include "filterModel.h"
#include "../utility/filterList.h"

Node *filterListHead = NULL;

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

Filter *filter_Create()
{
    Filter *newFilter = make_filter();
    filterList_add(*newFilter, filterListHead);
    return newFilter;
}

void filter_AddConstraintToFilter(Filter *filter, Key key, ConstraintOperator constraintOperator, int constraintValue, BooleanOperator booleanOperator)
{
    KeyConstraint *current = NULL;
    if (filter->head == NULL)
    {
        filter->head = createHeadKeyConstrait(key, constraintOperator, constraintValue);
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
