#ifndef FILTERMODEL_H
#define FILTERMODEL_H

#include "keys.h"
#include "../utility/logicExpressions.h"

typedef struct FilterNode
{
    Key key;
    ConstraintOperator constraintOperator;
    int constraintValue;
    BooleanOperator booleanOperator;
    struct FilterNode *next;

} FilterNode;

typedef struct
{
    FilterNode *head;

} Filter;

void *filter_Create(Key key, ConstraintOperator constrainOperator, int constrainValue, BooleanOperator booleanOperator);

void *filter_AddConstraintToFilter(FilterNode filterNode, BooleanOperator booleanOperator, Key key, ConstraintOperator constraintOperator, int constrainValue);

#endif // FILTERMODEL_H
