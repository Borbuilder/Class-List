#include "gtest.h"
#include "../List/List/TPolinom.h"
#include "../List/List/Monom.h"
#include<vector>

//TEST(TPolinom, can_create_polinom)
//{
   // ASSERT_NO_THROW(TPolinom p);
   // TPolinom p1;
   // Monom m(0, 0);
   // p1.addMonom(m);
//}
/*
TEST(TPolinom, can_compare_polinoms)
{
    TPolinom p1;
    TPolinom p2;
    p1.createPolinom("x^2y^2z^2+x^3y^3z^3");
    p2.createPolinom("x^2y^2z^2+x^3y^3z^3");
    EXPECT_EQ(1, p1==p2);
}

TEST(TPolinom, can_applied_one_polinom_to_second)
{
    TPolinom p1;
    TPolinom p2;
    TPolinom p3;
    TPolinom p4;
    p1.createPolinom("x^2y^2z^2+x^3y^3z^3");
    p2.createPolinom("x^2y^2z^2+x^4y^4z^4");
    p3.createPolinom("x^4y^4z^4+x^3y^3z^3+2x^2y^2z^2");
    p4=p1 + p2;
    EXPECT_EQ(p3, p4);
}

TEST(TPolinom, can_subtract_two_polinoms)
{
    TPolinom p1;
    TPolinom p2;
    TPolinom p3;
    TPolinom p4;
    p1.createPolinom("x^2y^2z^2+x^3y^3z^3");
    p2.createPolinom("x^2y^2z^2+x^4y^4z^4");
    p3.createPolinom("x^4y^4z^4-x^3y^3z^3");
    p4 = p1 + p2;
    EXPECT_EQ(p3, p4);
}
TEST(TPolinom, can_applied_one_monnom_in_polynom)
{

    TMonom mon(3, 457);
    int masres[][2] = { {3, 457},{2,234},{-3,231},{-2,123} };
    int mas[][2] = { {2,234},{-3,231},{-2,123 } };
    TPolinom res(masres, 4);
    TPolinom pol_project1(mas, 3);


    ASSERT_NO_THROW(pol_project1.AddMonom(mon));



    EXPECT_TRUE(pol_project1 == res);
}
TEST(TPolinom, can_multiply_two_polinoms)
{
    TPolinom res;
    int masres[][2] = { {25,468},{-9,462 },{15,357},{3,354},{2,246} };
    int mas[][2] = { {5,234},{-3,231},{2,123 } };
    int mas1[][2] = { {5,234},{3,231},{1,123 } };
    TPolinom pol_project1(mas, 3);
    TPolinom pol_project2(mas1, 3);
    TPolinom pol_project(masres, 5);

    ASSERT_NO_THROW(res = pol_project1 * pol_project2);



    EXPECT_TRUE(pol_project == res);
}
TEST(TPolinom, can_multiply_polinom_on_const)
{
    TPolinom res;

    int mas[][2] = { {5,234},{-3,231},{2,123 } };
    int mas1[][2] = { {25,234},{15,231},{5,123 } };
    TPolinom pol_project1(mas, 3);
    TPolinom pol_project2(mas1, 3);


    ASSERT_NO_THROW(res = pol_project1 * 5);



    EXPECT_TRUE(pol_project2 == res);
}
*/