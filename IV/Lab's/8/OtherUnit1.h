#pragma once
#include <vector>
#include <time.h>
#include <random>

using namespace std;

double GetRandomDouble(double minNum, double maxNum)
{
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<double> distr(minNum, maxNum);

    double res = distr(eng);

    if ((int)res % 2 == 0)
    {
        int inty = (int)res;
        return (double)inty;
    }
    
    return res;
}

