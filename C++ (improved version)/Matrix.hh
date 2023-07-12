#ifndef MATRIX_HH 
#define MATRIX_HH

#include "Cell.hh"
#include <vector>

using namespace std;

class Matrix {
public:
  Matrix(int rows);
  ~Matrix();

  void avanzarTiempo();
  int contarVecinos(int i, int j);
  bool checkState(int i, int j);
  vector< vector< Cell>> matriz;

  void imprimirMatriz();

private:
  int numberOfRows;
  
};

#endif
