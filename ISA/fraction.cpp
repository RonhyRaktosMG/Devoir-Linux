#include "fraction.h"
#include <iostream>
#include <string>



using namespace std;

namespace Isa
{
   Fraction::Fraction ( int _num, int _den) : num(_num), den(_den) {
    if (den == 0) {
        cout << "ERREUR , 0 Division Error" << endl;
        exit(0);
    }
    }

    Fraction::~Fraction () {

    }

    string Fraction::toString () const {
        string res;
        if (den == 0) {
            return "Zero Division Error";
        } else if (num == 0) {
            return "0";
        } else if (num==den) {
            return "1";
        } else if (den == 1) {
            return to_string(num);
        } else {
        return to_string(num) + "/" + to_string(den);
        }
    }


    void Fraction::display () const {
        cout << toString();
    }

    void Fraction::setNum (int _num) {
        num = _num;
    }
    void Fraction::setDen (int _den) {
        den = _den;
    }
    int Fraction::getNum () {
        return num;
    }
    int Fraction::getDen () {
        return den;
    }

    void Fraction::simplify () {
        int a = num;
        int b = den;
        int r;
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        num = num / a;
        den = den / a;

        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

    Fraction Fraction::addition (Fraction b) {
         Fraction a = Fraction(getNum(), getDen());
         Fraction res(0, 1);
         
        int den_a = a.getDen();
        int den_b = b.getDen();

        a.setNum(a.getNum()*den_b);
        a.setDen(a.getDen()*den_b);

        b.setNum(b.getNum()*den_a);
        b.setDen(b.getDen()*den_a);

        res.setNum( a.getNum() + b.getNum());
        res.setDen(den_a*den_b);

        return res;
    }
    Fraction Fraction::soustract (Fraction b) {
        Fraction a(getNum(), getDen());
        Fraction res(0, 1);
        

        int den_a = a.getDen();
        int den_b = b.getDen();

        a.setNum(a.getNum()*den_b);
        a.setDen(a.getDen()*den_b);

        b.setNum(b.getNum()*den_a);
        b.setDen(b.getDen()*den_a);

        res.setNum( a.getNum() - b.getNum());
        res.setDen(den_a*den_b);

        return res;
    }
    Fraction Fraction::multiply (Fraction b) {
        Fraction a(getNum(), getDen());
        Fraction res(0, 1);

        res.setNum( a.getNum() * b.getNum());
        res.setDen(a.getDen() * b.getDen());

        return res;
    }
    Fraction Fraction::divide (Fraction b) {
        Fraction a(getNum(), getDen());
        Fraction res(0, 1);

        res.setNum( a.getNum() * b.getDen());
        res.setDen(a.getDen() *  b.getNum());

        return res;
    }
}

