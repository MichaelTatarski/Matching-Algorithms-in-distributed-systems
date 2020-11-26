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

typedef struct Filter
{
    KeyConstraint *head;

} Filter;

Filter *filter_Create();

void filter_AddConstraintToFilter(Filter *filter, Key key, ConstraintOperator constraintOperator, int constraintValue, BooleanOperator booleanOperator);

#endif // FILTERMODEL_H
