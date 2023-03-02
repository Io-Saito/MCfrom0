#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
#include "Monomer.h"
#include "Polymer.h"
#include "RandomChain.h"
#include "Random.h"

void RandomChain::monomer_of_polymerMove(int i)
{
    Random rand;
    float x = rand.randomNumber() + getMonomer(i)->GetX();
    float y = rand.randomNumber() + getMonomer(i)->GetY();
    float z = rand.randomNumber() + getMonomer(i)->GetZ();
    Monomers[i]->update(x, y, z);
}

bool RandomChain::CheckAngle(int j)
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
            return true;
        }
    }
}

bool RandomChain::Potential_in_chain(int i)
{
    int count = 0;
    for (int k = 0; k < static_cast<int>(Monomers.size()); k++)
    {
        if (k != i)
        {
            if (k == i - 1 || k == i + 1)
            {
                if (distance(i, k) >= cutoff * 0.1 && distance(i, k) < cutoff * 1.5)
                {
                    count++;
                }
            }
            else
            {
                if (distance(i, k) >= cutoff * 0.1 && distance(i, k) < cutoff * 3)
                {
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    
    if (count == (static_cast<int>(Monomers.size()) - 2))
    {
        return true;
    }
    else
    {
        return true;
    }
}