/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "template_list.h"

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_ListSizeShouldBeZero(void);
extern void test_ListPushShouldReturnSizeOfListWhichShouldBeOne(void);
extern void test_ListSizeShouldBeOneAferPush(void);
extern void test_ListPopPushedContentShouldReturnPtrToSameElem(void);
extern void test_ListPopWithOneElemShouldGetZeroSizedList(void);
extern void test_ListPushAndPopShouldNotAlterData(void);


//=======Test Reset Option=====
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  UnityBegin(".//test_template_list_basics.c");
  RUN_TEST(test_ListSizeShouldBeZero, 19);
  RUN_TEST(test_ListPushShouldReturnSizeOfListWhichShouldBeOne, 24);
  RUN_TEST(test_ListSizeShouldBeOneAferPush, 33);
  RUN_TEST(test_ListPopPushedContentShouldReturnPtrToSameElem, 42);
  RUN_TEST(test_ListPopWithOneElemShouldGetZeroSizedList, 51);
  RUN_TEST(test_ListPushAndPopShouldNotAlterData, 61);

  return (UnityEnd());
}