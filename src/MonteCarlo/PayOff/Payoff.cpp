//
// Created by 林大中 on .
//

#include "Payoff.h"

Payoff::Payoff() {}

Payoff::~Payoff() {}

matrix& Payoff::getPayoffMatrix(){
    return payoffMatrix;
}

matrix *Payoff::setPayoffMatrix() {
    return &payoffMatrix;
}

void Payoff::display() const{

    for (int row = 0; row < payoffMatrix.size(); ++row){
        std::cout << "[";

        for (int column = 0; column < payoffMatrix.at(0).size(); ++column){
            std::cout << payoffMatrix.at(row).at(column) << ", ";
        }
        std::cout << "]" << std::endl;
    }
}

void Payoff::deleteSimulatorMemory(Simulator *ptr_simulator) {
    delete ptr_simulator;
}
