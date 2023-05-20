#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
using namespace std;

constexpr int MAX_INT = numeric_limits<int>::max(); // for overflow
constexpr int MIN_INT = numeric_limits<int>::min(); // for overflow

namespace ariel
{
    class Fraction
    {
        int numerator; // top part of fraction
        int denominator; // bottom part of fraction

        public:
        Fraction(): numerator(0), denominator(1) {}; // default ctor: 0/1
        Fraction(int, int); // ctor using int for numerator & int for denominator
        Fraction(float); // ctor for creating a fraction from a float
        int getNumerator(); // numerator getter - for test
        int getDenominator(); // denominator getter - for test
        Fraction& reduce(); // it simplies the frac 
        Fraction operator-() const { return Fraction(-this->numerator, this->denominator).reduce();} // form of -n/m

        // I/O Stream:
        friend ostream& operator<< (ostream&, const Fraction&); // for output stream 
        friend istream& operator>> (istream&, Fraction&); // for input stream

        // Fraction <Arithmetic Operator> Fraction:
        Fraction operator+(const Fraction&) const;
        Fraction operator-(const Fraction& frac) const;
        Fraction operator*(const Fraction&) const;
        Fraction operator/(const Fraction&) const;

        // Fraction <Arithmetic Operator> Float:
        Fraction operator+ (float num) const {return *this + Fraction(num);}
        Fraction operator- (float num) const {return *this + -num;}
        Fraction operator* (float num) const {return *this * Fraction(num);}
        Fraction operator/ (float num) const {return *this / Fraction(num);}

        // Float <Arithmetic Operator> Fraction:
        friend Fraction operator+ (float num, const Fraction& frac){return frac + num;}
        friend Fraction operator- (float num, const Fraction& frac){return -frac + num;}
        friend Fraction operator* (float num, const Fraction& frac){return Fraction(num) * frac;}
        friend Fraction operator/ (float num, const Fraction& frac){return Fraction(num) / frac;}

        // ++ & -- :
        Fraction& operator++(); // prefix
        Fraction operator++(int); // postfix
        Fraction& operator--(); // prefix
        Fraction operator--(int); // postfix

        // Fraction <Boolean Operator> Fraction:
        bool operator==(const Fraction&) const;
        bool operator!=(const Fraction& other) const {return !(*this == other);}
        bool operator>(const Fraction&) const;
        bool operator<(const Fraction&) const;
        bool operator>=(const Fraction& other) const {return !(*this < other);}
        bool operator<=(const Fraction& other) const {return !(*this > other);}

        // Fraction <Boolean Operator> Float:
        bool operator==(float) const;
        bool operator!=(float num) const {return !(*this == num);}
        bool operator>(float) const;
        bool operator<(float) const;
        bool operator>=(float num) const {return !(*this < num);}
        bool operator<=(float num) const {return !(*this > num);}

        // Float <Boolean Operator> Fraction:
        friend bool operator== (float num, const Fraction& frac) {return Fraction(num) == frac;}
        friend bool operator!= (float num, const Fraction& frac) {return !(num == frac);}
        friend bool operator> (float num, const Fraction& frac) {return Fraction(num) > frac;}
        friend bool operator< (float num, const Fraction& frac) {return Fraction(num) < frac;}
        friend bool operator>= (float num, const Fraction& frac) {return !(num < frac);}
        friend bool operator<= (float num, const Fraction& frac) {return !(num > frac);}
    };

    // Helper Functions:
    long long _lcm(int, int); // Lowest Common Multiple
    void overFlowCheck(long long, long long); // OverFlow Checking
    void reduceNums(long long&, long long&); // Avoid OverFlow Error
}