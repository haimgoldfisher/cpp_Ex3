#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;


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

        friend ostream& operator<< (ostream&, const Fraction&); // for output stream 
        friend istream& operator>> (istream&, Fraction&); // for input stream

        Fraction operator+(const Fraction&) const;
        Fraction operator-(const Fraction&) const;
        Fraction operator*(const Fraction&) const;
        Fraction operator/(const Fraction&) const;

        Fraction operator+ (float num) const {return *this + Fraction(num);}
        Fraction operator- (float num) const {return *this + -num;}
        Fraction operator* (float num) const {return *this * Fraction(num);}
        Fraction operator/ (float num) const {return *this / Fraction(num);}

        friend Fraction operator+ (float num, const Fraction& frac){return frac + num;}
        friend Fraction operator- (float num, const Fraction& frac){return -frac + num;}
        friend Fraction operator* (float num, const Fraction& frac){return Fraction(num) * frac;}
        friend Fraction operator/ (float num, const Fraction& frac){return Fraction(num) / frac;}

        Fraction& operator++(); // prefix
        Fraction operator++(int); // postfix
        Fraction& operator--(); // prefix
        Fraction operator--(int); // postfix

        bool operator==(const Fraction&) const;
        bool operator!=(const Fraction& other) const {return !(*this == other);}
        bool operator>(const Fraction&) const;
        bool operator<(const Fraction&) const;
        bool operator>=(const Fraction& other) const {return !(*this < other);}
        bool operator<=(const Fraction& other) const {return !(*this > other);}

        bool operator==(float) const;
        bool operator!=(float num) const {return !(*this == num);}
        bool operator>(float) const;
        bool operator<(float) const;
        bool operator>=(float num) const {return !(*this < num);}
        bool operator<=(float num) const {return !(*this > num);}

        friend bool operator== (float num, const Fraction& frac) {return Fraction(num) == frac;}
        friend bool operator!= (float num, const Fraction& frac) {return !(Fraction(num) == frac);}
        friend bool operator> (float num, const Fraction& frac) {return Fraction(num) > frac;}
        friend bool operator< (float num, const Fraction& frac) {return Fraction(num) < frac;}
        friend bool operator>= (float num, const Fraction& frac) {return Fraction(num) >= frac;}
        friend bool operator<= (float num, const Fraction& frac) {return Fraction(num) <= frac;}
    };

    long long __lcm(int, int); // Lowest Common Multiple
    void overFlowCheck(long long, long long); // OverFlow Checking
}