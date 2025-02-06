#include "arithmetique.h"


using namespace std;

namespace Isa
{
    Arithm::Arithm () {}   

    Arithm::~Arithm () {}

  


    /* ======= TO COMPLEXE ======== */
    Complexe Arithm::toComplexe(int a) {
        return Complexe(
            Fraction(a, 1), Fraction(0, 1)
        );
    }

    Complexe Arithm::toComplexe(double a) {
        Fraction b(0, 1);
        int decimalDigits = getDecimalDigits(a);
        if (decimalDigits > 0) {
            int denominator = 1;
            for (int i = 0; i < decimalDigits; i++) {
                denominator *= 10;
            }
            b = Fraction(a * denominator, denominator);
        }

        b.simplify();
        return Complexe(
            b, Fraction(0, 1)
        );
    }
    int Arithm::getDecimalDigits(double number) {
    std::string numberString = std::to_string(number);
    size_t decimalPointPos = numberString.find('.');
    if (decimalPointPos != std::string::npos) {
        return numberString.length() - decimalPointPos - 1;
    }
    return 0;
    }

    Complexe Arithm::toComplexe(Fraction a) {
        return Complexe(a, Fraction(0, 1));
    }

    Complexe Arithm::toComplexe(Complexe a) {
        return a;
    }
}

