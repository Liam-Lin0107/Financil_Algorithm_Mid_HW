//
// Created by 林大中 on .
//

#include "CombinatorialMethod.h"

double CombinatorialMethod::calcPrice(int time, int num_from_top) {
    return S * pow(u, time - num_from_top) * pow(d, num_from_top);
}

CombinatorialMethod::CombinatorialMethod(const double s, const double t, const int n, const double sigma,
                                         const double r, const double q, const double k, const char whichOption)
                                         : S(s), T(t), n(n), sigma(sigma), r(r), q(q), K(k), whichOption(whichOption) {}

CombinatorialMethod::~CombinatorialMethod() {}

double CombinatorialMethod::getOptionValue() {
    double result = 0.0;
    for (int count = 0; count <= n; count++){
        if (whichOption == 'C') {
            result += B(n, p, count) * max(calcPrice(n, count) - K, 0.0);
        }
        if (whichOption == 'P') {
            result += B(n, p, count) * max(K - calcPrice(n, count), 0.0);
        }
    }

    return exp(-r * T) * result;
}
