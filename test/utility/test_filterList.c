#include "unity.h"
#include "../core/filterModel.h"
#include "filterList.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_filterList_add(void)
{
    Filter *testFilter;
    testFilter->head = NULL;
    FilterList *testFilterList = make_filterList();
    filterList_add(*testFilter, testFilterList);
}
