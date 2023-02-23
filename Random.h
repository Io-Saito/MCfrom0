#pragma once
class Random
{
public:
    Random() { setSeed(); }
    double randomNumber();
    double randomAngle();

private:
    void setSeed();
    double ran1(long *);

private:
    long idum;
};