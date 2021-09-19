#ifndef _SUDOKU_HPP_
#define _SUDOKU_HPP_

#define MAX 9

class Sudoku {
    private:
        int element[MAX][MAX];
        
    public:
        void creaMatriz();
        bool jugar();
        bool comprobar();
        Sudoku();
        ~Sudoku();

};

#endif