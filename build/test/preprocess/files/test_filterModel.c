#include "build/temp/_test_filterModel.c"
#include "src/utility/../utility/../core/filterModel.h"
#include "src/utility/../utility/filterList.h"
#include "/home/michael/.rbenv/versions/2.7.2/lib/ruby/gems/2.7.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_filter_Create(void)

{

    Filter *testFilter = filter_Create();

    filter_AddConstraintToFilter(testFilter, ID, EQUALS, 20, FIRST_EXPRESSION);

}
