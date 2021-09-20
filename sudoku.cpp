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
            
            numero = rand() % MAX;
            
            if(this->validarInsercion(i, j, numero))
                element[i][j] = numero;
            else
                element[i][j] = 0;

            //std::cout << element[i][j] << "  ";

        }
        //i = 0;
        //std::cout << std::endl;
    }
}

void Sudoku::imprimeMatriz(){
    int i,j;
    for(j = 0; j < MAX; j++){
        for(i = 0; i < MAX; i++){

            std::cout << element[i][j] << "  ";

        }
        std::cout << std::endl;
    }
}

void Sudoku::jugar(){
    int x,y, numero;
    bool res = false;
    std::cout << "Ingresa coordenada x: "; std::cin >> x;
    std::cout << "Ingresa coordenada y: "; std::cin >> y;
    std::cout << "Ingresa número: "; std::cin >> numero;

    if(this->validarInsercion(x, y, numero)){
        if(this->validarCeldaEditable(x, y, numero)){
            res = true;

        } else {
            res = false;
            std::cout << "Celda no editable" << std::endl;
        }
    } else {
        std::cout << "El numero ya se encuentra en la cuadrícula" << std::endl;
    }

    if(res)
          element[x][y] = numero;
        
}

bool Sudoku::comprobar(){
    int i, j;
    bool res = false;
    for(j = 0; j < MAX; j++){
        for(i = 0; i < MAX; i++){
            if(this->validarInsercion( i, j, element[i][j])){
                res = true;
            } else {
                res = false;
            }

        }
    }

    if(res)
        std::cout << "Victoria!!!" << std::endl;
    else
        std::cout << "Perdiste" << std::endl;

    return true;
}


bool Sudoku::validarInsercion(int fila, int columna, int numero) {
    int i,j;
    
    /*verificar si número existe en fila o en columna*/
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

bool Sudoku::validarCeldaEditable(int fila, int columna, int numero){
    if(element[fila][columna] != 0)
        return false;

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

Sudoku::~Sudoku(){

}