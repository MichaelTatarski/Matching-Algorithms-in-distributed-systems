#ifndef FILTERMODEL_H
#define FILTERMODEL_H

#include "keys.h"
#include "../utility/logicExpressions.h"

typedef struct KeyConstraint
{
    Key key;
    ConstraintOperator constraintOperator;
    int constraintValue;
    BooleanOperator booleanOperator;
    struct KeyConstraint *next;

} KeyConstraint;

typedef struct
{
    KeyConstraint *head;

} Filter;

Filter *filter_Create(Key key, ConstraintOperator constrainOperator, int constrainValue);

void filter_AddConstraintToFilter(KeyConstraint keyConstraint, BooleanOperator booleanOperator, Key key, ConstraintOperator constraintOperator, int constraintValue);

#endif // FILTERMODEL_H
