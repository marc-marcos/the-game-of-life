#include "Cell.hh"
#include <iostream>

using namespace std;

Cell::Cell() {
  alive = false;
}

Cell::Cell(bool estado) {
  alive = estado;
}

Cell::Cell(int estado) {
  if (estado == 0) alive = false;
  else alive = true;
}

bool Cell::check_state() {
  if (alive == true) return true;
  else return false;
}

void Cell::change_state() {
  if (alive == true) alive = false;
  else alive = true;
}

void Cell::print_itself() {
  if (alive == true) cout << "#";
  else cout << " ";
}

Cell::~Cell() {
  
}
