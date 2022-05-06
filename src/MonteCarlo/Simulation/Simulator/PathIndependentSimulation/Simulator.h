//
// Created by 林大中 on .
//
/*
 * Simulator is abstract class for simulator derived class
 */
#ifndef HW1_SIMULATOR_H
#define HW1_SIMULATOR_H

#include <cmath>
#include <vector>
#include <iostream>
#include "../../../Statics/RandomSample.h"

using matrix = std::vector<std::vector<long double>>;

class Simulator {
private:
    // the priceMatrix for the simulation data
    matrix priceMatrix;

public:
    int N; // one batch rvN amount of data

    int n; // n batch

    // Constructor and Destructor
    Simulator();
    Simulator(const int N, const int n);
    virtual ~Simulator();

    // return  asset price
    matrix& getPriceMatrix();

    // setting the priceMatrix
    matrix* setPriceMatrix();

    // print asset price at screen
    void display() const;

    // virtual function to calculate one price
    inline virtual long double calcOnePrice() const = 0;

    // virtual function to add price to priceMatrix to form price matrix
    virtual void calcPriceMatrix() = 0;

};


#endif //HW1_SIMULATOR_H
