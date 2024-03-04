#include "gtest.h"
#include "../List/List/THeadList.h"

TEST(THeadList, can_create_list)
{
    ASSERT_NO_THROW(THeadList<int> list_project);
}

TEST(THeadList, can_insert_first)
{
    THeadList<int> list_project;
    ASSERT_NO_THROW(list_project.InsFirst(1));
    int value = list_project.Front();
    EXPECT_EQ(1, value);
}

TEST(THeadList, can_delete_first)
{
    THeadList<int> list_project;
    list_project.InsFirst(1);
    list_project.InsFirst(2);
    ASSERT_NO_THROW(list_project.DelFirst());
    int value = list_project.Front();
    EXPECT_EQ(1, value);
}

TEST(THeadList, cant_delete_first_in_empty_list)
{
    THeadList<int> list_project;
    ASSERT_ANY_THROW(list_project.DelFirst());
}

TEST(THeadList, can_insert_last)
{
    THeadList<int> list_project;
    ASSERT_NO_THROW(list_project.InsLast(1));
    list_project.InsLast(2);
    int value = list_project.Back();
    EXPECT_EQ(2, value);
}

TEST(THeadList, can_delete_last)
{
    THeadList<int> list_project;
    int value;
    list_project.InsLast(1);
    list_project.InsLast(2);
    list_project.SetPos(1);
    ASSERT_NO_THROW(list_project.DelCurrent());
    value = list_project.Back();
    EXPECT_EQ(1, value);
}

TEST(THeadList, cant_delete_last_in_empty_list)
{
    THeadList<int> list_project;
    ASSERT_ANY_THROW(list_project.DelCurrent());
}

TEST(THeadList, can_reset_current)
{
    THeadList<int> list_project;
    int value1, value2;
    list_project.InsLast(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
    list_project.SetPos(1);
    value1 = list_project.GetPos();
    ASSERT_NO_THROW(list_project.Reset());
    value2 = list_project.GetPos();
    EXPECT_NE(value1, value2);
    EXPECT_EQ(value2, 0);
}

TEST(THeadList, can_Go_Next)
{
    int value1;
    THeadList<int> list_project;
    list_project.InsLast(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
    list_project.SetPos(1);
    ASSERT_NO_THROW(list_project.GoNext());
    value1 = list_project.GetPos();
    EXPECT_EQ(value1, 2);
}

TEST(THeadList, can_delete_list)
{
    int value1;
    THeadList<int> list_project;
    list_project.InsLast(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
    ASSERT_NO_THROW(list_project.DelList());
    EXPECT_EQ(list_project.GetPos(), -1);
    EXPECT_EQ(list_project.GetLenght(), 0);
    EXPECT_EQ(list_project.empty(), 1);
}

TEST(THeadList, can_insert_first_by_InsCurr)
{
    THeadList<int> list_project;
    int value;
    list_project.InsFirst(1);
    list_project.InsLast(2);
    list_project.SetPos(0);
    list_project.InsCurrent(0);
    value = list_project.Front();
    EXPECT_EQ(0, value);
}

TEST(THeadList, can_insert_in_center_by_InsCurr)
{
    THeadList<int> list;
    list.InsFirst(1);
    list.InsLast(2);
    list.InsLast(3);
    list.SetPos(1);
    ASSERT_NO_THROW(list.InsCurrent(5));
    EXPECT_EQ(2, list.GetCurrentValue());
    /*
    THeadList<int> list_project;
    int value;
    list_project.InsFirst(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
    list_project.SetPos(1);
    ASSERT_NO_THROW(list_project.InsCurrent(4));
    value = list_project.GetCurrentValue();
    EXPECT_EQ(4, value);*/
}

TEST(THeadList, can_insert_in_end_by_InsCurr)
{
    THeadList<int> list;
    list.InsFirst(1);
    list.InsLast(2);
    list.InsLast(3);
    list.SetPos(2);
    ASSERT_NO_THROW(list.InsCurrent(4));
    EXPECT_EQ(3, list.GetCurrentValue());
    /*THeadList<int> list_project;
    int value;
    list_project.InsFirst(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
    list_project.SetPos(2);
    ASSERT_NO_THROW(list_project.InsCurrent(4));
    value = list_project.GetCurrentValue();
    EXPECT_EQ(4, value);*/
}

TEST(THeadList, can_delete_first_by_DelCurr)
{
    THeadList<int> list_project;
    int value;
    list_project.InsFirst(1);
    list_project.InsLast(2);
    list_project.SetPos(0);
    ASSERT_NO_THROW(list_project.DelCurrent());
    value = list_project.Front();
    EXPECT_EQ(2, value);
}

TEST(THeadList, can_delete_from_center_by_DelCurr)
{
    THeadList<int> list_project;
    int value;
    list_project.InsFirst(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
    list_project.SetPos(1);
    ASSERT_NO_THROW(list_project.DelCurrent());
    value = list_project.GetCurrentValue();
    EXPECT_EQ(3, value);
}

TEST(THeadList, can_delete_last_by_DelCurr)
{
    THeadList<int> list_project;
    int value;
    list_project.InsFirst(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
    list_project.SetPos(2);
    ASSERT_NO_THROW(list_project.DelCurrent());
    value = list_project.Back();
    EXPECT_EQ(2, value);
}
