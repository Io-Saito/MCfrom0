
#include <polymer.h>
#include <monomer.h>
#include <vector>
using std::vector;

class Field
{
public:
    Field() {}
    Field(double _x, double _y, double _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    ~Field() {}

public:
    void setFieldDimensions(double _x, double _y, double _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    void addPolymers(vector<Polymer *> _polymer) { polymers = _polymer; }

public:
    int move(int);
    bool Potential_between_chains(int, int, int);
    bool CheckAngle(int, int, int);
    double distance(int, int, int, int);
    double angle(int, int, int, int);

public:
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }

private:
    double rand();

private:
    double x, y, z;
    double x_old, y_old, z_old;
    vector<Polymer *> polymers;
};