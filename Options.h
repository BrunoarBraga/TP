#pragma once
#include "run_Game.h"
#include "Utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM 3

// Este arquivo controla as opções de jogo e o que elas fazem

// Função que mostra as opções na tela
void show_Options(){

    usleep(200*1000); printf(BOLD(WHITE("\t\t\t\t\t\t0. Sair do Jogo\n")));
    usleep(200*1000); printf(BOLD(WHITE("\t\t\t\t\t\t1. Começar um novo jogo\n")));
    usleep(200*1000); printf(BOLD(WHITE("\t\t\t\t\t\t2. Continuar um jogo salvo\n")));
    usleep(200*1000); printf(BOLD(WHITE("\t\t\t\t\t\t3. Continuar o jogo atual\n")));
    usleep(200*1000); printf(BOLD(WHITE("\t\t\t\t\t\t4. Exibir o ranking\n")));
    usleep(200*1000); printf(BOLD(WHITE("\t\t\t\t\t\tDurante o jogo digite “voltar” para retornar ao menu.\n")));

}


// Função que controla
int options(){

    int  voltar_check, option_selected, num_of_players;
    char player_name[100], **board, option[250], num_of_players_selected[250];

    //Loop para validar a opção.
    do {

        printf("Escolha a opção: ");
        scanf("%s", option);
        if(strcmp(option, "0") == 0)
            option_selected = 0;
        else if(strcmp(option, "1") == 0)
            option_selected = 1;
        else if(strcmp(option, "2") == 0)
            option_selected = 2;
        else if(strcmp(option, "3") == 0)
            option_selected = 3;
        else if(strcmp(option, "4") == 0)
            option_selected = 4;
        else
            option_selected = 404;

        if(option_selected == 404)
            printf("\nOpção inválida! digite outra opção.\n");

    } while (option_selected == 404);

    // Switch para controlar o que será feito, dependendo da opção escolhida.

    switch (option_selected) {

        // Se a pessoa digitar '0', volta pra main e acaba o programa.
        case 0:
            return 0;

        //Cria um novo jogo.
        case 1:

            //Valida a quantidade de jogadores digitados
            do{

                printf("\nDigite o número de jogadores (1 ou 2): ");
                scanf("%s", num_of_players_selected);

                if(strcmp(num_of_players_selected, "1") == 0)
                    num_of_players = 1;
                else if(strcmp(num_of_players_selected, "2") == 0)
                    num_of_players = 2;
                else
                    printf("Número inválido escolhido! Digite novamente.");

            }while(num_of_players != 1 && num_of_players != 2);

            FILE *newgame = fopen("new_game.txt", "w+");

            fprintf(newgame, "%d\n", num_of_players);

            getchar();

            //Verifica e Lê o nome dos jogadores, depois coloca no arquivo.
            for (int i = 1; i < num_of_players + 1; i++) {

                do {

                    printf("\nDigite o nome do jogador %d: ", i);
                    fgets(player_name, 100, stdin);
                    if((strcmp(player_name, "\n") == 0) || (strcmp(player_name," ") == 0))
                        printf("\nNome inválido! Digite outro nome.\n");

                } while ((strcmp(player_name,"\n") == 0) || (strcmp(player_name," ") == 0));


                fprintf(newgame, "%s", player_name);

            }

            board = create_Matrix(TAM);
            fill_Matrix(&board, TAM, '-');

            //Loop para printar a matriz no arquivo
            for (int i = 0; i < TAM; i++) {
                for (int j = 0; j < TAM; j++) {
                    fprintf(newgame, "%c", board[i][j]);
                }
                fprintf(newgame,"\n");
            }

            voltar_check = run_Game(newgame);

            free_Matrix(board, TAM);
            fclose(newgame);

            // Verifica se o usuário digitou voltar dentro do jogo, se ele digitou,
            // retorna 2, e volta pro loop das opções na main
            if(voltar_check == 2)
                return 2;
            else
                return 0;

        case 2:

            break;
        case 3:

            break;
    }
    return 0;
}



