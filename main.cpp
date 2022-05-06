#include <iostream>
#include "src/MonteCarlo/Simulation/Simulator/PathIndependentSimulation/SimpleMCSimulation.h"
#include "src/MonteCarlo/PayOff/EuropeanCall.h"
#include "src/MonteCarlo/PayOff/EuropeanPut.h"
#include "src/MonteCarlo/Discount/Discount.h"
#include "src/MonteCarlo/Statics/SummaryStatistics.h"
#include "src/BinomialTree/CRRBinomialTree.h"
#include "src/CombinatorialMehtod/CombinatorialMethod.h"
#include "src/ImpliedVolatility/src/ImpliiedVolatility.h"


using namespace std;

// Hyper-parameters <----
char whichOption = 'C';
char OptionType = 'E';
int N = 1000000; // size in one batch
int n = 20; // batch size
double S = 100, r = 0.05, q = 0.02, T = 0.4, sigma = 0.3;
double K = 100; // strike price

double init = 0.5;

double criteria = 0.0001;

double MktCall = 19.4611;
double MktPut = 8.23397;
double MktCallAmerican = 19.499;
double MktPutAmerican = 8.34893;


char userEntry();

bool userInputForMonteCarlo();

bool userInputForTree();

bool userInputForCombinatorial();

bool userInputForImpliedVolatility();

int main() {

    int userChoice;

    while(true) {
        userChoice = userEntry();
        switch (userChoice) {
            case 'a': {
                userInputForMonteCarlo();
                // simulator
                SimpleMCSimulation *ptr_simulator = new SimpleMCSimulation(N, n, S, r, q, T, sigma);

                // choose call function and setting the strike price
                if (whichOption == 'P') {

                    EuropeanPut *ptr_optionPayoff = new EuropeanPut(K);
                    // calculate the payoffMatrix
                    (*ptr_optionPayoff)(ptr_simulator);

                    // constantDiscount it, then get n value in values vector
                    vector<long double> optionValues = constantDiscount(*ptr_optionPayoff, r, T);


                    // Summary
                    cout << "Option Summary: " << endl;
                    Summary::summary(optionValues);
                    cout << endl;
                } else {
                    EuropeanCall *ptr_optionPayoff = new EuropeanCall(K);
                    // calculate the payoffMatrix
                    (*ptr_optionPayoff)(ptr_simulator);

                    // constantDiscount it, then get n value in values vector
                    vector<long double> optionValues = constantDiscount(*ptr_optionPayoff, r, T);


                    // Summary
                    cout << "Option Summary: " << endl;
                    Summary::summary(optionValues);
                    cout << endl;
                    break;
                }
            }
            case 'b': {
                userInputForTree();
                if (whichOption == 'C') {
                    if (OptionType == 'E') {
                        CRRBinomialTree EuropeanCall(S, T, n, sigma, r, q, K, 'C', E);
                        cout << "Call: " << EuropeanCall.getOptionValue() << endl;
                        cout << endl;
                    } else if (OptionType == 'A') {
                        CRRBinomialTree AmericanCall(S, T, n, sigma, r, q, K, 'C', A);
                        cout << "American Call: " << AmericanCall.getOptionValue() << endl;
                        cout << endl;
                    }
                    break;
                }

                if (whichOption == 'P') {
                    if (OptionType == 'E') {
                        CRRBinomialTree EuropeanPut(S, T, n, sigma, r, q, K, 'P', E);
                        cout << "Put: " << EuropeanPut.getOptionValue() << endl;
                        cout << endl;
                    } else if (OptionType == 'A') {
                        CRRBinomialTree AmericanPut(S, T, n, sigma, r, q, K, 'P', A);
                        cout << "American Put: " << AmericanPut.getOptionValue() << endl;
                        cout << endl;
                    }
                    break;
                }
            }
            case 'c': {
                userInputForCombinatorial();
                if (whichOption == 'C') {
                    CombinatorialMethod call(S, T, n, sigma, r, q, K, 'C');
                    cout << "Call: " << call.getOptionValue() << endl;
                    cout << endl;
                } else if (whichOption == 'P') {
                    CombinatorialMethod put(S, T, n, sigma, r, q, K, 'P');
                    cout << "Put: " << put.getOptionValue() << endl;
                    cout << endl;
                }
                break;
            }
            case 'd': {
                userInputForImpliedVolatility();
                cout << "Implied Volatility" << endl << endl;


                cout << "===================" << endl;
                cout << "Newton's Method" << endl;
                cout << "===================" << endl;


                cout << "BSModel" << endl;
                if (OptionType == 'E') {
                    if (whichOption == 'C') {
                        cout << "Call Volatility: " << BSMNewton(S, K, r, q, T, 'C', init, MktCall, criteria) << endl;
                        cout << endl;
                    }


                    else {
                        cout << "Put Volatility: " << BSMNewton(S, K, r, q, T, 'P', init, MktPut, criteria) << endl;
                        cout << endl;
                    }

                } else if (OptionType == 'A') {
                    if (whichOption == 'C') {
                        cout << "American Call Volatility: "
                             << TreeNewton(S, K, r, q, T, 'C', A, n, init, MktCallAmerican, criteria) << endl;
                        cout << endl;
                    }
                    else {
                        cout << "American Put Volatility: "
                             << TreeNewton(S, K, r, q, T, 'P', A, n, init, MktPutAmerican, criteria) << endl;
                        cout << endl;
                    }
                }
                break;
            }

            case 'e': {
                cout << "See ya~~~";
                return 0;
            }
        }
    }
}

