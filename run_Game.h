// Este arquivo é responsável por fazer o jogo funcionar, executar os comandos do jogador, etc...
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utilities.h"
#include "Computer_Move.h"

#define TAM 3

int run_Game(FILE *game_state);
int command_Validation(char command[50]);                                                                //USAR ALOCAÇÃO DINÂMICA AQUI DEPOIS
int execute_Command(char command[50], char** matrix, int n, int player_Number, char* player1_name, char* player2_name, int num_of_players, int *num_of_rounds);


//Struct que guarda o nome e contabiliza o placar dos jogadores
typedef struct {

    char name[100];  //USAR ALOCAÇÃO DINAMICA AQUI DEPOIS, POR ENQUANTO SÓ FAZENDO A ESTRUTURA
    int wins;
    int draws;
    int losses;

}Players;

// Função que roda o jogo.
//Se retornar 2, significa que o jogador digitou "voltar", e precisa voltar para as opções.
int run_Game(FILE *game_state){

    rewind(game_state);

    char **board, lixo;
    int num_of_players = 0;
    Players player1, player2;

    board = create_Matrix(TAM);

    // Lẽ o primeiro elemento do arquivo, que é o número de jogadores
    fscanf(game_state, "%d", &num_of_players);
    fscanf(game_state, "%c", &lixo);


    // Lẽ o nome de um jogador, se forem 2 jogadores, lê o do segundo também.
    fgets(player1.name, 100, game_state);
    player1.name[strlen(player1.name) - 1] = '\0';
    if (num_of_players == 2) {
        fgets(player2.name, 100, game_state);
        player2.name[strlen(player2.name) - 1] = '\0';
    }

    // Lẽ a situação do jogo, a matriz que corresponde ao tabuleiro
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            fscanf(game_state, "%c", &board[i][j]);
        }
        fscanf(game_state,"%c", &lixo);
    }

    // Funcionamento do jogo em si ↓ ___________________________________________________________________________________

    int num_of_rounds = 0, c_Validation, c_Validation2;
    char command[50];                                   //USAR ALOCAÇÃO DINÂMICA AQUI DEPOIS



    // Loop que percorre a matriz e determina o número de jogadas que já foram feitas
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if(board[i][j] != '-')
                num_of_rounds++;
        }
    }


    switch (num_of_players) {

        // Funcionamento do jogo para 1 jogador
        case 1:

            // Loop para verificar se o jogo não acabou com todas as posições marcadas.
            while (num_of_rounds <= 9){

                // Loop para executar o comando e certificar de que uma posião marcada não foi marcada novamente.
                do {
                    // Loop para certificar de que um comando válido foi digitado.
                    do {

                        print_Board(board, TAM);
                        printf("%s, digite o comando: ", player1.name);
                        fgets(command, 50, stdin);                                          //USAR ALOCAÇÃO DINÂMICA AQUI DEPOIS
                        c_Validation = command_Validation(command);

                    }while (c_Validation != 1);

                    c_Validation2 = execute_Command(command, board, TAM, num_of_players, player1.name, player2.name, num_of_players,&num_of_rounds);

                    //Se o execute command retornar 2, o comando "voltar" foi digitado,
                    //O run_game vai retorna2 2 também, e o programa vai voltar pras opções.
                    if(c_Validation2 == 2)
                        return 2;

                } while (c_Validation2 == 0);

                //Se o jogador marcou, imprime o novo tableira, a maáquina joga.
                if(c_Validation2 == 1){

                    print_Board(board, TAM);
                    computer_Move(board, &num_of_rounds, TAM);

                }
            }
            break;
    }
    printf("\nteste\n");
    free_Matrix(board, TAM);
    return 0;
}

// Função que valida o comando digitado, se o comando for inválida retorna 0, se for válido retorna 1.
int command_Validation(char command[50]){                          //USAR ALOCAÇÃO DINÂMICA AQUI DEPOIS

    int size_of_command = strlen(command);

    if(strcmp(command, "marcar 11") != 0 &&
       strcmp(command, "marcar 12") != 0 &&
       strcmp(command, "marcar 13") != 0 &&
       strcmp(command, "marcar 21") != 0 &&
       strcmp(command, "marcar 22") != 0 &&
       strcmp(command, "marcar 23") != 0 &&
       strcmp(command, "marcar 31") != 0 &&
       strcmp(command, "marcar 32") != 0 &&
       strcmp(command, "marcar 33") != 0 &&
       strcmp(command, "voltar")    != 0 &&

       command[0] != 's'                 &&
       command[1] != 'a'                 &&
       command[2] != 'l'                 &&
       command[3] != 'v'                 &&
       command[4] != 'a'                 &&
       command[5] != 'r'                   ){

        printf("Comando inválido! Por favor digite outro comando.\nOs comandos são: marcar <XX>, salvar <XXX.txt>, voltar\n");
        return 0;

    }
    else if((command[0] == 's'                  )&&(
             command[size_of_command - 2] != 't' ||
             command[size_of_command - 3] != 'x' ||
             command[size_of_command - 4] != 't'   )){

        printf("O arquivo no qual o jogo será salvo deve ser do tipo texto (.txt)!\nDigite o comando novamente.\n");
        return 0;

    }
    else
        return 1;

}

// Funão que executa o comando que vai ser rodado no jogo, retorna 0 se a posição já estiver marcada,
// 1 se a posição for válida, e 2 se o jogador quiser "voltar" para as opções.
int execute_Command(char command[50], char** matrix, int n, int player_Number, char* player1_name, char* player2_name, int num_of_players, int *num_of_rounds){

    // Como já houve a verificação dos comandos anteriormente, somente verificando a primeira letra aqui
    // é possívelsaber qual comando está sendo executado

    if (command[0] == 'm'){

        int  size_of_command = strlen(command);


        //Usando esta string para converter as posições para números inteiros, utilizando a função atoi.
        char positions[2] = {command[size_of_command - 3], command[size_of_command - 2]};
        int  positions2 = atoi(positions);


        int position1_line = (positions2 - (positions2 % 10)) / 10,
            position2_column = positions2 % 10;


        // Verifica se a posião já foi marcada, se não, marca ela.
        if(matrix[position1_line - 1][position2_column - 1] != '-'){

            printf("Essa posição já foi marcada, marque outra posição.\n");
            return 0;

        }
        else{

            if(player_Number == 1)
                matrix[position1_line - 1][position2_column - 1] = 'X';
            else if(player_Number == 2)
                matrix[position1_line - 1][position2_column - 1] = 'O';

            *num_of_rounds = *num_of_rounds + 1; // incrementa a quantidade de rounds que foram jogados. talves tenha que por o *.

            return 1;
        }
    }

    else if(command[0] == 'v'){
        return 2;
    }

    else if(command[0] == 's'){

        int command_length = strlen(command), counter = 0;
        char file_name[42];

        //Loop para pegar o nome do arquivo no qual o usuário quer salvar o jogo.
        for (int i = 0; i < command_length - 1; i++) {

            if(i > 6) {
                file_name[counter] = command[i];
                counter++;
            }

        }

        //Abre o arquivo e salva o jogo dentro dele
        FILE *current_Game = fopen(file_name, "w+");

        fprintf(current_Game, "%d\n", num_of_players);
        fprintf(current_Game, "%s\n", player1_name);
        if(num_of_players == 2)
            fprintf(current_Game, "%s\n", player2_name);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fprintf(current_Game, "%c", matrix[i][j]);
            }
            fprintf(current_Game, "\n");
        }

        fclose(current_Game);
        return 3;
    }
    return 4;
}
