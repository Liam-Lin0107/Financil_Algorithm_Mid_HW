//
// Created by 林大中 on .
//

#ifndef HW1_EUROPEANCALL_H
#define HW1_EUROPEANCALL_H

#include "Payoff.h"

class EuropeanCall final : public Payoff{
private:
    double K;

    // inline function need to be declared in .h file
    inline long double calcOnePayoff(long double value) const override{
        return std::max<long double>(value - K, 0);
    }

    void calcPayoffMatrix(matrix& price) override;

public:
    EuropeanCall(const double K);
    matrix& operator () (Simulator* ptr_simulator) override;
    virtual ~EuropeanCall(){};
};


#endif //HW1_EUROPEANCALL_H
