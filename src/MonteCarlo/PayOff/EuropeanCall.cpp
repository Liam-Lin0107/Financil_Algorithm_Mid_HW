//
// Created by 林大中 on .
//

#include "EuropeanCall.h"

EuropeanCall::EuropeanCall(const double K) : K(K){}

void EuropeanCall::calcPayoffMatrix(matrix& price) {

    for (size_t row = 0; row < price.size(); ++row){
        // add row
        setPayoffMatrix()->push_back(std::vector<long double>());

        for(size_t column = 0; column < price.at(0).size(); ++column){
            // add element at end of the row
            setPayoffMatrix()->at(row).push_back(calcOnePayoff(price.at(row).at(column)));
        }
    }
}

matrix& EuropeanCall::operator()(Simulator* ptr_simulator) {
    calcPayoffMatrix(ptr_simulator->getPriceMatrix());
    // delete the simulator memory
    deleteSimulatorMemory(ptr_simulator);
    return getPayoffMatrix();
}


