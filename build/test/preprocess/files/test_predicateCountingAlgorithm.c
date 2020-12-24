#include "build/temp/_test_predicateCountingAlgorithm.c"
#include "src/utility/../core/dataModel/dataModel.h"
#include "src/utility/../core/filterModel/filterModel.h"
#include "src/core/dataModel/../../core/matchingAlgorithms/predicateCountingAlgorithm.h"
#include "/home/michael/.rbenv/versions/2.7.2/lib/ruby/gems/2.7.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"




NameList *headNameElement;

OperatorList *firstOperatorElement;

ValueList *firstValueElement;

Data data1, data2;



void setUp(void)

{

    data1.INTEGER32 = 30;

    data2.DOUBLE = 16.0;



    headNameElement = 

                     ((void *)0)

                         ;



    NameList *NameElement1 = createNameListElement("bazz");

    NameList *NameElement2 = createNameListElement("fuzz");

    NameList *NameElement3 = createNameListElement("hello");

    NameList *NameElement4 = createNameListElement("world");



    do { __typeof(headNameElement) _tmp; (NameElement1)->next=

   ((void *)0)

   ; if (headNameElement) { _tmp = (headNameElement); while (_tmp->next) { _tmp = _tmp->next; } _tmp->next=(NameElement1); } else { (headNameElement)=(NameElement1); } } while (0);

    do { __typeof(headNameElement) _tmp; (NameElement2)->next=

   ((void *)0)

   ; if (headNameElement) { _tmp = (headNameElement); while (_tmp->next) { _tmp = _tmp->next; } _tmp->next=(NameElement2); } else { (headNameElement)=(NameElement2); } } while (0);

    do { __typeof(headNameElement) _tmp; (NameElement3)->next=

   ((void *)0)

   ; if (headNameElement) { _tmp = (headNameElement); while (_tmp->next) { _tmp = _tmp->next; } _tmp->next=(NameElement3); } else { (headNameElement)=(NameElement3); } } while (0);

    do { __typeof(headNameElement) _tmp; (NameElement4)->next=

   ((void *)0)

   ; if (headNameElement) { _tmp = (headNameElement); while (_tmp->next) { _tmp = _tmp->next; } _tmp->next=(NameElement4); } else { (headNameElement)=(NameElement4); } } while (0);



    OperatorList *OperatorElement1 = createOperatorListElement(GREATER_THAN);

    OperatorList *OperatorElement2 = createOperatorListElement(EQUALS);

    OperatorList *OperatorElement3 = createOperatorListElement(LESSER_THAN);



    NameElement1->operatorListHead = 

                                    ((void *)0)

                                        ;

    do { __typeof(NameElement1->operatorListHead) _tmp; (OperatorElement1)->next=

   ((void *)0)

   ; if (NameElement1->operatorListHead) { _tmp = (NameElement1->operatorListHead); while (_tmp->next) { _tmp = _tmp->next; } _tmp->next=(OperatorElement1); } else { (NameElement1->operatorListHead)=(OperatorElement1); } } while (0);

    do { __typeof(NameElement1->operatorListHead) _tmp; (OperatorElement2)->next=

   ((void *)0)

   ; if (NameElement1->operatorListHead) { _tmp = (NameElement1->operatorListHead); while (_tmp->next) { _tmp = _tmp->next; } _tmp->next=(OperatorElement2); } else { (NameElement1->operatorListHead)=(OperatorElement2); } } while (0);

    do { __typeof(NameElement1->operatorListHead) _tmp; (OperatorElement3)->next=

   ((void *)0)

   ; if (NameElement1->operatorListHead) { _tmp = (NameElement1->operatorListHead); while (_tmp->next) { _tmp = _tmp->next; } _tmp->next=(OperatorElement3); } else { (NameElement1->operatorListHead)=(OperatorElement3); } } while (0);

    firstOperatorElement = NameElement1->operatorListHead;



    ValueList *ValueElement1 = createValueListElement(data1, INTEGER32);

    ValueList *ValueElement2 = createValueListElement(data2, DOUBLE);



    ValueList *ValueElement3 = createValueListElement(data1, INTEGER32);

    ValueList *ValueElement4 = createValueListElement(data2, DOUBLE);



    OperatorElement1->valueListHead = 

                                     ((void *)0)

                                         ;

    do { __typeof(OperatorElement1->valueListHead) _tmp; (ValueElement1)->next=

   ((void *)0)

   ; if (OperatorElement1->valueListHead) { _tmp = (OperatorElement1->valueListHead); while (_tmp->next) { _tmp = _tmp->next; } _tmp->next=(ValueElement1); } else { (OperatorElement1->valueListHead)=(ValueElement1); } } while (0);

    do { __typeof(OperatorElement1->valueListHead) _tmp; (ValueElement2)->next=

   ((void *)0)

   ; if (OperatorElement1->valueListHead) { _tmp = (OperatorElement1->valueListHead); while (_tmp->next) { _tmp = _tmp->next; } _tmp->next=(ValueElement2); } else { (OperatorElement1->valueListHead)=(ValueElement2); } } while (0);



    OperatorElement2->valueListHead = 

                                     ((void *)0)

                                         ;

    do { __typeof(OperatorElement2->valueListHead) _tmp; (ValueElement3)->next=

   ((void *)0)

   ; if (OperatorElement2->valueListHead) { _tmp = (OperatorElement2->valueListHead); while (_tmp->next) { _tmp = _tmp->next; } _tmp->next=(ValueElement3); } else { (OperatorElement2->valueListHead)=(ValueElement3); } } while (0);

    do { __typeof(OperatorElement2->valueListHead) _tmp; (ValueElement4)->next=

   ((void *)0)

   ; if (OperatorElement2->valueListHead) { _tmp = (OperatorElement2->valueListHead); while (_tmp->next) { _tmp = _tmp->next; } _tmp->next=(ValueElement4); } else { (OperatorElement2->valueListHead)=(ValueElement4); } } while (0);



    firstValueElement = firstOperatorElement->valueListHead;

}



