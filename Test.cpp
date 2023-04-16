#pragma

#include "doctest.h"
#include <stdexcept>

#include "sources/Fraction.hpp"
using namespace ariel;

TEST_CASE("Fraction Constructor TEST:")
{
    CHECK_NOTHROW(Fraction(1, 1));
    CHECK_NOTHROW(Fraction(-1, 1));
    CHECK_NOTHROW(Fraction(1, -1));
    CHECK_NOTHROW(Fraction(-1, -1));
    CHECK_THROWS(Fraction(5, 0)); // CANNOT DIVIDE BY ZERO
}

TEST_CASE("Fraction Simplifying (Reducing) TEST:")
{
    Fraction a(1,2), b(2,4), c(3,6), d(4,8);
    CHECK_EQ(a, b); // 1/2 == 2/4
    CHECK_EQ(a, c); // 1/2 == 3/6
    CHECK_EQ(a, d); // 1/2 == 4/8
}

TEST_CASE("Fraction Addition TEST:")
{
    Fraction a(1,2), b(1,4), c(3,4);
    CHECK_EQ((a + b), c); // 1/2 + 1/4 = 2/4 + 1/4 = 3/4
    CHECK_EQ((a + a), 1); // 1/2 + 1/2 = 2/2 = 1
}