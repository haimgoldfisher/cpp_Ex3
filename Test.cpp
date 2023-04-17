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
    Fraction a(1,2), b(1,4), c(3,4), g(0,1);
    Fraction d = a + b; // 1/2 + 1/4 = 2/4 + 1/4 = 3/4
    CHECK(c == d); // 3/4 == 3/4
    Fraction e = -a; // e = -1/2
    Fraction f = e + a; // -1/2 + 1/2 = 0/2
    CHECK(f == g); // 0/2 == 0
}

TEST_CASE("Only Fraction Subtraction TEST:")
{
    Fraction a(1,2), b(1,4), c(0,1);
    Fraction d = a - b; // 1/2 - 1/4 == 1/4
    CHECK(d == b); // 1/4 == 1/4
    Fraction e = a - a; // 1/2 - 1/2 = 0/2
    CHECK(e == c); // 0/2 == 0
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
    Fraction a(1,2), b(1,1);
    Fraction c = a / a; // 1/2 / 1/2 = 1/1
    CHECK(c == b);
    Fraction d(1,4), e(2/1);
    Fraction f = a / d; // 1/2 / 1/4 = 2/1 = 2
    Fraction g = d / a; // 1/4 / 1/2 = 1/2
    CHECK(f == e);
    CHECK(g == a);
}

TEST_CASE("Fraction & Float Addition TEST:")
{

}

TEST_CASE("Fraction & Float Subtraction TEST:")
{

}

TEST_CASE("Fraction & Float Multiplication TEST:")
{

}

TEST_CASE("Fraction & Float Division TEST:")
{
    Fraction a(1/2);
    Fraction b = -a; // -1/2
    CHECK(-0.5 == b);
    CHECK(b == -0.5);
    Fraction c = a/10;
    CHECK(c == 0.05);
    CHECK_THROWS(a/0); // CANNOT DIVIDE BY ZERO
    Fraction d = 0/a;
    CHECK(0 == d);
    Fraction e = a/3; // (1/2 / 3) = (1/2 / 3000/1000) = (1/2 / 3/1) = 1/6
    Fraction f(1/6);
    CHECK(e == f);
    Fraction g(1/1), h(1/3);
    Fraction i = g/3; // (1/1 / 3) = (1/1 / 3000/1000) = (1/1 / 3/1) = 1/3
    CHECK(h == i);
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
    // VERY SIMPLE TESTS:
    Fraction a(1,3), b(2,3), c(4,3);
    Fraction d = ++a; // 1/3++ = 4/3
    CHECK(a == c);
    CHECK_FALSE(a == b);
    Fraction e(0,3), f(2,3);
    Fraction g = -f; // -2/3
    Fraction h = --a;
    CHECK(g == h); // -2/3 == -2/3
    CHECK(g != e);  // -2/3 != 0/3

    // PREFIX METHOD TEST:
    Fraction prefix(1/2);
    CHECK(++prefix == 1.5);
    CHECK(++prefix != prefix);
}

TEST_CASE("Fraction Postfix TEST:")
{
    // VERY SIMPLE TESTS:
    Fraction a(1,3), b(2,3), c(4,3);
    Fraction d = a++; // 1/3++ = 4/3
    CHECK(a == c);
    CHECK_FALSE(a == b);
    Fraction e(0,3), f(2,3);
    Fraction g = -f; // -2/3
    Fraction h = a--;
    CHECK(g == h); // -2/3 == -2/3
    CHECK(g != e);  // -2/3 != 0/3

    // POSTFIX METHOD TEST:
    Fraction postfix(1/2);
    CHECK_NOTHROW(postfix++);
}