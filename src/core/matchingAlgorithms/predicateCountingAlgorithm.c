#include "predicateCountingAlgorithm.h"

int nameCompare(NameList *a, NameList *b)
{
    return strcmp(a->Name, b->Name);
}

NameList *doesNameReferenceExist(char name[TEXT32], NameList *nameList)
{
    NameList *elt = NULL;
    NameList *like;
    like = malloc(sizeof(NameList));
    strcpy(like->Name, name);
    LL_SEARCH(nameList, elt, like, nameCompare);
    return elt;
};

OperatorList *doesOperatorReferenceExist(Operator usedOperator, OperatorList *operatorList)
{
    OperatorList *elt = NULL;
    LL_SEARCH_SCALAR(operatorList, elt, operator, usedOperator);
    return elt;
};

ValueList *doesValueReferenceExist(Data usedValue, ValueList *valueList, DataType type)
{
    ValueList *elt = NULL;

    if (type == INTEGER64)
        LL_SEARCH_SCALAR(valueList, elt, value.INTEGER64, usedValue.INTEGER64);
    if (type == INTEGER32)
        LL_SEARCH_SCALAR(valueList, elt, value.INTEGER32, usedValue.INTEGER32);
    if (type == DOUBLE)
        LL_SEARCH_SCALAR(valueList, elt, value.DOUBLE, usedValue.DOUBLE);
    if (type == TEXT)
        LL_SEARCH_SCALAR(valueList, elt, value.TEXT, usedValue.TEXT);

    return elt;
};

NameList *createNameListElement(char name[TEXT32])
{
    NameList *newNameList = malloc(sizeof(NameList));
    strcpy(newNameList->Name, name);
    return newNameList;
}

OperatorList *createOperatorListElement(Operator usedOperator)
{
    OperatorList *newOperatorList = malloc(sizeof(OperatorList));
    newOperatorList->operator= usedOperator;
    return newOperatorList;
}

ValueList *createValueListElement(Data value, DataType type)
{
    ValueList *newValueList = malloc(sizeof(ValueList));
    newValueList->isMatching = false;
    if (type == INTEGER64)
        newValueList->value.INTEGER64 = value.INTEGER64;
    if (type == INTEGER32)
        newValueList->value.INTEGER32 = value.INTEGER32;
    if (type == DOUBLE)
        newValueList->value.DOUBLE = value.DOUBLE;
    if (type == TEXT)
        strcpy(newValueList->value.TEXT, value.TEXT);

    return newValueList;
}

ValueList *getReferenceForPredicate(Filter *filter, NameList *nameList)
{
    NameList *nameExist;
    OperatorList *operatorExist;
    ValueList *valueExist;

    Operator *operator= &(filter->Operator);
    char *name = filter->attribute.Name;
    Data *value = malloc(sizeof(Data));

    if (filter->attribute.type == INTEGER64)
        value->INTEGER64 = filter->attribute.data.INTEGER64;
    if (filter->attribute.type == INTEGER32)
        value->INTEGER32 = filter->attribute.data.INTEGER32;
    if (filter->attribute.type == DOUBLE)
        value->DOUBLE = filter->attribute.data.DOUBLE;
    if (filter->attribute.type == TEXT)
        strcpy(value->TEXT, name);

    nameExist = doesNameReferenceExist(name, nameList);
    if (nameExist == NULL)
        return NULL;
    operatorExist = doesOperatorReferenceExist(*operator, nameExist->operatorListHead);
    if (operatorExist == NULL)
        return NULL;
    valueExist = doesValueReferenceExist(*value, operatorExist->valueListHead, filter->attribute.type);
    return valueExist;
}

