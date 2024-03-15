#include "gtest.h"
#include "../List/List/THeadList.h"

TEST(THeadList, can_create_list)
{
    ASSERT_NO_THROW(THeadList<int> list);
}

TEST(THeadList, can_insert_first)
{
    THeadList<int> list;
    ASSERT_NO_THROW(list.InsFirst(1));
    int value = list.Front();
    EXPECT_EQ(1, value);
}

TEST(THeadList, can_delete_first)
{
    THeadList<int> list;
    list.InsFirst(1);
    list.InsFirst(2);
    ASSERT_NO_THROW(list.DelFirst());
    int value = list.Front();
    EXPECT_EQ(1, value);
}

TEST(THeadList, cant_delete_first_in_empty_list)
{
    THeadList<int> list;
    ASSERT_ANY_THROW(list.DelFirst());
}

TEST(THeadList, can_insert_last)
{
    THeadList<int> list;
    ASSERT_NO_THROW(list.InsLast(1));
    list.InsLast(2);
    int value = list.Back();
    EXPECT_EQ(2, value);
}

TEST(THeadList, can_delete_last)
{
    THeadList<int> list;
    int value;
    list.InsLast(1);
    list.InsLast(2);
    list.SetPos(1);
    ASSERT_NO_THROW(list.DelCurrent());
    value = list.Back();
    EXPECT_EQ(1, value);
}

TEST(THeadList, cant_delete_last_in_empty_list)
{
    THeadList<int> list;
    ASSERT_ANY_THROW(list.DelCurrent());
}

TEST(THeadList, can_reset_current)
{
    THeadList<int> list;
    int value1, value2;
    list.InsLast(1);
    list.InsLast(2);
    list.InsLast(3);
    list.SetPos(1);
    value1 = list.GetPos();
    ASSERT_NO_THROW(list.Reset());
    value2 = list.GetPos();
    EXPECT_NE(value1, value2);
    EXPECT_EQ(value2, 0);
}

TEST(THeadList, can_GoNext)
{
    int value1;
    THeadList<int> list;
    list.InsLast(1);
    list.InsLast(2);
    list.InsLast(3);
    list.SetPos(1);
    ASSERT_NO_THROW(list.GoNext());
    value1 = list.GetPos();
    EXPECT_EQ(value1, 2);
}

TEST(THeadList, can_delete_list)
{
    int value1;
    THeadList<int> list;
    list.InsLast(1);
    list.InsLast(2);
    list.InsLast(3);
    ASSERT_NO_THROW(list.DelList());
    EXPECT_EQ(list.GetPos(), -1);
    EXPECT_EQ(list.GetLenght(), 0);
    EXPECT_EQ(list.empty(), 1);
}

TEST(THeadList, can_insert_first_by_InsCurrent)
{
    THeadList<int> list;
    int value;
    list.InsFirst(1);
    list.InsLast(2);
    list.SetPos(0);
    list.InsCurrent(0);
    value = list.Front();
    EXPECT_EQ(0, value);
}

TEST(THeadList, can_insert_in_center_by_InsCurrent)
{
    THeadList<int> list;
    list.InsFirst(1);
    list.InsLast(2);
    list.InsLast(3);
    list.SetPos(1);
    ASSERT_NO_THROW(list.InsCurrent(5));
    EXPECT_EQ(2, list.GetCurrentValue());
}

TEST(THeadList, can_insert_in_end_by_InsCurrent)
{
    THeadList<int> list;
    list.InsFirst(1);
    list.InsLast(2);
    list.InsLast(3);
    list.SetPos(2);
    ASSERT_NO_THROW(list.InsCurrent(4));
    EXPECT_EQ(3, list.GetCurrentValue());
}

TEST(THeadList, can_delete_first_by_DelCurrent)
{
    THeadList<int> list;
    int value;
    list.InsFirst(1);
    list.InsLast(2);
    list.SetPos(0);
    ASSERT_NO_THROW(list.DelCurrent());
    value = list.Front();
    EXPECT_EQ(2, value);
}

TEST(THeadList, can_delete_from_center_by_DelCurrent)
{
    THeadList<int> list;
    int value;
    list.InsFirst(1);
    list.InsLast(2);
    list.InsLast(3);
    list.SetPos(1);
    ASSERT_NO_THROW(list.DelCurrent());
    value = list.GetCurrentValue();
    EXPECT_EQ(3, value);
}

TEST(THeadList, can_delete_last_by_DelCurrent)
{
    THeadList<int> list;
    int value;
    list.InsFirst(1);
    list.InsLast(2);
    list.InsLast(3);
    list.SetPos(2);
    ASSERT_NO_THROW(list.DelCurrent());
    value = list.Back();
    EXPECT_EQ(2, value);
}
