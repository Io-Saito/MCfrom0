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
    x = x + rand.randomNumber() * 10;
    y = y + rand.randomNumber() * 10;
    z = z + rand.randomNumber() * 10;
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
    x = x * x_;
    y = y * y_;
    z = z * z_;
}