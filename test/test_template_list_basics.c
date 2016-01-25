
#include "unity.h"
#include "template_list.h"

template_list(int);

List(int)	list;

void		setUp(void)
{
   list = new_list(int);
}

void		tearDown(void)
{
  delete_list(list, NULL);
}

void		test_ListSizeShouldBeZero(void)
{
  TEST_ASSERT_EQUAL(0, list_size(list));
}

void		test_ListPushShouldReturnSizeOfListWhichShouldBeOne(void)
{
  int		a;

  a = 0xa;
  TEST_ASSERT_EQUAL(1, push_list(list, &a));
}


void		test_ListSizeShouldBeOneAferPush(void)
{
  int		a;

  a = 0xa;
  TEST_ASSERT_EQUAL(1, push_list(list, &a));
  TEST_ASSERT_EQUAL(1, list_size(list));
}

void		test_ListPopPushedContentShouldReturnPtrToSameElem(void)
{
  int		a;

  a = 0xa;
  push_list(list, &a);
  TEST_ASSERT_EQUAL(&a, pop_list(list));
}

void		test_ListPopWithOneElemShouldGetZeroSizedList(void)
{
  int		a;

  a = 0xa;
  push_list(list, &a);
  TEST_ASSERT_EQUAL(&a, pop_list(list));
  TEST_ASSERT_EQUAL(0, list_size(list));
}

void		test_ListPushAndPopShouldNotAlterData(void)
{
  int		a;
  int		*b;
  a = 0xa;
  push_list(list, &a);
  b = pop_list(list);
  TEST_ASSERT_EQUAL(&a, b);
  TEST_ASSERT_EQUAL(a, *b);
  TEST_ASSERT_EQUAL(0, list_size(list));
}
