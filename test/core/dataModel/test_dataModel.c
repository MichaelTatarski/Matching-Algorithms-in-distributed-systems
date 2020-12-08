#include "unity.h"
#include "dataModel.h"

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
    returnValue = dataModel_getValueINT64(testDataModel, testName);
    TEST_ASSERT_EQUAL_INT64(testInt64, returnValue);
}

void test_getValueINT32(void)
{
    DataModel *testDataModel = dataModel_create();
    char testName[] = "TestInt32";
    int32_t testInt32 = 2020;
    dataModel_addAttributeINT32(testDataModel, testName, testInt32);
    int32_t returnValue;
    returnValue = dataModel_getValueINT32(testDataModel, testName);
    TEST_ASSERT_EQUAL_INT64(testInt32, returnValue);
}

void test_getValueDOUBLE(void)
{
    DataModel *testDataModel = dataModel_create();
    char testName[] = "TestDouble";
    double testDouble = 2020;
    dataModel_addAttributeDOUBLE(testDataModel, testName, testDouble);
    int32_t returnValue;
    returnValue = dataModel_getValueDOUBLE(testDataModel, testName);
    TEST_ASSERT_EQUAL_DOUBLE(testDouble, returnValue);
}

void test_getTEXT32(void)
{
    DataModel *testDataModel = dataModel_create();
    char testName[] = "TestString";
    char testString[TEXT32] = "KZH";
    dataModel_addAttributeTEXT32(testDataModel, testName, testString);
    char returnString[TEXT32];
    dataModel_getValueTEXT32(testDataModel, testName, returnString);
    TEST_ASSERT_EQUAL_STRING(testString, returnString);
}
void test_dataModel_getDataType(void)
{
    DataModel *testDataModel = dataModel_create();
    char testName[] = "TestDouble";
    double testDouble = 2020;
    dataModel_addAttributeDOUBLE(testDataModel, testName, testDouble);
    DataType expected = DOUBLE;
    TEST_ASSERT_EQUAL_INT(expected, dataModel_getDataType(testDataModel, testName));
}
