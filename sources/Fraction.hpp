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
        Fraction operator-() const { return Fraction(-this->numerator, this->denominator);}
        Fraction operator+(const Fraction& other) const { return Fraction(this->numerator + other.numerator, this->denominator);} // change it
        friend ostream& operator<< (ostream&, const Fraction&);
        Fraction operator+(const Fraction& other) const { return Fraction(this->numerator + other.numerator, this->denominator);} // change it
        Fraction operator-(const Fraction& other) const { return Fraction(this->numerator - other.numerator, this->denominator);} // change it
        Fraction operator*(const Fraction& other) const { return Fraction(this->numerator * other.numerator, this->denominator);} // change it
        Fraction operator/(const Fraction& other) const { return Fraction(this->numerator / other.numerator, this->denominator);} // change it
        friend const Fraction operator+ (const Fraction& frac, float num) // change it
        {
            return frac.numerator + num;
        }
        friend const Fraction operator- (const Fraction& frac, float num) // change it
        {
            return frac.numerator - num;
        }
        friend const Fraction operator* (const Fraction& frac, float num) // change it
        {
            return frac.numerator * num;
        }
        friend const Fraction operator/ (const Fraction& frac, float num); // since x/y != y/x
        friend const Fraction operator+ (float num, const Fraction& frac)
        {
            return frac + num;
        }
        friend const Fraction operator- (float num, const Fraction& frac)
        {
            return frac - num;
        }
        friend const Fraction operator* (float num, const Fraction& frac)
        {
            return frac * num;
        }
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
        friend bool operator!= (Fraction&, Fraction&);
        friend bool operator> (Fraction&, Fraction&);
        friend bool operator< (Fraction&, Fraction&);
        friend bool operator>= (Fraction&, Fraction&);
        friend bool operator<= (Fraction&, Fraction&);

        friend bool operator== (Fraction&, float);
        friend bool operator!= (Fraction&, float);
        friend bool operator> (Fraction&, float);
        friend bool operator< (Fraction&, float);
        friend bool operator>= (Fraction&, float);
        friend bool operator<= (Fraction&, float);

        friend bool operator== (float num, Fraction& frac) {return frac == num;}
        friend bool operator!= (float num, Fraction& frac) {return frac != num;}
        friend bool operator> (float num, Fraction& frac) {return frac < num;}
        friend bool operator< (float num, Fraction& frac) {return frac > num;}
        friend bool operator>= (float num, Fraction& frac) {return frac <= num;}
        friend bool operator<= (float num, Fraction& frac) {return frac >= num;}
    };
}