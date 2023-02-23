#include "fh.h"

//Verificar vitoria (linhas/colunas/diagonais)
//Verificar defesa (linhas/colunas/diagonais)
//se nenhuma das 2 de cima retorna afirmativo, random playVitoria

void	pc_play(Tabuleiro *tabuleiro, char chPlayer, char chPC)
{
	int linha;
	int coluna;

	while (1)
	{
		header(3);
		int *playVitoria = verificar_vitoriaPC(tabuleiro, chPC);
		int *playDefesa = verificar_defesaPC(tabuleiro, chPlayer);
		if (playVitoria != 0)
		{
			linha = playVitoria[1];
			coluna = playVitoria[2];
		}
		else if(playDefesa != 0)
		{
			linha = playDefesa[1];
			coluna = playDefesa[2];
		}
		else
		{
			srand(time(NULL));
			linha = (rand() % 3);
			coluna = (rand() % 3);
		}

		Jogada jogada = {linha, coluna, chPC};

		atualizar_tab(jogada, tabuleiro);
		header(3);
		print_tabuleiro(tabuleiro);
		printf("Pressione alguma tecla para CONTINUAR");
		getchar();
        break;

	}
	
}