#include "Polymer.h"

using namespace std;
class Box
{
public:
    Box() {}
    Box(double _x, double _y, double _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    ~Box() {}

public:
    void setFieldDimensions(double _x, double _y, double _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    void addPolymers(vector<Polymer *> _polymer) { Polymers = _polymer; }

public:
    int move();
    bool Potential_between_chains(int, int);
    bool CheckAngle(int, int, int);
    double distance(int, int, int, int);
    double angle(int, int, int, int);
    void BoxMove();
    void BoxMoveBack();
    bool CheckBoxMove();

public:
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }

private:
    double rand();

private:
    double x, y, z;
    double x_old, y_old, z_old;
    vector<Polymer *> Polymers;
};