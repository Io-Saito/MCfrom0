#pragma once
class Monomer
{
public:

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
    void update(float,float,float);
    void getback();
    void AdjustField(float, float, float);

private:
    double x, y, z;
    double x_old, y_old, z_old;
    double energy;
};
