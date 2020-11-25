#ifndef FILTERMODEL_H
#define FILTERMODEL_H

#include "keys.h"
#include "../utility/logicOperators.h"

typedef struct
{
    Key key;
    ConstraintOperator constraintOperator;
    int constrainValue;

} KeyConstraint;

typedef struct
{
    KeyConstraint *keyConstraint;
    BooleanOperator BooleanOperator;
    KeyConstraint *next;

} Filter;

Filter *filter_Create(Key key, ConstraintOperator constrainOperator, int constrainValue);

Filter *filter_AddAdditionalConstraintToFilter(Filter filter, BooleanOperator booleanOperator, Key key, ConstraintOperator constrainOperator, int constrainValue);

#endif // FILTERMODEL_H
