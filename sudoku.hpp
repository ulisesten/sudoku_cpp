#ifndef _SUDOKU_HPP_
#define _SUDOKU_HPP_

#define MAX 9


/**
  * @brief Clase sudoku
  */
class Sudoku {
    private:
        int element[MAX][MAX];

    public:
        /**
         * @brief Inicializa la matriz y la imprime en pantalla
        */
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

        Sudoku();

        ~Sudoku();

};

#endif