char userEntry(){
    cout << "Welcome to Option Calculator~" << endl;
    cout << "Which Function you want to use ?" << endl;
    cout << "a. Monte Carlo simulation" << endl;
    cout << "b. Binomial Tree Method" << endl;
    cout << "c. Combinatorial Method" << endl;
    cout << "d. Calculate Implied Volatility" << endl;
    cout << "e. exit" << endl;
    char userChoice;
    cout << "Your choice: ";
    cin >> userChoice;

    return  userChoice;
}

bool userInputForMonteCarlo(){

    cout << "Please, enter the following parameters" << endl;

    cout << "Plain vanilla Call or Put(C/P): ";
    cin >> whichOption;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        cin.clear();
        return false;
    }


    cout << "How many times to form monte carlo: ";
    cin >> n;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        cin.clear();
        return false;
    }

    cout << "Simulation times: ";
    cin >> N;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        cin.clear();
        return false;
    }


    cout << "Stock price: ";
    cin >> S;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        cin.clear();
        return false;
    }


    cout << "Risk-free rate: ";
    cin >> r;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cout << "Dividend yield: ";
    cin >> q;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cout << "Time to maturity day: ";
    cin >> T;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }


    cout << "Volatility: ";
    cin >> sigma;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }


    cout << "Strike price: ";
    cin >> K;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cout << "Computing........" << endl << endl;
    return true;
}

bool userInputForTree(){

    cout << "Please, enter the following parameters" << endl;

    cout << "Call or Put(C/P): ";
    cin >> whichOption;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        cin.clear();
        return false;
    }

    cout << "American or European(A/E): ";
    cin >> OptionType;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        cin.clear();
        return false;
    }


    cout << "How many time interval(need larger than 100): ";
    cin >> n;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        cin.clear();
        return false;
    }


    cout << "Stock price: ";
    cin >> S;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        cin.clear();
        return false;
    }


    cout << "Risk-free rate: ";
    cin >> r;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cout << "Dividend yield: ";
    cin >> q;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cout << "Time to maturity day: ";
    cin >> T;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }


    cout << "Volatility: ";
    cin >> sigma;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }


    cout << "Strike price: ";
    cin >> K;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cout << "Computing........" << endl << endl;
    return true;
}

bool userInputForCombinatorial(){

    cout << "Please, enter the following parameters" << endl;

    cout << "Call or Put(C/P): ";
    cin >> whichOption;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        cin.clear();
        return false;
    }


    cout << "How many time interval(need larger than 100): ";
    cin >> n;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        cin.clear();
        return false;
    }


    cout << "Stock price: ";
    cin >> S;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        cin.clear();
        return false;
    }


    cout << "Risk-free rate: ";
    cin >> r;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cout << "Dividend yield: ";
    cin >> q;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cout << "Time to maturity day: ";
    cin >> T;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }


    cout << "Volatility: ";
    cin >> sigma;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }


    cout << "Strike price: ";
    cin >> K;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cout << "Computing........" << endl << endl;
    return true;
}

bool userInputForImpliedVolatility(){

    cout << "Please, enter the following parameters" << endl;

    cout << "Call or Put(C/P): ";
    cin >> whichOption;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        cin.clear();
        return false;
    }



    cout << "American or European(A/E): ";
    cin >> OptionType;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        cin.clear();
        return false;
    }

    cout << "Market price of this option: ";
    if (whichOption == 'C'){
        if (OptionType == 'E'){
            cin >> MktCall;
            if (cin.fail()) {
                cerr << "Wrong Type input" << endl;
                cin.clear();
                return false;
            }
        }
        else{
            cin >> MktCallAmerican;
            if (cin.fail()) {
                cerr << "Wrong Type input" << endl;
                cin.clear();
                return false;
            }
        }

    }
    else{
        if (OptionType == 'E'){
            cin >> MktPut;
            if (cin.fail()) {
                cerr << "Wrong Type input" << endl;
                cin.clear();
                return false;
            }
        }
        else{
            cin >> MktPutAmerican;
            if (cin.fail()) {
                cerr << "Wrong Type input" << endl;
                cin.clear();
                return false;
            }
        }
    }
    if (OptionType == 'A') {
        cout << "How many time interval(need larger than 100): ";
        cin >> n;
        if (cin.fail()) {
            cerr << "Wrong Type input" << endl;
            cin.clear();
            return false;
        }
    }


    cout << "Stock price: ";
    cin >> S;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        cin.clear();
        return false;
    }


    cout << "Risk-free rate: ";
    cin >> r;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cout << "Dividend yield: ";
    cin >> q;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cout << "Time to maturity day: ";
    cin >> T;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }


    cout << "Strike price: ";
    cin >> K;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cout << "Computing........" << endl << endl;
    return true;
}
