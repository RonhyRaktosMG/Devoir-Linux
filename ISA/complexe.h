#include "fraction.h"

namespace Isa
{
 class Complexe {
    public:
        Complexe(Fraction _reel, Fraction _img);
        ~Complexe();

        void display() const;
        void setReel(Fraction _reel);
        void setImg(Fraction _img);
        Fraction getReel();
        Fraction getImg();

        void simplify ();

        Complexe addition(Complexe b);
        Complexe soustract(Complexe b);

    private:
        Fraction reel, img;
};   
}