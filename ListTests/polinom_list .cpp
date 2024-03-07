#include "gtest.h"
#include "../List/List/TPolinom.h"
#include "../List/List/Monom.h"
#include<vector>

TEST(TPolinom, can_create_polinom)
{
    ASSERT_NO_THROW(TPolinom p);
}

/*TEST(TPolinom, can_compare_equal_polinoms)
{
    std::vector<Monom> v;
    Monom m1(3, 111); v.push_back(m1);
    Monom m2(2, 222); v.push_back(m2);
    Monom m3(1, 333); v.push_back(m3);
    TPolinom p1;
    ASSERT_NO_THROW(p1.createPolinomOnVector(v));
    TPolinom p2;
    ASSERT_NO_THROW(p2.createPolinomOnVector(v));
    EXPECT_EQ(1, p1 == p2);
}*/
