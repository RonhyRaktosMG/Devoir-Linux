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
            

            Complexe addition_complexe (Complexe a, Complexe b); 
            Complexe soustract_complexe (Complexe a, Complexe b); 

            template <typename T>
            void toComplexe(T a){
                string var_type = typeid(a).name();
                cout << var_type;
            }
    };
}
