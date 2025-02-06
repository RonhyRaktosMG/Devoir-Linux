#include <iostream>
#include <string>


namespace Isa
{
    class Fraction {
    public:
        Fraction(int _num, int _den);
        ~Fraction();
        void display() const;
        std::string toString() const;
        void setNum(int _num);
        void setDen(int _den);
        int getNum();
        int getDen();
        
        Fraction addition (Fraction b);
        Fraction soustract (Fraction b);
        Fraction multiply (Fraction b);
        Fraction divide (Fraction b);

        void simplify();

    private:
        int num, den;
    };
    
} 

