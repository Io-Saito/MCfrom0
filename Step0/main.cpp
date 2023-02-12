#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <vector>
using namespace std;
#include "Random.hpp"
#include "monomer.hpp"
#include "field.hpp"
#include "Read.hpp"
#include "WebLab.hpp"

int main()
{
    const int total_number_of_steps = 500;
    const int number_of_beads = 100;
    vector<Monomer *> beads(number_of_beads);
    vector<double> line;
    Read read;
    read.setFileName("/Users/io/Project/MCfrom0/MCfrom0/Step0/start.txt");
    read.openFile();
    int i, j;
    for (i = 0; i < number_of_beads; i++)
    {
        beads[i] = new Monomer;
        line = read.getLine();
        beads[i]->SetX(line[0]);
        beads[i]->SetY(line[1]);
        beads[i]->SetZ(line[2]);
    }
    read.closeFile();

    const int number_of_polymers = 10;
    const int number_of_beads_in_polymer = 10;
    vector<Polymer *> polymers(number_of_polymers);

    for (i = 0; i < number_of_polymers; i++)
    {
        polymers[i] = new Polymer;
        for (j = 0; j < number_of_beads_in_polymer; j++)
        {
            polymers[i]->addMonomer(beads[j + i * number_of_beads_in_polymer]);
        }
    }

    double box_x = 20.0;
    double box_y = 20.0;
    double box_z = 20.0;
    Field *field = new Field(box_x, box_y, box_z);
    field->addPolymers(polymers);

    WebLab weblab;
    weblab.setFileName("movie.pdb");
    weblab.openFile();
    vector<char> chain(10);
    chain[0] = 'A';
    chain[1] = 'B';
    chain[2] = 'C';
    chain[3] = 'D';
    chain[4] = 'E';
    chain[5] = 'F';
    chain[6] = 'G';
    chain[7] = 'H';
    chain[8] = 'I';
    chain[9] = 'J';

    FILE *_stream;
    _stream = fopen("/Users/io/Project/MCfrom0/MCfrom0/Step0/finish.txt", "w");

    Monomer *temp;
    int l;

    for (i = 0; i < total_number_of_steps; i++)
    {

        field->move();
        l = 1;
        weblab.writeHeader(i);
        fprintf(_stream, "%d\n", i);
        fprintf(_stream, "%lf\t%lf\t%lf\n", field->getX(), field->getY(), field->getZ());
        for (j = 0; j < number_of_polymers; j++)
        {
            for (int k = 0; k < number_of_beads_in_polymer; k++)
            {
                temp = polymers[j]->getMonomer(k);
                fprintf(_stream, "%lf\t", temp->GetX());
                fprintf(_stream, "%lf\t", temp->GetY());
                fprintf(_stream, "%lf\n", temp->GetZ());
                weblab.writePosition(l, chain[j], j, temp->GetX(), temp->GetY(), temp->GetZ());
                l++;
            }
        }
        fprintf(_stream, "\n");
        weblab.writeEnd();
    }
    fclose(_stream);
    weblab.closeFile();
    cout << "finish" << endl;
    return 0;
}