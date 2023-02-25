#include <math.h>
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
#include "Random.h"
#include "Box.h"
#include "Polymer.h"
#include "Monomer.h"

int Box::move()
{
    for (int i = 0; i < static_cast<int>(Polymers.size()); i++)
    {
        Polymer *temp = Polymers[i];
        for (int j = 0; j < temp->Length(); j++)
        {
            int k = 0;
            while (k < 1000)
            {
                k++;
                temp->monomer_of_polymerMove(j);
                if (Potential_between_chains(i, j) && temp->Potential_in_chain(j) && temp->CheckAngle(j))
                {
                    cout << "monomer move accepted" << endl;
                    break;
                }
                else
                {
                    temp->monomer_of_polymerBack(j);
                }
            };
        }
    }

    int k = 0;
    while (k < 1000)
    {
        k++;
        BoxMove();
        if (CheckBoxMove() == true)
        {
            cout << "box move accepted" << endl;
            break;
        }
        else
        {
            BoxMoveBack();
        }
    };

    return 0;
};

void Box::BoxMove()
{
    Random rand;
    x_old = x;
    y_old = y;
    z_old = z;
    x = x_old + rand.randomNumber() * 0.5;
    y = y_old + rand.randomNumber() * 0.5;
    z = z_old + rand.randomNumber() * 0.5;
    // Move all monomers to adjust Box
    for (int i = 0; i < static_cast<int>(Polymers.size()); i++)
    {
        Polymers[i]->adjustBox(x / x_old, y / y_old, z / z_old);
    }
}

void Box::BoxMoveBack()
{
    for (int i = 0; i < static_cast<int>(Polymers.size()); i++)
    {
        Polymers[i]->adjustBoxback();
    }
    x = x_old;
    y = y_old;
    z = z_old;
}

bool Box::CheckBoxMove()
{
    int accept = 0;
    int num = 0;
    for (int i = 0; i < static_cast<int>(Polymers.size()); i++)
    {
        Polymer *temp = Polymers[i];
        for (int j = 0; j < temp->Length(); j++)
        {
            num++;
            if (Potential_between_chains(i, j) && temp->Potential_in_chain(j) && temp->CheckAngle(j))
            {
                accept++;
            }
            else
            {
            }
        }
    }
    if (accept == (num - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Box::Potential_between_chains(int i, int j)
{
    // Potential between j-th monomer of i-th polymer and other all monomers
    int accept = 0;
    int num = 0;
    for (int k = 0; k < static_cast<int>(Polymers.size()); k++)
    {
        for (int q = 0; q < Polymers[k]->Length(); q++)
        {
            num += 1;
            if (i == k && j == q)
            {
                accept++;
            }
            else
            {
                double cutoff_ = fmin(Polymers[k]->cutoff, Polymers[i]->cutoff);
                if (distance(i, j, k, q) >= cutoff_*0.02)
                {
                    accept++;
                }
            }
        }
    }

    if (accept == (num - 1))
    {
        return true;
    }
    else
    {
        return true;
    }
}

bool CheckAngle(int, int, int);

double Box::distance(int i, int j, int k, int q)
{
    // distance between j-th monomer of i-th polymer and q-th monomer of k-th polymer
    Polymer *p_i = Polymers[i];
    Polymer *p_k = Polymers[k];
    Monomer *p_i_j = p_i->getMonomer(j);
    Monomer *p_k_q = p_k->getMonomer(q);
    double dx = (p_i_j->GetX() - p_k_q->GetX());
    double dy = (p_i_j->GetY() - p_k_q->GetY());
    double dz = (p_i_j->GetZ() - p_k_q->GetZ());
    double r = sqrt(dx * dx + dy * dy + dz * dz);
    return r;
};

double Box::angle(int ip, int i, int j, int k)
{
    Monomer *temp1;
    Monomer *temp2;
    Monomer *temp3;
    temp1 = Polymers[ip]->getMonomer(i); //
    temp2 = Polymers[ip]->getMonomer(j); // last bead
    temp3 = Polymers[ip]->getMonomer(k); // next bead
    double vx1 = (temp2->GetX() - temp1->GetX());
    double vy1 = (temp2->GetY() - temp1->GetY());
    double vz1 = (temp2->GetZ() - temp1->GetZ());
    double vx2 = (temp3->GetX() - temp1->GetX());
    double vy2 = (temp3->GetY() - temp1->GetY());
    double vz2 = (temp3->GetZ() - temp1->GetZ());
    double dx1 = fabs(temp2->GetX() - temp1->GetX());
    double dy1 = fabs(temp2->GetY() - temp1->GetY());
    double dz1 = fabs(temp2->GetZ() - temp1->GetZ());
    double v1 = sqrt(pow(dx1, 2.0) + pow(dy1, 2.0) + pow(dz1, 2.0));
    double dx2 = fabs(temp3->GetX() - temp1->GetX());
    double dy2 = fabs(temp3->GetY() - temp1->GetY());
    double dz2 = fabs(temp3->GetZ() - temp1->GetZ());
    double v2 = sqrt(pow(dx2, 2.0) + pow(dy2, 2.0) + pow(dz2, 2.0));
    return acos((vx1 * vx2 + vy1 * vy2 + vz1 * vz2) / (v1 * v2));
};