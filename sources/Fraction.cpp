#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
using namespace std;

#include "Fraction.hpp"

namespace ariel
{
    Fraction::Fraction(int top, int bottom) : numerator(top), denominator(bottom) // initialization list - ctor from 2 ints
    {
        // if (bottom == 0)
        // {
        //     throw logic_error("CANNOT DIVIDE BY ZERO");
        // }
    }

    Fraction::Fraction(float num) : numerator(num*1000), denominator(1000) // initialization list - ctor from a float
    {
        // maybe i should simply this Fraction now
    }

    int Fraction::getNumerator()
    {
        return this->numerator;
    }

    int Fraction::getDenominator()
    {
        return this->denominator;
    }

    void Fraction::setTop(int newTop)
    {
        this->numerator = newTop;
    }

    void Fraction::setBottom(int newBottom)
    {
        this->denominator = newBottom;
    }

    Fraction& Fraction::reduce()
    {
        return *this; // implement later
    }

    ostream& operator<< (ostream& os, const Fraction& frac) 
    {
        return (os << frac.numerator << '/' << frac.denominator);
    }

    istream& operator>> (istream& is, Fraction& frac)
    {
        int numerator, denominator; // implement later
        frac = Fraction(numerator, denominator);
        return is;
    }

    Fraction Fraction::operator+(const Fraction& other) const
    {
        return Fraction(this->numerator + other.numerator, this->denominator + other.denominator); // IMPLEMENTION LATER
    }

    Fraction Fraction::operator-(const Fraction& other) const
    {
        return Fraction(this->numerator - other.numerator, this->denominator - other.denominator); // IMPLEMENTION LATER
    }

    Fraction Fraction::operator*(const Fraction& other) const
    {
        return Fraction(this->numerator - other.numerator, this->denominator - other.denominator); // IMPLEMENTION LATER
    }

    Fraction Fraction::operator/(const Fraction& other) const
    {
        return Fraction(this->numerator - other.numerator, this->denominator - other.denominator); // IMPLEMENTION LATER
    }

    Fraction Fraction::operator+ (float num) const
    {
        return Fraction(this->numerator + num, this->denominator);  // IMPLEMENTION LATER
    }

    Fraction Fraction::operator- (float num) const
    {
        return Fraction(this->numerator / num, this->denominator);  // IMPLEMENTION LATER
    }

    Fraction Fraction::operator* (float num) const
    {
        return Fraction(this->numerator / num, this->denominator);  // IMPLEMENTION LATER
    }

    Fraction Fraction::operator/ (float num) const
    {
        return Fraction(this->numerator / num, this->denominator);  // IMPLEMENTION LATER
    }

    const Fraction operator/ (float num, const Fraction& frac)
    {
        return Fraction(frac.numerator / num, frac.denominator);  // IMPLEMENTION LATER
    }

    bool operator== (const Fraction& frac1, const Fraction& frac2)
    {
        return true;
    }

    bool operator> (const Fraction& frac1, const Fraction& frac2)
    {
        return true;
    }

    bool operator< (const Fraction& frac1, const Fraction& frac2)
    {
        return true;
    }

    bool operator>= (const Fraction& frac1, const Fraction& frac2)
    {
        return true;
    }

    bool operator<= (const Fraction& frac1, const Fraction& frac2)
    {
        return true;
    }

    bool operator== (const Fraction& frac, float num)
    {
        return true;
    }

    bool operator> (const Fraction& frac, float num)
    {
        return true;
    }

    bool operator< (const Fraction& frac, float num)
    {
        return true;
    }

    bool operator>= (const Fraction& frac, float num)
    {
        return true;
    }

    bool operator<= (const Fraction& frac, float num)
    {
        return true;
    }
}