#include <iostream> // <>
#include <time.h>

#define MAX 9

using std::cout;
using std::cin;

class Sudoku
{
private:
    int element[MAX][MAX];

public:
    Sudoku();
    void creaMatriz();
    void imprimeMatriz();

    /**
         * @brief valida que el número a ser ingresado no esté ya en
         * la misma fila ni en la misma columna
        */
    bool validarInsercion(int fila, int columna, int numero);

    bool validarCeldaEditable(int fila, int columna, int numero);

    /**
         * @brief por ahora solo imprime: jugando.
         * Esta es la función donde se pedirán las coordenadas y el número a ingresar
        */
    void jugar();

    /**
         * @brief por ahora solo imprime: comprobando..
         * Esta función comprobará si los números ingresados son correctos
         * y si el usuario ganó o perdió el juego
        */
    bool comprobar();

    int getSubCuadricula(int celda);
    ~Sudoku();
};


void mainLoop();

int main() {

    mainLoop();

    return 0;

}

void mainLoop(){
    int opcion = 0;

    
    Sudoku sudoku;
    sudoku.creaMatriz();

    while(opcion != 3){
        sudoku.imprimeMatriz();

        std::cout << "Opción 1: Jugar" << std::endl;
        std::cout << "Opción 2: Comprobar" << std::endl;
        std::cout << "Opción 3: Salir" << std::endl;

        /*capturando elección del usuario*/
        cin >> opcion;

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

        }
    }
}

void Sudoku::imprimeMatriz(){
    int i,j;
    for(j = 0; j < MAX; j++){
        for(i = 0; i < MAX; i++){

            std::cout << element[i][j] << "  ";
            if(i == 2 || i == 5)
                std::cout << "  ";

        }
        std::cout << std::endl;
        if(j == 2 || j == 5)
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