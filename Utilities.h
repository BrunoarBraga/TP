#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Colours.h"
#include "Game_Ui.h"

char** create_Matrix(int n){

    char **matrix;
    matrix = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(char));
    }
    return matrix;
}

void free_Matrix(char** matrix, int n){

    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);

}

void fill_Matrix(char*** matrix, int n, char character){

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*matrix)[i][j] = character;
        }
    }
}

void print_Board(char** matrix, int n){

    char matrix_copy[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix_copy[i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(matrix_copy[i][j] == '-')
                matrix_copy[i][j] = ' ';
        }
    }

    printf("\n");
    Centralize_on_terminal();
    printf("\t\t\t\t\t"TAB_TL TAB_HOR TAB_HOR TAB_HOR TAB_TJ TAB_HOR TAB_HOR TAB_HOR TAB_TJ TAB_HOR TAB_HOR TAB_HOR TAB_TJ TAB_HOR TAB_HOR TAB_HOR TAB_TR "\n");
    Centralize_on_terminal();
    printf("\t\t\t\t\t"TAB_VER " ඞ " TAB_VER " 1 " TAB_VER " 2 " TAB_VER " 3 " TAB_VER"\n");
    Centralize_on_terminal();
    printf("\t\t\t\t\t"TAB_ML TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MR "\n");
    Centralize_on_terminal();
    printf("\t\t\t\t\t"TAB_VER " 1 " TAB_VER " %c " TAB_VER " %c " TAB_VER " %c " TAB_VER "\n", matrix_copy[0][0], matrix_copy[0][1], matrix_copy[0][2]);
    Centralize_on_terminal();
    printf("\t\t\t\t\t"TAB_ML TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MR "\n");
    Centralize_on_terminal();
    printf("\t\t\t\t\t"TAB_VER " 2 " TAB_VER " %c " TAB_VER " %c " TAB_VER " %c " TAB_VER "\n", matrix_copy[1][0], matrix_copy[1][1], matrix_copy[1][2]);
    Centralize_on_terminal();
    printf("\t\t\t\t\t"TAB_ML TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MR "\n");
    Centralize_on_terminal();
    printf("\t\t\t\t\t"TAB_VER " 3 " TAB_VER " %c " TAB_VER " %c " TAB_VER " %c " TAB_VER "\n", matrix_copy[2][0], matrix_copy[2][1], matrix_copy[2][2]);
    Centralize_on_terminal();
    printf("\t\t\t\t\t"TAB_BL TAB_HOR TAB_HOR TAB_HOR TAB_BJ TAB_HOR TAB_HOR TAB_HOR TAB_BJ TAB_HOR TAB_HOR TAB_HOR TAB_BJ TAB_HOR TAB_HOR TAB_HOR TAB_BR "\n");
    printf("\n");

}


