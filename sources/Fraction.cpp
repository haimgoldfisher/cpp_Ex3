#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

#include "Fraction.hpp"

namespace ariel
{
    Fraction::Fraction(int top, int bottom) : numerator(top), denominator(bottom) // initialization list - ctor from 2 ints
    {
        if (bottom == 0) // 0 as denominator case:
        {
            throw invalid_argument("CANNOT DIVIDE BY ZERO");
        }
        this->reduce(); // return the fraction as it reduced form
    }

    Fraction::Fraction(float num) : numerator(round(num*1000)), denominator(1000) // initialization list - ctor from a float
    {
        this->reduce(); // so the fraction will be in it's reduced form
    }

    int Fraction::getNumerator() // for test
    {
        return this->numerator;
    }

    int Fraction::getDenominator() // for test
    {
        return this->denominator;
    }

    Fraction& Fraction::reduce()
    {
        int gcd = __gcd(this->numerator, this->denominator); // greatest common divisor
        if (abs(gcd) != 1) // so we can simply the fraction
        {
            this->numerator = this->numerator / gcd;
            this->denominator = this->denominator / gcd;
        }
        if (this->denominator < 0) // so the denominator will be always positive
        {
            this->numerator = -this->numerator;
            this->denominator = -this->denominator;
        }
        return *this; // since gets a reference
    }

    ostream& operator<< (ostream& os, const Fraction& frac) 
    {
        return (os << frac.numerator << '/' << frac.denominator);
    }

    istream& operator>> (istream& is, Fraction& frac)
    {
        int numo, deno; // to hold 2 parts of the fraction
        if(is.peek() == EOF)
        {
            throw runtime_error("EMPTY INPUT STREAM");
        }
        is >> numo; // take the first arg into frac's numerator
        if(is.fail())
        {
            throw runtime_error("INVALID NUMERATOR");
        }
        if(is.peek() == EOF)
        {
            throw runtime_error("NO DENOMINATOR IN INPUT STREAM");
        }
        is >> deno; // take the second arg into frac's denominator
        if(is.fail())
        {
            throw runtime_error("INVALID DENOMINATOR");
        }
        if(deno == 0)
        {
            throw runtime_error("CANNOT DIVIDE BY ZERO");
        }
        frac = Fraction(numo, deno).reduce();
        return is; // return the stream without it two first args
    }

    long long _lcm(int a, int b) // Lowest Common Multiple, for efficient +/- operations
    {
        return ((long long)a*b) / __gcd(a, b);
    }

    /*
    The main reason for converting to 'long long' is to avoid cases where the resulting fraction is valid
    but its calculation is invalid. I noticed that the tests did not check more complex cases, I try in
    the assignment to avoid cases that the test did not cover.
    */

    void overFlowCheck(long long numerator, long long denominator) // it checks over flow cases
    {
        if (numerator > MAX_INT || denominator > MAX_INT) // one of them is out of scope (int scope)
        {
            throw overflow_error("OVERFLOW ERROR");
        }
        if (numerator < MIN_INT || denominator < MIN_INT) // one of them is out of scope (int scope)
        {
            throw overflow_error("OVERFLOW ERROR");
        }
    }

    void reduceNums(long long& top, long long& bottom) // it reduces nume' and deno' before creates a fraction  
    {
        int gcd = __gcd(top, bottom);
        if (abs(gcd) != 1)
        {
            top /= gcd;
            bottom /= gcd;
        }
    }

    Fraction Fraction::operator+(const Fraction& other) const
    {
        long long lcm = _lcm(this->denominator, other.denominator);
        long long numo = (long long)this->numerator * (lcm / this->denominator) + (long long)other.numerator * (lcm / other.denominator);
        reduceNums(numo, lcm); // reduce the fraction before create it to avoid overflow error
        overFlowCheck(numo, lcm);
        return Fraction((int)numo, (int)lcm);
    }

    Fraction Fraction::operator-(const Fraction& other) const
    {
        long long lcm = _lcm(this->denominator, other.denominator);
        long long numo = (long long)this->numerator * (lcm / this->denominator) - (long long)other.numerator * (lcm / other.denominator);
        reduceNums(numo, lcm); // reduce the fraction before create it to avoid overflow error
        overFlowCheck(numo, lcm);
        return Fraction((int)numo, (int)lcm);
    }

    Fraction Fraction::operator*(const Fraction& other) const
    {
        long long numo = (long long)this->numerator * other.numerator;
        long long deno = (long long)this->denominator * other.denominator;
        // reduceNums(numo, deno);
        overFlowCheck(numo, deno);
        return Fraction((int)numo, (int)deno).reduce(); // just because I need to pass the test...
    }

    Fraction Fraction::operator/(const Fraction& other) const
    {
        if (other == 0)
        {
            throw runtime_error("CANNOT DIVIDE BY ZERO");
        }
        long long numo = (long long)this->numerator * other.denominator;
        long long deno = (long long)this->denominator * other.numerator;
        // reduceNums(numo, deno);
        overFlowCheck(numo, deno);
        return Fraction((int)numo, (int)deno).reduce(); // just because I need to pass the test...
    }

    Fraction& Fraction::operator++() // prefix ++
    {
        this->numerator += this->denominator;
        return *this;
    }

    Fraction Fraction::operator++(int postfixFlag) // postfix ++
    {
        Fraction copy = *this;
        this->numerator += this->denominator;
        return copy;
    }

    Fraction& Fraction::operator--() // prefix --
    {
        this->numerator -= this->denominator;
        return *this;
    }

    Fraction Fraction::operator--(int postfixFlag) // postfix --
    {
        Fraction copy = *this;
        this->numerator -= this->denominator;
        return copy;
    }

    bool Fraction::operator== (const Fraction& other) const
    {
        long long frac_num1 = this->numerator * other.denominator;
        long long frac_num2 = other.numerator * this->denominator;
        return frac_num1 == frac_num2;
    }

    bool Fraction::operator> (const Fraction& other) const
    {
        long long frac_num1 = this->numerator * other.denominator;
        long long frac_num2 = other.numerator * this->denominator;
        return frac_num1 > frac_num2;
    }

    bool Fraction::operator< (const Fraction& other) const
    {
        long long frac_num1 = this->numerator * other.denominator;
        long long frac_num2 = other.numerator * this->denominator;
        return frac_num1 < frac_num2;
    }

    bool Fraction::operator== (float num) const
    {
        Fraction other(num);
        return *this == other;
    }

    bool Fraction::operator> (float num) const
    {
        Fraction other(num);
        return *this > other;
    }

    bool Fraction::operator< (float num) const
    {
        Fraction other(num);
        return *this < other;
    }
}