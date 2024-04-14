#ifndef UTILS_HPP
#define UTILS_HPP
#include <fstream>

using namespace std;

// Definisco la funzione che stampa i valori di "w" e "r".
void print_vec(const double (&data)[11][2], ofstream& of);

// Definisco la funzione che calcola il tasso di rendimento.
double r(const double (&data)[11][2]);

#endif
