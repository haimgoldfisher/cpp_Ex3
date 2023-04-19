#pragma

#include "doctest.h"
#include <stdexcept>
using namespace std;
#include "sources/Fraction.hpp"
using namespace ariel;

/*

A number of preliminary assumptions that I used in my tests:

1) getTop(): getter function that returns the Fraction's numerator.
2) getBottom(): getter function that returns the Fraction's denominator.
   * You can change it to YOUR getters by using "Change All Occurrences" (ctrl+F2).*
3) No empty ctor (= Fraction()).
4) '++' equal to add 1/1 to Fraction: ++1/3 -> 4/3.
5) A Float with more than 3 digits after the dot is not allowed here.
6) Denominator cannot be negative: Fraction(1,-1) -> Fraction(-1,1) , Fraction(-1,-1) -> Fraction(1,1).

*/

TEST_CASE("Fraction Constructor TEST:")
{
    // CREATE FRACTION FROM TWO INTEGERS:
    CHECK_NOTHROW(Fraction(1, 1));
    CHECK_NOTHROW(Fraction(-1, 1));
    CHECK_NOTHROW(Fraction(1, -1));
    CHECK_NOTHROW(Fraction(-1, -1));
    CHECK_THROWS(Fraction(5, 0)); // CANNOT DIVIDE BY ZERO

    // CREATE FRACTION FROM VALID FLOAT (CAST TO FRACTION):
    CHECK_NOTHROW(Fraction(0.5));
    CHECK_NOTHROW(Fraction(-1.25));
    CHECK_NOTHROW(Fraction(0.000));
    CHECK_NOTHROW(Fraction(-0.000));
    CHECK_THROWS(Fraction(0.0000006)); // cannot create a fraction from float with more than 3 digits after the dot
    CHECK_THROWS(Fraction(1/3)); // 0.3333333333... is not valid float
    CHECK_NOTHROW(Fraction(1/2)); // 0.5 is OK
    // CHECK_NOTHROW(Fraction(1/3)); // 0.333333333... is OK
    // CHECK_NOTHROW(Fraction(0.0000006)); // taking only 3 digits after the dot, ignore the rest
}

TEST_CASE("No Negative Denominator TEST:")
{
    // TRUE BY DEFINITION:
    Fraction a(-1,1), b(1,-1), c(-1,-1), d(1,1);
    CHECK((a.getTop() == -1) + (a.getBottom() == 1) == 2); // both must be true since -1/1 == -1/1
    CHECK((b.getTop() == -1) + (b.getBottom() == 1) == 2); // both must be true since 1/-1 == -1/1
    CHECK((c.getTop() == 1) + (c.getBottom() == 1) == 2); // both must be true since -1/-1 == 1/1

    // ALWAYS TRUE:
    CHECK(a == b); // -1/1 == 1/-1
    CHECK(c == d); // -1/-1 == 1/1
}

TEST_CASE("Fractions Equivalence TEST")
{
    // Fraction VS Float:
    Fraction a(1,2);
    CHECK(a == Fraction(2,4)); // 1/2 == 2/4
    CHECK(a == Fraction(3,6)); // 1/2 == 3/6
    CHECK(a == Fraction(4,8)); // 1/2 == 4/8
    CHECK(a == 0.5); // 1/2 == 0.5
    CHECK(0.5 == Fraction(21,42)); // 0.5 == 21/42

    // Fraction Ctors:
    CHECK(a == Fraction(1/2));
    CHECK(a == Fraction(0.5));
}

TEST_CASE("Only Fraction Addition TEST:")
{
    Fraction a(1,2);
    Fraction b = a + Fraction(1,4); // 1/2 + 1/4 = 2/4 + 1/4 = 3/4
    CHECK(Fraction(3,4) == b); // 3/4 == 3/4
    Fraction c = -a; // c = -1/2
    Fraction d = c + a; // -1/2 + 1/2 = 0/2
    CHECK(d == Fraction(0,1)); // 0/2 == 0
}

TEST_CASE("Only Fraction Subtraction TEST:")
{
    Fraction a(1,2), b(1,4);
    Fraction d = a - b; // 1/2 - 1/4 == 1/4
    CHECK(d == b); // 1/4 == 1/4
    Fraction e = a - a; // 1/2 - 1/2 = 0/2
    CHECK(e == Fraction(0,1)); // 0/2 == 0
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
    Fraction d(1,4), e(2,1);
    Fraction f = a / d; // 1/2 / 1/4 = 2/1 = 2
    Fraction g = d / a; // 1/4 / 1/2 = 1/2
    CHECK(f == e);
    CHECK(g == a);
}

