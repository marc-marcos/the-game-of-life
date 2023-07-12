# The Game of Life 

A simple script to simulate and visualiza John Conway's game of life.

<img src="img/readme_gif.gif"
     alt="Markdown Monster icon"
     />

## Description

This project is a very simplescript that simulates and draws the result to a Pygame window to be able to see them.

## Getting Started

### Dependencies

* Python 3
* Ubuntu (or any other Unix system) 

### Installing

#### Python version
* Clone the repository
* ``pip install -r requirements.txt``

#### C++ version
* Clone the repository
* ``sudo apt get install libsfml-dev``
* (in C++ improved version folder) ``make``
* ``./output.exe``

### Executing program

* ``python3 index.py <winwo-size-px> <number-of-rows> <delay-in-seconds>``

## Help

This script at the moment only runs in Unix, running it in Windows might result in errors.

## Authors
[@marc-marcos](https://github.com/marc-marcos)

## Version History

* 0.1
    * C++ version, very basic
* 0.2
    * Python version, still terminal based, better code
* 0.3
    * Pygame implemented, graphical output
* 0.4
    * C++ graphical version done. Runs ~6.5 times faster than the 0.3 Python version.

## License

This project is licensed under the GPL License - see the LICENSE.md file for details