#include "fh.h"

int	main(void)
{
	Tabuleiro	tabuleiro;
    char ch_j1;
    char ch_j2;
    char simb;
    char op_escolha;
	limparTela();
	init_tab(&tabuleiro);

	switch (Menu())
	{
	case 1:
        limparTela();
        limparInput();
        op_escolha = Menu_Escolha();
        if(op_escolha == 'x' || op_escolha == 'X')
        {
            ch_j1 = 'X';
            ch_j2 = 'O';
        }
        else
        {
            ch_j1 = 'O';
            ch_j2 = 'X';
        }
		// Loop principal do jogo
		while (1)
		{
			// Jogador 1
            header(1);
			jogar(&tabuleiro, ch_j1,1);
			// Verifica se o jogo terminou
			if (verificarVitoria(&tabuleiro, &simb) || verificarEmpate(&tabuleiro))
				break ;

			// Jogador 2
            header(2);
			jogar(&tabuleiro, ch_j2,2);
			// Verifica se o jogo terminou
			if (verificarVitoria(&tabuleiro, &simb) || verificarEmpate(&tabuleiro))
				break ;
		}
		if (verificarVitoria(&tabuleiro, &simb))
		{
			if(simb == ch_j1)
                printf("Jogador 1 ganhou o jogo (%c)\n",simb);
            else
                printf("Jogador 2 ganhou o jogo (%c)\n",simb);
		}
		else
		{
			printf("O jogo empatou!\n");
		}
		break ;
	default:
		break ;
	}
	return (0);
}