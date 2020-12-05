#include "build/temp/_test_filterModel.c"
#include "src/core/filterModel.h"
#include "/home/michael/.rbenv/versions/2.7.2/lib/ruby/gems/2.7.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_addSubFilterINT64(void)

{

    Filter *testFilter = Filter_create();

    char testName[] = "testString";

    int64_t testInt64 = 2020;

    Operator testOperator = GREATER_THAN;

    Filter_addSubFilterINT64(testFilter, testName, testOperator, testInt64);

    Filter_addSubFilterINT64(testFilter, "2ndtestName", SMALLER_THAN, 30);

}



void test_addSubFilterINT32(void)

{

    Filter *testFilter = Filter_create();

    char testName[] = "testString";

    int64_t testInt32 = 2020;

    Operator testOperator = GREATER_THAN;

    Filter_addSubFilterINT32(testFilter, testName, testOperator, testInt32);

    Filter_addSubFilterINT32(testFilter, "2ndtestName", EQUALS, 50);

}



void test_addSubFilterDouble(void)

{

    Filter *testFilter = Filter_create();

    char testName[] = "testString";

    double testDouble = 2020.1;

    Operator testOperator = GREATER_THAN;

    Filter_addSubFilterDOUBLE(testFilter, testName, testOperator, testDouble);

    Filter_addSubFilterDOUBLE(testFilter, "2ndtestName", EQUALS, 50.1);

}



void test_addSubFilterText(void)

{

    Filter *testFilter = Filter_create();

    char testName[] = "testString";

    char testText[] = "Tes";

    Operator testOperator = GREATER_THAN;

    Filter_addSubFilterTEXT32(testFilter, testName, testOperator, testText);

    Filter_addSubFilterTEXT32(testFilter, "2ndtestName", EQUALS, "KES");

}
