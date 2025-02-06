#include "complexe.h"
#include <typeinfo>
#include <string>
#include <iostream>

using namespace std;

namespace Isa
{
    class Arithm {
        public:
            Arithm();
            ~Arithm();
            
            template <typename T1, typename T2>
            Complexe addition (T1 const& a, T2 const& b) {
                Complexe res = toComplexe(a).addition(toComplexe(b)); 
                res.simplify();
                return res;
            }

            template <typename T1, typename T2>
            Complexe soustract (T1 const& a, T2 const& b) {
                Complexe res = toComplexe(a).soustract(toComplexe(b)); 
                res.simplify();
                return res;
            }

            Complexe toComplexe(int a);
            Complexe toComplexe(double a);
            int getDecimalDigits(double number);
            Complexe toComplexe(Fraction a);
            Complexe toComplexe(Complexe a);
    };
}
