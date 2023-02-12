#include "polymer.hpp"
#include <math.h>
using namespace std;

void Polymer::monomer_of_polymerMove(int i)
{
    Monomers[i]->update();
}

Monomer *Polymer::getMonomer(int i)
{
    return Monomers[i];
}

void Polymer::monomer_of_polymerBack(int i)
{
    Monomers[i]->getback();
}

void Polymer::adjustBox(float x_, float y_, float z_)
{
    for (int i = 0; i <= static_cast<int>(Monomers.size()); i++)
    {
        Monomers[i]->AdjustField(x_, y_, z_);
    }
};

void Polymer::adjustBoxback()
{
    for (int i = 0; i <= static_cast<int>(Monomers.size()); i++)
    {
        Monomers[i]->getback();
    }
};

bool Polymer::CheckAngle(int j)
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

bool Polymer::Potential_in_chain(int i)
{
    int count = 0;
    for (int k = 0; k < static_cast<int>(Monomers.size()); k++)
    {
        if (k != i)
        {
            if (k == i - 1 || k == i + 1)
            {
                if (distance(i, k) >= cutoff && distance(i, k) < cutoff * 1.5)
                {
                    count++;
                }
            }
            else
            {
                if (distance(i, k) >= cutoff)
                {
                    count++;
                }
            }
        }
    }
    if (count == (static_cast<int>(Monomers.size()) - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Polymer::distance(int i, int j)
{
    Monomer *m_i;
    Monomer *m_j;
    double distance;
    m_i = getMonomer(i);
    m_j = getMonomer(j);
    double d_x = m_i->GetX() - m_j->GetX();
    double d_y = m_i->GetY() - m_j->GetY();
    double d_z = m_i->GetZ() - m_j->GetZ();
    distance = sqrt(d_x * d_x + d_y * d_y + d_z * d_z);
    return distance;
}

double Polymer::angle(int i, int j, int k)
{
    // i->j->k
    Monomer *m_i;
    Monomer *m_j;
    Monomer *m_k;
    m_i = getMonomer(i);
    m_j = getMonomer(j);
    m_k = getMonomer(k);
    double vx1 = (m_i->GetX() - m_j->GetX());
    double vy1 = (m_i->GetY() - m_j->GetY());
    double vz1 = (m_i->GetZ() - m_j->GetZ());
    double vx2 = (m_k->GetX() - m_j->GetX());
    double vy2 = (m_k->GetY() - m_j->GetY());
    double vz2 = (m_k->GetZ() - m_j->GetZ());
    double dx1 = fabs(vx1);
    double dy1 = fabs(vy1);
    double dz1 = fabs(vz1);
    double v1 = sqrt(pow(dx1, 2.0) + pow(dy1, 2.0) + pow(dz1, 2.0));
    double dx2 = fabs(vx2);
    double dy2 = fabs(vy2);
    double dz2 = fabs(vz2);
    double v2 = sqrt(pow(dx2, 2.0) + pow(dy2, 2.0) + pow(dz2, 2.0));
    return acos((vx1 * vx2 + vy1 * vy2 + vz1 * vz2) / (v1 * v2));
}