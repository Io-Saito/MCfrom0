#include "Monomer.h"
#include <math.h>
#pragma once
using namespace std;

class Polymer
{
public:
public:
    void addMonomer(Monomer *_Monomer) { Monomers.push_back(_Monomer); }

public:
    Monomer *getMonomer(int);
    virtual void monomer_of_polymerMove(int);
    void monomer_of_polymerBack(int);
    void adjustBox(float, float, float);
    void adjustBoxback();
    void set_BondLength(double bond_length) { BondLength = bond_length; }
    double distance(int, int);
    double angle(int, int, int);
    bool Potential_in_chain(int);
    bool CheckAngle(int);
    void set_Cutoff(double cutoff_) { cutoff = cutoff_; }
    void set_BondAngle(double bondangle_) { BondAngle = bondangle_ * M_PI / 180; }
    int Length() { return static_cast<int>(Monomers.size()); };

public:
    float cutoff;
    float BondAngle;
    float BondLength;
    vector<Monomer *> Monomers;
};