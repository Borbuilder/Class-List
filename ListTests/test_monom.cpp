#include "gtest.h"
#include "../List/List/Monom.h"
#include<string.h>


TEST(Monom, can_create_monom)
{
    ASSERT_NO_THROW(Monom m);
    ASSERT_NO_THROW(Monom m1(1,2));
}

TEST(Monom, can_compare_two_monoms)
{
    Monom m(1, 2),m1(1,2);
    Monom m2(2, 3), m3(1, 3);
    Monom m4(1, 4), m5(1, 5);
    EXPECT_EQ(1, m == m1);
    EXPECT_EQ(1, m2 > m3);
    EXPECT_EQ(1, m3 < m2);
    EXPECT_EQ(1, m5 > m4);
    EXPECT_EQ(1, m4 < m5);
    EXPECT_EQ(1, m4 != m5);
}

TEST(Monom, can_copy_monom)
{
    Monom m(1,2);
    ASSERT_NO_THROW(Monom m1(m));
    Monom m1(m);
    EXPECT_EQ(1,m1== m);
}

TEST(Monom, can_create_monom_on_input_parametrs)
{
    Monom m(1,111);
    Monom m1;
    ASSERT_NO_THROW(m1.createMonom(1, 1, 1, 1));
    EXPECT_EQ(1, m == m1);
}

TEST(Monom, can_get_index)
{
    Monom m(1, 111);
    EXPECT_EQ(111, m.getIndex());
}

TEST(Monom, can_get_coef)
{
    Monom m(1, 111);
    EXPECT_EQ(1, m.getCoef());
}

TEST(Monom, can_set_index)
{
    Monom m(1, 0);
    m.setIndex(111);
    EXPECT_EQ(111, m.getIndex());
}

TEST(Monom, can_set_coef)
{
    Monom m(0,111);
    m.setCoef(1);
    EXPECT_EQ(1, m.getCoef());
}

TEST(Monom, can_turn_monom_into_string)
{
    Monom m(2, 222);
    ASSERT_NO_THROW(m.monomToString());
    std::string str1 = m.monomToString();
    std::string str = "2x^2y^2z^2";
    EXPECT_EQ(1, str==str1);
}
