#include "sudoku.hpp"

#include <iostream>

Sudoku::Sudoku(){
    std::cout << "Sudoku:" << std::endl;
}

void Sudoku::creaMatriz(){
    int fila, columna;

    for(columna = 0; columna < MAX; columna++){
        for(fila = 0; fila < MAX; fila++){
            element[fila][columna] = 0;

            std::cout << 0 << "  ";
        }
        fila = 0;
        std::cout << std::endl;
    }
}

bool Sudoku::jugar(){
    std::cout << "jugando.." << std::endl;
    return true;
}

bool Sudoku::comprobar(){
    std::cout << "comprobando.." << std::endl;
    return true;
}

Sudoku::~Sudoku(){

}