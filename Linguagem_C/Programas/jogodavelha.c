#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int opcao;
    char simbolo = ' ';
    char simboloComputador = ' ';
    char choice[3][3];
    int condition = 1;
    int pontoJogador = 0, pontoComputador = 0;
    int contador;
    int jogadas = 0;
    int ganhadorMaquina = 0;
    int ganhadorJogador = 0;
    int linha, coluna;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            choice[i][j] = ' ';
        }
    }

    printf("Quantas jogadas voce deseja?\n");
    scanf(" %d", &jogadas);
    printf("Escolha X ou O para jogar!\n");
    scanf(" %c", &simbolo);

    while (condition == 1)
    {
        contador = 0;
        if (simbolo == 'X' || simbolo == 'x' || simbolo == 'O' || simbolo == 'o')
        {
            if (simbolo == 'X' || simbolo == 'x')
            {
                simboloComputador = 'O';
            }
            else if (simbolo == 'O' || simbolo == 'o')
            {
                simboloComputador = 'X';
            }

            for (int k = 1; k <= jogadas;)
            {

                if (ganhadorMaquina == 1)
                {
                    do
                    {
                        linha = rand() % 3;
                        coluna = rand() % 3;
                    } while (choice[linha][coluna] != ' ');

                    choice[linha][coluna] = simboloComputador;
                    ganhadorMaquina = 0;

                    printf("\nA maquina inicia esta rodada:\n");
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            printf("[ %c ]", choice[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
                else if (ganhadorJogador == 1)
                {
                    ganhadorJogador = 0;
                }

                printf("Escolha qual casa [1 - 9] voce deseja marcar!\n");
                scanf(" %d", &opcao);

                if (opcao == 0 || opcao > 9)
                {
                    do
                    {
                        printf("Opção inválida! \nEscolha qual casa [1 - 9] voce deseja marcar!\n");
                        scanf(" %d", &opcao);

                    } while (opcao == 0 || opcao > 9);
                }

                int r = (opcao - 1) / 3;
                int c = (opcao - 1) % 3;

                while (opcao < 1 || opcao > 9 || choice[r][c] != ' ')
                {
                    printf("Opção já marcada! Escolha [1 - 9]: ");
                    scanf("%d", &opcao);
                    r = (opcao - 1) / 3;
                    c = (opcao - 1) % 3;
                }

                choice[r][c] = simbolo;

                switch (opcao)
                {
                case 1:
                    choice[0][0] = simbolo;
                    break;
                case 2:
                    choice[0][1] = simbolo;
                    break;
                case 3:
                    choice[0][2] = simbolo;
                    break;
                case 4:
                    choice[1][0] = simbolo;
                    break;
                case 5:
                    choice[1][1] = simbolo;
                    break;
                case 6:
                    choice[1][2] = simbolo;
                    break;
                case 7:
                    choice[2][0] = simbolo;
                    break;
                case 8:
                    choice[2][1] = simbolo;
                    break;
                case 9:
                    choice[2][2] = simbolo;
                    break;
                default:
                    break;
                }

                contador = 0;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (choice[i][j] != ' ')
                        {
                            contador++;
                        }
                    }
                }

                if (contador < 9)
                {
                    // ============================================================
                    // 1. ATAQUES HORIZONTAIS (Linhas: 0, 1 e 2)
                    // ============================================================
                    if (choice[0][0] == simboloComputador && choice[0][1] == simboloComputador && choice[0][2] == ' ')
                    {
                        choice[0][2] = simboloComputador;
                    }
                    else if (choice[0][2] == simboloComputador && choice[0][1] == simboloComputador && choice[0][0] == ' ')
                    {
                        choice[0][0] = simboloComputador;
                    }
                    else if (choice[0][0] == simboloComputador && choice[0][2] == simboloComputador && choice[0][1] == ' ')
                    {
                        choice[0][1] = simboloComputador;
                    }
                    else if (choice[1][0] == simboloComputador && choice[1][1] == simboloComputador && choice[1][2] == ' ')
                    {
                        choice[1][2] = simboloComputador;
                    }
                    else if (choice[1][2] == simboloComputador && choice[1][1] == simboloComputador && choice[1][0] == ' ')
                    {
                        choice[1][0] = simboloComputador;
                    }
                    else if (choice[1][0] == simboloComputador && choice[1][2] == simboloComputador && choice[1][1] == ' ')
                    {
                        choice[1][1] = simboloComputador;
                    }
                    else if (choice[2][0] == simboloComputador && choice[2][1] == simboloComputador && choice[2][2] == ' ')
                    {
                        choice[2][2] = simboloComputador;
                    }
                    else if (choice[2][2] == simboloComputador && choice[2][1] == simboloComputador && choice[2][0] == ' ')
                    {
                        choice[2][0] = simboloComputador;
                    }
                    else if (choice[2][0] == simboloComputador && choice[2][2] == simboloComputador && choice[2][1] == ' ')
                    {
                        choice[2][1] = simboloComputador;
                    }

                    // ============================================================
                    // 2. ATAQUES VERTICAIS (Colunas: 0, 1 e 2)
                    // ============================================================
                    else if (choice[0][0] == simboloComputador && choice[1][0] == simboloComputador && choice[2][0] == ' ')
                    {
                        choice[2][0] = simboloComputador;
                    }
                    else if (choice[2][0] == simboloComputador && choice[1][0] == simboloComputador && choice[0][0] == ' ')
                    {
                        choice[0][0] = simboloComputador;
                    }
                    else if (choice[0][0] == simboloComputador && choice[2][0] == simboloComputador && choice[1][0] == ' ')
                    {
                        choice[1][0] = simboloComputador;
                    }
                    else if (choice[0][1] == simboloComputador && choice[1][1] == simboloComputador && choice[2][1] == ' ')
                    {
                        choice[2][1] = simboloComputador;
                    }
                    else if (choice[2][1] == simboloComputador && choice[1][1] == simboloComputador && choice[0][1] == ' ')
                    {
                        choice[0][1] = simboloComputador;
                    }
                    else if (choice[0][1] == simboloComputador && choice[2][1] == simboloComputador && choice[1][1] == ' ')
                    {
                        choice[1][1] = simboloComputador;
                    }
                    else if (choice[0][2] == simboloComputador && choice[1][2] == simboloComputador && choice[2][2] == ' ')
                    {
                        choice[2][2] = simboloComputador;
                    }
                    else if (choice[2][2] == simboloComputador && choice[1][2] == simboloComputador && choice[0][2] == ' ')
                    {
                        choice[0][2] = simboloComputador;
                    }
                    else if (choice[0][2] == simboloComputador && choice[2][2] == simboloComputador && choice[1][2] == ' ')
                    {
                        choice[1][2] = simboloComputador;
                    }

                    // ============================================================
                    // 3. ATAQUES DIAGONAIS
                    // ============================================================
                    else if (choice[0][0] == simboloComputador && choice[1][1] == simboloComputador && choice[2][2] == ' ')
                    {
                        choice[2][2] = simboloComputador;
                    }
                    else if (choice[2][2] == simboloComputador && choice[1][1] == simboloComputador && choice[0][0] == ' ')
                    {
                        choice[0][0] = simboloComputador;
                    }
                    else if (choice[0][0] == simboloComputador && choice[2][2] == simboloComputador && choice[1][1] == ' ')
                    {
                        choice[1][1] = simboloComputador;
                    }
                    else if (choice[0][2] == simboloComputador && choice[1][1] == simboloComputador && choice[2][0] == ' ')
                    {
                        choice[2][0] = simboloComputador;
                    }
                    else if (choice[2][0] == simboloComputador && choice[1][1] == simboloComputador && choice[0][2] == ' ')
                    {
                        choice[0][2] = simboloComputador;
                    }
                    else if (choice[0][2] == simboloComputador && choice[2][0] == simboloComputador && choice[1][1] == ' ')
                    {
                        choice[1][1] = simboloComputador;
                    }

                    // ============================================================
                    // 1. BLOQUEIOS HORIZONTAIS (Linhas: 0, 1 e 2)
                    // ============================================================
                    else if (choice[0][0] == simbolo && choice[0][1] == simbolo && choice[0][2] == ' ')
                    {
                        choice[0][2] = simboloComputador;
                    }
                    else if (choice[0][2] == simbolo && choice[0][1] == simbolo && choice[0][0] == ' ')
                    {
                        choice[0][0] = simboloComputador;
                    }
                    else if (choice[0][0] == simbolo && choice[0][2] == simbolo && choice[0][1] == ' ')
                    {
                        choice[0][1] = simboloComputador;
                    }
                    else if (choice[1][0] == simbolo && choice[1][1] == simbolo && choice[1][2] == ' ')
                    {
                        choice[1][2] = simboloComputador;
                    }
                    else if (choice[1][2] == simbolo && choice[1][1] == simbolo && choice[1][0] == ' ')
                    {
                        choice[1][0] = simboloComputador;
                    }
                    else if (choice[1][0] == simbolo && choice[1][2] == simbolo && choice[1][1] == ' ')
                    {
                        choice[1][1] = simboloComputador;
                    }
                    else if (choice[2][0] == simbolo && choice[2][1] == simbolo && choice[2][2] == ' ')
                    {
                        choice[2][2] = simboloComputador;
                    }
                    else if (choice[2][2] == simbolo && choice[2][1] == simbolo && choice[2][0] == ' ')
                    {
                        choice[2][0] = simboloComputador;
                    }
                    else if (choice[2][0] == simbolo && choice[2][2] == simbolo && choice[2][1] == ' ')
                    {
                        choice[2][1] = simboloComputador;
                    }

                    // ============================================================
                    // 2. BLOQUEIOS VERTICAIS (Colunas: 0, 1 e 2)
                    // ============================================================
                    else if (choice[0][0] == simbolo && choice[1][0] == simbolo && choice[2][0] == ' ')
                    {
                        choice[2][0] = simboloComputador;
                    }
                    else if (choice[2][0] == simbolo && choice[1][0] == simbolo && choice[0][0] == ' ')
                    {
                        choice[0][0] = simboloComputador;
                    }
                    else if (choice[0][0] == simbolo && choice[2][0] == simbolo && choice[1][0] == ' ')
                    {
                        choice[1][0] = simboloComputador;
                    }
                    else if (choice[0][1] == simbolo && choice[1][1] == simbolo && choice[2][1] == ' ')
                    {
                        choice[2][1] = simboloComputador;
                    }
                    else if (choice[2][1] == simbolo && choice[1][1] == simbolo && choice[0][1] == ' ')
                    {
                        choice[0][1] = simboloComputador;
                    }
                    else if (choice[0][1] == simbolo && choice[2][1] == simbolo && choice[1][1] == ' ')
                    {
                        choice[1][1] = simboloComputador;
                    }
                    else if (choice[0][2] == simbolo && choice[1][2] == simbolo && choice[2][2] == ' ')
                    {
                        choice[2][2] = simboloComputador;
                    }
                    else if (choice[2][2] == simbolo && choice[1][2] == simbolo && choice[0][2] == ' ')
                    {
                        choice[0][0] = simboloComputador;
                    }
                    else if (choice[0][2] == simbolo && choice[2][2] == simbolo && choice[1][2] == ' ')
                    {
                        choice[1][2] = simboloComputador;
                    }

                    // ============================================================
                    // 3. BLOQUEIOS DIAGONAIS
                    // ============================================================
                    else if (choice[0][0] == simbolo && choice[1][1] == simbolo && choice[2][2] == ' ')
                    {
                        choice[2][2] = simboloComputador;
                    }
                    else if (choice[2][2] == simbolo && choice[1][1] == simbolo && choice[0][0] == ' ')
                    {
                        choice[0][0] = simboloComputador;
                    }
                    else if (choice[0][0] == simbolo && choice[2][2] == simbolo && choice[1][1] == ' ')
                    {
                        choice[1][1] = simboloComputador;
                    }
                    else if (choice[0][2] == simbolo && choice[1][1] == simbolo && choice[2][0] == ' ')
                    {
                        choice[2][0] = simboloComputador;
                    }
                    else if (choice[2][0] == simbolo && choice[1][1] == simbolo && choice[0][2] == ' ')
                    {
                        choice[0][2] = simboloComputador;
                    }
                    else if (choice[0][2] == simbolo && choice[2][0] == simbolo && choice[1][1] == ' ')
                    {
                        choice[1][1] = simboloComputador;
                    }
                    else
                    {
                        do
                        {
                            linha = rand() % 3;
                            coluna = rand() % 3;
                        } while (choice[linha][coluna] != ' ');

                        choice[linha][coluna] = simboloComputador;
                    }
                }

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        printf("[ %c ]", choice[i][j]);
                    }
                    printf("\n");
                }

                if (choice[0][0] == simbolo && choice[0][1] == simbolo && choice[0][2] == simbolo ||
                    choice[1][0] == simbolo && choice[1][1] == simbolo && choice[1][2] == simbolo ||
                    choice[2][0] == simbolo && choice[2][1] == simbolo && choice[2][2] == simbolo ||
                    choice[0][0] == simbolo && choice[1][0] == simbolo && choice[2][0] == simbolo ||
                    choice[0][1] == simbolo && choice[1][1] == simbolo && choice[2][1] == simbolo ||
                    choice[0][2] == simbolo && choice[1][2] == simbolo && choice[2][2] == simbolo ||
                    choice[0][0] == simbolo && choice[1][1] == simbolo && choice[2][2] == simbolo ||
                    choice[0][2] == simbolo && choice[1][1] == simbolo && choice[2][0] == simbolo)
                {
                    ganhadorJogador = 1;
                    pontoJogador += 1;
                    printf("Voce ganhou esta jogada!\n Jogador: %d pontos | Máquina: %d pontos\n", pontoJogador, pontoComputador);
                    printf("Fim da %dª jogada!\n", k);
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            choice[i][j] = ' ';
                        }
                    }
                    k++;
                }
                else if (choice[0][0] == simboloComputador && choice[0][1] == simboloComputador && choice[0][2] == simboloComputador ||
                         choice[1][0] == simboloComputador && choice[1][1] == simboloComputador && choice[1][2] == simboloComputador ||
                         choice[2][0] == simboloComputador && choice[2][1] == simboloComputador && choice[2][2] == simboloComputador ||
                         choice[0][0] == simboloComputador && choice[1][0] == simboloComputador && choice[2][0] == simboloComputador ||
                         choice[0][1] == simboloComputador && choice[1][1] == simboloComputador && choice[2][1] == simboloComputador ||
                         choice[0][2] == simboloComputador && choice[1][2] == simboloComputador && choice[2][2] == simboloComputador ||
                         choice[0][0] == simboloComputador && choice[1][1] == simboloComputador && choice[2][2] == simboloComputador ||
                         choice[0][2] == simboloComputador && choice[1][1] == simboloComputador && choice[2][0] == simboloComputador)
                {
                    ganhadorMaquina = 1;
                    pontoComputador += 1;
                    printf("Computador ganhou esta jogada!\n Jogador: %d pontos | Máquina: %d pontos\n", pontoJogador, pontoComputador);
                    printf("Fim da %dª jogada!\n", k);
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            choice[i][j] = ' ';
                        }
                    }
                    k++;
                }
                else
                {
                    contador = 0;
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            if (choice[i][j] != ' ')
                            {
                                contador++;
                            }
                        }
                    }

                    if (contador == 9)
                    {
                        printf("Jogo empatado! - Jogador - %d pontos - Computador - %d pontos.\n", pontoJogador, pontoComputador);
                        printf("Fim da %dª jogada!\n", k);
                        for (int i = 0; i < 3; i++)
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                choice[i][j] = ' ';
                            }
                        }
                        k++;
                    }
                }
            }

            printf("Fim do Jogo! - Jogador - %d pontos - Computador - %d pontos.\n", pontoJogador, pontoComputador);
            condition = 0;
        }
        else
        {
            printf("Opção inválida!!! - Escolha X ou O para jogar\n");
            scanf(" %c", &simbolo);
        }
    }

    return 0;
}