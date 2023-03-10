#include "fh.h"

/**
 * Function: *verificar_vit_coluna
 * 
 * Verifica se a jogada seguinte nas colunas pode ser vencedora
 * caso seja a função retorna um ponteiro contendo as coordenadas
 * da jogada a fazer para se vencer
 * 
 * tabuleiro: Estado atual do tabuleiro
 * chPC: Jogada do PC(X/O)
 * 
 **/
int	*verificar_vit_coluna(Tabuleiro *tabuleiro, char chPC)
{
	int	*rt;

	rt = (int *)(malloc(sizeof(int) * 3));
	if (rt == NULL)
		return (0);
	for (int i = 0; i < N; i++)
	{
		if ((tabuleiro->board[i][0].caracter == chPC
				&& tabuleiro->board[i][1].caracter == chPC)
			&& tabuleiro->board[i][2].caracter == ' ')
		{
			rt[0] = 1;
			rt[1] = i;
			rt[2] = 2;
			return (rt);
		}
		else if ((tabuleiro->board[i][0].caracter == chPC
					&& tabuleiro->board[i][2].caracter == chPC)
				&& tabuleiro->board[i][1].caracter == ' ')
		{
			rt[0] = 1;
			rt[1] = i;
			rt[2] = 1;
			return (rt);
		}
		else if ((tabuleiro->board[i][1].caracter == chPC
					&& tabuleiro->board[i][2].caracter == chPC)
				&& tabuleiro->board[i][0].caracter == ' ')
		{
			rt[0] = 1;
			rt[1] = i;
			rt[2] = 0;
			return (rt);
		}
	}
	free(rt);
}


/**
 * Function: *verificar_vit_linha
 * 
 * Verifica se a jogada seguinte nas linha pode ser vencedora
 * caso seja a função retorna um ponteiro contendo as coordenadas
 * da jogada a fazer para se vencer
 * 
 * tabuleiro: Estado atual do tabuleiro
 * chPC: Jogada do PC(X/O)
 * 
 **/
int	*verificar_vit_linha(Tabuleiro *tabuleiro, char chPC)
{
	int	*rt;

	rt = (int *)(malloc(sizeof(int) * 3));
	if (rt == NULL)
		return (0);
	for (int i = 0; i < N; i++)
	{
		if ((tabuleiro->board[0][i].caracter == chPC
				&& tabuleiro->board[1][0].caracter == chPC)
			&& tabuleiro->board[2][i].caracter == ' ')
		{
			rt[0] = 2;
			rt[1] = 2;
			rt[2] = i;
			return (rt);
		}
		else if ((tabuleiro->board[0][i].caracter == chPC
					&& tabuleiro->board[2][i].caracter == chPC)
				&& tabuleiro->board[1][i].caracter == ' ')
		{
			rt[0] = 2;
			rt[1] = 1;
			rt[2] = i;
			return (rt);
		}
		else if ((tabuleiro->board[1][i].caracter == chPC
					&& tabuleiro->board[2][i].caracter == chPC)
				&& tabuleiro->board[0][i].caracter == ' ')
		{
			rt[0] = 2;
			rt[1] = 0;
			rt[2] = i;
			return (rt);
		}
	}
	free(rt);
}



/**
 * Function: *verificar_vit_diagonal
 * 
 * Verifica se a jogada seguinte nas diagonais pode ser vencedora
 * caso seja a função retorna um ponteiro contendo as coordenadas
 * da jogada a fazer para se vencer
 * 
 * tabuleiro: Estado atual do tabuleiro
 * chPC: Jogada do PC(X/O)
 * 
 **/
int	*verificar_vit_diagonal(Tabuleiro *tabuleiro, char chPC)
{
	int	*rt;

	rt = (int *)(malloc(sizeof(int) * 3));
	if (rt == NULL)
		return (0);
	// Diagonal 1
	if ((tabuleiro->board[0][0].caracter == chPC
			&& tabuleiro->board[1][1].caracter == chPC)
		&& tabuleiro->board[2][2].caracter == ' ')
	{
		rt[0] = 3;
		rt[1] = 2;
		rt[2] = 2;
		return (rt);
	}
	else if ((tabuleiro->board[0][0].caracter == chPC
				&& tabuleiro->board[2][2].caracter == chPC)
			&& tabuleiro->board[1][1].caracter == ' ')
	{
		rt[0] = 3;
		rt[1] = 1;
		rt[2] = 1;
		return (rt);
	}
	else if ((tabuleiro->board[1][1].caracter == chPC
				&& tabuleiro->board[2][2].caracter == chPC)
			&& tabuleiro->board[0][0].caracter == ' ')
	{
		rt[0] = 3;
		rt[1] = 0;
		rt[2] = 0;
		return (rt);
	}
	// Diagonal 2
	else if ((tabuleiro->board[0][2].caracter == chPC
				&& tabuleiro->board[1][1].caracter == chPC)
			&& tabuleiro->board[2][0].caracter == ' ')
	{
		rt[0] = 3;
		rt[1] = 2;
		rt[2] = 0;
		return (rt);
	}
	else if ((tabuleiro->board[0][2].caracter == chPC
				&& tabuleiro->board[2][0].caracter == chPC)
			&& tabuleiro->board[1][1].caracter == ' ')
	{
		rt[0] = 3;
		rt[1] = 1;
		rt[2] = 1;
		return (rt);
	}
	else if ((tabuleiro->board[1][1].caracter == chPC
				&& tabuleiro->board[2][0].caracter == chPC)
			&& tabuleiro->board[0][2].caracter == ' ')
	{
		rt[0] = 3;
		rt[1] = 0;
		rt[2] = 2;
		return (rt);
	}
	else
		free(rt);
}


/**
 * Function: *verificar_vitoriaPC
 * 
 * Verifica se existe uma jogada vencedora, caso sim
 * a função retorna o ponteiro com as coordenadas
 * 
 * tabuleiro: Estado atual do tabuleiro
 * chPC: Jogada do PC(X/O)
 * 
 **/
int	*verificar_vitoriaPC(Tabuleiro *tabuleiro, char chPC)
{
	int *coluna = verificar_vit_coluna(tabuleiro, chPC);
	if (coluna != 0 && coluna[0] == 1)
		return (coluna);

	int *linha = verificar_vit_linha(tabuleiro, chPC);
	if (linha != 0 && linha[0] == 2)
		return (linha);

	int *diagonal = verificar_vit_diagonal(tabuleiro, chPC);
	if (diagonal != 0 && diagonal[0] == 3)
		return (diagonal);
	return (0);
}