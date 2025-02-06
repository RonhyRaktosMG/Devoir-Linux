#include "complexe.h"
#include <iostream>
#include <string>

using namespace std;


namespace Isa
{
    Complexe::Complexe(Fraction _reel, Fraction _img) : reel(_reel), img(_img) {

    }

    Complexe::~Complexe() {

    }

    void Complexe::display () const {
        string str_reel = reel.toString();
        string str_img = img.toString();
        string output;
        if (str_reel == "0" && str_img == "0") {
            output = "0";
            return;
        }
        else {
            if (str_reel != "0") {
                output += str_reel;
            }
            if (str_img != "0") {
                if (!output.empty()) {
                    output += " + ";
                }
                if (str_img != "1"){
                    output += str_img;
                }
                output += "i";
            }
        }

        cout << "( " << output << " )";
    }

    void Complexe::setReel (Fraction _reel) {
        reel = _reel;
    }
    void Complexe::setImg (Fraction _img) {
        img = _img;
    }
    Fraction Complexe::getReel () {
        return reel;
    }
    Fraction Complexe::getImg () {
        return img;
    }

    void Complexe::simplify () {
        reel.simplify();
        img.simplify();
    }
    
    Complexe Complexe::addition (Complexe b){
        return Complexe(
            getReel().addition(b.getReel()),
            getImg().addition(b.getImg())    
        );
    }
    Complexe Complexe::soustract (Complexe b){
        return Complexe(
            getReel().soustract(b.getReel()),
            getImg().soustract(b.getImg())    
        );
    }
}
