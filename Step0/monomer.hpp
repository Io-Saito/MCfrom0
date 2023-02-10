
struct Position
{
    double x, y, z;
};

class Monomer
{
public:
    void SetX(double _x) { x = _x; }
    void SetY(double _y) { y = _y; }
    void SetZ(double _z) { z = _z; }
    void setEnergy(double e) { energy = e; }

public:
    double GetX() { return x; }
    double GetY() { return y; }
    double GetZ() { return z; }
    double getEnergy() { return energy; }

public:
    void update();
    void getback();
    void AdjsutBox();
    void AdjsutBoxBack();

private:
    double x, y, z;
    double x_old, y_old, z_old;
    double energy;
};