//
// Created by 林大中 on .
//
/*
 *  for drift and volatility term are constant
 */
#ifndef HW1_SIMPLEMCSIMULATION_H
#define HW1_SIMPLEMCSIMULATION_H

#include "Simulator.h"
class SimpleMCSimulation final: public Simulator{
private:

    // based data for underlying asset
    long double S;
    long double r;
    long double q;
    long double T;
    long double sigma;

    // price simulate
    inline long double calcOnePrice() const override;

    // calculate price matrix by using calcOnePrice
    void calcPriceMatrix() override;

    // Avoid default constructor : S,r,q.. is random value
    SimpleMCSimulation();

public:

    // Constructor and Destructor
    SimpleMCSimulation(const long double N, const long double n, const long double S, const long double r, const long double q, const long double T, const long double sigma);
    virtual ~SimpleMCSimulation();

};


#endif //HW1_SIMPLEMCSIMULATION_H
