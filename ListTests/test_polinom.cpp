#include "gtest.h"
#include "../List/List/TPolinom.h"
#include "../List/List/Monom.h"
#include<vector>

TEST(TPolinom, can_create_polinom)
{
    ASSERT_NO_THROW(TPolinom p);
}

TEST(TPolinom, can_compare_polinoms)
{
    TPolinom p1;
    TPolinom p2;
    p1.createPolinom("x^2y^2z^2+x^3y^3z^3");
    p2.createPolinom("x^2y^2z^2+x^3y^3z^3");
    EXPECT_EQ(1, p1==p2);
}

TEST(TPolinom, can_copy_polinoms)
{
    TPolinom p1;
    p1.createPolinom("x^2y^2z^2+x^3y^3z^3");
    TPolinom p2(p1);
    bool fact = p1 == p2;
    EXPECT_EQ(1, fact);
}

TEST(TPolinom, can_applied_one_polinom_to_second)
{
    TPolinom p1;
    TPolinom p2;
    TPolinom p3;
    TPolinom p4;
    p1.createPolinom("x^2y^2z^2+x^3y^3z^3+x^5y^5z^5");
    p2.createPolinom("x^2y^2z^2+x^4y^4z^4-x^5y^5z^5");
    p3.createPolinom("x^4y^4z^4+x^3y^3z^3+2x^2y^2z^2");
    p4 = p1 + p2;
    EXPECT_EQ(1,p3==p4);
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
    p4 = p2 - p1;
    EXPECT_EQ(1,p3== p4);
}

TEST(TPolinom, can_applied_monnom_in_polynom)
{
    TPolinom p1, p2;
    std::vector<Monom> v1;
    Monom m1(1, 111);
    v1.push_back(m1);
    p1.createPolinomOnVector(v1);
    Monom m2(2, 222);
    p1.addMonom(m2);

    std::vector<Monom> v2;
    v2.push_back(m1);
    v2.push_back(m2);
    p2.createPolinomOnVector(v2);

    EXPECT_EQ(1,p1==p2);
}

TEST(TPolinom, can_multiply_two_polinoms)
{
    TPolinom p1;
    TPolinom p2;
    TPolinom p3;
    TPolinom p4;
    p1.createPolinom("x^2y^2z^2+x^4y^4z^4");
    p2.createPolinom("2x^3y^3z^3-x^4y^4z^4");
    p3.createPolinom("-x^8y^8z^8+2x^7y^7z^7-x^6y^6z^6+2x^5y^5z^5");
    p4 = p1 * p2;
    EXPECT_EQ(1, p3 == p4);
}

TEST(TPolinom, cant_multiply_two_polinoms_with_deg_higher_9)
{
    TPolinom p1;
    TPolinom p2;
    TPolinom p3;
    TPolinom p4;
    p1.createPolinom("x^5y^5z^5");
    p2.createPolinom("x^5y^5z^5");
    ASSERT_ANY_THROW(p1 * p2);
   
}

TEST(TPolinom, can_multiply_polinom_on_const)
{
    TPolinom p1;
    TPolinom p2;
    TPolinom p3;
    p1.createPolinom("x^2y^2z^2+x^4y^4z^4");
    p2.createPolinom("5x^2y^2z^2+5x^4y^4z^4");
    p3 = p1 * 5;
    EXPECT_EQ(1, p2 == p3);
}
