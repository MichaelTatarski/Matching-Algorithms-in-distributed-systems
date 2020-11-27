#include "unity.h"
#include "filterList.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_filterList_add(void)
{
    Node *filterList = NULL;
    Filter testFilter;
    Filter newFilter;
    filterList_add(testFilter, filterList);
    filterList_add(newFilter, filterList);
}
