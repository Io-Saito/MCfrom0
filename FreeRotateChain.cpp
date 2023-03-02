#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
#include "Monomer.h"
#include "Polymer.h"
#include "FreeRotateChain.h"
#include "Random.h"

void FreeRotateChain::monomer_of_polymerMove(int i)
{
    float x, y, z;
    float x_j, y_j, z_j;
    Random rand;
    float theta = Polymer::BondAngle;
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

bool FreeRotateChain::Potential_in_chain(int i)
{
    int count = 0;
    for (int k = 0; k < static_cast<int>(Monomers.size()); k++)
    {
        if (k == i)
        {
            count++;
        }
        else
        {
            if (k == i - 1 || k == i + 1)
            {
                if (distance(i, k) == BondLength)
                {
                    count++;
                }
            }
            else
            {
                if (distance(i, k) >= Polymer::cutoff || BondLength*2 >= distance(i, k))
                {
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    if (count == static_cast<int>(Polymer::Monomers.size() - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool FreeRotateChain::CheckAngle(int j)
{
    if (j == 0 || j == static_cast<int>(Monomers.size()) - 1)
    {
        // j is the first/last monomer of the polymer
        return true;
    }
    else
    {
        double angle_ = angle(j - 1, j, j + 1);
        if (cos(angle_) < cos(BondAngle))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}