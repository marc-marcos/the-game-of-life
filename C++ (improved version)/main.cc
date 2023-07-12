#include<iostream>
#include "Cell.cc"
#include "Matrix.cc"
#include <SFML/Graphics.hpp>

using namespace std;

int SCREEN_SIZE = 1000;
int NUMBER_OF_ROWS = 500;

int main() {
  sf::RenderWindow window(sf::VideoMode(SCREEN_SIZE, SCREEN_SIZE), "Game of Life");
  sf::VertexArray lines(sf::Lines, 2);

  Matrix matrix = Matrix(NUMBER_OF_ROWS);

  window.setFramerateLimit(24);

  // matrix.imprimirMatriz();

  bool paused = false;
  bool reset = false;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();

      else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) paused = !paused;
        else if (event.key.code == sf::Keyboard::R) reset = true;
      }
    }
    // ! Quizá estos dos for se pueden unir en uno solo y mejora el rendimiento


    /*
    for (int i = 0; i < NUMBER_OF_ROWS; i++)
    {
      lines[0].position = sf::Vector2f(0, i*SCREEN_SIZE/NUMBER_OF_ROWS);
      lines[1].position = sf::Vector2f(SCREEN_SIZE, i*SCREEN_SIZE/NUMBER_OF_ROWS);

      window.draw(lines);
    }

    for (int i = 0; i < NUMBER_OF_ROWS; i++) {
      lines[0].position = sf::Vector2f(i*SCREEN_SIZE/NUMBER_OF_ROWS, 0);
      lines[1].position = sf::Vector2f(i*SCREEN_SIZE/NUMBER_OF_ROWS, SCREEN_SIZE);

      window.draw(lines);
    }
    */


    // Draw the matrix
    sf::RectangleShape square;
    square.setFillColor(sf::Color::White);
    square.setSize(sf::Vector2f(SCREEN_SIZE/NUMBER_OF_ROWS-1, SCREEN_SIZE/NUMBER_OF_ROWS-1));


    for (int i = 0; i < NUMBER_OF_ROWS; i++) {
      for (int j = 0; j < NUMBER_OF_ROWS; j++) {
        if (matrix.matriz[i][j].check_state() == 1) {
          square.setPosition(i*SCREEN_SIZE/NUMBER_OF_ROWS-1, j*SCREEN_SIZE/NUMBER_OF_ROWS-1);
          window.draw(square);
        }
      }
    }

    if (!paused) matrix.avanzarTiempo();

    if (reset) {
      matrix = Matrix(NUMBER_OF_ROWS);
      reset = false;
    }
    
    window.display();
    window.clear();
  }

}
