//
// Created by 林大中 on .
//
/*
 * values()
 * mean()
 * std()
 * CI()
 * range()
 */
#ifndef HW1_SUMMARYSTATISTICS_H
#define HW1_SUMMARYSTATISTICS_H

#include <vector>
#include <math.h>
#include <iostream>
#include <limits>

using namespace std;

namespace Summary {
    void valuesPlot(vector<long double> &values);

    double mean(vector<long double> &values);

    long double standerError(vector<long double> &values);

    vector<long double> CI(vector<long double> &values, long double n_stdError);

    long double max(vector<long double> &values);

    long double min(vector<long double> &values);

    long double range(vector<long double> &values);

    void summary(vector<long double> &values);
}
#endif //HW1_SUMMARYSTATISTICS_H
