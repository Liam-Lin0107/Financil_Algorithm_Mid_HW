//
// Created by 林大中 on .
//

#ifndef HW1_DEPENDENTSIMPLEMCSIMULATION_H
#define HW1_DEPENDENTSIMPLEMCSIMULATION_H

#include "DependentSimulator.h"

class DependentSimpleMCSimulation final:public DependentSimulator{
private:
    double S = 0, r = 0 , q = 0, T = 0, sigma = 0;
    double deltaT = T / N;

    // price simulate
    double priceSimulate(double prevprice) const override;

    // form 3-dim array
    void calcPrice() override;

    // can't use default constructor
    DependentSimpleMCSimulation();
public:

    DependentSimpleMCSimulation(const double S, const double r, const double q, const double T, const double sigma);

    virtual ~DependentSimpleMCSimulation() override;

};


#endif //HW1_DEPENDENTSIMPLEMCSIMULATION_H
