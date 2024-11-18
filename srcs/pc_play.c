#include "fh.h"

/**
 * Function: pc_play
 * 
 * Verifica primeiramente se existe alguma jogada vencedora
 * e se verdadeiro ela faz essa jogada, caso contrário verifica
 * se há alguma jogada para bloquear se afirmativo ela faz essa jogada
 * caso nenhuma das verificações anteriores for verdadeira faz uma
 * jogado gerada randomicamente
 * 
 * tabuleiro: Estado atual do tabuleiro
 * chPlayer: Jogada do adversário(X/O)
 * chPC: Jogada do PC(X/O)
 * 
 **/
void	pc_play(Tabuleiro *tabuleiro, char chPlayer, char chPC)
{
	int linha;
	int coluna;

	while (1)
	{
		header(3);
		int *playVitoria = verificar_vitoriaPC(tabuleiro, chPC);
		int *playDefesa = verificar_defesaPC(tabuleiro, chPlayer);
		if (playVitoria != 0 && !verificarJogada(tabuleiro, playVitoria[1], playVitoria[2]))
		{
			linha = playVitoria[1];
			coluna = playVitoria[2];
		}
		else if(playDefesa != 0 && !verificarJogada(tabuleiro, playDefesa[1], playDefesa[2]))
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