#include "build/temp/_test_dataModel.c"
#include "src/core/dataModel.h"
#include "/home/michael/.rbenv/versions/2.7.2/lib/ruby/gems/2.7.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


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

    UnityAssertEqualIntArray(( const void*)((simple_array)), ( const void*)((correspondingDataSet->lookupArray)), (UNITY_UINT32)((3)), (

   ((void *)0)

   ), (UNITY_UINT)(16), UNITY_DISPLAY_STYLE_INT, UNITY_ARRAY_TO_ARRAY);

}



void test_getValue(void)

{

    DataSet newDataSet = dataSet_Create(1, 2, 3);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((dataSet_getValue(newDataSet, ID))), (

   ((void *)0)

   ), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((dataSet_getValue(newDataSet, VALUE))), (

   ((void *)0)

   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((dataSet_getValue(newDataSet, ERRORCODE))), (

   ((void *)0)

   ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);

}
