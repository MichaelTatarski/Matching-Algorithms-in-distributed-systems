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

/**
 * Creates an empty filter and add it to the tail of filterlist.
 */
Filter *filter_Create();

/**
 * Adds a subfilter(aka keyconstrain) to an existing filter.
 *
 * @param filter filter which should be extended
 * @param key key that should be constrained
 * @param constraintOperator determines how the key should be filtered.
 * @param constraintValue value which corresponds to the filter.
 * @param booleanOperator determines how to link keyconstraint to the existing filter (either as a conjunction or disjunction).
 */
void filter_AddConstraintToFilter(Filter *filter, Key key, ConstraintOperator constraintOperator, int constraintValue, BooleanOperator booleanOperator);

#endif // FILTERMODEL_H
