#include "../List/List/TList.h"
#include "gtest.h"
#include "../List/List/THeadList.h"

TEST(TList, can_create_list)
{
    ASSERT_NO_THROW(TList<int> list);
}
TEST(THeadList, can_create_listttttttttt)
{
    ASSERT_NO_THROW(THeadList<int> list_project);
}
TEST(TList, can_insert_first)
{
    TList<int> list;
    ASSERT_NO_THROW(list.InsFirst(1));
    EXPECT_EQ(1, list.Front());
}

TEST(TList, cant_delete_first_from_empty_list)
{
    TList<int> list;
    ASSERT_ANY_THROW(list.DelFirst());
}

TEST(TList, can_delete_first)
{
    TList<int> list;
    list.InsFirst(1);
    list.InsFirst(2);
    ASSERT_NO_THROW(list.DelFirst());
    EXPECT_EQ(1, list.Front());
}

TEST(TList, can_insert_last)
{
    TList<int> list;
    list.InsFirst(1);
    ASSERT_NO_THROW(list.InsLast(2));
    EXPECT_EQ(2, list.Back());
}

TEST(TList, cant_set_wrong_position)
{
    TList<int> list;
    list.InsFirst(1);
    ASSERT_ANY_THROW(list.SetPos(10));
    ASSERT_ANY_THROW(list.SetPos(-10));
    
}

TEST(TList, can_set_position)
{
    TList<int> list;
    list.InsFirst(1);
    list.InsFirst(1);
    ASSERT_NO_THROW(list.SetPos(1));
    EXPECT_EQ(list.GetPos(), 1);
}

TEST(TList, can_reset_current)
{
    TList<int> list;
    int value1, value2;
    list.InsFirst(3);
    list.InsFirst(2);
    list.InsFirst(1);
    list.SetPos(2);
    value1 = list.GetPos();
    list.Reset();
    value2 = list.GetPos();
    EXPECT_NE(value1, value2);
    EXPECT_EQ(value2, 0);
}

TEST(TList, can_Go_Next)
{
    int value1,value2,value3;
    TList<int> list;
    list.InsFirst(1);
    list.InsFirst(2);
    list.InsFirst(3);
    list.SetPos(0);
    for (int i = 1; i < 3; i++)
    {
        ASSERT_NO_THROW(list.GoNext());
        EXPECT_EQ(list.GetPos(), i);
    }
}

TEST(TList, can_delete_list)
{
    int value1;
    TList<int> list;
    list.InsLast(1);
    list.InsLast(2);
    list.InsLast(3);

    ASSERT_NO_THROW(list.DelList());

    EXPECT_EQ(list.GetPos(), -1);
    EXPECT_EQ(list.GetLenght(), 0);
    EXPECT_EQ(list.empty(), 1);
}

TEST(TList, can_insert_first_by_InsCurrent)
{
    TList<int> list;
    list.InsFirst(1);
    list.InsLast(2);
    list.SetPos(0);
    ASSERT_NO_THROW(list.InsCurrent(10));
    EXPECT_EQ(10, list.Front());
}

TEST(TList, can_insert_in_middle_by_InsCurrent)
{
    TList<int> list;
    list.InsFirst(1);
    list.InsLast(2);
    list.InsLast(3);
    list.SetPos(1);
    ASSERT_NO_THROW(list.InsCurrent(5));
    EXPECT_EQ(2, list.GetCurrentValue());
}

TEST(TList, can_insert_in_the_end_by_InsCurr)
{
    TList<int> list;
    list.InsFirst(1);
    list.InsLast(2);
    list.InsLast(3);
    list.SetPos(2);
    ASSERT_NO_THROW(list.InsCurrent(4));
    EXPECT_EQ(3, list.GetCurrentValue());
}

TEST(TList, can_delete_first_by_DelCurr)
{
    TList<int> list;
    list.InsFirst(1);
    list.InsLast(2);
    list.SetPos(0);
    ASSERT_NO_THROW(list.DelCurrent());
    EXPECT_EQ(2, list.GetCurrentValue());
}

TEST(TList, can_delete_from_the_middle_by_DelCurr)
{
    TList<int> list;
    list.InsFirst(1);
    list.InsLast(2);
    list.InsLast(3);
    list.SetPos(1);
    ASSERT_NO_THROW(list.DelCurrent());
    EXPECT_EQ(3, list.GetCurrentValue());
}

TEST(TList, can_delete_last_by_DelCurr)
{
    TList<int> list;
    list.InsFirst(1);
    list.InsLast(2);
    list.InsLast(3);
    list.SetPos(2);
    ASSERT_NO_THROW(list.DelCurrent());
    EXPECT_EQ(nullptr, list.GetpCur());
}
