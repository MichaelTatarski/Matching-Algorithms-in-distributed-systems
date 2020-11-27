#ifndef LOGIC_EXPRESSIONS_H
#define LOGIC_EXPRESSIONS_H

typedef enum
{
    AND,
    OR,
    FIRST_EXPRESSION

} BooleanOperator;

typedef enum
{
    GREATER_THAN,
    GREATER_EQUAL,
    SMALLER_THAN,
    SMALLER_EQUAL,
    EQUALS

} ConstraintOperator;

#endif // LOGIC_EXPRESSIONS_H