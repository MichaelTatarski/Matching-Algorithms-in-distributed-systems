#include "unity.h"

#include "predicateCountingAlgorithm.h"
#include "../core/filterModel/filterModel.h"
#include "../core/dataModel/dataModel.h"

NameList *headNameElement;
OperatorList *firstOperatorElement;
ValueList *firstValueElement;
Data data1, data2;

void setUp(void)
{
    data1.INTEGER32 = 30;
    data2.DOUBLE = 16.0;

    headNameElement = NULL;

    NameList *NameElement1 = createNameListElement("bazz");
    NameList *NameElement2 = createNameListElement("fuzz");
    NameList *NameElement3 = createNameListElement("hello");
    NameList *NameElement4 = createNameListElement("world");

    LL_APPEND(headNameElement, NameElement1);
    LL_APPEND(headNameElement, NameElement2);
    LL_APPEND(headNameElement, NameElement3);
    LL_APPEND(headNameElement, NameElement4);

    OperatorList *OperatorElement1 = createOperatorListElement(GREATER_THAN);
    OperatorList *OperatorElement2 = createOperatorListElement(EQUALS);
    OperatorList *OperatorElement3 = createOperatorListElement(LESSER_THAN);

    NameElement1->operatorListHead = NULL;
    LL_APPEND(NameElement1->operatorListHead, OperatorElement1);
    LL_APPEND(NameElement1->operatorListHead, OperatorElement2);
    LL_APPEND(NameElement1->operatorListHead, OperatorElement3);
    firstOperatorElement = NameElement1->operatorListHead;

    ValueList *ValueElement1 = createValueListElement(data1, INTEGER32);
    ValueList *ValueElement2 = createValueListElement(data2, DOUBLE);

    ValueList *ValueElement3 = createValueListElement(data1, INTEGER32);
    ValueList *ValueElement4 = createValueListElement(data2, DOUBLE);

    OperatorElement1->valueListHead = NULL;
    LL_APPEND(OperatorElement1->valueListHead, ValueElement1);
    LL_APPEND(OperatorElement1->valueListHead, ValueElement2);

    OperatorElement2->valueListHead = NULL;
    LL_APPEND(OperatorElement2->valueListHead, ValueElement3);
    LL_APPEND(OperatorElement2->valueListHead, ValueElement4);

    firstValueElement = firstOperatorElement->valueListHead;
}

void tearDown(void)
{
}

void test_doesValueReferenceExist(void)
{
    TEST_ASSERT_NOT_NULL(doesValueReferenceExist(data1, firstValueElement, INTEGER32));
}

void test_getReferenceForPredicate(void)
{

    Filter *testFilter = malloc(sizeof(Filter));
    testFilter->attribute.data.DOUBLE = 16.0;
    testFilter->attribute.type = DOUBLE;
    strcpy(testFilter->attribute.Name, "bazz");
    testFilter->Operator = GREATER_THAN;

    ValueList *test_predicate = getReferenceForPredicate(testFilter, headNameElement);

    TEST_ASSERT_EQUAL_PTR(test_predicate, firstValueElement->next);
}

void test_insertPredicate(void)
{
    Filter *testFilter = malloc(sizeof(Filter));
    testFilter->attribute.data.DOUBLE = 42.0;
    testFilter->attribute.type = DOUBLE;
    strcpy(testFilter->attribute.Name, "hello");
    testFilter->Operator = GREATER_THAN;

    insertPredicate(testFilter, headNameElement);
    TEST_ASSERT_NOT_NULL(getReferenceForPredicate(testFilter, headNameElement));
}

void test_lookForPredicate(void)
{
    Filter *testFilter = malloc(sizeof(Filter));
    testFilter->attribute.data.INTEGER64 = 53;
    testFilter->attribute.type = INTEGER64;
    strcpy(testFilter->attribute.Name, "keks");
    testFilter->Operator = LESSER_THAN_EQUAL;

    ValueList *testValue = lookForPredicate(testFilter, headNameElement);
    TEST_ASSERT_EQUAL(testValue->value.INTEGER64, 53);
    TEST_ASSERT_EQUAL_STRING(headNameElement->next->next->next->next->Name, "keks");
    TEST_ASSERT_EQUAL_INT(headNameElement->next->next->next->next->operatorListHead->operator, LESSER_THAN_EQUAL);
}

void test_matchingOfEqual(void)
{

    DataModel *notification = dataModel_create();
    dataModel_addAttributeDOUBLE(notification, "bazz", 16.0);

    startMatching(notification, headNameElement);
    TEST_ASSERT_TRUE(headNameElement->operatorListHead->next->valueListHead->next->isMatching);
}

void test_matchingOfGreaterThan(void)
{
    DataModel *notification = dataModel_create();
    dataModel_addAttributeDOUBLE(notification, "bazz", 42.0);

    startMatching(notification, headNameElement);
    TEST_ASSERT_TRUE(headNameElement->operatorListHead->valueListHead->next->isMatching);
}