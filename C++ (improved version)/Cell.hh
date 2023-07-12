#ifndef CELL_H
#define CELL_H

class Cell {
public:
  Cell(bool estado);
  Cell(int estado);
  Cell();
  ~Cell();

  bool check_state();
  void change_state();
  void print_itself();

private:
  bool alive;
  
};

#endif
