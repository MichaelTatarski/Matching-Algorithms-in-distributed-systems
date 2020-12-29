#ifndef PREDICATE_COUNTING_DATASTRUCTURE_H
#define PREDICATE_COUNTING_DATASTRUCTURE_H

#include <stdbool.h>

#include "../../utility/dataType.h"
#include "../../utility/logicalExpressions.h"

typedef struct ValueList
{
    Data value;
    bool isMatching;
    struct ValueList *next;
} ValueList;

typedef struct OperatorList
{
    Operator operator;
    struct OperatorList *next;
    ValueList *valueListHead;
} OperatorList;

typedef struct NameList
{
    char Name[TEXT32];
    struct NameList *next;
    OperatorList *operatorListHead;
} NameList;

#endif //PREDICATE_COUNTING_DATASTRUCTURE_H