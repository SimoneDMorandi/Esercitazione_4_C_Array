#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

int main()
{
  // Apro il file e verifico che l'apertura vada a buon fine.
  ifstream input_file("data.csv");
  if ( !input_file.is_open() )
  {
      cerr << "Impossibile aprire il file di input." << endl;
      return 1;
  }

  // Leggo il file e ricavo i dati necessari.
  /* Dato che il formato del file è noto, conviene memorizzare le due colonne principali
     e poi ricavare i valori desiderati.
     Ovviamente il codice diventa poco riutilizzabile in caso di file generici,
     ma recuperare la dimensione del file leggendolo per intero, per poi creare un array statico mi sembra
     inutilmente costoso a livello computazionale. */

  // Definisco la matrice in cui saranno memorizzati i dati.
  const int size_row = 11;
  const int size_col = 2;
  double data[size_row][size_col];

  // Inizio la lettura del file.
  int rows = 0;
  int column = 0;
  string line;
  while(getline(input_file,line) && rows < size_row)
  {
      stringstream ss(line);
      string cell;
      column = 0;

      // Leggo la riga estratta e riempio la matrice, ponendo a 0 i valori letterali.
      while(getline(ss,cell,';') && column < size_col)
      {
          try{
            data[rows][column] = stod(cell);
          } catch(...){
            data[rows][column] = 0.0;
          }
          column++;
      }
      rows++;
  }

  // Chiudo il file di input.
  input_file.close();

  // Calcolo il tasso di rendimento.
  double rate_of_return = r(data);

  // Calcolo il valore finale del portofolio.
  double final_value = data[0][1]*(1+rate_of_return);

  //Controllo l'apertura del file di output.
  ofstream of("result.txt", ios::out | ios::trunc);
  if(!of.is_open())
  {
    cerr << "Impossibile aprire il file di output." << endl;
    return 1;
  }

  // Stampo i risultati sul file.
  print_vec(data, of);  // Questa funzione stampa gli array letti in precedenza sia a schermo che sul file.
  of << endl;
  of << "Rate of return of the portfolio: " << fixed << setprecision(4) << rate_of_return << endl;
  of << "V: " << setprecision(2) << final_value << endl;

  // Chiudo il file di output.
  of.close();

  // Stampo i risultati a schermo.
  cout << endl;
  cout << "Rate of return of the portfolio: " << fixed << setprecision(4) << rate_of_return << endl;
  cout << "V: " << setprecision(2) << final_value << endl;

  return 0;
}
