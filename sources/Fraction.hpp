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
        Fraction(int, int); // ctor using int for numerator & int for denominator
        Fraction(float); // ctor for creating a fraction from a float
        int getTop(); // numerator getter
        int getBottom(); // denominator getter
        void setTop(int newTop); // numerator setter
        void setBottom(int newBottom); // denominator setter
        Fraction& reduce(); // it simplies the frac 
        Fraction operator-() const { return Fraction(-this->numerator, this->denominator);} // form of -n/m
        friend ostream& operator<< (ostream&, const Fraction&); // for output stream 
        friend istream& operator>> (istream&, const Fraction&); // for input stream
        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator/(const Fraction& other) const;
        friend const Fraction operator+ (const Fraction& frac, float num);
        friend const Fraction operator- (const Fraction& frac, float num);
        friend const Fraction operator* (const Fraction& frac, float num);
        friend const Fraction operator/ (const Fraction& frac, float num);
        friend const Fraction operator+ (float num, const Fraction& frac){return frac + num;}
        friend const Fraction operator- (float num, const Fraction& frac){return frac - num;}
        friend const Fraction operator* (float num, const Fraction& frac){return frac * num;}
        friend const Fraction operator/ (float num, const Fraction& frac); // since x/y != y/x
        Fraction& operator++() // prefix
        {
            this->numerator++;
            return *this;
        }
        Fraction operator++(int postfixFlag) // postfix
        {
            Fraction copy = *this;
            this->numerator++;
            return copy;
        }
        Fraction& operator--() // prefix
        {
            this->numerator--;
            return *this;
        }
        Fraction operator--(int postfixFlag) // postfix
        {
            Fraction copy = *this;
            this->numerator--;
            return copy;
        }
        friend bool operator== (Fraction&, Fraction&);
        friend bool operator!= (Fraction& frac1, Fraction& frac2) {return !(frac1==frac2);}
        friend bool operator> (Fraction&, Fraction&);
        friend bool operator< (Fraction&, Fraction&);
        friend bool operator>= (Fraction&, Fraction&);
        friend bool operator<= (Fraction&, Fraction&);

        friend bool operator== (Fraction&, float);
        friend bool operator!= (Fraction& frac, float num) {return !(frac == num);}
        friend bool operator> (Fraction&, float);
        friend bool operator< (Fraction&, float);
        friend bool operator>= (Fraction&, float);
        friend bool operator<= (Fraction&, float);

        friend bool operator== (float num, Fraction& frac) {return frac == num;}
        friend bool operator!= (float num, Fraction& frac) {return !(frac == num);}
        friend bool operator> (float num, Fraction& frac) {return frac < num;}
        friend bool operator< (float num, Fraction& frac) {return frac > num;}
        friend bool operator>= (float num, Fraction& frac) {return frac <= num;}
        friend bool operator<= (float num, Fraction& frac) {return frac >= num;}
    };
}