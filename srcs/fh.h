#ifndef FH_H
# define FH_H

//Bibliotecas
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

//Constantes
# define N 3

//Structs

/**Representa uma jogada**/
typedef struct
{
	int linha;     //Representa o x da jogada
	int coluna;    //Representa o y da jogada
	char caracter; //Representa o caracter(X/O)

}		Jogada;

/**Representa um tabuleiro**/
typedef struct
{
	Jogada board[N][N]; //Representa o tabuleiro 3x3

}		Tabuleiro;

//Funções
int		Menu(void);
int		Menu_Escolha(void);
void	header(int n_jogador);

void	limparTela(void);
void	limparInput(void);

void	print_tabuleiro(Tabuleiro *tabuleiro);
void	init_tab(Tabuleiro *tabuleiro);
void	atualizar_tab(Jogada jogada, Tabuleiro *tabuleiro);

int		verificarVitoria(Tabuleiro *tabuleiro, char *ch);
int		verificarEmpate(Tabuleiro *tabuleiro);

void	jogar(Tabuleiro *tabuleiro, char caracter, int n_jogador);

#endif
