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