#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <vector>
using namespace std;

class Read
{
public:
    Read() {}
    void setFileName(string name)
    {
        filename = name;
        cout << filename << endl;
    }
    void openFile();
    vector<double> getLine();
    double getDouble();
    int getInt();
    void skipLine();
    // eof function
    void closeFile();

private:
    string filename;
    FILE *stream;
};