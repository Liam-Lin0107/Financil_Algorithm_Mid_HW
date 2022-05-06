//
// Created by 林大中 on .
//

#include "NormalCDF.h"
double rvN(double x){
    using namespace std;
    return erfc(-x/sqrt(2))/2;
}