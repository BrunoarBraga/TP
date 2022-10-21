#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

// LEMBRAR DE AUMENTAR O NÚMERO DE ROUNDS PELO PONTEIRO (TALVEZ)

int computer_Move(char** board, int *num_of_rounds, int n){

    *num_of_rounds = *num_of_rounds + 1;
    srand(time(NULL));
    int random, random1, random2;

    // Evita a derrota imediata na primeira rodada
    if(*num_of_rounds == 2){

        if((board)[1][1] == 'X'){

            random = rand() % 4;
            switch (random) {
                case 0:
                    (board)[0][0] = 'O';
                    return 0;
                case 1:
                    (board)[0][2] = 'O';
                    return 0;
                case 2:
                    (board)[2][0] = 'O';
                    return 0;
                case 3:
                    (board)[2][2] = 'O';
                    return 0;
            }
        }

        else if((board)[0][1] == 'X') {

            random = rand() % 6;
            switch (random) {
                case 0:
                    (board)[0][0] = 'O';
                    return 0;
                case 1:
                    (board)[0][2] = 'O';
                    return 0;
                case 2:
                    (board)[1][1] = 'O';
                    return 0;
                case 3:
                    (board)[2][1] = 'O';
                    return 0;
                case 4:
                    (board)[2][0] = 'O';
                    return 0;
                case 5:
                    (board)[2][2] = 'O';
                    return 0;
            }
        }

        else if((board)[1][2] == 'X') {

            random = rand() % 6;
            switch (random) {
                case 0:
                    (board)[0][0] = 'O';
                    return 0;
                case 1:
                    (board)[0][2] = 'O';
                    return 0;
                case 2:
                    (board)[1][1] = 'O';
                    return 0;
                case 3:
                    (board)[1][0] = 'O';
                    return 0;
                case 4:
                    (board)[2][0] = 'O';
                    return 0;
                case 5:
                    (board)[2][2] = 'O';
                    return 0;
            }
        }

        else if((board)[1][0] == 'X') {

            random = rand() % 6;
            switch (random) {
                case 0:
                    (board)[0][0] = 'O';
                    return 0;
                case 1:
                    (board)[0][2] = 'O';
                    return 0;
                case 2:
                    (board)[1][1] = 'O';
                    return 0;
                case 3:
                    (board)[1][2] = 'O';
                    return 0;
                case 4:
                    (board)[2][0] = 'O';
                    return 0;
                case 5:
                    (board)[2][2] = 'O';
                    return 0;
            }
        }

        else if((board)[2][1] == 'X') {

            random = rand() % 6;
            switch (random) {
                case 0:
                    (board)[0][0] = 'O';
                    return 0;
                case 1:
                    (board)[0][2] = 'O';
                    return 0;
                case 2:
                    (board)[1][1] = 'O';
                    return 0;
                case 3:
                    (board)[0][1] = 'O';
                    return 0;
                case 4:
                    (board)[2][0] = 'O';
                    return 0;
                case 5:
                    (board)[2][2] = 'O';
                    return 0;
            }
        }

        else if((board)[0][0] == 'X' ||
                (board)[0][2] == 'X' ||
                (board)[2][0] == 'X' ||
                (board)[2][2] == 'X'   ) {
            (board)[1][1] = 'O';
            return 0;
        }

    }


    //Impede o jogador de ganhar, se for possível a própria maquina ganhar, ela ganha
    else {

        //Verifica se dá pra ganhar
        if(*num_of_rounds >= 6){

            if ((board)[0][0] == 'O' && (board)[0][1] == 'O' && (board[0][2] == '-')) {
                (board)[0][2] = 'O';
                return 0;
            }
            else if ((board)[0][0] == 'O' && (board)[0][2] == 'O' && (board[0][1] == '-')) {
                (board)[0][1] = 'O';
                return 0;
            }
            else if ((board)[0][1] == 'O' && (board)[0][2] == 'O' && (board[0][0] == '-')) {
                (board)[0][0] = 'O';
                return 0;
            }

                //linha 2
            else if ((board)[1][0] == 'O' && (board)[1][1] == 'O' && (board[1][2] == '-')) {
                (board)[1][2] = 'O';
                return 0;
            }
            else if ((board)[1][0] == 'O' && (board)[1][2] == 'O' && (board[1][1] == '-')) {
                (board)[1][1] = 'O';
                return 0;
            }
            else if ((board)[1][1] == 'O' && (board)[1][2] == 'O' && (board[1][0] == '-')) {
                (board)[1][0] = 'O';
                return 0;
            }

                //linha 3
            else if ((board)[2][0] == 'O' && (board)[2][1] == 'O' && (board[2][2] == '-')) {
                (board)[2][2] = 'O';
                return 0;
            }
            else if ((board)[2][0] == 'O' && (board)[2][2] == 'O' && (board[2][1] == '-')) {
                (board)[2][1] = 'O';
                return 0;
            }
            else if ((board)[2][1] == 'O' && (board)[2][2] == 'O' && (board[2][0] == '-')) {
                (board)[2][0] = 'O';
                return 0;
            }

                //coluna 1
            else if ((board)[0][0] == 'O' && (board)[1][0] == 'O' && (board[2][0] == '-')) {
                (board)[2][0] = 'O';
                return 0;
            }
            else if ((board)[1][0] == 'O' && (board)[2][0] == 'O' && (board[0][0] == '-')) {
                (board)[0][0] = 'O';
                return 0;
            }
            else if ((board)[0][0] == 'O' && (board)[2][0] == 'O' && (board[1][0] == '-')) {
                (board)[1][0] = 'O';
                return 0;
            }

                //coluna 2
            else if ((board)[0][1] == 'O' && (board)[1][1] == 'O' && (board[2][1] == '-')) {
                (board)[2][1] = 'O';
                return 0;
            }
            else if ((board)[1][1] == 'O' && (board)[2][1] == 'O' && (board[0][1] == '-')) {
                (board)[0][1] = 'O';
                return 0;
            }
            else if ((board)[0][1] == 'O' && (board)[2][1] == 'O' && (board[1][1] == '-')) {
                (board)[1][1] = 'O';
                return 0;
            }

                //coluna 3
            else if ((board)[0][2] == 'O' && (board)[1][2] == 'O' && (board[2][2] == '-')) {
                (board)[2][2] = 'O';
                return 0;
            }
            else if ((board)[1][2] == 'O' && (board)[2][2] == 'O' && (board[0][2] == '-')) {
                (board)[0][2] = 'O';
                return 0;
            }
            else if ((board)[0][2] == 'O' && (board)[2][2] == 'O' && (board[1][2] == '-')) {
                (board)[1][2] = 'O';
                return 0;
            }

                //Diagonal 1
            else if ((board)[0][0] == 'O' && (board)[1][1] == 'O' && (board[2][2] == '-')) {
                (board)[2][2] = 'O';
                return 0;
            }
            else if ((board)[0][0] == 'O' && (board)[2][2] == 'O' && (board[1][1] == '-')) {
                (board)[1][1] = 'O';
                return 0;
            }
            else if ((board)[1][1] == 'O' && (board)[2][2] == 'O' && (board[0][0] == '-')) {
                (board)[0][0] = 'O';
                return 0;
            }

                //Diagonal 2
            else if ((board)[0][2] == 'O' && (board)[1][1] == 'O' && (board[2][0] == '-')) {
                (board)[2][0] = 'O';
                return 0;
            }
            else if ((board)[1][1] == 'O' && (board)[2][0] == 'O' && (board[0][2] == '-')) {
                (board)[0][2] = 'O';
                return 0;
            }
            else if ((board)[0][2] == 'O' && (board)[2][0] == 'O' && (board[1][1] == '-')) {
                (board)[1][1] = 'O';
                return 0;
            }



        }

        //Verifica se dá pra perder
        //Linha 1
        if ((board)[0][0] == 'X' && (board)[0][1] == 'X' && (board[0][2] == '-')) {
            (board)[0][2] = 'O';
            return 0;
        }
        else if ((board)[0][0] == 'X' && (board)[0][2] == 'X' && (board[0][1] == '-')) {
            (board)[0][1] = 'O';
            return 0;
        }
        else if ((board)[0][1] == 'X' && (board)[0][2] == 'X' && (board[0][0] == '-')) {
            (board)[0][0] = 'O';
            return 0;
        }

            //linha 2
        else if ((board)[1][0] == 'X' && (board)[1][1] == 'X' && (board[1][2] == '-')) {
            (board)[1][2] = 'O';
            return 0;
        }
        else if ((board)[1][0] == 'X' && (board)[1][2] == 'X' && (board[1][1] == '-')) {
            (board)[1][1] = 'O';
            return 0;
        }
        else if ((board)[1][1] == 'X' && (board)[1][2] == 'X' && (board[1][0] == '-')) {
            (board)[1][0] = 'O';
            return 0;
        }

            //linha 3
        else if ((board)[2][0] == 'X' && (board)[2][1] == 'X' && (board[2][2] == '-')) {
            (board)[2][2] = 'O';
            return 0;
        }
        else if ((board)[2][0] == 'X' && (board)[2][2] == 'X' && (board[2][1] == '-')) {
            (board)[2][1] = 'O';
            return 0;
        }
        else if ((board)[2][1] == 'X' && (board)[2][2] == 'X' && (board[2][0] == '-')) {
            (board)[2][0] = 'O';
            return 0;
        }

            //coluna 1
        else if ((board)[0][0] == 'X' && (board)[1][0] == 'X' && (board[2][0] == '-')) {
            (board)[2][0] = 'O';
            return 0;
        }
        else if ((board)[1][0] == 'X' && (board)[2][0] == 'X' && (board[0][0] == '-')) {
            (board)[0][0] = 'O';
            return 0;
        }
        else if ((board)[0][0] == 'X' && (board)[2][0] == 'X' && (board[1][0] == '-')) {
            (board)[1][0] = 'O';
            return 0;
        }

            //coluna 2
        else if ((board)[0][1] == 'X' && (board)[1][1] == 'X' && (board[2][1] == '-')) {
            (board)[2][1] = 'O';
            return 0;
        }
        else if ((board)[1][1] == 'X' && (board)[2][1] == 'X' && (board[0][1] == '-')) {
            (board)[0][1] = 'O';
            return 0;
        }
        else if ((board)[0][1] == 'X' && (board)[2][1] == 'X' && (board[1][1] == '-')) {
            (board)[1][1] = 'O';
            return 0;
        }

            //coluna 3
        else if ((board)[0][2] == 'X' && (board)[1][2] == 'X' && (board[2][2] == '-')) {
            (board)[2][2] = 'O';
            return 0;
        }
        else if ((board)[1][2] == 'X' && (board)[2][2] == 'X' && (board[0][2] == '-')) {
            (board)[0][2] = 'O';
            return 0;
        }
        else if ((board)[0][2] == 'X' && (board)[2][2] == 'X' && (board[1][2] == '-')) {
            (board)[1][2] = 'O';
            return 0;
        }

            //Diagonal 1
        else if ((board)[0][0] == 'X' && (board)[1][1] == 'X' && (board[2][2] == '-')) {
            (board)[2][2] = 'O';
            return 0;
        }
        else if ((board)[0][0] == 'X' && (board)[2][2] == 'X' && (board[1][1] == '-')) {
            (board)[1][1] = 'O';
            return 0;
        }
        else if ((board)[1][1] == 'X' && (board)[2][2] == 'X' && (board[0][0] == '-')) {
            (board)[0][0] = 'O';
            return 0;
        }

            //Diagonal 2
        else if ((board)[0][2] == 'X' && (board)[1][1] == 'X' && (board[2][0] == '-')) {
            (board)[2][0] = 'O';
            return 0;
        }
        else if ((board)[1][1] == 'X' && (board)[2][0] == 'X' && (board[0][2] == '-')) {
            (board)[0][2] = 'O';
            return 0;
        }
        else if ((board)[0][2] == 'X' && (board)[2][0] == 'X' && (board[1][1] == '-')) {
            (board)[1][1] = 'O';
            return 0;
        }

        //Marca posições aleatórias se não for possível ganhar nem perder, verifica antes pra não marcar uma já marcada
        else {
            while (1) {                                             //MUDAR ESSA PORRA DEPOIS

                random1 = rand() % 3;
                random2 = rand() % 3;
                if ((board)[random1][random2] == '-') {
                    (board)[random1][random2] = 'O';
                    return 0;
                }
            }
        }
    }
    return 0;
}