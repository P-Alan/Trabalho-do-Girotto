#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    int menu = 1;

    while (menu == 1)
    {
        int option;
        printf("\n=====GIROTTOS'S GAME=====\n");

        printf("1: Pergunta e Resposta\n");
        printf("2: Cobra na Caixa!\n");
        printf("3: Gousmas War\n");
        printf("4: Sair\n");

        scanf("%d", &option);

        while (option == 1)
        {

            option = 0;
            menu = 0;

            char alternativa1[2];

            printf("\n=====PERGUNTA E RESPOSTA=====\n");
            printf("O jogo consiste em 5 perguntas, tente acertar! ;)\n\n");

            printf("PRIMEIRA PERGUNTA:\nQual o professor mais lindo do CESUPA? [A-D]\n");

            printf("\n[A] Pedro Girotto");
            printf("\n[B] Polyana Ribeiro");
            printf("\n[C] Ricardo Casseb");
            printf("\n[D] Alessandra Baganha\n\n");

            scanf("%s", &alternativa1[0]);

            if (alternativa1[0] == 'A' || alternativa1[0] == 'a')
            {
                printf("\nVOCE ACERTOU !!\n\n");
            }
            else
            {
                printf("\nERROU !!\n");
                printf("Pressione '1' para reiniciar: ");
                scanf("%d", &option);
            }

            if (alternativa1[0] == 'A' || alternativa1[0] == 'a')
            {
                char alternativa2[2];

                printf("SEGUNDA PERGUNTA:\nQuanto vale esse trabalho? [A-D]\n");

                printf("\n[A] 2");
                printf("\n[B] 0.5");
                printf("\n[C] 3");
                printf("\n[D] Pra esse daqui especificamente: 0!\n\n");

                scanf("%s", &alternativa2[0]);

                if (alternativa2[0] == 'C' || alternativa2[0] == 'c')
                {
                    printf("\nVOCE ACERTOU !!\n");
                }
                else
                {
                    printf("\nERROU !!\n");
                    printf("Pressione '1' para reiniciar: ");
                    scanf("%d", &option);
                }
                if (alternativa2[0] == 'C' || alternativa2[0] == 'c')
                {
                    char alternativa3[2];

                    printf("TERCEIRA PERGUNTA:\nQual vai ser o game do ano? [A-D]\n");

                    printf("\n[A] Resident Evil: Requiem");
                    printf("\n[B] Mineirinho 2");
                    printf("\n[C] Girotto's Game");
                    printf("\n[D] Cafe Girotto Adventure\n\n");

                    scanf("%s", &alternativa3[0]);

                    if (alternativa3[0] == 'D' || alternativa3[0] == 'd')
                    {
                        printf("\nVOCE ACERTOU !!\n\n");
                    }
                    else
                    {
                        printf("\nERROU !!\n");
                        printf("Pressione '1' para reiniciar: ");
                        scanf("%d", &option);
                    }
                    if (alternativa3[0] == 'D' || alternativa3[0] == 'd')
                    {
                        char alternativa4[2];

                        printf("QUARTA PERGUNTA:\nQuanto eh 2 + 2? [A-D]\n");

                        printf("\n[A] -4");
                        printf("\n[B] 0.19");
                        printf("\n[C] 321");
                        printf("\n[D] 4\n\n");

                        scanf("%s", &alternativa4[0]);

                        if (alternativa4[0] == 'D' || alternativa4[0] == 'd')
                        {
                            printf("\nVOCE ACERTOU !!\n");
                        }
                        else
                        {
                            printf("\nERROU !!\n");
                            printf("Pressione '1' para reiniciar: ");
                            scanf("%d", &option);
                        }
                        if (alternativa4[0] == 'D' || alternativa4[0] == 'd')
                        {
                            char alternativa5[2];

                            printf("QUINTA PERGUNTA:\nQual a melhor my little poney? [A-D]\n");

                            printf("\n[A] Rainbow Dash");
                            printf("\n[B] Apple Jack");
                            printf("\n[C] Twilight Sparkle");
                            printf("\n[D] Pinkie Pie\n\n");

                            scanf("%s", &alternativa5[0]);


                            if (alternativa5[0] == 'A' || alternativa5[0] == 'a')
                            {
                                printf("\nPARABENS VOCE EH MUITO INTELIGENTE !!\n");
                                int fim = 0;
                                if (fim == 0)
                                {

                                    printf("Você deseja jogar de novo?:\n");
                                    printf("[S] Pressione '1' \n[N] Pressione '2'\n");
                                    scanf("%d", &fim);
                                    if (fim == 1)
                                    {
                                        option = 1;
                                    }
                                    else
                                    {
                                        menu = 1;
                                    }
                                }
                                
                            }else
                                {
                                    printf("\nERROU !!\n");
                                    printf("Pressione '1' para reiniciar: ");
                                    scanf("%d", &option);
                                }
                        }
                    }
                }
            }
        }
   
        while (option == 2)
        {
            printf("=====COBRA NA CAIXA=====\n");
            printf("O jogo consiste em...!\n");
        }

        while (option == 3)
        {
            printf("=====GOUSMAS WAR=====\n");
            printf("O jogo consiste em...!\n");
        }

        while (option == 4)
        {
            printf("Obrigado por jogar!\n");
        }
    }  
}
