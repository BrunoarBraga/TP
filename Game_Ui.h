//Esse arquivo serve para imprimir a interface do jogo.
#pragma once
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "Colours.h"

//Função que conta a quantidade de colunas do terminal para imprimir espaos e Centralize_on_terminal( interface
void Centralize_on_terminal(){

    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    if(w.ws_col <= 117)
        return;
    else{
        for (int i = 0; i < (w.ws_col - 117)/2 ; i++) {
            printf(" ");
        }
    }
}

//Funão que imprime a interface em si.
void print_Interface(){

    Centralize_on_terminal();
    printf(RED("    _____                                      _______                   __     __            __  __                 \n"));
    Centralize_on_terminal();
    printf("   ");
    printf(RED(BG_BLUE("|")));
    printf(BOLD(BG_BLUE("     ")));
    printf(RED("\\"));
    printf("                                    ");
    printf(RED("|"));
    printf(BOLD(BG_BLUE("       ")));
    printf(RED("\\"));
    printf("                 ");
    printf(RED("|"));
    printf(BOLD(BG_BLUE("  ")));
    printf(RED("\\"));
    printf("   ");
    printf(RED("|"));
    printf(BOLD(BG_BLUE("  ")));
    printf(RED("\\"));
    printf("          ");
    printf(RED("|"));
    printf(BOLD(BG_BLUE("  ")));
    printf(RED("\\|"));
    printf(BOLD(BG_BLUE("  ")));
    printf(RED("\\"));
    printf("                ");
    printf("\n");
    Centralize_on_terminal();
    printf("    ");
    printf(BOLD(RED(BG_BLUE("\\$$$$$"))));
    printf(BOLD(RED("  ______    ______    ______        ")));
    printf(BOLD(RED(BG_BLUE("| $$$$$$$"))));
    printf(BOLD(RED("\\")));
    printf(BOLD(RED("  ______        ")));
    printf(BOLD(RED(BG_BLUE("| $$"))));
    printf("   ");
    printf(BOLD(RED(BG_BLUE("| $$"))));
    printf(BOLD(RED("  ______  ")));
    printf(BOLD(RED(BG_BLUE("| $$| $$"))));
    printf(BOLD(RED("____    ______  ")));
    printf("\n");
    Centralize_on_terminal();
    printf("      ");
    printf(BOLD(RED(BG_BLUE("| $$"))));
    printf(" ");
    printf(BOLD(RED(BG_BLUE("/      \\"))));
    printf("  ");
    printf(BOLD(RED(BG_BLUE("/      \\"))));
    printf("  ");
    printf(BOLD(RED(BG_BLUE("/      \\"))));
    printf("       ");
    printf(BOLD(RED(BG_BLUE("| $$"))));
    printf("  ");
    printf(BOLD(RED(BG_BLUE("| $$"))));
    printf(" ");
    printf(BOLD(RED(BG_BLUE("|      \\"))));
    printf("       ");
    printf(BOLD(RED(BG_BLUE("| $$"))));
    printf("   ");
    printf(BOLD(RED(BG_BLUE("| $$"))));
    printf(" ");
    printf(BOLD(RED(BG_BLUE("/      \\"))));
    printf(" ");
    printf(BOLD(RED(BG_BLUE("| $$| $$    \\"))));
    printf("  ");
    printf(BOLD(RED(BG_BLUE("|      \\"))));
    printf("\n");
    Centralize_on_terminal();
    printf(BOLD(RED(" __   ")));
    printf(BOLD(YELLOW(BG_BLUE("| $$|  $$$$$$\\|  $$$$$$\\|  $$$$$$\\"))));
    printf("      ");
    printf(BOLD(YELLOW(BG_BLUE("| $$"))));
    printf("  ");
    printf(BOLD(YELLOW(BG_BLUE("| $$"))));
    printf("  ");
    printf(BOLD(YELLOW(BG_BLUE("\\$$$$$$\\"))));
    printf("       ");
    printf(BOLD(YELLOW(BG_BLUE("\\$$\\"))));
    printf(" ");
    printf(BOLD(YELLOW(BG_BLUE("/  $$|  $$$$$$\\| $$| $$$$$$$\\"))));
    printf("  ");
    printf(BOLD(YELLOW(BG_BLUE("\\"))));
    printf(BOLD(BLACK(BG_BLUE("$$$$$$"))));
    printf(BOLD(YELLOW(BG_BLUE("\\"))));
    printf("\n");
    Centralize_on_terminal();
    printf(BOLD(YELLOW(BG_BLUE("|  \\"))));
    printf("  ");
    printf(BOLD(YELLOW(BG_BLUE("| $$| $$"))));
    printf("  ");
    printf(BOLD(YELLOW(BG_BLUE("| $$| $$"))));
    printf("  ");
    printf(BOLD(YELLOW(BG_BLUE("| $$| $$"))));
    printf("  ");
    printf(BOLD(YELLOW(BG_BLUE("| $$"))));
    printf("      ");
    printf(BOLD(YELLOW(BG_BLUE("| $$"))));
    printf("  ");
    printf(BOLD(YELLOW(BG_BLUE("| $$"))));
    printf(" ");
    printf(BOLD(BLACK(BG_BLUE("/      $$"))));
    printf("        ");
    printf(BOLD(YELLOW(BG_BLUE("\\$$\\  $$"))));
    printf(" ");
    printf(BOLD(YELLOW(BG_BLUE("| $$    $$| $$| $$"))));
    printf("  ");
    printf(BOLD(YELLOW(BG_BLUE("| $$"))));
    printf(" ");
    printf(BOLD(YELLOW(BG_BLUE("/      $$"))));
    printf("\n");
    Centralize_on_terminal();
    printf(BOLD(GREEN(BG_BLUE("| $$"))));
    printf(BOLD(GREEN("__")));
    printf(BOLD(GREEN(BG_BLUE("| $$| $$"))));
    printf(BOLD(GREEN("__")));
    printf(BOLD(GREEN(BG_BLUE("/ $$| $$"))));
    printf(BOLD(GREEN("__")));
    printf(BOLD(GREEN(BG_BLUE("| $$| $$"))));
    printf(BOLD(GREEN("__")));
    printf(BOLD(GREEN(BG_BLUE("/ $$"))));
    printf("      ");
    printf(BOLD(GREEN(BG_BLUE("| $$"))));
    printf(BOLD(GREEN("__")));
    printf(BOLD(GREEN(BG_BLUE("/ $$|  $$$$$$$"))));
    printf("         ");
    printf(BOLD(GREEN(BG_BLUE("\\$$ $$"))));
    printf("  ");
    printf(BOLD(GREEN(BG_BLUE("| $$$$$$$$| $$| $$"))));
    printf("  ");
    printf(BOLD(GREEN(BG_BLUE("| $$|  $$$$$$$"))));
    printf("\n");
    Centralize_on_terminal();
    printf(" ");
    printf(BOLD(GREEN(BG_BLUE("\\$$    $$"))));
    printf(" ");
    printf(BOLD(GREEN(BG_BLUE("\\$$    $$"))));
    printf(" ");
    printf(BOLD(GREEN(BG_BLUE("\\$$    $$"))));
    printf(" ");
    printf(BOLD(GREEN(BG_BLUE("\\$$    $$"))));
    printf("      ");
    printf(BOLD(GREEN(BG_BLUE("| $$    $$"))));
    printf(" ");
    printf(BOLD(GREEN(BG_BLUE("\\$$    $$"))));
    printf("          ");
    printf(BOLD(GREEN(BG_BLUE("\\$$$"))));
    printf("    ");
    printf(BOLD(GREEN(BG_BLUE("\\$$     \\| $$| $$"))));
    printf("  ");
    printf(BOLD(GREEN(BG_BLUE("| $$"))));
    printf(" ");
    printf(BOLD(GREEN(BG_BLUE("\\$$"))));
    printf("    ");
    printf(BOLD(GREEN(BG_BLUE("$$"))));
    printf("\n");
    Centralize_on_terminal();
    printf("  ");
    printf(BOLD(MAGENTA(BG_BLUE("\\$$$$$$"))));
    printf("   ");
    printf(BOLD(MAGENTA(BG_BLUE("\\$$$$$$"))));
    printf(BOLD(MAGENTA("  _")));
    printf(BOLD(MAGENTA(BG_BLUE("\\$$$$$$$"))));
    printf("  ");
    printf(BOLD(MAGENTA(BG_BLUE("\\$$$$$$"))));
    printf("        ");
    printf(BOLD(MAGENTA(BG_BLUE("\\$$$$$$$"))));
    printf("   ");
    printf(BOLD(MAGENTA(BG_BLUE("\\$$$$$$$"))));
    printf("           ");
    printf(BOLD(MAGENTA(BG_BLUE("\\$"))));
    printf("      ");
    printf(BOLD(MAGENTA(BG_BLUE("\\$$$$$$$"))));
    printf(" ");
    printf(BOLD(MAGENTA(BG_BLUE("\\$$"))));
    printf(" ");
    printf(BOLD(MAGENTA(BG_BLUE("\\$$"))));
    printf("   ");
    printf(BOLD(MAGENTA(BG_BLUE("\\$$"))));
    printf("  ");
    printf(BOLD(MAGENTA(BG_BLUE("\\$$$$$$$"))));
    printf("\n");
    Centralize_on_terminal();
    printf("                    ");
    printf(BOLD(MAGENTA(BG_BLUE("|  \\"))));
    printf(BOLD(MAGENTA("__")));
    printf(BOLD(MAGENTA(BG_BLUE("| $$"))));
    printf("                                                                                       ");
    printf("\n");
    Centralize_on_terminal();
    printf("                     ");
    printf(BOLD(CYAN(BG_BLUE("\\$$    $$"))));
    printf("                                                                                       ");
    printf("\n");
    Centralize_on_terminal();
    printf("                      ");
    printf(BOLD(CYAN(BG_BLUE("\\$$$$$$"))));
    printf("                                                                                        ");
    printf("\n");
    Centralize_on_terminal();
    printf("                                ");
    printf("\n\n");
    Centralize_on_terminal();

    printf(BOLD(WHITE("\t\t\t\t\t\tBem Vindo Ao Jogo Da Velha!\n")));
    Centralize_on_terminal();
    printf(BOLD(WHITE("\t\t\t\t\t\t    Selecione uma opção:\n\n\n")));

    /*printf(TAB_TL TAB_HOR TAB_TJ TAB_HOR TAB_TJ TAB_HOR TAB_TR "\n");
    printf(TAB_VER "a" TAB_VER "b" TAB_VER "c" TAB_VER "\n");
    printf(TAB_ML TAB_HOR TAB_MJ TAB_HOR TAB_MJ TAB_HOR TAB_MR "\n");
    printf(TAB_VER "d" TAB_VER "e" TAB_VER "f" TAB_VER "\n");
    printf(TAB_BL TAB_HOR TAB_BJ TAB_HOR TAB_BJ TAB_HOR TAB_BR "\n");
    printf("\n");
    */

}

