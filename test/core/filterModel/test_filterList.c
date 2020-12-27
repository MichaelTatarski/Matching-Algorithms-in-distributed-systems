#include "unity.h"

#include "filterList.h"
#include "filterModel.h"

FilterList *testFilterList;

void setUp(void)
{
    testFilterList = filterList_create();
}

void tearDown(void)
{
}

void test_FilterList_addFilter(void)
{
    Filter *testFilter = filter_create();
    filter_addSubFilterDOUBLE(testFilter, "TestName", GREATER_THAN, 40.2);
    filterList_addFilter(testFilterList, testFilter);
}
