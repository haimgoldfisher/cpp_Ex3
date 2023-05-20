/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    Fraction a(5,3), b(14,21);
    cout << "a: " << a << "b: " << b << endl;
    cout << "a+b" << a+b << endl; 
    cout << "a-b" << a-b << endl; 
    cout << "a/b" << a/b << endl; 
    cout << "a*b" << a*b << endl; 
    cout << "2.3*b" << 2.3*b << endl; 
    cout << "a+2.421" << a+2.421 << endl; 
    Fraction c = a+b-1;
    cout << c++ << endl;
    cout << --c << endl;

    cout << "c >=b ? : " << (c >= b) << endl;
    if (a > 1.1) cout << " a is bigger than 1.1" << endl;
    else cout << " a is smaller than 1.1" << endl;

    // My demo:
    cout << endl << "*** MY DEMO ***" << endl << endl;

    cout << endl << "Ctors Check:" << endl;
    cout << "Fraction(): Should print 0/1 and print: " << Fraction() << " " << endl;
    cout << "Fraction(int, int): Should print 1/2 and print: " << Fraction(1,2) << " " << endl;
    cout << "Fraction(float): Should print 333/1000 and print: " << Fraction(0.333) << " " << endl;

    cout << endl << "LCM function (self check):" << endl;
    cout << "The LCM of 4 & 6 is: " << ariel::_lcm(4, 12) << " (should return 12)" << endl;
    cout << "The LCM of 4 & 2 is: " << ariel::_lcm(4, 2) << " (should return 4)" << endl;
    cout << "The LCM of 5 & 7 is: " << ariel::_lcm(5, 7) << " (should return 35)" << endl;
    cout << "The LCM of 10 & 10 is: " << ariel::_lcm(10, 10) << " (should return 10)" << endl;

    Fraction my(1,2);
    cout << endl << "+ OPERATOR:" << endl;
    cout << "1/2 + 1/2 = " << my + my << " (should return 1/1)" << endl;
    cout << "-1/-2 + -1/-2 = " << Fraction(-1,-2) + Fraction(-1,-2) << " (should return 1/1)" << endl;
    cout << "1/2 + 0.25 = " << my + 0.25 << " (should return 3/4)" << endl;
    cout << "0.25 + 1/2 = " << 0.25 + my << " (should return 3/4)" << endl;

    cout << endl << "- OPERATOR:" << endl;  
    cout << "1/2 - 1/2 = " << my - my << " (should return 0/1)" << endl;
    cout << "1/2 - 1/-2 = " << my - Fraction(1,-2) << " (should return 1/1)" << endl; 
    cout << "1/2 - -1/2 = " << my - -my << " (should return 1/1)" << endl;
    cout << "1/2 - 0.25 = " << my - 0.25 << " (should return 1/4)" << endl;
    cout << "0.1 - -5/9 = " << 0.1 - Fraction(-5,9) << " (should return 59/90)" << endl; 
    cout << "-1/4 - -0.8 = " << Fraction(-1,4) - -0.8 << " (should return 11/20)" << endl;  

    cout << endl << "* OPERATOR:" << endl;
    cout << "5/1 * 2/1 = " << Fraction(5,1) * Fraction(2,1) << " (should return 10/1)" << endl;
    cout << "1/3 * -2/6 = " << Fraction(1,3) * Fraction(-2,6) << " (should return -1/9)" << endl;
    cout << "1/3 * 3 = " << Fraction(1,3) * 3 << " (should return 1/1)" << endl;
    cout << "-0.25 * -2/4 = " << -0.25 * -Fraction(2,4) << " (should return 1/8)" << endl;

    cout << endl << "/ OPERATOR:" << endl;
    cout << "1/3 / 3/1 = " << Fraction(1,3) / Fraction(3,1) << " (should return 1/9)" << endl;
    cout << "1/2 / 2 = " << my / 2 << " (should return 1/4)" << endl;
    cout << "3 / 1/4 = " << 3 / Fraction(1,4) << " (should return 12/1)" << endl;
    cout << "1/3 / -1 = " << Fraction(1,3) / -1 << " (should return -1/3)" << endl;
    cout << "-1/2 / 0.5 = " << -my / 0.5 << " (should return -1/1)" << endl;   

    cout << endl << "OVERFLOW DEMO:" << endl;
    cout << "max_int() / max_int()-1 * max_int() / max_int()-1 = ";
    try
    {
        cout << Fraction(MAX_INT, MAX_INT-1) * Fraction(MAX_INT, MAX_INT-1);
    }
    catch(const exception& e)
    {
        cerr << e.what();
    }
    cout << " (should return OVERFLOW ERROR)" << endl;
     

}