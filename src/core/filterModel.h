#ifndef FILTERMODEL_H
#define FILTERMODEL_H

#include "keys.h"
#include "../utility/logicalExpressions.h"

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
 * Create an empty filter and adds it to filterlist.
 */
Filter *filter_Create();

/**
 * Adds a subfilter(aka keyconstraint) to an existing filter.
 *
 * @param filter filter in which a keyconstraint should be added to.
 * @param key key that should be filtered.
 * @param constraintOperator determines how to filter the key.
 * @param constraintValue corresponding value for the filter.
 * @param booleanoperator determines if the created keyconstraint should be linked as a conjunction or disjunction to the filter.
 */
void filter_AddConstraintToFilter(Filter *filter, Key key, ConstraintOperator constraintOperator, int constraintValue, BooleanOperator booleanOperator);

#endif // FILTERMODEL_H
