#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

#include "Fraction.hpp"

#define MAX_INT numeric_limits<int>::max()
#define MIN_INT numeric_limits<int>::min()

namespace ariel
{
    Fraction::Fraction(int top, int bottom) : numerator(top), denominator(bottom) // initialization list - ctor from 2 ints
    {
        if (bottom == 0)
        {
            throw invalid_argument("CANNOT DIVIDE BY ZERO");
        }
        this->reduce();
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
        int gcd = __gcd(this->numerator, this->denominator);
        if (abs(gcd) != 1) // so we can simply the fraction
        {
            this->numerator = this->numerator / gcd;
            this->denominator = this->denominator / gcd;
        }
        if (this->denominator < 0) // so the denominator will be positive
        {
            this->numerator = -this->numerator;
            this->denominator = -this->denominator;
        }
        return *this;
    }

    ostream& operator<< (ostream& os, const Fraction& frac) 
    {
        return (os << frac.numerator << '/' << frac.denominator);
    }

    istream& operator>> (istream& is, Fraction& frac)
    {
        int numo, deno;
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

    long long __lcm(int a, int b) // Lowest Common Multiple, for efficient +/- operations
    {
        return ((long long)a*b) / __gcd(a, b);
    }

    void overFlowCheck(long long numerator, long long denominator) // it checks over flow cases
    {
        if (numerator > MAX_INT || denominator > MAX_INT)
        {
            throw overflow_error("OVERFLOW ERROR");
        }
        if (numerator < MIN_INT || denominator < MIN_INT)
        {
            throw overflow_error("OVERFLOW ERROR");
        }
    }

    Fraction Fraction::operator+(const Fraction& other) const
    {
        long long lcm = __lcm(this->denominator, other.denominator);
        long long numo = (long long)this->numerator * (lcm / this->denominator) + (long long)other.numerator * (lcm / other.denominator);
        overFlowCheck(numo, lcm);
        return Fraction((int)numo, (int)lcm).reduce();
    }

    Fraction Fraction::operator-(const Fraction& other) const
    {
        long long lcm = __lcm(this->denominator, other.denominator);
        long long numo = (long long)this->numerator * (lcm / this->denominator) - (long long)other.numerator * (lcm / other.denominator);
        overFlowCheck(numo, lcm);
        return Fraction((int)numo, (int)lcm).reduce();
    }

    Fraction Fraction::operator*(const Fraction& other) const
    {
        long long numo = (long long)this->numerator * other.numerator;
        long long deno = (long long)this->denominator * other.denominator;
        overFlowCheck(numo, deno);
        return Fraction((int)numo, (int)deno).reduce();
    }

    Fraction Fraction::operator/(const Fraction& other) const
    {
        if (other == 0)
        {
            throw runtime_error("CANNOT DIVIDE BY ZERO");
        }
        long long numo = (long long)this->numerator * other.denominator;
        long long deno = (long long)this->denominator * other.numerator;
        overFlowCheck(numo, deno);
        return Fraction((int)numo, (int)deno).reduce();
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