
struct Position{
    double x, y, z;
};

class Monomer
{
public:
    void SetX(double _x) { x = _x; }
    void SetY(double _y) { y = _y; }
    void SetZ(double _z) { z = _z; }
    void setDiameter(double d) { diameter = d; }
    void setEnergy(double e) { energy = e; }

public:
    double getDiameter() { return diameter; }
    double getEnergy() { return energy; }

public:
    void update();
    void getback();

private:
    double x,y,z;
    double x_old,y_old,z_old;
    double diameter;
    double energy;
};