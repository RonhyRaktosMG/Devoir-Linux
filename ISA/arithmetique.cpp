#include "arithmetique.h"


using namespace std;

namespace Isa
{
    Arithm::Arithm () {}   

    Arithm::~Arithm () {}

    Complexe Arithm::addition_complexe (Complexe a, Complexe b) {
        return a.addition(b);
    }
    Complexe Arithm::soustract_complexe (Complexe a, Complexe b) {
        return a.soustract(b);
    }

}
