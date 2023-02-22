#include "fh.h"

/**
 * Function: jogar
 * 
 * Faz a jogada referida pelo o jogador
 * 
 * tabuleiro: Estado atual do tabuleiro
 * caracter: Jogada do jogador(X/O)
 * 
 **/
void	jogar(Tabuleiro *tabuleiro, char caracter, int n_jogador)
{
	int lin, col; // Recebe o valor da linha e da coluna

	while (1)
	{
		limparTela();
		if (n_jogador == 1)
			header(1);
		else
			header(2);
		print_tabuleiro(tabuleiro);
		puts("Insira as coordenadas da sua jogada");

		printf("Linha: ");
		while (scanf("%d", &lin) != 1 || !((lin >= 0 && lin <= 2)))
		{
			limparTela();
			if (n_jogador == 1)
				header(1);
			else
				header(2);
			print_tabuleiro(tabuleiro);
			puts("A posição não é válida");
			puts("Insira novamente");
			printf("Linha: ");
			//Seguintes scanf servem para limpar o buffer e descartar entradas inválidas
			scanf("%*[^\n]");
			scanf("%*c");
		}

		printf("Coluna: ");
		while (scanf("%d", &col) != 1 || !((col >= 0 && col <= 2)))
		{
			limparTela();
			if (n_jogador == 1)
				header(1);
			else
				header(2);
			print_tabuleiro(tabuleiro);
			puts("A posição não é válida");
			puts("Insira novamente");
			printf("Coluna: ");
			//Seguintes scanf servem para limpar o buffer e descartar entradas inválidas
			scanf("%*[^\n]");
			scanf("%*c");
		}

		Jogada jogada = {lin, col, caracter};

		limparTela();
		atualizar_tab(jogada, tabuleiro);
		if (n_jogador == 1)
			header(1);
		else
			header(2);
		print_tabuleiro(tabuleiro);
		limparInput();
		printf("Pressione alguma tecla para CONTINUAR");
		getchar();
        break;
	}
}