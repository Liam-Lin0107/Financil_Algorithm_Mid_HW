//
// Created by 林大中 on .
//

#include "RandomSample.h"
double normalRV(){
    // random device
    std::random_device rd;

    // random generator
    std::mt19937 generator(rd());

    // distribution
    std::normal_distribution<double> norm(0.0, 1.0);

    // random sample
    double x = norm(generator);
    return x;
}
