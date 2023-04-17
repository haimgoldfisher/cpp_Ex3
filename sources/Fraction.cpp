#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
using namespace std;

#include "Fraction.hpp"

namespace ariel
{
    Fraction::Fraction(int top, int bottom) // ctor: numerator & denominator
    {
        // if (bottom == 0)
        // {
        //     throw logic_error("CANNOT DIVIDE BY ZERO");
        // }
        this->numerator = top;
        this->denominator = bottom;
    }

    Fraction::Fraction(float num) // ctor: float casting to fraction
    {
        this->numerator = this->denominator = num;
    }

    int Fraction::getTop()
    {
        return this->numerator;
    }

    int Fraction::getBottom()
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

    istream& operator>> (istream& is, const Fraction& frac)
    {
        return is;  // implement later
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

    const Fraction operator+ (const Fraction& frac, float num)
    {
        return Fraction(frac.numerator + num, frac.denominator);  // IMPLEMENTION LATER
    }

    const Fraction operator- (const Fraction& frac, float num)
    {
        return Fraction(frac.numerator / num, frac.denominator);  // IMPLEMENTION LATER
    }

    const Fraction operator* (const Fraction& frac, float num)
    {
        return Fraction(frac.numerator / num, frac.denominator);  // IMPLEMENTION LATER
    }

    const Fraction operator/ (const Fraction& frac, float num)
    {
        return Fraction(frac.numerator / num, frac.denominator);  // IMPLEMENTION LATER
    }

    const Fraction operator/ (float num, const Fraction& frac)
    {
        return Fraction(frac.numerator / num, frac.denominator);  // IMPLEMENTION LATER
    }

    bool operator== (Fraction& frac1, Fraction& frac2)
    {
        return true;
    }

    bool operator> (Fraction& frac1, Fraction& frac2)
    {
        return true;
    }

    bool operator< (Fraction& frac1, Fraction& frac2)
    {
        return true;
    }

    bool operator>= (Fraction& frac1, Fraction& frac2)
    {
        return true;
    }

    bool operator<= (Fraction& frac1, Fraction& frac2)
    {
        return true;
    }

    bool operator== (Fraction& frac, float num)
    {
        return true;
    }

    bool operator> (Fraction& frac, float num)
    {
        return true;
    }

    bool operator< (Fraction& frac, float num)
    {
        return true;
    }

    bool operator>= (Fraction& frac, float num)
    {
        return true;
    }

    bool operator<= (Fraction& frac, float num)
    {
        return true;
    }
}