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

    Fraction::Fraction(float num) // ctor: float
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
        return *this;
    }

    ostream& operator<< (ostream& os, const Fraction& frac) 
    {
        return (os << frac.numerator << '/' << frac.denominator);
    }
}