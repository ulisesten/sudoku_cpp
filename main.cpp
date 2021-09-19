#include <iostream>
#include "sudoku.hpp"

void mainLoop();

int main() {

    mainLoop();

    return 0;

}

void mainLoop(){
    int opcion = 0;

    /*
     *Creando objeto sudoku */
    Sudoku sudoku;

    while(opcion != 3){
        sudoku.creaMatriz();
        //sudoku.testingInit();
        std::cout << "Opción 1: Jugar" << std::endl;
        std::cout << "Opción 2: Comprobar" << std::endl;
        std::cout << "Opción 3: Salir" << std::endl;

        /*capturando elección del usuario*/
        std::cin >> opcion;

        /*limpiando consola*/
        system("cls");

        switch (opcion)
        {
            case 1:
                sudoku.jugar();
                break;
            case 2:
                sudoku.comprobar();
                break;
            
            default:
                if(opcion != 3)
                    std::cout << "Elige una opción entre 1 y 3" << std::endl;
                break;

        }
        
    }
}