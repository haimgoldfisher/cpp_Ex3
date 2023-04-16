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
        int getTop(); // numerator getter
        int getBottom(); // denominator getter
        void setTop(int newTop); // numerator setter
        void setBottom(int newBottom); // denominator setter
    }
}