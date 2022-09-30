#include <stdio.h>
#define TAM 5

float leMatrizes (float matriz[][], int tamlinha, int tamcoluna){   //Função que lê matrizes float

	for (int linha = 0; linha < tamlinha; linha++){			  //para linhas
		for(int coluna = 0; coluna < tamcoluna; coluna++){        //para colunas
			scanf("%f ", &matriz[i][k]); 
		}	
		printf("\n");			
	}
	return 0;

}


void imprimeMatrizes (float matriz[][], int tamlinha, int tamcoluna){     //função para imprimir matrizes 

	for (int linha = 0; linha < tamlinha; linha++){			  //para linhas
		for(int coluna = 0; coluna < tamcoluna; coluna++){        //para colunas
			printf("%f ", matriz[i][k]); 
		}	
		printf("\n");			
	}

}

int main(){

	float matriz[TAM][TAM];
	leMatrizes(matriz, TAM, TAM);
	imprimeMatrizes(matriz, TAM, TAM);
	return 0;	
}
