#include "sudoku.hpp"

#include <iostream>

Sudoku::Sudoku(){
    std::cout << "Sudoku:" << std::endl;
}

void Sudoku::creaMatriz(){
    int fila, columna;
    int i,j;
    bool prensentInFila = false;
    bool presentInColumn = false;

    for(j = 0; j < MAX; j++){
        for(i = 0; i < MAX; i++){
            element[i][j] = 0;

            //if(this->validarNumero())

            std::cout << 0 << "  ";
        }
        i = 0;
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

bool Sudoku::validarNumero(int fila, int columna, int numero){
    int i,j;
    
    /*verificar si existe en fila o en columna*/
    for(i = 0; i < MAX; i++){
        if( numero == element[fila][i]) return false;
        if( numero == element[i][columna]) return false;
    }

    /*valida si número ya se encuentra en la subcuadricula*/
    int filaSubCadricula = fila / 3;
    int columnaSubCuadricula = columna / 3;

    for ( j = columnaSubCuadricula; j < columnaSubCuadricula + 3; j++) {
        for (i = filaSubCadricula; i < filaSubCadricula + 3; i++) {

            if(numero == element[i][j]) return false;
            
        }
        
    }
    
}

void Sudoku::testingInit(){
    int matriz[9][9];
	
	srand(time(0));
	
	for(int i = 0; i<9; i++){
		for(int j = 0; j<9; j++){
			matriz[i][j] = 0;
		}
	}
	
	for(int i = 0; i<31; i++){
		int ale1 = rand() % 9;
		int ale2 = rand() % 9;
		
		matriz[ale1][ale2] = 1 + rand() % 9;
	}
	
	std::cout<<std::endl;
	
	for(int i = 0; i<9; i++){
		std::cout << std::endl;
		for(int j = 0; j<9; j++){
			std::cout << matriz[i][j] << " ";
		}
	}
}