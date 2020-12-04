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
    char testName[] = "TestInt64";
    int64_t testInt64 = 2020;
    dataModel_addAttributeINT64(testName, testInt64);
    int64_t returnValue;
    returnValue = getValueINT64(testName);
    TEST_ASSERT_EQUAL_INT64(testInt64, returnValue);
}

void test_getValueINT32(void)
{
    char testName[] = "TestInt32";
    int32_t testInt32 = 2020;
    dataModel_addAttributeINT32(testName, testInt32);
    int32_t returnValue;
    returnValue = getValueINT32(testName);
    TEST_ASSERT_EQUAL_INT64(testInt32, returnValue);
}

void test_getValueDOUBLE(void)
{
    char testName[] = "TestDouble";
    double testDouble = 2020;
    dataModel_addAttributeDOUBLE(testName, testDouble);
    int32_t returnValue;
    returnValue = getValueDOUBLE(testName);
    TEST_ASSERT_EQUAL_DOUBLE(testDouble, returnValue);
}

void test_getTEXT32(void)
{
    char testName[] = "TestString";
    char testString[TEXT32] = "KZH";
    dataModel_addAttributeTEXT32(testName, testString);
    char returnString[TEXT32];
    getValueTEXT32(testName, returnString);
    TEST_ASSERT_EQUAL_STRING(testString, returnString);
}
void test_getDataType(void)
{
    char testName[] = "TestDouble";
    double testDouble = 2020;
    dataModel_addAttributeDOUBLE(testName, testDouble);
    DataType expected = DOUBLE;
    TEST_ASSERT_EQUAL_INT(expected, getDataType(testName));
}