ValueList *insertNameAndOperatorAndValue(char *name, Operator *operator, Data value, DataType * type, NameList * nameList)
{
    ValueList *newValueListNode;
    NameList *newNameListNode = createNameListElement(name);
    OperatorList *newOperatorListNode = createOperatorListElement(*operator);
    newValueListNode = createValueListElement(value, *type);
    newNameListNode->operatorListHead = NULL;
    newOperatorListNode->valueListHead = NULL;

    LL_APPEND(nameList, newNameListNode);
    LL_APPEND(newNameListNode->operatorListHead, newOperatorListNode);
    LL_APPEND(newOperatorListNode->valueListHead, newValueListNode);
    return newValueListNode;
}

ValueList *insertOperatorAndValue(NameList *nameExist, Operator *operator, Data value, DataType * type, NameList * nameList)
{
    ValueList *newValueListNode;

    OperatorList *newOperatorListNode = createOperatorListElement(*operator);
    newValueListNode = createValueListElement(value, *type);

    newOperatorListNode->valueListHead = NULL;

    LL_APPEND(nameExist->operatorListHead, newOperatorListNode);
    LL_APPEND(newOperatorListNode->valueListHead, newValueListNode);
    return newValueListNode;
}

ValueList *insertPredicate(Filter *filter, NameList *nameList)
{
    ValueList *newValueListNode;
    Operator *operator= &(filter->Operator);
    char *name = filter->attribute.Name;
    DataType *type = &(filter->attribute.type);
    Data value;

    NameList *nameExist;
    OperatorList *operatorExist;
    ValueList *valueExist;

    if (*type == INTEGER64)
        value.INTEGER64 = filter->attribute.data.INTEGER64;
    if (*type == INTEGER32)
        value.INTEGER32 = filter->attribute.data.INTEGER32;
    if (*type == DOUBLE)
        value.DOUBLE = filter->attribute.data.DOUBLE;
    if (*type == TEXT)
        strcpy(value.TEXT, name);

    nameExist = doesNameReferenceExist(name, nameList);
    if (!nameExist)
    {
        return insertNameAndOperatorAndValue(name, operator, value, type, nameList);
    }
    operatorExist = doesOperatorReferenceExist(*operator, nameExist->operatorListHead);

    if (!operatorExist)
    {
        return insertOperatorAndValue(nameExist, operator, value, type, nameList);
    }

    newValueListNode = createValueListElement(value, *type);
    LL_APPEND(operatorExist->valueListHead, newValueListNode);
    return NULL;

    /*
    nameExist = doesNameReferenceExist(name, nameList);

    if (nameExist)
    {
        operatorExist = doesOperatorReferenceExist(*operator, nameExist->operatorListHead);

        if (operatorExist)
        {
            newValueListNode = createValueListElement(value, *type);
            LL_APPEND(operatorExist->valueListHead, newValueListNode);
        }
        else
        {
            OperatorList *newOperatorListNode = createOperatorListElement(*operator);
            newValueListNode = createValueListElement(value, *type);

            newOperatorListNode->valueListHead = NULL;

            LL_APPEND(nameExist->operatorListHead, newOperatorListNode);
            LL_APPEND(newOperatorListNode->valueListHead, newValueListNode);
        }
    }
    else
    {
        NameList *newNameListNode = createNameListElement(name);
        OperatorList *newOperatorListNode = createOperatorListElement(*operator);
        newValueListNode = createValueListElement(value, *type);
        newNameListNode->operatorListHead = NULL;
        newOperatorListNode->valueListHead = NULL;

        LL_APPEND(nameList, newNameListNode);
        LL_APPEND(newNameListNode->operatorListHead, newOperatorListNode);
        LL_APPEND(newOperatorListNode->valueListHead, newValueListNode);
    }

    return newValueListNode;
    */
}

ValueList *lookForPredicate(Filter *filter, NameList *nameList)
{
    ValueList *predicateReference = getReferenceForPredicate(filter, nameList);
    bool doesPredicateAlreadyExist;
    predicateReference == NULL ? doesPredicateAlreadyExist = false : true;
    if (!doesPredicateAlreadyExist)
        predicateReference = insertPredicate(filter, nameList);
    return predicateReference;
}

void startMatching(DataModel *dataModel, NameList *nameList)
{
    // to be continued
}