#include "unity.h"

#include "../utility/filterList.h"
#include "filterModel.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_List_filter_Create(void)
{
    KeyFilter *newKeyFilter = filter_Create(ID, GREATER_THAN, 10);
    printf("%d", newKeyFilter->constraintValue);
}
