//
// Created by 林大中 on .
//

#ifndef HW1_HW1_OPTION_H
#define HW1_HW1_OPTION_H

#include "Payoff.h"

class HW1_Option :public Payoff{
    double K1, K2, K3, K4;

    inline long double calcOnePayoff(long double value) const override;

    void calcPayoffMatrix(matrix& price) override;

public:
    HW1_Option(const double K1, const double K2, const double K3, const double K4);
    matrix& operator () (Simulator* ptr_simulator) override;
    ~HW1_Option() override;
};


#endif //HW1_HW1_OPTION_H
