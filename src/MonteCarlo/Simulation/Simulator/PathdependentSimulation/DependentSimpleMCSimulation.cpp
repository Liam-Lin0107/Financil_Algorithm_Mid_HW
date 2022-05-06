//
// Created by 林大中 on .
//

#include "DependentSimpleMCSimulation.h"


double DependentSimpleMCSimulation::priceSimulate(double prevPrice) const {

    return exp(log(prevPrice) + ((r - q - pow(sigma, 2) / 2) * deltaT) + normalRV() * sigma * sqrt(deltaT));
}

void DependentSimpleMCSimulation::calcPrice() {
    for (size_t partition = 0; partition < partitionAmount; ++partition){
        // add new partition
        container.push_back(std::vector<std::vector<double>>());
        for (size_t row = 0; row < n; ++row){
            // add new row at end
            container[partition].push_back(std::vector<double>());
            // the first element in each row are S0
            container[partition][row].push_back(S);

            for (size_t column = 0; column < N + 1; ++column) {

                // get one price at next delta t
                double underlyingPriceAtNextDeltaT = priceSimulate(container[partition][row][column]);

                // add new element at end of row
                container[partition][row].push_back(underlyingPriceAtNextDeltaT);
            }
        }
    }
}

DependentSimpleMCSimulation::DependentSimpleMCSimulation() {}

DependentSimpleMCSimulation::DependentSimpleMCSimulation(const double S, const double r, const double q, const double T,
                                                         const double sigma)
:S(S), r(r), T(T), q(q), sigma(sigma){}

DependentSimpleMCSimulation::~DependentSimpleMCSimulation() {}
