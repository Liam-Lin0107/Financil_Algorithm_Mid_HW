//
// Created by 林大中 on .
//

#include "EuropeanPut.h"

EuropeanPut::EuropeanPut(const double K) : K(K){}

void EuropeanPut::calcPayoffMatrix(matrix& price) {

    for (size_t row = 0; row < price.size(); ++row){
        setPayoffMatrix()->push_back(std::vector<long double>());

        for(size_t column = 0; column < price.at(0).size(); ++column){
            setPayoffMatrix()->at(row).push_back(calcOnePayoff(price.at(row).at(column)));
        }
    }
}

matrix& EuropeanPut::operator()(Simulator* ptr_simulator) {
    calcPayoffMatrix(ptr_simulator->getPriceMatrix());

    deleteSimulatorMemory(ptr_simulator);

    return getPayoffMatrix();
}




