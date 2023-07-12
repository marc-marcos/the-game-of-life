#include "Matrix.hh"
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <iostream>
#include <chrono>

using namespace std;

Matrix::Matrix(int rows) {
  this->numberOfRows = rows;
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  std::uniform_int_distribution<int> distribution(0, 1);

  vector< vector< Cell>> matriz(rows, vector<Cell>(rows));

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < rows; j++)
    {
      matriz[i][j] = Cell(distribution(generator));
    }
    
  }

  this->matriz = matriz;
}

bool Matrix::checkState(int i, int j) {
  return matriz[i][j].check_state();
}

void Matrix::imprimirMatriz() {
  for (int i = 0; i < numberOfRows; i++)
  {
    for (int j = 0; j < numberOfRows; j++)
    {
      matriz[i][j].print_itself();
    }
    cout << endl;
  }
  
}

int Matrix::contarVecinos(int i, int j) {
  int suma = 0;

  if (i < numberOfRows-1 and j < numberOfRows-1 and i > 0 and j > 0) {
    if (i > 0) {
      if (j > 0) if (matriz[i-1][j-1].check_state()) suma = suma + 1;
      if (matriz[i-1][j].check_state()) suma = suma + 1;
      if (j < numberOfRows-1) if (matriz[i-1][j+1].check_state()) suma = suma + 1;
    }

    if (j > 0) if (matriz[i][j-1].check_state()) suma = suma + 1;
    if (j < numberOfRows-1) if (matriz[i][j+1].check_state()) suma = suma + 1;

    if (i < numberOfRows-1) {
      if (j > 0) if (matriz[i+1][j-1].check_state()) suma = suma + 1;
      if (matriz[i+1][j].check_state()) suma = suma + 1;
      if (j < numberOfRows-1) if (matriz[i+1][j+1].check_state()) suma = suma + 1;
    }
    return suma;
  }
  
  return -1;
}

void Matrix::avanzarTiempo() {
  vector< vector< Cell>> nuevaMatriz = matriz;

  for (int i = 0; i < numberOfRows; i++) {
    for (int j = 0; j < numberOfRows; j++) {
      int vecinos = contarVecinos(i, j);

      if (matriz[i][j].check_state()) { // Si esta vivo
        if (vecinos < 2) nuevaMatriz[i][j].change_state();
        else if (vecinos > 3) nuevaMatriz[i][j].change_state();
      } else { // Si esta muerto
        if (vecinos == 3) nuevaMatriz[i][j].change_state();
      }
    }
  }

  matriz = nuevaMatriz;
}

Matrix::~Matrix() {
  
}
