#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <vector>
using namespace std;
#include "Random.h"
#include "monomer.h"
#include "field.h"
#include "Read.h"
#include "WebLab.h"

int main()
{
    const int total_number_of_steps = 500;
    const int number_of_beads = 50;
    vector<Monomer *> beads(number_of_beads);
    vector<double> line;
    Read read;
    read.setFileName("/Users/io/Project/MCfrom0/Step0/start.txt");
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
    const int number_of_beads_in_polymer = 5;
    vector<Polymer *> polymers(number_of_polymers);
    for (i = 0; i < number_of_polymers; i++)
    {
        polymers[i] = new Polymer;
        polymers[i]->set_identifier(static_cast<char>(i));
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
    // WebLab weblab;
    // weblab.setFileName("movie.pdb");
    // weblab.openFile();
    cout << "ready to start";
    FILE *_stream;
    _stream = fopen("/Users/io/Project/MCfrom0/Step0/finish.txt", "w");
    cout << "ready to move polymer";

    Monomer *temp;
    int l;

    for (i = 0; i < total_number_of_steps; i++)
    {

        field->move();
        l = 1;
        // weblab.writeHeader(i);
        fprintf(_stream, "%d\n", i);
        cout << i << "th iteration \n";
        fprintf(_stream, "%lf\t%lf\t%lf\n", field->getX(), field->getY(), field->getZ());
        for (j = 0; j < number_of_polymers; j++)
        {
            for (int k = 0; k < number_of_beads_in_polymer; k++)
            {
                temp = polymers[j]->getMonomer(k);
                fprintf(_stream, "%lf\t", temp->GetX());
                fprintf(_stream, "%lf\t", temp->GetY());
                fprintf(_stream, "%lf\n", temp->GetZ());
                // weblab.writePosition(l, polymers[j]->get_identifier(), j, temp->GetX(), temp->GetY(), temp->GetZ());
                l++;
            }
        }
        fprintf(_stream, "\n");
        // weblab.writeEnd();
    }
    fclose(_stream);
    // weblab.closeFile();
    cout << "finish" << endl;
    return 0;
}