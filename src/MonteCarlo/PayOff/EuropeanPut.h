//
// Created by 林大中 on .
//

#ifndef HW1_EUROPEANPUT_H
#define HW1_EUROPEANPUT_H

#include "Payoff.h"

class EuropeanPut final :public Payoff{
private:
    double K;

    inline long double calcOnePayoff(long double value) const override{
        return std::max<long double>(K - value, 0.0);
    };

    void calcPayoffMatrix(matrix& price) override;

public:
    EuropeanPut(const double K);
    matrix& operator () (Simulator* ptr_simulator) override;
    virtual ~EuropeanPut(){};
};


#endif //HW1_EUROPEANPUT_H
