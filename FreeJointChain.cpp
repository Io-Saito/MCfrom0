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
    float x_, y_, z_;
    Random rand;
    float theta = rand.randomAngle();
    float phi = rand.randomAngle();

    if (i == 0)
    {
        x_j = getMonomer(i)->GetX();
        y_j = getMonomer(i)->GetY();
        z_j = getMonomer(i)->GetZ();
        z_ = cos(theta) ;
        x_ = cos(phi) * sin(theta) ;
        y_ = sin(phi) * sin(theta) ;
    }
    else
    {
        x_j = getMonomer(i - 1)->GetX();
        y_j = getMonomer(i - 1)->GetY();
        z_j = getMonomer(i - 1)->GetZ();
        z_ = cos(theta) * BondLength;
        x_ = cos(phi) * sin(theta) * BondLength;
        y_ = sin(phi) * sin(theta) * BondLength;
    }
    x = x_j + x_;
    y = y_j + y_;
    z = z_j + z_;
    Polymer::getMonomer(i)->update(x, y, z);
}

bool FreeJointChain::Potential_in_chain(int i)
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
                if (distance(i, k) >= Polymer::cutoff || BondLength * 1.5 >= distance(i, k))
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

bool FreeJointChain::CheckAngle(int j)
{
    if (j == 0 || j == static_cast<int>(Polymer::Monomers.size()) - 1)
    {
        // j is the first/last monomer of the polymer
        return true;
    }
    else
    {
        double angle_ = angle(j - 1, j, j + 1);
        if (cos(angle_) < cos(Polymer::BondAngle))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
