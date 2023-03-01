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
    float x_j, y_j, z_j;
    Random rand;
    float theta = rand.randomAngle();
    float phi = rand.randomAngle();
    float z_ = cos(theta) * Polymer::BondLength;
    float x_ = cos(phi) * sin(theta) * Polymer::BondLength;
    float y_ = sin(phi) * sin(theta) * Polymer::BondLength;
    if (i == 0)
    {
        x_j = Polymer::Monomers[i]->GetX();
        y_j = Polymer::Monomers[i]->GetY();
        z_j = Polymer::Monomers[i]->GetZ();
    }
    else
    {
        x_j = Polymer::Monomers[i - 1]->GetX();
        y_j = Polymer::Monomers[i - 1]->GetY();
        z_j = Polymer::Monomers[i - 1]->GetZ();

    }
    x = x_j + x_;
    y = y_j + y_;
    z = z_j + z_;
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
