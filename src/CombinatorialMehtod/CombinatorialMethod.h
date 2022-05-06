//
// Created by 林大中 on .
//

#ifndef COMBINATORIALMETHOD_COMBINATORIALMETHOD_H
#define COMBINATORIALMETHOD_COMBINATORIALMETHOD_H
#include<cmath>
#include <vector>
#include "util/BinomialPF.h"

using namespace std;

class CombinatorialMethod {
private:
    // user Input
    const double S;
    const double T;
    const int n;
    const double sigma;
    const double r;
    const double q;
    const double K;
    const char whichOption;

    // parameter calculation
    double delta_T = T/ n;
    double u = exp(sigma * sqrt(delta_T));
    double d = 1/u;
    double p = (exp((r - q) * delta_T) - d) / (u - d);


    // calculate one price
    inline double calcPrice(int time, int num_from_top);


public:
    CombinatorialMethod(const double s, const double t, const int n, const double sigma, const double r, const double q,
                        const double k, const char whichOption);

    virtual ~CombinatorialMethod();


    double getOptionValue();

};


#endif //COMBINATORIALMETHOD_COMBINATORIALMETHOD_H
