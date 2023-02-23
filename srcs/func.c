#include "fh.h"

/**
 * Function: limparTela
 * 
 * Limpa o conteúdo da tela
 * 
 **/
void	limparTela(void)
{
	system("clear");
}

/**
 * Function: limparInput
 * 
 * Limpa o conteúdo que ficou no buffer
 * 
 **/
void	limparInput(void)
{
	while (getchar() != '\n')
		;
}


/**
 * Function: verificarJogada
 * 
 * Verifica se a posição atual está livre
 * 
 * tabuleiro: Estado atua do tabuleiro
 * linha:
 * coluna:
 * 
 * returns:
 *  1 se estiver ocupada
 *  0 caso contrário
 * 
 * 
 **/
int	verificarJogada(Tabuleiro *tab, int linha, int coluna)
{
	if (tab->board[linha][coluna].caracter == 'X' || tab->board[linha][coluna].caracter == 'O')
		return (1);
	return (0);
}