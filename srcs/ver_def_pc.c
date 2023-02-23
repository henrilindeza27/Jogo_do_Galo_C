#include "fh.h"

int	*verificar_def_coluna(Tabuleiro *tabuleiro, char chPlayer)
{
	int	*rt;

	rt = (int *)(malloc(sizeof(int) * 3));
	if (rt == NULL)
		return (0);
	for (int i = 0; i < N; i++)
	{
		if ((tabuleiro->board[i][0].caracter == chPlayer
				&& tabuleiro->board[i][1].caracter == chPlayer)
			&& tabuleiro->board[i][2].caracter == ' ')
		{
			rt[0] = 1;
			rt[1] = i;
			rt[2] = 2;
			return (rt);
		}
		else if ((tabuleiro->board[i][0].caracter == chPlayer
					&& tabuleiro->board[i][2].caracter == chPlayer)
				&& tabuleiro->board[i][1].caracter == ' ')
		{
			rt[0] = 1;
			rt[1] = i;
			rt[2] = 1;
			return (rt);
		}
		else if ((tabuleiro->board[i][1].caracter == chPlayer
					&& tabuleiro->board[i][2].caracter == chPlayer)
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

int	*verificar_def_linha(Tabuleiro *tabuleiro, char chPlayer)
{
	int	*rt;

	rt = (int *)(malloc(sizeof(int) * 3));
	if (rt == NULL)
		return (0);
	for (int i = 0; i < N; i++)
	{
		if ((tabuleiro->board[0][i].caracter == chPlayer
				&& tabuleiro->board[1][0].caracter == chPlayer)
			&& tabuleiro->board[2][i].caracter == ' ')
		{
			rt[0] = 2;
			rt[1] = 2;
			rt[2] = i;
			return (rt);
		}
		else if ((tabuleiro->board[0][i].caracter == chPlayer
					&& tabuleiro->board[2][i].caracter == chPlayer)
				&& tabuleiro->board[1][i].caracter == ' ')
		{
			rt[0] = 2;
			rt[1] = 1;
			rt[2] = i;
			return (rt);
		}
		else if ((tabuleiro->board[1][i].caracter == chPlayer
					&& tabuleiro->board[2][i].caracter == chPlayer)
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

int	*verificar_def_diagonal(Tabuleiro *tabuleiro, char chPlayer)
{
	int	*rt;

	rt = (int *)(malloc(sizeof(int) * 3));
	if (rt == NULL)
		return (0);
	// Diagonal 1
	if ((tabuleiro->board[0][0].caracter == chPlayer
			&& tabuleiro->board[1][1].caracter == chPlayer)
		&& tabuleiro->board[2][2].caracter == ' ')
	{
		rt[0] = 3;
		rt[1] = 2;
		rt[2] = 2;
		return (rt);
	}
	else if ((tabuleiro->board[0][0].caracter == chPlayer
				&& tabuleiro->board[2][2].caracter == chPlayer)
			&& tabuleiro->board[1][1].caracter == ' ')
	{
		rt[0] = 3;
		rt[1] = 1;
		rt[2] = 1;
		return (rt);
	}
	else if ((tabuleiro->board[1][1].caracter == chPlayer
				&& tabuleiro->board[2][2].caracter == chPlayer)
			&& tabuleiro->board[0][0].caracter == ' ')
	{
		rt[0] = 3;
		rt[1] = 0;
		rt[2] = 0;
		return (rt);
	}
	// Diagonal 2
	else if ((tabuleiro->board[0][2].caracter == chPlayer
				&& tabuleiro->board[1][1].caracter == chPlayer)
			&& tabuleiro->board[2][0].caracter == ' ')
	{
		rt[0] = 3;
		rt[1] = 2;
		rt[2] = 0;
		return (rt);
	}
	else if ((tabuleiro->board[0][2].caracter == chPlayer
				&& tabuleiro->board[2][0].caracter == chPlayer)
			&& tabuleiro->board[1][1].caracter == ' ')
	{
		rt[0] = 3;
		rt[1] = 1;
		rt[2] = 1;
		return (rt);
	}
	else if ((tabuleiro->board[1][1].caracter == chPlayer
				&& tabuleiro->board[2][0].caracter == chPlayer)
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

int	*verificar_defesaPC(Tabuleiro *tabuleiro, char chPlayer)
{
	int *coluna = verificar_vit_coluna(tabuleiro, chPlayer);
	if (coluna != 0 && coluna[0] == 1)
		return (coluna);

	int *linha = verificar_vit_linha(tabuleiro, chPlayer);
	if (linha != 0 && linha[0] == 2)
		return (linha);

	int *diagonal = verificar_vit_diagonal(tabuleiro, chPlayer);
	if (diagonal != 0 && diagonal[0] == 3)
		return (diagonal);
	return (0);
}