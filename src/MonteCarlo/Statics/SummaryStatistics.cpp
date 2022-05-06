//
// Created by 林大中 on .
//

#include "SummaryStatistics.h"


void Summary::valuesPlot(vector<long double>& values) {
    cout << "Values:" << endl;
    cout << "[";
    for (size_t ix = 0; ix < values.size(); ++ix){
        cout <<values.at(ix) << " ";
    }
    cout << "]" << endl << endl;
    double min = Summary::min(values);
    double max = Summary::max(values);
    double range = Summary::range(values);
    double increment = range / 5;
    // account for different intervals
    size_t Q1 = 0;
    size_t Q2 = 0;
    size_t Q3 = 0;
    size_t Q4 = 0;
    size_t Q5 = 0;

    for (double value : values){
        if (value > (max - increment) && value <= max)
            ++Q5;
        else if (value < (max - increment) && value >= (max - 2 * increment))
            ++Q4;
        else if (value < (max - 2 * increment) && value >= (max - 3 * increment))
            ++Q3;
        else if (value < (max - 3 * increment) && (max - 4 * increment) >= min)
            ++Q2;
        else if (value < (max - 4 * increment) && value >= min)
            ++Q1;
        else
            cerr << "error in value plot" << endl;
    }
    // for Q1
    cout << "Distribution Plot: " << endl;
    cout << "-----------------" << endl;
    cout << "min" << endl;
    cout << "|" << endl;
    cout << "|";
    for (size_t count = 0; count < Q1; ++count){
        cout << "*";
    }
    cout << endl;

    // for Q2
    cout << "|";
    for (size_t count = 0; count < Q2; ++count){
        cout << "*";
    }
    cout << endl;

    //for Q3;
    cout << "|";
    for (size_t count = 0; count < Q3; ++count){
        cout << "*";
    }
    cout << endl;

    // for Q4
    cout << "|";
    for (size_t count = 0; count < Q4; ++count){
        cout << "*";
    }
    cout << endl;

    // for Q5
    cout << "|";
    for (size_t count = 0; count < Q5; ++count){
        cout << "*";
    }
    cout << endl;
    cout << "|" << endl;
    cout << "max" << endl;
    cout << "-----------------" << endl << endl;
}

double Summary::mean(vector<long double>& values) {
    double sum = 0;

    for (long double value : values){
        sum += value;
    }
    double mean = sum / values.size();

    return mean;
}

long double Summary::standerError(vector<long double> &values) {
    long double sum = 0;

    for (long double value : values){
        sum += value;
    }
    long double mean = sum / values.size();

    long double mean_sqaure_error = 0;
    for (long double value : values){
        mean_sqaure_error += pow((value - mean), 2) / values.size();
    }
    long double std_error = sqrt(mean_sqaure_error);


    return std_error;
}

vector<long double> Summary::CI(vector<long double> &values, long double n_stdError) {
    long double sum = 0;

    for (long double value : values){
        sum += value;
    }
    long double mean = sum / values.size();

    long double mean_sqaure_error = 0;
    for (long double value : values){
        mean_sqaure_error += pow((value - mean), 2) / values.size();
    }
    long double std_error = sqrt(mean_sqaure_error);

    cout << "C.I:" << endl
    << "(mean -/+ " << n_stdError << " * std" << ")" << " = "
    << "(" << mean - n_stdError * std_error << ", " << mean + n_stdError * std_error << ")" << endl;

    return vector<long double>{mean - n_stdError * std_error, mean + n_stdError * std_error};
}

long double Summary::max(vector<long double> &values) {
    long double max = numeric_limits<long double>::min();
    for (long double value : values){
        if (value > max)
            max = value;
    }

    return max;
}

long double Summary::min(vector<long double> &values) {
    long double min = numeric_limits<long double>::max();
    for (long double value : values){
        if (value < min)
            min = value;
    }

    return min;
}

long double Summary::range(vector<long double> &values) {
    long double range = Summary::max(values) - Summary::min(values);

    return range;
}

void Summary::summary(vector<long double> &values) {

//    Summary::valuesPlot(values);

    cout << "Summary Statistics: " << endl;
    long double mean = Summary::mean(values);
    cout << "Mean: " << mean << endl;
    long double std_error = Summary::standerError(values);
    cout << "std: " << std_error << endl;
    long double max = Summary::max(values);
    cout << "max: " << max << endl;
    long double min = Summary::min(values);
    cout << "min: " << min << endl;
    long double range = Summary::range(values);
    cout << "range: " << range << endl;
    Summary::CI(values, 2);
}



