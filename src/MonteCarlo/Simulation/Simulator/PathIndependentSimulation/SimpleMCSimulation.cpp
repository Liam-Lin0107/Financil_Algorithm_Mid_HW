//
// Created by 林大中 on .
//

#include "SimpleMCSimulation.h"

SimpleMCSimulation::SimpleMCSimulation() {}

SimpleMCSimulation::SimpleMCSimulation(const long double N, const long double n, const long double S, const long double r, const long double q,
                                       const long double T, const long double sigma) :Simulator(N, n), S(S), r(r), q(q), T(T), sigma(sigma) {
    calcPriceMatrix();
}

SimpleMCSimulation::~SimpleMCSimulation() {}

inline long double SimpleMCSimulation::calcOnePrice() const{
    return exp(log(S) + (r - q - pow(sigma, 2) / 2) * T + normalRV() * sigma * sqrt(T));
}

void SimpleMCSimulation::calcPriceMatrix() {
    for (size_t row = 0; row < n; ++row){
        // add new row at end
        setPriceMatrix()->push_back(std::vector<long double>());

        for (size_t column = 0; column < N; ++column) {

            // add new element at end of row
            setPriceMatrix()->at(row).push_back(calcOnePrice());
        }
    }
}
