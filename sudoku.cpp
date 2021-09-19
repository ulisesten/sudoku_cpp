#include "sudoku.hpp"

#include <iostream>

Sudoku::Sudoku(){
    std::cout << "Sudoku:" << std::endl;
}

void Sudoku::creaMatriz(){

    int i,j, numero = 0;

    srand(time(0));

    for(j = 0; j < MAX; j++){
        for(i = 0; i < MAX; i++){
            
            numero = rand() % 9;
            
            if(this->validarInsercion(i, j, numero))
                element[i][j] = numero;
            else
                element[i][j] = 0;

            std::cout << element[i][j] << "  ";

        }
        //i = 0;
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

bool Sudoku::validarInsercion(int fila, int columna, int numero) {
    int i,j;
    
    /*verificar si existe en fila o en columna*/
    for(i = 0; i < MAX; i++) {
        if( numero == element[fila][i]) return false;
        if( numero == element[i][columna]) return false;
    }

    /*valida si número ya se encuentra en la subcuadricula*/
    int filaSubCadricula = this->getSubCuadricula(fila);
    int columnaSubCuadricula = this->getSubCuadricula(columna);

    for ( j = columnaSubCuadricula; j < columnaSubCuadricula + 3; j++) {
        for (i = filaSubCadricula; i < filaSubCadricula + 3; i++) {

            if(numero == element[i][j]) return false;

        }
        
    }

    return true;
    
}

int Sudoku::getSubCuadricula(int celda){
    if(celda < 3)
        return 0;
    
    else if(celda > 2 && celda < 6)
        return 3;

    else
        return 6;

}