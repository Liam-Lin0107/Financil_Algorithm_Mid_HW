//
// Created by 林大中 on .
//

#include "BinomialPF.h"

long double B(int n, double p, int x){

    long double result = 0.0;

    for (int count = n; count > n - x; count--){
        result += log(count);
    }

    for (int count =  x; count > 0; count--){
        result -= log(count);
    }

    result += ((n - x) * log(p) + x * log(1 - p));

    return exp(result);
}