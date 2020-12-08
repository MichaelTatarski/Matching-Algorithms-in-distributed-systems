#include "unity.h"

#include "filterList.h"
#include "filterModel.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_FilterList_addFilter(void)
{
    FilterList *testFilterList = filterList_create();
    Filter *testFilter = filter_create();
    filter_addSubFilterDOUBLE(testFilter, "TestName", GREATER_THAN, 40.2);
    filterList_addFilter(testFilterList, testFilter);
}
