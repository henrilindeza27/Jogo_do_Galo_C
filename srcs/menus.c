#include "fh.h"

/**
 * Function: Menu
 * 
 * Mostra o menu principal 
 * 
 * Return: Opção selecionada no menu
 * 
 **/
int	Menu(void)
{
	int op;

	printf("╔════════════════════════════════╗\n");
	printf("╠════════════  MENU  ════════════╣\n");
	printf("║- [1] Jogar contra pessoa       ║\n");
	printf("║- [2] Jogar contra PC           ║\n");
	printf("║- [3] Sair                      ║\n");
	printf("╚════════════════════════════════╝\n");
	printf(" Selecione a opção que deseja --> ");
	while (scanf("%d", &op) != 1 || !(op >= 1 && op <= 3))
	{
		printf("Opção inválida, por favor digite uma opção válida -> ");
		//Seguintes scanf servem para limpar o buffer e descartar entradas inválidas
		scanf("%*[^\n]");
		scanf("%*c");
	}
	return (op);
}


/**
 * Function: Menu_Escolha
 * 
 * Mostra o menu para escolher o simbolo 
 * 
 * Return: Opção selecionada no menu
 * 
 **/
int	Menu_Escolha(void)
{
	char op;

	printf("╔════════════════════════════════╗\n");
	printf("╠══════════  ESCOLHE  ═══════════╣\n");
	printf("║   Jogador1 queres jogar com:   ║\n");
	printf("║          [X] ou [O]            ║\n");
	printf("║-     (Insere 'X' ou 'O')      -║\n");
	printf("╚════════════════════════════════╝\n");
	printf(" Selecione a opção que deseja --> ");
	while (scanf("%c", &op) != 1 || !((op == 'X' || op == 'O')||(op == 'x' || op == 'o')))
	{
		printf("Opção inválida, por favor digite uma opção válida -> ");
		//Seguintes scanf servem para limpar o buffer e descartar entradas inválidas
		scanf("%*[^\n]");
		scanf("%*c");
	}
	return (op);
}


/**
 * Function: header
 * 
 * Mostra o jogador que vai fazer a jogada
 * 
 * n_jogador: 1 se for o Jogador1
 * 			  2 se for o Jogador2
 * 
 * Return: Void
 * 
 **/
void	header(int n_jogador)
{
	if(n_jogador < 3)
	{
		system("clear");
		printf("-------------\n");
		printf("  JOGADOR %d  \n", n_jogador);
		printf("-------------\n");
		printf("\n");
	}
	else
	{
		system("clear");
		printf("-------------\n");
		printf("      AI     \n");
		printf("-------------\n");
		printf("\n");
	}
	
}