void tearDown(void)

{

}



void test_doesValueReferenceExist(void)

{

    do {if ((((doesValueReferenceExist(data1, firstValueElement, INTEGER32))) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(62))));}} while(0);

}



void test_getReferenceForPredicate(void)

{



    Filter *testFilter = malloc(sizeof(Filter));

    testFilter->attribute.data.DOUBLE = 16.0;

    testFilter->attribute.type = DOUBLE;

    strcpy(testFilter->attribute.Name, "bazz");

    testFilter->Operator = GREATER_THAN;



    ValueList *test_predicate = getReferenceForPredicate(testFilter, headNameElement);



    UnityAssertEqualNumber((UNITY_INT64)((test_predicate)), (UNITY_INT64)((firstValueElement->next)), (

   ((void *)0)

   ), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_HEX64);

}



void test_insertPredicate(void)

{

    Filter *testFilter = malloc(sizeof(Filter));

    testFilter->attribute.data.DOUBLE = 42.0;

    testFilter->attribute.type = DOUBLE;

    strcpy(testFilter->attribute.Name, "hello");

    testFilter->Operator = GREATER_THAN;



    insertPredicate(testFilter, headNameElement);

    do {if ((((getReferenceForPredicate(testFilter, headNameElement))) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(88))));}} while(0);

}



void test_lookForPredicate(void)

{

    Filter *testFilter = malloc(sizeof(Filter));

    testFilter->attribute.data.INTEGER64 = 53;

    testFilter->attribute.type = INTEGER64;

    strcpy(testFilter->attribute.Name, "keks");

    testFilter->Operator = LESSER_THAN_EQUAL;



    ValueList *testValue = lookForPredicate(testFilter, headNameElement);

    UnityAssertEqualNumber((UNITY_INT)((testValue->value.INTEGER64)), (UNITY_INT)((53)), (

   ((void *)0)

   ), (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)((headNameElement->next->next->next->next->Name)), (const char*)(("keks")), (

   ((void *)0)

   ), (UNITY_UINT)(101));

    UnityAssertEqualNumber((UNITY_INT)((headNameElement->next->next->next->next->operatorListHead->operator)), (UNITY_INT)((LESSER_THAN_EQUAL)), (

   ((void *)0)

   ), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_INT);

}



void test_matchingOfEqual(void)

{



    DataModel *notification = dataModel_create();

    dataModel_addAttributeDOUBLE(notification, "bazz", 16.0);



    startMatching(notification, headNameElement);

    do {if ((headNameElement->operatorListHead->next->valueListHead->next->isMatching)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(112)));}} while(0);

}



void test_matchingOfGreaterThan(void)

{

    DataModel *notification = dataModel_create();

    dataModel_addAttributeDOUBLE(notification, "bazz", 42.0);



    startMatching(notification, headNameElement);

    do {if ((headNameElement->operatorListHead->valueListHead->next->isMatching)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(121)));}} while(0);

}
