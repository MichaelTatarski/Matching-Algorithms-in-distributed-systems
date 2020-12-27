#include "unity.h"
#include "filterModel.h"
#include "../../core/matchingAlgorithms/predicateCountingAlgorithm.h"
#include "../../core/filterModel/filterList.h"

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

    // _filter_addSubFilterINT64_(testFilter, "testString", GREATER_THAN, 2020);
    // _filter_addSubFilterINT64_(testFilter, "2ndtestName", LESSER_THAN, 30);
    Data data1, data2;
    data1.INTEGER64 = 2020;
    data2.INTEGER64 = 30;

    ValueList *valueListHead = NULL;
    ValueList *ValueElement1 = createValueListElement(data1, INTEGER64);
    ValueList *ValueElement2 = createValueListElement(data2, INTEGER64);
    ValueElement1->isMatching = true;
    ValueElement2->isMatching = false;
    LL_APPEND(valueListHead, ValueElement1);
    LL_APPEND(valueListHead, ValueElement2);

    testFilter->predicateCountingReference = ValueElement1;
    testFilter->next->predicateCountingReference = ValueElement2;

    TEST_ASSERT_FALSE(isFilterMatching(testFilter));
}
