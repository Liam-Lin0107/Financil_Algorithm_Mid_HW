//
// Created by 林大中 on .
//

#ifndef HW1_DISCOUNT_H
#define HW1_DISCOUNT_H

#include <vector>
#include "../PayOff/Payoff.h"
#include "../Simulation/Simulator/PathIndependentSimulation/Simulator.h"

// inline function need to declare the fall function in .h file
inline std::vector<long double> constantDiscount(Payoff& optionPayoff, long double r, long double T){

    auto row_itr = optionPayoff.getPayoffMatrix().cbegin();

    // values is the storage of the value of n options
    std::vector<long double> values;

    // rvN is the amount of elements in a row
    size_t N = row_itr->size();

    while (row_itr != optionPayoff.getPayoffMatrix().cend()){

        // row sum
        long double sum = 0;

        auto col_itr = row_itr->cbegin();

        while (col_itr != row_itr->cend()){
            sum += (*col_itr);
            ++col_itr;
        }

        values.push_back((sum / N) * exp(-r * T));
        ++row_itr;
    }

    return values;
}

#endif //HW1_DISCOUNT_H
