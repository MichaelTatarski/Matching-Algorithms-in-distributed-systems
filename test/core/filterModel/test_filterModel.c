#include "unity.h"
#include "filterModel.h"

Filter *testFilter;

void setUp(void)
{
    testFilter = filter_create();
}

void tearDown(void)
{
}

void test_addSubFilterINT64(void)
{
    filter_addSubFilterINT64(testFilter, "testString", GREATER_THAN, 2020);
    filter_addSubFilterINT64(testFilter, "2ndtestName", LESSER_THAN, 30);
}

void test_addSubFilterINT32(void)
{
    filter_addSubFilterINT32(testFilter, "testString", GREATER_THAN, 2020);
    filter_addSubFilterINT32(testFilter, "2ndtestName", EQUALS, 50);
}

void test_addSubFilterDouble(void)
{
    filter_addSubFilterDOUBLE(testFilter, "testString", GREATER_THAN, 2020.1);
    filter_addSubFilterDOUBLE(testFilter, "2ndtestName", EQUALS, 50.1);
}

void test_addSubFilterText(void)
{
    filter_addSubFilterTEXT32(testFilter, "testString", GREATER_THAN, "Tes");
    filter_addSubFilterTEXT32(testFilter, "2ndtestName", EQUALS, "KES");
}
