#include <iostream>
#include "arithmetique.h"

using namespace std;
using namespace Isa;

ostream& operator<<( ostream& flux, Fraction const& fraction ){
    fraction.display();
    return flux;
}
Fraction operator+(Fraction a, Fraction b){
   return a.addition(b);
}
Fraction operator-(Fraction a, Fraction b){
    return a.soustract(b);
}
Fraction operator*(Fraction a, Fraction b){
    return a.multiply(b);    
}
Fraction operator/(Fraction a, Fraction b){
    return a.divide(b);
}


ostream& operator<<( ostream& flux, Complexe const& complexe ){
    complexe.display();
    return flux;
}
Complexe operator+(Complexe a ,Complexe b) {
    return a.addition(b);
}
Complexe operator-(Complexe a ,Complexe b) {
    return a.soustract(b);
}




int main () {

    Fraction f1 = Fraction(2, 3);
    Fraction f2 = Fraction(3, 2);
    Fraction f3 = Fraction(1, 2);
    Fraction f4 = Fraction(1, 3);
    
    // cout << "addition de " << f1 << " + " << f2 << " = " <<  f1 + f2 << endl;
    // cout << "soustraction de " << f1 << " - " << f2 << " = " <<  f1 - f2 << endl;
    // cout << "produit de " << f1 << " * " << f2 << " = " <<  f1 * f2 << endl;
    // cout << "division de " << f1 << " / " << f2 << " = " <<  f1 / f2 << endl;
    

   

    Complexe c1 = Complexe(f1, f2);
    Complexe c2 = Complexe(f3, f4);

    /*     
    cout << "addition de " << c1 << " + " << c2 << " = " << c1 + c2 << " \n";
    cout << "soustraction de " << c1 << " - " << c2 << " = " <<  c1 - c2 << " \n";
    */

    Arithm a;

    cout << a.addition(1.5, c2) << endl;


    return 0;

}