#include <stdlib.h>
#include "filterModel.h"

KeyConstraint *keyConstrain_Create(Key key, ConstraintOperator constrainOperator, int constrainValue)
{
    KeyConstraint *newKeyConstraint = malloc(sizeof(KeyConstraint));
    newKeyConstraint->key = key;
    newKeyConstraint->constraintOperator = constrainOperator;
    newKeyConstraint->constrainValue = constrainValue;
    return &newKeyConstraint;
}

Filter *filter_Create(Key key, ConstraintOperator constraintOperator, int constrainValue)
{
    KeyConstraint *newKeyConstraint = keyConstrain_Create(key, constraintOperator, constrainValue);
    Filter *newFilter = malloc(sizeof(Filter));
    newFilter->keyConstraint = newKeyConstraint;
    newFilter->BooleanOperator = NULL;
    newFilter->next = NULL;
}

Filter *filter_AddAdditionalConstrainToFilter(Filter filter, BooleanOperator booleanOperator, Key key, ConstraintOperator constrainOperator, int constrainValue)
{
}