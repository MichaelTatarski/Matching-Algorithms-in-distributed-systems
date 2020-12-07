#include "unity.h"
#include "filterModel.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_addSubFilterINT64(void)
{
    Filter *testFilter = filter_create();
    char testName[] = "testString";
    int64_t testInt64 = 2020;
    Operator testOperator = GREATER_THAN;
    filter_addSubFilterINT64(testFilter, testName, testOperator, testInt64);
    filter_addSubFilterINT64(testFilter, "2ndtestName", SMALLER_THAN, 30);
}

void test_addSubFilterINT32(void)
{
    Filter *testFilter = filter_create();
    char testName[] = "testString";
    int64_t testInt32 = 2020;
    Operator testOperator = GREATER_THAN;
    filter_addSubFilterINT32(testFilter, testName, testOperator, testInt32);
    filter_addSubFilterINT32(testFilter, "2ndtestName", EQUALS, 50);
}

void test_addSubFilterDouble(void)
{
    Filter *testFilter = filter_create();
    char testName[] = "testString";
    double testDouble = 2020.1;
    Operator testOperator = GREATER_THAN;
    filter_addSubFilterDOUBLE(testFilter, testName, testOperator, testDouble);
    filter_addSubFilterDOUBLE(testFilter, "2ndtestName", EQUALS, 50.1);
}

void test_addSubFilterText(void)
{
    Filter *testFilter = filter_create();
    char testName[] = "testString";
    char testText[] = "Tes";
    Operator testOperator = GREATER_THAN;
    filter_addSubFilterTEXT32(testFilter, testName, testOperator, testText);
    filter_addSubFilterTEXT32(testFilter, "2ndtestName", EQUALS, "KES");
}

void test_FilterList_addFilter(void)
{
    FilterList *testFilterList = FilterList_create();
    Filter *testFilter = filter_create();
    filter_addSubFilterDOUBLE(testFilter, "TestName", GREATER_THAN, 40.2);
    FilterList_addFilter(testFilterList, testFilter);
}