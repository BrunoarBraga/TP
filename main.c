#include <stdio.h>
#include "Game_Ui.h"
#include "Options.h"


int main() {

    int control;

    print_Interface();

    // Repetição que mostra e controla as opções, e, se o usuário digitar "voltar" dentro do jogo, repete.
    do{

        show_Options();
        control = options();
        // se o comando no meio do jogo for voltar, a função retorna 2, volta pra esse loop e mostra as opções denovo.

    } while(control == 2);

    return 0;
}





