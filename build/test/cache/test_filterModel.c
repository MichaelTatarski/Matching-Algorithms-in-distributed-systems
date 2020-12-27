#include "build/temp/_test_filterModel.c"
#include "src/core/dataModel/../../core/filterModel/filterList.h"
#include "src/core/dataModel/../../core/matchingAlgorithms/predicateCountingAlgorithm.h"
#include "src/core/filterModel/filterModel.h"
#include "/home/michael/.rbenv/versions/2.7.2/lib/ruby/gems/2.7.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


Filter *testFilter;



void setUp(void)

{

    testFilter = filter_create();

}



void tearDown(void)

{

}



void test_isFilterMatching(void)

{

    filter_addSubFilterINT64(testFilter, "testString", GREATER_THAN, 2020);

    filter_addSubFilterINT64(testFilter, "2ndtestName", LESSER_THAN, 30);







    Data data1, data2;

    data1.INTEGER64 = 2020;

    data2.INTEGER64 = 30;



    ValueList *valueListHead = 

                              ((void *)0)

                                  ;

    ValueList *ValueElement1 = createValueListElement(data1, INTEGER64);

    ValueList *ValueElement2 = createValueListElement(data2, INTEGER64);

    ValueElement1->isMatching = 

                               1

                                   ;

    ValueElement2->isMatching = 

                               0

                                    ;

    do { __typeof(valueListHead) _tmp; (ValueElement1)->next=

   ((void *)0)

   ; if (valueListHead) { _tmp = (valueListHead); while (_tmp->next) { _tmp = _tmp->next; } _tmp->next=(ValueElement1); } else { (valueListHead)=(ValueElement1); } } while (0);

    do { __typeof(valueListHead) _tmp; (ValueElement2)->next=

   ((void *)0)

   ; if (valueListHead) { _tmp = (valueListHead); while (_tmp->next) { _tmp = _tmp->next; } _tmp->next=(ValueElement2); } else { (valueListHead)=(ValueElement2); } } while (0);



    testFilter->predicateCountingReference = ValueElement1;

    testFilter->next->predicateCountingReference = ValueElement2;



    do {if (!(isFilterMatching(testFilter))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(39)));}} while(0);

}
