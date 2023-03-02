#include "Polymer.h"

class RandomChain : public Polymer
{

public:
    void monomer_of_polymerMove(int) override;
    bool Potential_in_chain(int) override;
    bool CheckAngle(int) override;
};