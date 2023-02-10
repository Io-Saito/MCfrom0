#include <monomer.h>
#include <vector>
using std::vector;

class Polymer
{

public:
    void addMonomer(Monomer *_Monomer) { Monomers.push_back(_Monomer); }

public:
    Monomer *getMonomer(int);
    void bead_of_polymerMove(int);
    void bead_of_polymerBack(int);
    double distance(int, int);
    bool Potential_in_chain(int);

private:
    vector<Monomer* > Monomers;
};