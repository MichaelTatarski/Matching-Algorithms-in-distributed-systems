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

    DataModel *testDataModel = dataModel_create();

    char testName[] = "TestInt64";

    int64_t testInt64 = 2020;

    dataModel_addAttributeINT64(testDataModel, testName, testInt64);

    int64_t returnValue;

    returnValue = getValueINT64(testDataModel, testName);

    UnityAssertEqualNumber((UNITY_INT)((testInt64)), (UNITY_INT)((returnValue)), (

   ((void *)0)

   ), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_INT64);

}



void test_getValueINT32(void)

{

    DataModel *testDataModel = dataModel_create();

    char testName[] = "TestInt32";

    int32_t testInt32 = 2020;

    dataModel_addAttributeINT32(testDataModel, testName, testInt32);

    int32_t returnValue;

    returnValue = getValueINT32(testDataModel, testName);

    UnityAssertEqualNumber((UNITY_INT)((testInt32)), (UNITY_INT)((returnValue)), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT64);

}



void test_getValueDOUBLE(void)

{

    DataModel *testDataModel = dataModel_create();

    char testName[] = "TestDouble";

    double testDouble = 2020;

    dataModel_addAttributeDOUBLE(testDataModel, testName, testDouble);

    int32_t returnValue;

    returnValue = getValueDOUBLE(testDataModel, testName);

    UnityAssertDoublesWithin((UNITY_DOUBLE)((UNITY_DOUBLE)((testDouble)) * (UNITY_DOUBLE)(1e-12)), (UNITY_DOUBLE)((UNITY_DOUBLE)((testDouble))), (UNITY_DOUBLE)((UNITY_DOUBLE)((returnValue))), ((

   ((void *)0)

   )), (UNITY_UINT)((UNITY_UINT)(43)));

}



void test_getTEXT32(void)

{

    DataModel *testDataModel = dataModel_create();

    char testName[] = "TestString";

    char testString[4] = "KZH";

    dataModel_addAttributeTEXT32(testDataModel, testName, testString);

    char returnString[4];

    getValueTEXT32(testDataModel, testName, returnString);

    UnityAssertEqualString((const char*)((testString)), (const char*)((returnString)), (

   ((void *)0)

   ), (UNITY_UINT)(54));

}

void test_dataModel_getDataType(void)

{

    DataModel *testDataModel = dataModel_create();

    char testName[] = "TestDouble";

    double testDouble = 2020;

    dataModel_addAttributeDOUBLE(testDataModel, testName, testDouble);

    DataType expected = DOUBLE;

    UnityAssertEqualNumber((UNITY_INT)((expected)), (UNITY_INT)((dataModel_getDataType(testDataModel, testName))), (

   ((void *)0)

   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

}
