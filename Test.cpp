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
    CHECK(a == b); // 1/2 == 2/4
    CHECK(a == c); // 1/2 == 3/6
    CHECK(a == d); // 1/2 == 4/8
    CHECK(a == 0.5); // 1/2 == 0.5
    CHECK(0.5 == b); // 0.5 == 2/4
}

TEST_CASE("Only Fraction Addition TEST:")
{
    Fraction a(1,2), b(1,4), c(3,4);
    Fraction d = a + b; // 1/2 + 1/4 = 2/4 + 1/4 = 3/4
    CHECK(c == d); // 3/4 == 3/4
    Fraction e = -a; // e = -1/2
    Fraction f = e + a; // -1/2 + 1/2 = 0/2
    CHECK(f == 0); // 0/2 == 0
}

TEST_CASE("Only Fraction Subtraction TEST:")
{
    Fraction a(1,2), b(1,4), c(0,1);
    Fraction d = a - b; // 1/2 - 1/4 == 1/4
    CHECK(d == b); // 1/4 == 1/4
    Fraction e = a - a; // 1/2 - 1/2 = 0/2
    CHECK(e == 0); // 0/2 == 0
}

TEST_CASE("Only Fraction Multiplication TEST:")
{
    Fraction a(1,2), b(1,4), c(3,5), d(9,25);
    Fraction e = a * a; // 1/2 * 1/2 = 1/4
    CHECK(e == b); // 1/4 == 1/4
    Fraction f = c * d; // 3/5 * 3/5 = 9/25
    CHECK(f == d); // 9/25 == 9/25
    Fraction h = -a; // -1/2
    Fraction i = a * h; // -1/2 * 1/2 = -1/4
    CHECK(i != b); // -1/4 != 1/4
    Fraction j = h * h; // -1/2 * -1/2 = 1/4
    CHECK(b == j); // 1/4 == 1/4
}

TEST_CASE("Only Fraction Division TEST:") 
{

}

TEST_CASE("Fraction & Integer Addition TEST:")
{

}

TEST_CASE("Fraction & Integer Subtraction TEST:")
{

}

TEST_CASE("Fraction & Integer Division TEST:")
{

}

TEST_CASE("Fraction & Integer Subtraction TEST:")
{

}

TEST_CASE("Fraction & Float Addition TEST:")
{

}

TEST_CASE("Fraction & Float Subtraction TEST:")
{

}

TEST_CASE("Fraction & Float Division TEST:")
{

}

TEST_CASE("Fraction & Float Subtraction TEST:")
{

}

TEST_CASE("Fraction Equalities TEST:")
{
    Fraction a(1,2), b(1,3);
    Fraction c = -a; // -1/2
    CHECK(a > c); // 1/2 > -1/2
    CHECK(a >= 0.5);
    CHECK(0.5 == a);
    CHECK(a <= 0.5);
    CHECK_FALSE(!(b < a));
    CHECK(c <= b);
    CHECK((a > b) + (c < b) == 2); // both true
}

TEST_CASE("Fraction Prefix TEST:")
{
    
}

TEST_CASE("Fraction Postfix TEST:")
{

}