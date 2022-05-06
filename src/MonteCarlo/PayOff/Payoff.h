//
// Created by 林大中 on .
//

#ifndef HW1_PAYOFF_H
#define HW1_PAYOFF_H
/*
 * This class is abstract class only for being inherited
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include "../Simulation/Simulator/PathIndependentSimulation/Simulator.h"

using matrix = std::vector<std::vector<long double>>;

class Payoff {
private:
    // contain payoffMatrix data
    matrix payoffMatrix;

public:

    // constructor and destructor
    Payoff();
    virtual ~Payoff();

    // virtual display() method
    void display() const;

    // get the payoffMatrix
    matrix& getPayoffMatrix();

    // set the payoffMatrix
    matrix* setPayoffMatrix();

    // calculate one payoffMatrix
    inline virtual long double calcOnePayoff(long double value) const = 0;

    // using calcOnePayoff to get payoffMatrix, then change the payoffMatrix matrix in the class
    virtual void calcPayoffMatrix(matrix& price) = 0;

    // virtual overloaded operator () method : to convert the price matrix in "()" to payoffMatrix matrix
    virtual matrix& operator () (Simulator* ptr_simulator) = 0;

    // delete the simulator memory and use it in the end of operator ()
    virtual void deleteSimulatorMemory(Simulator* ptr_simulator);

};


#endif //HW1_PAYOFF_H
