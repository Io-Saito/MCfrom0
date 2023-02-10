#include "monomer.hpp"
#include "Random.hpp"
#include <cstdlib>
using namespace std;

void Monomer::update(){
    Random rand;
    x_old = x;
    y_old = y;
    z_old = z;
    x = x + rand.randomNumber();
    y = y + rand.randomNumber();
    z = z + rand.randomNumber();
}

void Monomer::getback()
{
    x = x_old;
    y = y_old;
    z = z_old;
}