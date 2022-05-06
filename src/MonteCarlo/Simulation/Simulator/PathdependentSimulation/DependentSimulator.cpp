//
// Created by 林大中 on .
//

#include "DependentSimulator.h"

DependentSimulator::DependentSimulator() {}

DependentSimulator::DependentSimulator(const int N, const int n, const int partitionAmount)
:N(N), n(n), partitionAmount(partitionAmount){}

DependentSimulator::~DependentSimulator() {}

array3dim &DependentSimulator::getAssetPriceThroughTime() {
    return container;
}

void DependentSimulator::display() const {
    for (int index = 0; index < n; ++index) {
        std::cout << "n = " << index << ":" << std::endl;
        for (int row = 0; row < N; ++row) {
            std::cout << "[";
            for (int column = 0; column < partitionAmount; ++column) {
                std::cout << container[index][row][column] << ", ";
            }
            std::cout << "]" << std::endl;
        }
    }
}
