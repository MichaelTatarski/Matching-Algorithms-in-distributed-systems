#include "unity.h"
#include "dataModel.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_DataSet_Create(void)
{
    int simple_array[3] = {1, 2, 3};
    DataSet correspondingDataSet = dataSet_Create(simple_array[0], simple_array[1], simple_array[2]);
    TEST_ASSERT_EQUAL_INT_ARRAY(simple_array, correspondingDataSet->lookupArray, 3);
}

void test_getValue(void)
{
    DataSet newDataSet = dataSet_Create(1, 2, 3);
    TEST_ASSERT_EQUAL_INT(1, dataSet_getValue(newDataSet, ID));
    TEST_ASSERT_EQUAL_INT(2, dataSet_getValue(newDataSet, VALUE));
    TEST_ASSERT_EQUAL_INT(3, dataSet_getValue(newDataSet, ERRORCODE));
}