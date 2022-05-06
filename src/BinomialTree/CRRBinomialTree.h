//
// Created by 林大中 on .
//

#ifndef CRRBINOMIALTREEBETTERVERSION_CRRBINOMIALTREE_H
#define CRRBINOMIALTREEBETTERVERSION_CRRBINOMIALTREE_H
#include <vector>
#include <cmath>
using namespace std;

enum OptionType{E = 1,A};

class CRRBinomialTree {
private:
    // user input
    const double S;
    const double T;
    const int n;
    const double sigma;
    const double r;
    const double q;
    const double K;
    const char whichOption;
    const char type;

    // container
    vector<double> treeInOneVector;

    // parameter calculation
    double delta_T = T/ n;
    double u = exp(sigma * sqrt(delta_T));
    double d = 1 / u;
    double p = (exp((r - q) * delta_T) - d) / (u - d);

    // calculate one price
    inline double calcPrice(int time, int num_from_top);

    // calculate one call payoff at maturity
    inline double callPayoffAtMaturity(int num_from_top);

    // calculate one put payoff at maturity
    inline double putPayoffAtMaturity(int num_from_top);

    // calculate the tree value at specific position
    inline double valueInTree(int num_from_top);

    // calculate the call value if exercise in now
    inline double callValueExercise(int time, int num_from_top);

    // calculate the put value if exercise in now
    inline double putValueExercise(int time, int num_from_top);

    // construct tree
    void createTree();

public:
    CRRBinomialTree(const double s, const double t, const int n, const double sigma, const double r, const double q,
                    const double k, const char whichOption, const char type);

    virtual ~CRRBinomialTree();

    double getOptionValue();
};


#endif //CRRBINOMIALTREEBETTERVERSION_CRRBINOMIALTREE_H
