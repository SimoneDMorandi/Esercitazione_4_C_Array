#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//Corpo della funzione di stampa di "w" e "r".
void print_vec(const double (&data)[11][2], ofstream &of)
{
    // Ricavo i valori di "S" e "N" dal file, stampandoli.
    double S = data[0][1];
    int n = data[1][1];
    of << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    of << defaultfloat;

    cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    cout << defaultfloat;

    // Stampo le componenti di "w" e "r".
    int size_row = 11;
    int size_col = 2;
    for (int j = 0; j<size_col; j++)
    {
        if( j==0){
            of << "w = [ ";
            cout << "w = [ ";
        }
        else{
            of << "r = [ ";
            cout << "r = [ ";
        }
        for(int i=3; i<size_row ; i++)
        {
            of << data[i][j] << " ";
            cout << data[i][j] << " ";
        }
        of << "]";
        cout << "]";
        if (j == 0)
        {
            of << endl;
            cout << endl;
        }
    }
}

// Corpo della funzione per il calcolo del tasso di rendimento.
double r(const double (&data)[11][2])
{
    int size_row = 11;
    int size_col = 2;
    double rate_of_return = 0;
    for (int i=3; i < size_row; i++)
    {
        // Rendimento calcolato come media pesata dei singoli r_i.
        double prod = 1.0;
        for (int j=0; j < size_col; j++)
        {
            prod *=data[i][j];
        }
        rate_of_return += prod;
    }
    return rate_of_return;
}
