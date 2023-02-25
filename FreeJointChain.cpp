#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
#include "Monomer.h"
#include "Polymer.h"
#include "FreeJointChain.h"
#include "Random.h"

void FreeJointChain::monomer_of_polymerMove(int i)
{
    float x, y, z;
    Random rand;
    if (i == 0)
    {
        x = rand.randomNumber();
        y = rand.randomNumber();
        z = rand.randomNumber();
    }
    else
    {
        float theta = rand.randomAngle();
        float phi = rand.randomAngle();
        float z_ = cos(theta) * Polymer::BondLength;
        float x_ = cos(phi) * sin(theta) * Polymer::BondLength;
        float y_ = sin(phi) * sin(theta) * Polymer::BondLength;
        float x_j = Polymer::Monomers[i - 1]->GetX();
        float y_j = Polymer::Monomers[i - 1]->GetY();
        float z_j = Polymer::Monomers[i - 1]->GetZ();
        x = x_j + x_;
        y = y_j + y_;
        z = z_j + z_;
    }
    Polymer::Monomers[i]->update(x, y, z);
}

bool FreeJointChain::Potential_in_chain(int i)
{
    return true;
}

bool FreeJointChain::CheckAngle(int j)
{
    return true;
}
