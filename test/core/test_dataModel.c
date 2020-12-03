#include "unity.h"
#include "dataModel.h"
#include "../utility/uthash.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_getValueINT64(void)
{
    char testString[] = "Test";
    int64_t testInt64 = 2020;
    dataModel_createAttributeINT64(testString, testInt64);
    int64_t returnValue;
    returnValue = getValueINT64(testString);
    TEST_ASSERT_EQUAL_INT64(testInt64, returnValue);
}
