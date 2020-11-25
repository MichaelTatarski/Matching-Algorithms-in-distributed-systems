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



void test_List_filter_Create(void)

{

    KeyFilter *newKeyFilter = filter_Create(ID, GREATER_THAN, 10);

    printf("%d", newKeyFilter->constraintValue);

}
