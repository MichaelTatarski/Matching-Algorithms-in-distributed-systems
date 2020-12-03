#include "build/temp/_test_dataModel.c"
#include "src/core/../utility/uthash.h"
#include "src/core/dataModel.h"
#include "/home/michael/.rbenv/versions/2.7.2/lib/ruby/gems/2.7.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


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

    UnityAssertEqualNumber((UNITY_INT)((testInt64)), (UNITY_INT)((returnValue)), (

   ((void *)0)

   ), (UNITY_UINT)(20), UNITY_DISPLAY_STYLE_INT64);

    printf("%d and %d", returnValue, testInt64);

}
