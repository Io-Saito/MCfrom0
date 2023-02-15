#include <vector>
#include "monomer.h"
using namespace std;

class Polymer
{

public:
    void addMonomer(Monomer *_Monomer) { Monomers.push_back(_Monomer); }

public:
    Monomer *getMonomer(int);
    void monomer_of_polymerMove(int);
    void monomer_of_polymerBack(int);
    void adjustBox(float, float, float);
    void adjustBoxback();
    double distance(int, int);
    double angle(int, int, int);
    bool Potential_in_chain(int);
    bool CheckAngle(int);
    void set_Cutoff(double cutoff_) { cutoff = cutoff_; }
    void set_BondAngle(double bondangle_) { BondAngle = bondangle_; }
    void set_identifier(char ID) { identifier = ID; }
    char get_identifier() { return identifier; }
    int Length() { return Monomers.size(); };

public:
    float cutoff;
    float BondAngle;

private:
    vector<Monomer *> Monomers;
    char identifier;
};