TEST_CASE("Fraction Simplifying (Reduced Form) TEST:")
{
    // Assume that arithmetic operations (+,-,*,/) also simplify the fraction:
    Fraction a(2,2); // 2/2 == 1
    Fraction b = a + a; // 2/2 + 2/2 = 4/2 -> (simplify) -> 2/1
    CHECK((b.getTop() == 2) + (b.getBottom() == 1) == 2); // both must be true
    Fraction c(5,20), d(12,24); // 1/4 & 1/2 
    Fraction e = d - c; // 12/24 - 5/20 = 60/120 - 30/120 = 30/120 -> (simplify) -> 1/4
    CHECK((e.getTop() == 1) + (e.getBottom() == 4) == 2); // both must be true
    Fraction f = a / c; // 2/2 / 5/20 = 40/10 -> (simplify) -> 4/1
    CHECK((f.getTop() == 4) + (f.getBottom() == 1) == 2); // both must be true
    Fraction g(-14,21); // -2/3
    Fraction h = g*g; // -14/21 * -14/21 = 196/441 -> (simply) -> 4/9
    CHECK((h.getTop() == 4) + (h.getBottom() == 9) == 2); // both must be true
    Fraction i(0,12); // == 0
    Fraction j = i + i + i; // ((0/12 + 0/12 -> (simplify) -> 0/12 -> 0/1) + 0/12) = 0/1 + 0/12 = 0/12 + 0/12 = 0/12 -> (simplify) -> 0/1 
    CHECK((j.getTop() == 0) + (j.getBottom() == 1) == 2); // both must be true
}

TEST_CASE("Fraction & Float Addition TEST:")
{
    Fraction a(1,2), b(-1,4), c(1,4);
    Fraction d = c + 0.25; // 1/4 + 0.25 = 1/2
    CHECK(a == d); // 1/2 == 1/2
    Fraction e = 0.5 + b; // 0.5 + (-1/4) = 1/4
    CHECK(e == c); // 1/4 == 1/4
    Fraction f(3,4);
    Fraction g = b + 1; // -1/4 + 1 = -1/4 + 4/4 = 3/4
    CHECK(f == g);
    Fraction h = 0 + b; // 0 + -1/4 = -1/4
    CHECK(h == b); // -1/4 == -1/4
}

TEST_CASE("Fraction & Float Subtraction TEST:")
{
    Fraction a(1,2), b(-1,4), c(1,4);
    Fraction d = a - 0.25; // 1/2 - 0.25 = 1/4
    CHECK(c == d); // 1/4 == 1/4
    Fraction e = 0.5 - c; // 0.5 - 1/4 = 1/4
    CHECK(e == c); // 1/4 == 1/4
    Fraction f(3,4);
    Fraction g = f - 1; // -3/4 - 1 = -3/4 + 4/4 = 1/4
    CHECK(c == g);
    Fraction h = 0 - c; // 0 - 1/4 = -1/4
    CHECK(h == b); // -1/4 == -1/4
}

TEST_CASE("Fraction & Float Multiplication TEST:")
{
    Fraction a(1,2), b(1,4), c(-1,2), d(3,2);
    Fraction e = a * 3; // 1/2 * 3 = 3/2
    CHECK(e == d); // 3/2 == 3/2
    Fraction f = 1.5 * b; // 3/2 * 1/4 = 6/4 * 1/4 = 6/16 = 3/8
    Fraction g(3,8);
    CHECK(g == f); //  3/8 == 3/8
    Fraction h = -1 * a; // -1 * 1/2 = -1/2
    Fraction i = c * 1; // -1/2 * 1 = -1/2
    CHECK(h == i);
    Fraction j = 0 * c; // 0 * -1/2 == 0/1
    CHECK(j == 0);
}

TEST_CASE("Fraction & Float Division TEST:")
{
    Fraction a(1,2);
    Fraction b = -a; // -1/2
    CHECK(-0.5 == b);
    CHECK(b == -0.5);
    Fraction c = a/10;
    CHECK(c == 0.05);
    CHECK_THROWS(a/0); // CANNOT DIVIDE BY ZERO
    Fraction d = 0/a;
    CHECK(0 == d);
    Fraction e = a/3; // (1/2 / 3) = (1/2 / 3000/1000) = (1/2 / 3/1) = 1/6
    Fraction f(1,6);
    CHECK(e == f);
    Fraction g = Fraction(1,1)/3; // (1/1 / 3) = (1/1 / 3000/1000) = (1/1 / 3/1) = 1/3
    CHECK(Fraction(1,3) == g);
}

