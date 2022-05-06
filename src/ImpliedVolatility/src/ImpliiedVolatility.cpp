//
// Created by 林大中 on .
//

#include "ImpliiedVolatility.h"


double BSMBisection(const double S, const double K, const double r, const double q, const double T,
                    const char whichOption, const double leftGuess, const double rightGuess, const double MktPrice, const double criteria){

    double error = 0;
    double mid = 0;
    double an = leftGuess;
    double bn = rightGuess;


    do {
        BSModel theoreticalLeft(S, K, r, q, an + criteria / 2, T, whichOption);
        double leftError = theoreticalLeft.getOptionPrice() - MktPrice;


        BSModel theoreticalRight(S, K, r, q, bn, T, whichOption);
        double rightError = theoreticalRight.getOptionPrice() - MktPrice;


        mid = an + ((bn - an) / 2.0);

        if (leftError * rightError < 0) {
            BSModel theoreticalMid(S, K, r, q, mid, T, whichOption);
            double midError = theoreticalMid.getOptionPrice() - MktPrice;


            if (leftError *  midError < 0)
                bn = mid;

            else if (leftError * midError > 0)
                an = mid;

            else {
                return mid;
                break;
            }
            error = midError;
        }
        else {
            cerr << "Change the initial Guess!!!" << endl;
            break;
        }

    }while(abs(error) > criteria);

    return mid;
}




double TreeBisection(const double S, const double K, const double r, const double q, const double T,
                     const char whichOption, const OptionType type, const int n, const double leftGuess, const double rightGuess, const double MktPrice, const double criteria){

    double error = 0;
    double mid = 0;
    double an = leftGuess + criteria;
    double bn = rightGuess;


    do {
        CRRBinomialTree treeLeft(S, T, n, an, r, q, K, whichOption, type);
        double leftError = treeLeft.getOptionValue() - MktPrice;


        CRRBinomialTree treeRight(S, T, n, bn, r, q, K, whichOption, type);
        double rightError = treeRight.getOptionValue() - MktPrice;


        mid = an + ((bn - an) / 2.0);

        if (leftError * rightError < 0) {
            CRRBinomialTree treeMid(S, T, n, mid, r, q, K, whichOption, type);
            double midError = treeMid.getOptionValue() - MktPrice;


            if (leftError *  midError < 0)
                bn = mid;

            else if (leftError * midError > 0)
                an = mid;

            else {
                return mid;
                break;
            }
            error = midError;
        }
        else {
            return mid;
        }

    }while(abs(error) > criteria);

    return mid;
}


double BSMNewton(const double S, const double K, const double r, const double q, const double T,
                 const char whichOption, const double initGuess, const double MktPrice, const double criteria){


    double error = 0;
    double stepSize = 0.000001;
    double guess = initGuess;

    do{
        BSModel init(S, K, r, q, guess, T, whichOption);

        BSModel initPlusDelta(S, K, r, q, guess + stepSize, T, whichOption);

        // if the root we guess correctly at beginning.
        double initError = (init.getOptionPrice() - MktPrice);
        double initPlusDeltaError = (initPlusDelta.getOptionPrice() - MktPrice);

        if (abs(initError) <= criteria){
            return guess;
        }

        double differential = (initPlusDeltaError - initError) / stepSize;
        guess -= initError / differential;

        BSModel newRoot(S, K, r, q, guess, T, whichOption);

        error = newRoot.getOptionPrice() - MktPrice;


    }while(abs(error) > criteria);
    return guess;

}

double TreeNewton(const double S, const double K, const double r, const double q, const double T,
                  const char whichOption, const OptionType type, const int n, const double initGuess, const double MktPrice, const double criteria){
    double error = 0;
    double stepSize = 0.000001;
    double guess = initGuess;

    do{
        CRRBinomialTree init(S, T, n, guess, r, q, K, whichOption, type);

        CRRBinomialTree initPlusDelta(S, T, n, guess + stepSize, r, q, K, whichOption, type);

        // f(x) = option calculate - Market price = error, our object is to let the f(x) = 0
        double initError = (init.getOptionValue() - MktPrice);
        double initPlusDeltaError = (initPlusDelta.getOptionValue() - MktPrice);
        // if the root we guess correctly at beginning.
        if (abs(initError) <= criteria){
            return guess;
        }

        double differential = (initPlusDeltaError - initError) / stepSize;
        guess -= initError / differential;

        CRRBinomialTree newRoot(S, T, n, guess, r, q, K, whichOption, type);

        error = newRoot.getOptionValue() - MktPrice;


    }while(abs(error) > criteria);
    return guess;
}