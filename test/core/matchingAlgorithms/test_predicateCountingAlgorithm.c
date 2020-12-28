#include "unity.h"

#include "../../core/matchingAlgorithms/predicateCountingAlgorithm.h"
#include "../core/filterModel/filterModel.h"
#include "../core/dataModel/dataModel.h"
#include "../../core/filterModel/filterList.h"

NameList *headNameElement;
OperatorList *firstOperatorElement;
ValueList *firstValueElement;
Data data1, data2;
NameList *nameList = NULL;
FilterList *subscribtion;
DataModel *notification;

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
    /*----------------------------------------------------------------------------------------------------------------*/

    Filter *testFilter1 = filter_createINT64("temperatur", GREATER_THAN, 10);
    filter_addSubFilterINT64(testFilter1, "fehler", LESSER_THAN, 5);

    Filter *testFilter2 = filter_createINT64("fehler", EQUALS, 1);
    filter_addSubFilterINT64(testFilter2, "temperatur", LESSER_THAN, 100);

    Filter *testFilter3 = filter_createINT64("temperatur", GREATER_THAN, 0);
    filter_addSubFilterINT64(testFilter3, "fehler", LESSER_THAN, 30);

    subscribtion = filterList_create(testFilter1);
    filterList_addFilter(subscribtion, testFilter2);
    filterList_addFilter(subscribtion, testFilter3);

    notification = dataModel_create();
    dataModel_addAttributeINT64(notification, "temperatur", 5);
    dataModel_addAttributeINT64(notification, "fehler", 1);
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
    Filter *testFilter = filter_createDOUBLE("bazz", GREATER_THAN, 16.0);
    ValueList *test_predicate = getReferenceForPredicate(testFilter, headNameElement);

    TEST_ASSERT_EQUAL_PTR(firstValueElement->next, test_predicate);
}

void test_insertPredicate(void)
{
    Filter *testFilter = filter_createDOUBLE("hello", GREATER_THAN, 42.0);

    insertPredicate(testFilter, headNameElement);
    TEST_ASSERT_NOT_NULL(getReferenceForPredicate(testFilter, headNameElement));
}

void test_lookForPredicate(void)
{
    Filter *testFilter = filter_createINT64("keks", LESSER_THAN_EQUAL, 53);

    ValueList *testValue = lookForPredicate(testFilter, headNameElement);
    TEST_ASSERT_EQUAL(testValue->value.INTEGER64, 53);
    TEST_ASSERT_EQUAL_STRING(headNameElement->next->next->next->next->Name, "keks");
    TEST_ASSERT_EQUAL_INT(headNameElement->next->next->next->next->operatorListHead->operator, LESSER_THAN_EQUAL);
}

void test_matchingOfEqual(void)
{
    DataModel *notification = dataModel_create();
    dataModel_addAttributeDOUBLE(notification, "bazz", 16.0);

    startMatching(notification->DataModelHead, headNameElement);
    TEST_ASSERT_TRUE(headNameElement->operatorListHead->next->valueListHead->next->isMatching);
}

void test_matchingOfGreaterThan(void)
{
    DataModel *notification = dataModel_create();
    dataModel_addAttributeDOUBLE(notification, "bazz", 42.0);

    startMatching(notification->DataModelHead, headNameElement);
    TEST_ASSERT_TRUE(headNameElement->operatorListHead->valueListHead->next->isMatching);
}

void test_setUpPredicateCounting(void)
{
    Data data;
    data.INTEGER64 = 30;
    NameList *structure = setUpPredicateCounting(subscribtion);

    TEST_ASSERT_NOT_NULL(doesNameReferenceExist("temperatur", structure));
    TEST_ASSERT_NULL(doesNameReferenceExist("hello", structure));
    TEST_ASSERT_NOT_NULL(doesValueReferenceExist(data, structure->next->operatorListHead->valueListHead->next, INTEGER64));
}

void test_predicateCounting(void)
{
    nameList = setUpPredicateCounting(subscribtion);
    BoolList *machingSubscribtions = predicateCounting(subscribtion, nameList, notification);
    TEST_ASSERT_TRUE(machingSubscribtions->next->Booleanvalue);
}
