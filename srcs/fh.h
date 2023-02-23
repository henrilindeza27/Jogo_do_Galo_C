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
int		verificarJogada(Tabuleiro *tab, int linha, int coluna);

int		verificarVitoria(Tabuleiro *tabuleiro, char *ch);
int		verificarEmpate(Tabuleiro *tabuleiro);

void	jogar(Tabuleiro *tabuleiro, char caracter, int n_jogador);

int		*verificar_vit_coluna(Tabuleiro *tabuleiro, char chPC);
int		*verificar_vit_linha(Tabuleiro *tabuleiro, char chPC);
int		*verificar_vit_diagonal(Tabuleiro *tabuleiro, char chPC);
int		*verificar_vitoriaPC(Tabuleiro *tabuleiro, char chPC);

int		*verificar_def_coluna(Tabuleiro *tabuleiro, char chPlayer);
int		*verificar_def_linha(Tabuleiro *tabuleiro, char chPlayer);
int		*verificar_def_diagonal(Tabuleiro *tabuleiro, char chPlayer);
int		*verificar_defesaPC(Tabuleiro *tabuleiro, char chPlayer);

void	pc_play(Tabuleiro *tabuleiro, char chPlayer, char chPC);
#endif
