//
// Created by 林大中 on .
//

#include "Simulator.h"

Simulator::Simulator() {}

Simulator::Simulator(const int N, const int n) :N(N), n(n) {};

Simulator::~Simulator() {}

matrix& Simulator::getPriceMatrix(){

    return priceMatrix;
}

void Simulator::display() const{

    for (int row = 0; row < n; ++row){
        std::cout << "[";
        for (int column = 0; column < N; ++column){
            std::cout << priceMatrix[row][column] << ", ";
        }
        std::cout << "]" << std::endl;
    }
}

matrix* Simulator::setPriceMatrix() {
    return &priceMatrix;
}


