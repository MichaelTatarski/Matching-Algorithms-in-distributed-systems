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

    char testName[] = "TestInt64";

    int64_t testInt64 = 2020;

    dataModel_addAttributeINT64(testName, testInt64);

    int64_t returnValue;

    returnValue = getValueINT64(testName);

    UnityAssertEqualNumber((UNITY_INT)((testInt64)), (UNITY_INT)((returnValue)), (

   ((void *)0)

   ), (UNITY_UINT)(20), UNITY_DISPLAY_STYLE_INT64);

}



void test_getValueINT32(void)

{

    char testName[] = "TestInt32";

    int32_t testInt32 = 2020;

    dataModel_addAttributeINT32(testName, testInt32);

    int32_t returnValue;

    returnValue = getValueINT32(testName);

    UnityAssertEqualNumber((UNITY_INT)((testInt32)), (UNITY_INT)((returnValue)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT64);

}



void test_getValueDOUBLE(void)

{

    char testName[] = "TestDouble";

    double testDouble = 2020;

    dataModel_addAttributeDOUBLE(testName, testDouble);

    int32_t returnValue;

    returnValue = getValueDOUBLE(testName);

    UnityAssertDoublesWithin((UNITY_DOUBLE)((UNITY_DOUBLE)((testDouble)) * (UNITY_DOUBLE)(1e-12)), (UNITY_DOUBLE)((UNITY_DOUBLE)((testDouble))), (UNITY_DOUBLE)((UNITY_DOUBLE)((returnValue))), ((

   ((void *)0)

   )), (UNITY_UINT)((UNITY_UINT)(40)));

}



void test_getTEXT32(void)

{

    char testName[] = "TestString";

    char testString[4] = "KZH";

    dataModel_addAttributeTEXT32(testName, testString);

    char returnString[4];

    getValueTEXT32(testName, returnString);

    UnityAssertEqualString((const char*)((testString)), (const char*)((returnString)), (

   ((void *)0)

   ), (UNITY_UINT)(50));

}

void test_getDataType(void)

{

    char testName[] = "TestDouble";

    double testDouble = 2020;

    dataModel_addAttributeDOUBLE(testName, testDouble);

    DataType expected = DOUBLE;

    UnityAssertEqualNumber((UNITY_INT)((expected)), (UNITY_INT)((getDataType(testName))), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

}