TEST_CASE("Chain Of Operators TEST:")
{
    Fraction a = 0.5 + Fraction(0,1) * 1.7 -0.3; // 0.5 + 0 - 0.3 = 0.2 = 1/5
    CHECK(a == Fraction(1,5));
    Fraction b = Fraction(4,5) + 1 / Fraction(1,2) - 2.25; // 0.8 + 2 - 2.25 = 0.55
    CHECK(Fraction(55,100) == b);
    Fraction c = -2 + Fraction(1,8) * Fraction(4,1) - 0.25; // -2 + 0.5 - 0.25 = -1.75
    CHECK(c == Fraction(-7,4));
}

TEST_CASE("Fraction Equalities TEST:")
{
    Fraction a(1,2), b(1,3), c(2,4), d(-1,2), e(0,1);
    // == :
    CHECK(a == c);
    CHECK(c == a); 
    CHECK(a == 0.5); // 1/2 == 0.5
    CHECK(-0.5 == d);
    CHECK(e == 0);
    CHECK(0 == e);
    // !=
    CHECK(a != b); // 1/2 != 1/3
    CHECK(b != a); 
    CHECK(a != d);
    CHECK(d != a);
    // > , < , >=, >=
    CHECK(d < a); // -1/2 < 1/2
    CHECK(d <= a); // -1/2 >= 1/2
    CHECK(a > d);
    CHECK(a >= d);
    CHECK(a > b);
    CHECK(a >= b); // 1/2 >= 1/3
    CHECK(b < a);
    CHECK(b <= a);
    // && , || , !
    bool a1 = (a > b) && (c == a); // && operator
    bool a2 = (b > 0.333) && (0.334 > b); // tricky: 0.333 < 1/3 < 0.334
    bool a3 = (e < a) || (b > c); // || operator
    bool a4 = !(d > a); // ! operator
    CHECK(a1);  
    CHECK(a2);
    CHECK(a3);
    CHECK(a4);
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
    Fraction prefix(1,2);
    CHECK(++prefix == 1.5); // apply ++ and then return value
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
    Fraction postfix(1,2);
    bool post = (postfix++ == 0.5); // return value and then apply ++ 
    CHECK(post);
}

TEST_CASE("Output Stream TEST:")
{
    Fraction a(1,3), b(-1,1);
    Fraction c = -a;
    CHECK_NOTHROW(cout << "frac a: " << a << endl); // frac a: 1/3
    CHECK_NOTHROW(cout << "frac b: " << b << endl); // frac b: -1/1
}

TEST_CASE("Input Stream TEST:")
{
    istringstream input("1 3");
    Fraction a(1,1);
    CHECK_NOTHROW(input >> a); // update 'a' to 1/3
    CHECK(a.getTop() == 1);
    CHECK(a.getBottom() == 3);

    input.clear();
    string in1 = "-1 2";
    input.str(in1);
    CHECK_NOTHROW(input >> a); // update 'a' to -1/2
    CHECK(a.getTop() == -1);
    CHECK(a.getBottom() == 2);

    input.clear();
    string in2 = "a 1"; // bad input case A (Accept Only Int)
    input.str(in2);
    CHECK_THROWS(input >> a);
    
    input.clear();
    string in3 = "3 1 1"; // bad input case B (Too Many Args)
    input.str(in3);
    CHECK_THROWS(input >> a);

    input.clear();
    string in4 = "1 0"; // bad input case C (Divide By Zero)
    input.str(in4);
    CHECK_THROWS(input >> a);
}

TEST_CASE("Dealing With Illegal Float TEST:")
{
    Fraction a(0,1); // == 0
    float badFloat = 0.00001; // convert to 0/1 or throw excption when try to cast to Fraction???
    // CASE A: Throw Exception:
    CHECK_THROWS(a - badFloat);
    CHECK_THROWS(badFloat + a);

    // CASE B: Cast To 0/1:
    // CHECK(a == badFloat);
    // CHECK_FALSE(badFloat > a);
    // CHECK_NOTHROW(a - badFloat);
    // CHECK_NOTHROW(badFloat + a);
}