//
// Created by 林大中 on .
//

#ifndef IMPLIEDVOLATILITY_BSMODEL_H
#define IMPLIEDVOLATILITY_BSMODEL_H
#include <cmath>
#include "NormalCDF.h"
#include <iostream>
using namespace std;

class BSModel {
private:
    // user input
    const double S, K, r, q, sigma, T;
    const char whichOption;

    // calculate d1 d2
    double d1 = (log(S / K) + (r - q + pow(sigma, 2) / 2) * T) / (sigma * sqrt(T));
    double d2 = (log(S / K) + (r - q - pow(sigma, 2) / 2) * T) / (sigma * sqrt(T));

public:
    BSModel(const double s, const double k, const double r, const double q, const double sigma, const double t,
            const char whichOption);

    virtual ~BSModel();

    double getOptionPrice();

};


#endif //IMPLIEDVOLATILITY_BSMODEL_H
