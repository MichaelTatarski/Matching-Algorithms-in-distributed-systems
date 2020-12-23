/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#ifndef UNITY_INCLUDE_DOUBLE
#define UNITY_INCLUDE_DOUBLE
#endif /* UNITY_INCLUDE_DOUBLE */

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_doesValueReferenceExist(void);
extern void test_getReferenceForPredicate(void);
extern void test_insertPredicate(void);
extern void test_lookForPredicate(void);
extern void test_matchingOfEqual(void);
extern void test_matchingOfGreaterThan(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, int line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_predicateCountingAlgorithm.c");
  run_test(test_doesValueReferenceExist, "test_doesValueReferenceExist", 60);
  run_test(test_getReferenceForPredicate, "test_getReferenceForPredicate", 65);
  run_test(test_insertPredicate, "test_insertPredicate", 79);
  run_test(test_lookForPredicate, "test_lookForPredicate", 91);
  run_test(test_matchingOfEqual, "test_matchingOfEqual", 105);
  run_test(test_matchingOfGreaterThan, "test_matchingOfGreaterThan", 115);

  return UnityEnd();
}
