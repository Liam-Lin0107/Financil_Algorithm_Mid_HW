//
// Created by 林大中 on .
//

#ifndef IMPLIEDVOLATILITY_IMPLIIEDVOLATILITY_H
#define IMPLIEDVOLATILITY_IMPLIIEDVOLATILITY_H
#include "../util/BSModel.h"
#include "../../BinomialTree/CRRBinomialTree.h"
#include <iostream>


double BSMBisection(const double S, const double K, const double r, const double q, const double T,
                    const char whichOption, const double leftGuess, const double rightGuess, const double MktPrice, const double criteria);


double TreeBisection(const double S, const double K, const double r, const double q, const double T,
                     const char whichOption, const OptionType type, const int n, const double leftGuess, const double rightGuess, const double MktPrice, const double criteria);

double BSMNewton(const double S, const double K, const double r, const double q, const double T,
                 const char whichOption, const double initGuess, const double MktPrice, const double criteria);

double TreeNewton(const double S, const double K, const double r, const double q, const double T,
                  const char whichOption, const OptionType type, const int n, const double initGuess, const double MktPrice, const double criteria);



#endif //IMPLIEDVOLATILITY_IMPLIIEDVOLATILITY_H
