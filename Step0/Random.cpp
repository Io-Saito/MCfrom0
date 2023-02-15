#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
using namespace std;
#include "Random.h"

void Random::setSeed()
{
    idum = -579; //-long(time(NULL));
    srand(579);
}

double Random::randomNumber()
{
    if (ran1() < 0.5)
        return -ran1();
    else
        return ran1();
}

double Random::ran1()
{
    double r = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
    return r;
}