//
// Created by 林大中 on .
//

#include "HW1_Option.h"

HW1_Option::HW1_Option(const double K1, const double K2, const double K3, const double K4)
        :K1(K1), K2(K2), K3(K3), K4(K4){}


HW1_Option::~HW1_Option() {}


inline long double HW1_Option::calcOnePayoff(long double value) const {
    if(value >= K1 && value < K2)
        return value - K1;
    else if(value >= K2 && value < K3)
        return K2 - K1;
    else if(value >= K3 && value < K4)
        return K2 - K1 - (K2 - K1) / (K4 - K3) * (value - K3);
    else
        return 0;
}


void HW1_Option::calcPayoffMatrix(matrix& price) {

    for (size_t row = 0; row < price.size(); ++row){
        setPayoffMatrix()->push_back(std::vector<long double>());

        for(size_t column = 0; column < price.at(0).size(); ++column){
            setPayoffMatrix()->at(row).push_back(calcOnePayoff(price.at(row).at(column)));
        }
    }
}


matrix& HW1_Option::operator()(Simulator* ptr_simulator) {
    calcPayoffMatrix(ptr_simulator->getPriceMatrix());

    // remove simulator memory
    deleteSimulatorMemory(ptr_simulator);

    return getPayoffMatrix();
}
