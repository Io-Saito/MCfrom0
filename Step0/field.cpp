#include "field.hpp"
#include <math.h>
#include "Random.hpp"

int Field::move(){
    for (int i =0; i<Polymers.size(); i++){
        Polymer *temp = Polymers[i];
        for (int j = 0; j < temp->Length(); j++){
            temp->monomer_of_polymerMove(j);
            if (Potential_between_chains(i, j) && temp->Potential_in_chain(j) && temp->CheckAngle(j)){
            }else{
                temp->monomer_of_polymerBack(j);
            }
        }
    }

    ////moving Box
    Random rand;
    x_old = x;
    y_old = y;
    z_old = z;
    x = x_old + rand.randomNumber() ;
    y = y_old + rand.randomNumber() ;
    z = z_old + rand.randomNumber() ;
    Monomer *temp_Monomer;
    //Move all monomers to adjust Box
    for (int i = 0; i < Polymers.size(); i++)
    {
        for (int j = 0; j < Polymers[i]->Length(); j++)
        {
            temp_Monomer = Polymers[i]->getMonomer(j);
            temp_Monomer->SetX(temp_Monomer->GetX() * x / x_old);
            temp_Monomer->SetY(temp_Monomer->GetY() * y / y_old);
            temp_Monomer->SetZ(temp_Monomer->GetZ() * z / z_old);
        }
    }

    for (int i = 0; i < Polymers.size(); i++)
    {
        Polymer *temp = Polymers[i];
        for (int j = 0; j < temp->Length(); j++)
        {
            if (Potential_between_chains(i, j) && temp->Potential_in_chain(j) && temp->CheckAngle(j)){
            }
            else
            {
                
            }
        }
    }

    // cout << "box move accepted" << endl;
    return 0;
};

bool Field::Potential_between_chains(int i, int j){
    // Potential between j-th monomer of i-th polymer and other all monomers 
        int accept = 0;
        int num=0;
        Monomer *temp1;
        Monomer *temp2;
        temp1 = Polymers[i]->getMonomer(j);
        for (int k = 0; k < Polymers.size(); k++){
        for (int q = 0; q < Polymers[k]->Length(); q++){
            num+=1;
            if (i == k && j == q){}
            else{
                    double cutoff_ = fmin(Polymers[k]->cutoff, Polymers[i]->cutoff);
                    temp2 = Polymers[k]->getMonomer(q);
                    if (distance(i, j, k, q) >= cutoff_){
                        accept++;
                    }
            }
        }
        }

        if (accept == (num - 1)){
        return true;
        }else{
        return false;
        }
}


bool CheckAngle(int, int, int);

double Field::distance(int i, int j, int k, int q){
    //distance between j-th monomer of i-th polymer and q-th monomer of k-th polymer
    Polymer *p_i= Polymers[i];
    Polymer *p_k= Polymers[k];
    Monomer *p_i_j= p_i->getMonomer(j);
    Monomer *p_k_q = p_k->getMonomer(q);
    double dx = (p_i_j->GetX() - p_k_q->GetX());
    double dy = (p_i_j->GetY() - p_k_q->GetY());
    double dz = (p_i_j->GetZ() - p_k_q->GetZ());
    double r =sqrt(dx*dx + dy*dy + dz*dz);
    return r;
};


double Field::angle(int ip,int i, int j, int k){
    Monomer *temp1;
    Monomer *temp2;
    Monomer *temp3;
    temp1 = Polymers[ip]->getMonomer(i); //
    temp2 = Polymers[ip]->getMonomer(j); // last bead
    temp3 = Polymers[ip]->getMonomer(k); // next bead
    double vx1 = (temp2->GetX() - temp1->GetX());
    double vy1 = (temp2->GetY() - temp1->GetY());
    double vz1 = (temp2->GetZ() - temp1->GetZ());
    double vx2 = (temp3->GetX() - temp1->GetX());
    double vy2 = (temp3->GetY() - temp1->GetY());
    double vz2 = (temp3->GetZ() - temp1->GetZ());
    double dx1 = fabs(temp2->GetX() - temp1->GetX());
    double dy1 = fabs(temp2->GetY() - temp1->GetY());
    double dz1 = fabs(temp2->GetZ() - temp1->GetZ());
    double v1 = sqrt(pow(dx1, 2.0) + pow(dy1, 2.0) + pow(dz1, 2.0));
    double dx2 = fabs(temp3->GetX() - temp1->GetX());
    double dy2 = fabs(temp3->GetY() - temp1->GetY());
    double dz2 = fabs(temp3->GetZ() - temp1->GetZ());
    double v2 = sqrt(pow(dx2, 2.0) + pow(dy2, 2.0) + pow(dz2, 2.0));
    return acos((vx1 * vx2 + vy1 * vy2 + vz1 * vz2) / (v1 * v2));
};