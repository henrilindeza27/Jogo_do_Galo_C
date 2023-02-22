#include "fh.h"

/**
 * Function: verificarVitoria
 * 
 * Verifica se existe vitória no tabuleiro atual
 * 
 * tabuleiro: Estado atua do tabuleiro
 * ch: Simbolo vencedor
 * 
 * returns:
 *  1 se houver vitória
 *  0 caso contrário
 * 
 * 
 **/
int	verificarVitoria(Tabuleiro *tabuleiro, char *ch)
{
	//Verificar Linhas
	for (int i = 0; i < N; i++)
	{
		if (tabuleiro->board[i][0].caracter != ' '
			&& (tabuleiro->board[i][0].caracter == tabuleiro->board[i][1].caracter
				&& tabuleiro->board[i][1].caracter == tabuleiro->board[i][2].caracter))
		{
			*ch = tabuleiro->board[i][0].caracter;
			return (1);
		}
	}
	//Verificar Colunas
	for (int j = 0; j < N; j++)
	{
		if (tabuleiro->board[0][j].caracter != ' '
			&& (tabuleiro->board[0][j].caracter == tabuleiro->board[1][j].caracter
				&& tabuleiro->board[1][j].caracter == tabuleiro->board[2][j].caracter))
		{
			*ch = tabuleiro->board[0][j].caracter;
			return (1);
		}
	}
	//Verificar Diagonais
	if (tabuleiro->board[0][0].caracter != ' '
		&& (tabuleiro->board[0][0].caracter == tabuleiro->board[1][1].caracter
			&& tabuleiro->board[1][1].caracter == tabuleiro->board[2][2].caracter))
	{
		*ch = tabuleiro->board[0][0].caracter;
		return (1);
	}
	if (tabuleiro->board[0][2].caracter != ' '
		&& (tabuleiro->board[0][2].caracter == tabuleiro->board[1][1].caracter
			&& tabuleiro->board[1][1].caracter == tabuleiro->board[2][0].caracter))
	{
		*ch = tabuleiro->board[2][0].caracter;
		return (1);
	}
	//Caso não haja vitória
	return (0);
}

/**
 * Function: verificarEmpate
 * 
 * Verifica se existe empate na partida
 * 
 * tabuleiro: Estado atua do tabuleiro
 * 
 * returns:
 *  1 se houver empate
 *  0 caso contrário
 * 
 * 
 **/
int	verificarEmpate(Tabuleiro *tabuleiro)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (tabuleiro->board[i][j].caracter == ' ')
				return (0);
		}
	}
	return (1);
}