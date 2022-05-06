//
// Created by 林大中 on .
//

#include "BSModel.h"


BSModel::BSModel(const double s, const double k, const double r, const double q, const double sigma, const double t,
                 const char whichOption) : S(s), K(k), r(r), q(q), sigma(sigma), T(t), whichOption(whichOption) {}

BSModel::~BSModel() {

}

double BSModel::getOptionPrice() {
    // for call
    if (whichOption == 'C'){

        return S * exp(-q * T) * rvN(d1) - K * exp(-r * T) * rvN(d2);
    }
    // for put
    else if (whichOption == 'P'){
        return -S * exp(-q * T) * rvN(-d1) + K * exp(-r * T) * rvN(-d2);
    }

    else{
        cerr << "Error!!" << endl;
        return 0;
    }
}
