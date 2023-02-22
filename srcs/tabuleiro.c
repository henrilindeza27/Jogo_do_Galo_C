#include "fh.h"

/**
 * Function: print_tabuleiro
 * 
 * Mostra na tela o tabuleiro atual
 * 
 * tabuleiro: Estado atua do tabuleiro
 * 
 **/
void	print_tabuleiro(Tabuleiro *tabuleiro)
{
	int x = 0;
	int y = 0;

	for (int h = 0; h < 3; h++)
	{
		printf(" [%d]", x++);
	}
	printf("\n");
	printf("+");
	for (int h = 0; h < 3; h++)
	{
		printf("---+");
	}
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		printf("|");
		for (int j = 0; j < 3; j++)
		{
			printf(" %c |", tabuleiro->board[i][j].caracter);
		}
		printf(" [%d]", y++);
		printf("\n");
		printf("+");
		for (int j = 0; j < 3; j++)
		{
			printf("---+");
		}
		printf("\n");
	}
}

/**
 * Function: init_tab
 * 
 * Inicializa um tabuleiro.
 * 
 * tabuleiro: Apontador para o Tabuleiro que vai ser inicializado
 * 
 **/
void	init_tab(Tabuleiro *tabuleiro)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tabuleiro->board[i][j].linha = i;
			tabuleiro->board[i][j].coluna = j;
			tabuleiro->board[i][j].caracter = ' ';
		}
	}
}

/**
 * Function: atualizar_tab
 * 
 * Atualiza as posições vazias pelas jogadas feitas
 * 
 * 
 * jogada: Jogada feita pelo o jogador
 * tabuleiro: Estado atual do tabuleiro
 * 
 **/
void	atualizar_tab(Jogada jogada, Tabuleiro *tabuleiro)
{
	tabuleiro->board[jogada.linha][jogada.coluna].caracter = jogada.caracter;
}