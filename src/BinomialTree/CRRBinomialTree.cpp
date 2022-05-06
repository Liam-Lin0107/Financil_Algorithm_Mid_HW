//
// Created by 林大中 on .
//

#include "CRRBinomialTree.h"



CRRBinomialTree::CRRBinomialTree(const double s, const double t, const int n, const double sigma, const double r,
                                 const double q, const double k, const char whichOption, const char type)
        : S(s), T(t), n(n), sigma(sigma), r(r), q(q), K(k), whichOption(whichOption), type(type) {
    createTree();
}

CRRBinomialTree::~CRRBinomialTree() {}

double CRRBinomialTree::calcPrice(int time, int num_from_top) {
    return S * pow(u, time - num_from_top) * pow(d, num_from_top);
}

double CRRBinomialTree::callPayoffAtMaturity(int num_from_top) {
    return max(calcPrice(n, num_from_top) - K, 0.0);
}

double CRRBinomialTree::callValueExercise(int time, int num_from_top) {
    return max(calcPrice(time, num_from_top) - K, 0.0);
}

double CRRBinomialTree::putPayoffAtMaturity(int num_from_top) {
    return max(K - calcPrice(n, num_from_top), 0.0);
}

double CRRBinomialTree::putValueExercise(int time, int num_from_top) {
    return max(K - calcPrice(time, num_from_top), 0.0);
}

double CRRBinomialTree::valueInTree(int num_from_top) {
    return exp(-r * delta_T) * (p * treeInOneVector.at(num_from_top)+ (1 - p) * treeInOneVector.at(num_from_top + 1));
}

void CRRBinomialTree::createTree() {

    // initial vector with option payoff at maturity
    if (whichOption == 'C') {
        for (int num_from_top = 0; num_from_top <= n; num_from_top++) {
            treeInOneVector.push_back(callPayoffAtMaturity(num_from_top));
        }
    }
    if (whichOption == 'P') {
        for (int num_from_top = 0; num_from_top <= n; num_from_top++) {
            treeInOneVector.push_back(putPayoffAtMaturity(num_from_top));
        }
    }

    // for European Option
    if (type ==  E) {
        for (int time = n - 1; time >= 0; time--) {
            for (int num_from_top = 0; num_from_top <= time; num_from_top++) {
                treeInOneVector.at(num_from_top) = valueInTree(num_from_top);
            }
        }
    }

    // for American Option
    if (type == A) {
        for (int time = n - 1; time >= 0; time--) {
            for (int num_from_top = 0; num_from_top <= time; num_from_top++) {
                // cause !!!!
                if (whichOption == 'C')
                    treeInOneVector.at(num_from_top) = max(valueInTree(num_from_top), callValueExercise(time, num_from_top));
                if (whichOption == 'P')
                    treeInOneVector.at(num_from_top) = max(valueInTree(num_from_top), putValueExercise(time, num_from_top));
            }
        }
    }
}

double CRRBinomialTree::getOptionValue() {
    return treeInOneVector.at(0);
}




