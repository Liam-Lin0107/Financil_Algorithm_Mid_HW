//
// Created by 林大中 on .
//

#ifndef HW1_DEPENDENTSIMULATOR_H
#define HW1_DEPENDENTSIMULATOR_H

#include <vector>
#include <cmath>
#include <iostream>
#include "../../../Statics/RandomSample.h"

using array3dim = std::vector<std::vector<std::vector<double>>>;

class DependentSimulator {
public:
    int N; // one batch N amount of data
    int n; // n batch
    int partitionAmount; // the amount of division that divide the time period
    array3dim container; // the (n, N, partitionAmount) array for store the simulated price data

    // Constructor abd Destructor
    DependentSimulator();
    DependentSimulator(const int N, const int n, const int partitionAmount);
    virtual ~DependentSimulator();

    // return asset price
    array3dim& getAssetPriceThroughTime();

    // display
    void display() const;

    // function to calculate one price
    virtual double priceSimulate(double prevprice) const = 0;

    // function to add price to priceMatrix to from 3-dim array
    virtual void calcPrice() = 0;

};


#endif //HW1_DEPENDENTSIMULATOR_H
