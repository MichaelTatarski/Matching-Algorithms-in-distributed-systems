#include "unity.h"
#include "../utility/filterList.h"
#include "filterModel.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_filter_Create(void)
{
    Filter *testFilter = filter_Create();
    filter_AddConstraintToFilter(testFilter, ID, EQUALS, 20, FIRST_EXPRESSION);
    filter_AddConstraintToFilter(testFilter, VALUE, EQUALS, 30, AND);
    Filter *secondFilter = filter_Create();
    printf("%d", testFilter->head->next->constraintValue);
}
