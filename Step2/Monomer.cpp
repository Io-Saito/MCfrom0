#include <iostream>
#include <cstdlib>
using namespace std;
#include "Monomer.h"
#include "Random.h"

void Monomer::update()
{
    Random rand;
    x_old = x;
    y_old = y;
    z_old = z;
    x = x_old + rand.randomNumber();
    y = y_old + rand.randomNumber();
    z = z_old + rand.randomNumber();
};

void Monomer::getback()
{
    x = x_old;
    y = y_old;
    z = z_old;
};

void Monomer::AdjustField(float x_, float y_, float z_)
{
    x_old = x;
    y_old = y;
    z_old = z;
    x = x_old * x_;
    y = y_old * y_;
    z = z_old * z_;
}