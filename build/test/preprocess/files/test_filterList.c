#include "build/temp/_test_filterList.c"
#include "src/core/filterModel/filterModel.h"
#include "src/core/filterModel/filterList.h"
#include "/home/michael/.rbenv/versions/2.7.2/lib/ruby/gems/2.7.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"




void setUp(void)

{

}



void tearDown(void)

{

}



void test_FilterList_addFilter(void)

{

    FilterList *testFilterList = filterList_create();

    Filter *testFilter = filter_create();

    filter_addSubFilterDOUBLE(testFilter, "TestName", GREATER_THAN, 40.2);

    filterList_addFilter(testFilterList, testFilter);

}
