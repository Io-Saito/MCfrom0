#pragma once
class Random
{
public:
    Random() { setSeed(); }
    double randomNumber();

private:
    void setSeed();
    double ran1();

private:
    int idum;
};