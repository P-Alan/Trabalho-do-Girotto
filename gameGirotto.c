#include <stdio.h>
#include <stdlib.h>

// LIMPAR TELA

static void limpar_tela()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// LIMPAR A MEMÓRIA

static void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// FUNÇÃO PARA LER ESCOLHAS (números inteiros)

static int ler_int(const char *prompt, int min, int max)
{
    int valor;
    int resultado;

    while (1)
    {
        printf("%s", prompt);
        resultado = scanf("%d", &valor);

        // USUÁRIO FECHOU A ENTRADA

        if (resultado == EOF)
        {
            printf("\nEntrada encerrada. Saindo do jogo...\n");
            exit(0);
        }

        // USUÁRIO DIGITOU ALGO QUE NÃO É NÚMERO

        if (resultado != 1)
        {
            printf("Entrada inválida! Digite um número entre %d e %d.\n", min, max);
            limpar_buffer();
            continue;
        }

        // VERIFICA SE TEM LIXO DEPOIS DO NÚMERO

        int proximo = getchar();
        if (proximo == EOF)
        {
            printf("\nEntrada encerrada. Saindo do jogo...\n");
            exit(0);
        }
        if (proximo != '\n')
        {
            printf("Entrada inválida! Digite apenas o número entre %d e %d.\n", min, max);
            limpar_buffer();
            continue;
        }

        // VERIFICA SE O NÚMERO ESTÁ DENTRO DO INTERVALO

        if (valor < min || valor > max)
        {
            printf("Opção fora do intervalo! Escolha entre %d e %d.\n", min, max);
            continue;
        }

        return valor;
    }
}

// PERGUNTAS E RESPOSTAS

static int perguntas_e_respostas()
{
    limpar_tela();
    printf("\n=====PERGUNTAS E RESPOSTAS=====\n");
    printf("O jogo consiste em 5 perguntas, tente acertar! ;)\n\n");

    // PERGUNTA 1

    printf("PRIMEIRA PERGUNTA:\nQual o professor mais lindo do CESUPA?\n");
    printf("\n[1] Pedro Girotto");
    printf("\n[2] Polyana Ribeiro");
    printf("\n[3] Ricardo Casseb");
    printf("\n[4] Alessandra Baganha\n\n");

    int r1 = ler_int("Sua resposta: ", 1, 4);
    limpar_tela();
    if (r1 != 1)
    {
        printf("\nERROU !!\n");
        int op = ler_int("Pressione '1' para reiniciar ou '2' para o menu: ", 1, 2);
        if (op == 1)
            return 1; // reinicia o jogo
        else
            return 0; // volta ao menu
    }
    printf("\nVOCE ACERTOU !!\n\n");

    // PERGUNTA 2

    printf("SEGUNDA PERGUNTA:\nQuanto vale esse trabalho?\n");
    printf("\n[1] 2");
    printf("\n[2] 0.5");
    printf("\n[3] 3");
    printf("\n[4] Pra esse daqui especificamente: 0!\n\n");

    int r2 = ler_int("Sua resposta: ", 1, 4);
    limpar_tela();
    if (r2 != 3)
    {
        printf("\nERROU !!\n");
        int op = ler_int("Pressione '1' para reiniciar ou '2' para o menu: ", 1, 2);
        if (op == 1)
            return 1; // reinicia o jogo
        else
            return 0; // volta ao menu
    }
    printf("\nVOCE ACERTOU !!\n\n");
    // PERGUNTA 3


    printf("TERCEIRA PERGUNTA:\nQual vai ser o game do ano?\n");
    printf("\n[1] Resident Evil: Requiem");
    printf("\n[2] Mineirinho 2");
    printf("\n[3] Girotto's Game");
    printf("\n[4] Cafe Girotto Adventure\n\n");

    int r3 = ler_int("Sua resposta: ", 1, 4);
    limpar_tela();
    if (r3 != 4)
    {
        printf("\nERROU !!\n");
        int op = ler_int("Pressione '1' para reiniciar ou '2' para o menu: ", 1, 2);
        if (op == 1)
            return 1; // reinicia o jogo
        else
            return 0; // volta ao menu
    }
    printf("\nVOCE ACERTOU !!\n\n");

    // PERGUNTA 4

    printf("QUARTA PERGUNTA:\nQuanto eh 2 + 2?\n");
    printf("\n[1] -4");
    printf("\n[2] 0.19");
    printf("\n[3] 321");
    printf("\n[4] 4\n\n");

    int r4 = ler_int("Sua resposta: ", 1, 4);
    limpar_tela();
    if (r4 != 4)
    {
        printf("\nERROU !!\n");
        int op = ler_int("Pressione '1' para reiniciar ou '2' para o menu: ", 1, 2);
        if (op == 1)
            return 1; // reinicia o jogo
        else
            return 0; // volta ao menu
    }
    printf("\nVOCE ACERTOU !!\n\n");

    // PERGUNTA 5

    printf("QUINTA PERGUNTA:\nQual a melhor my little poney?\n");
    printf("\n[1] Rainbow Dash");
    printf("\n[2] Apple Jack");
    printf("\n[3] Twilight Sparkle");
    printf("\n[4] Pinkie Pie\n\n");

    int r5 = ler_int("Sua resposta: ", 1, 4);
    limpar_tela();
    if (r5 != 1)
    {
        printf("\nERROU !!\n");
        int op = ler_int("Pressione '1' para reiniciar ou '2' para o menu: ", 1, 2);
        if (op == 1)
            return 1; // reinicia o jogo
        else
            return 0; // volta ao menu
    }

    printf("\nPARABENS VOCE E MUITO INTELIGENTE !!\n");
    printf("Voce deseja jogar de novo?:\n");
    printf("[S] Pressione '1'\n[N] Pressione '2'\n");
    int fim = ler_int("Sua escolha: ", 1, 2);
    if (fim == 1)
        return 1; // reinicia o jogo
    else
        return 0; // volta ao menu
}

// COBRA NA CAIXA

static int cobra_na_caixa()
{
    const char *nomes[] = {"", "Pedro Alan", "João Gabriel", "Cleopatra", "Ronaldo", "Mordecai", "Rigby", "Café"};
    int n_nomes = 7;

    limpar_tela();
    printf("========Escolha seu nome=========\n");
    printf("===========JOGADOR 1=============\n");
    for (int i = 1; i <= n_nomes; i++)
        printf("%d. %s\n", i, nomes[i]);

    int escolha1 = ler_int("Jogador 1, escolha (1-7): ", 1, n_nomes);

    limpar_tela();
    printf("========Escolha seu nome=========\n");
    printf("==========JOGADOR 2==============\n");
    for (int i = 1; i <= n_nomes; i++)
        printf("%d. %s\n", i, nomes[i]);

    int escolha2 = ler_int("Jogador 2, escolha (1-7): ", 1, n_nomes);

    if (escolha1 == escolha2)
    {
        limpar_tela();
        printf("'%s' ja foi escolhido!\n", nomes[escolha1]);
        int op = ler_int("Pressione '1' para escolher novamente ou '2' para o menu: ", 1, 2);
        if (op == 1)
            return 1; // reinicia o jogo
        else
            return 0; // volta ao menu
    }

    // sorteio de qual jogador começa

    const char *jogadores[2] = {nomes[escolha1], nomes[escolha2]};
    int sorteio = rand() % 2;
    const char *jogador_escolhido = jogadores[sorteio];

    // pega sempre o valor contrário do que foi sorteado primeiro

    const char *jogador_resto = jogadores[1 - sorteio];

    int rodada = 1;
    int jogo_rodando = 1;
    int caixas_disponiveis[6] = {0, 1, 1, 1, 1, 1};
    int total_caixas = 5;

    limpar_tela();
    printf("O primeiro a jogar sera: %s\n", jogador_escolhido);

    // Randomização do botão e da cobra por reinicialização
    
    int cobra = (rand() % 5) + 1;
    int botao;
    do
    {
        botao = (rand() % 5) + 1;
    } while (botao == cobra);

    while (jogo_rodando)
    {

        printf("\n====Rodada %d====\n\n", rodada++);
        for (int i = 1; i <= 5; i++)
            if (caixas_disponiveis[i])
            {
                printf("[CAIXA %d]\n", i);

                // printf("%d %d", cobra, botao);
            }
        int caixa_escolhida;
        while (1)
        {
            printf("%s, escolha uma caixa disponivel (1-5): ", jogador_escolhido);
            caixa_escolhida = ler_int("", 1, 5);
            if (!caixas_disponiveis[caixa_escolhida])
                printf("Caixa %d ja foi eliminada! Tente outra.\n", caixa_escolhida);
            else
                break;
        }

        if (caixa_escolhida == cobra)
        {
            limpar_tela();
            printf("\nCOBRA! %s perdeu!\n", jogador_escolhido);
            printf("%s VENCEU!\n", jogador_resto);
            jogo_rodando = 0;
        }
        else if (caixa_escolhida == botao)
        {
            limpar_tela();
            printf("\nBOTAO! %s VENCEU!\n", jogador_escolhido);
            jogo_rodando = 0;
        }
        else
        {
            limpar_tela();
            caixas_disponiveis[caixa_escolhida] = 0;
            total_caixas--;
            printf("\nCaixa vazia! Caixa %d eliminada. Restam %d caixa(s).\n",
                   caixa_escolhida, total_caixas);
            const char *temp = jogador_escolhido;
            jogador_escolhido = jogador_resto;
            jogador_resto = temp;
        }

        if (!jogo_rodando)
        {
            printf("\nDeseja jogar novamente?\n1. Sim\n2. Nao\n");
            int fim = ler_int("Sua escolha: ", 1, 2);
            if (fim == 1)
                return 1; // reinicia o jogo
            else
                return 0; // volta ao menu
        }
    }
    return 0;
}

// GOUSMAS WAR

int calculo_furia_1[3] = {0, 1, 1};
int calculo_furia_2[3] = {0, 1, 1};
int furia_transferida;
int divisor;
int rodada;
int turno_p2, turno_p1;
int ação;
int gousma_valida = 0;
int max_pode_dar;
int max_pode_receber;
int limite_real;
int origem, destino;

int divisao1()
{
    // ZERANDO AS VARIÁVEIS QUE SIMPLIFICAM O CÓDIGO

    origem = 0;
    destino = 0;

    while (1)
    {
        limpar_tela();

        printf("\n-- Escolha qual Gousma você vai dividir --\n\n");
        printf("[1] Gousma Azul | Fúria: ");
        (calculo_furia_1[1] == 0) ? printf("MORTA\n") : printf("%i\n", calculo_furia_1[1]);

        printf("[2] Gousma Verde | Fúria: ");
        (calculo_furia_1[2] == 0) ? printf("MORTA\n\n") : printf("%i\n\n", calculo_furia_1[2]);

        origem = ler_int("Escolha a Gousma (1-2): ", 1, 2);
        destino = (origem == 1) ? 2 : 1;

        if (calculo_furia_1[origem] < 2)
        {
            printf("\nEssa Gousma está morta ou não tem fúria suficiente para dividir!\n");
            continue;
        }

        if (calculo_furia_1[destino] >= 5)
        {
            printf("\nA Gousma que você quer adicionar mais Fúria já está cheia (Fúria 5)!\n");
            continue;
        }

        max_pode_dar = calculo_furia_1[origem] - 1;
        max_pode_receber = 5 - calculo_furia_1[destino];
        limite_real = (max_pode_dar < max_pode_receber) ? max_pode_dar : max_pode_receber;

        printf("\nQuanto de Fúria transferir (1 - %d)?\n", limite_real);
        furia_transferida = ler_int("Escolha: ", 1, limite_real);

        calculo_furia_1[origem] -= furia_transferida;
        calculo_furia_1[destino] += furia_transferida;

        limpar_tela();

        printf("===== STATUS ATUAL =====\n\n");
        printf("\n- AZUL | FÚRIA : %d\n- VERDE | FÚRIA : %d\n", calculo_furia_1[1], calculo_furia_1[2]);
        break;
    }
    return 0;
}

int divisao2()
{
    // ZERANDO AS VARIÁVEIS QUE SIMPLIFICAM O CÓDIGO

    origem = 0;
    destino = 0;

    while (1)
    {
        limpar_tela();

        printf("\n-- Escolha qual Gousma você vai dividir --\n\n");
        printf("[1] Gousma Amarela | Fúria: ");
        (calculo_furia_2[1] == 0) ? printf("MORTA\n") : printf("%i\n", calculo_furia_2[1]);

        printf("[2] Gousma Vermelha | Fúria: ");
        (calculo_furia_2[2] == 0) ? printf("MORTA\n\n") : printf("%i\n\n", calculo_furia_2[2]);

        origem = ler_int("Escolha a Gousma (1-2): ", 1, 2);
        destino = (origem == 1) ? 2 : 1;

        if (calculo_furia_2[origem] < 2)
        {
            printf("\nEssa Gousma está morta ou não tem fúria suficiente para dividir!\n");
            continue;
        }

        if (calculo_furia_2[destino] >= 5)
        {
            printf("\nA Gousma que você quer adicionar mais Fúria já está cheia (Fúria 5)!\n");
            continue;
        }

        max_pode_dar = calculo_furia_2[origem] - 1;
        max_pode_receber = 5 - calculo_furia_2[destino];
        limite_real = (max_pode_dar < max_pode_receber) ? max_pode_dar : max_pode_receber;

        printf("\nQuanto de Fúria transferir (1 - %d)?\n", limite_real);
        furia_transferida = ler_int("Escolha: ", 1, limite_real);

        calculo_furia_2[origem] -= furia_transferida;
        calculo_furia_2[destino] += furia_transferida;

        limpar_tela();

        printf("===== STATUS ATUAL =====\n\n");
        printf("\n- AMARELA | FÚRIA : %d\n- VERMELHA | FÚRIA : %d\n", calculo_furia_2[1], calculo_furia_2[2]);
        break;
    }
    return 0;
}

int ataque1()
{
    int atacante, alvo;

    while (1)
    {
        limpar_tela();

        // ESCOLHER O ATACANTE

        printf("\n-- Escolha com qual Gousma você vai atacar --\n\n");
        printf("[1] Gousma Azul | Fúria: ");
        (calculo_furia_1[1] == 0) ? printf("MORTA\n") : printf("%i\n", calculo_furia_1[1]);

        printf("[2] Gousma Verde | Fúria: ");
        (calculo_furia_1[2] == 0) ? printf("MORTA\n\n") : printf("%i\n\n", calculo_furia_1[2]);

        atacante = ler_int("Escolha uma opcao (1-2): ", 1, 2);

        if (calculo_furia_1[atacante] == 0)
        {
            printf("\nGousma MORTA não pode atacar! Escolha outra.\n");
            continue;
        }

        // ESCOLHER O ALVO

        while (1)
        {
            limpar_tela();
            
            printf("\n-- Agora escolha qual Gousma você vai atacar --\n\n");
            printf("[1] Gousma Amarela | Fúria: ");
            (calculo_furia_2[1] == 0) ? printf("MORTA\n") : printf("%i\n", calculo_furia_2[1]);

            printf("[2] Gousma Vermelha | Fúria: ");
            (calculo_furia_2[2] == 0) ? printf("MORTA\n\n") : printf("%i\n\n", calculo_furia_2[2]);

            alvo = ler_int("Escolha uma opcao (1-2): ", 1, 2);

            if (calculo_furia_2[alvo] == 0)
            {
                printf("\nVocê não pode atacar uma Gousma que já está MORTA!\n");
                continue;
            }

            calculo_furia_2[alvo] += calculo_furia_1[atacante];
            if (calculo_furia_2[alvo] <= 5)
            {
                if (alvo == 1)
                {
                    printf("\nA Fúria da Gousma Amarela agora é de: %i", calculo_furia_2[alvo]);
                }
                if (alvo == 2)
                {
                    printf("\nA Fúria da Gousma Vermelha agora é de: %i", calculo_furia_2[alvo]);
                }
            }
            if (calculo_furia_2[alvo] > 5)
            {
                printf("\nMORRREU !! A Gousma morreu por excesso de fúria.");
                calculo_furia_2[alvo] = 0;
            }
            return 0;
        }
    }
}

int ataque2()
{
    int atacante, alvo;

    while (1)
    {
        limpar_tela();

        // ESCOLHER O ATACANTE

        printf("\n-- Escolha com qual Gousma você vai atacar --\n\n");
        printf("[1] Gousma Amarela | Fúria: ");
        (calculo_furia_2[1] == 0) ? printf("MORTA\n") : printf("%i\n", calculo_furia_2[1]);

        printf("[2] Gousma Vermelha | Fúria: ");
        (calculo_furia_2[2] == 0) ? printf("MORTA\n\n") : printf("%i\n\n", calculo_furia_2[2]);

        atacante = ler_int("Escolha uma opcao (1-2): ", 1, 2);

        if (calculo_furia_2[atacante] == 0)
        {
            printf("\nGousma MORTA não pode atacar! Escolha outra.\n");
            continue;
        }

        // ESCOLHER O ALVO

        while (1)
        {
            limpar_tela();

            printf("\n-- Agora escolha qual Gousma você vai atacar --\n\n");
            printf("[1] Gousma Azul | Fúria: ");
            (calculo_furia_1[1] == 0) ? printf("MORTA\n") : printf("%i\n", calculo_furia_1[1]);

            printf("[2] Gousma Verde | Fúria: ");
            (calculo_furia_1[2] == 0) ? printf("MORTA\n\n") : printf("%i\n\n", calculo_furia_1[2]);

            alvo = ler_int("Escolha uma opcao (1-2): ", 1, 2);

            if (calculo_furia_1[alvo] == 0)
            {
                printf("\nVocê não pode atacar uma Gousma que já está MORTA!\n");
                continue;
            }

            calculo_furia_1[alvo] += calculo_furia_2[atacante];
            if (calculo_furia_1[alvo] <= 5)
            {
                if (alvo == 1)
                {
                    printf("\nA Fúria da Gousma Azul agora é de: %i", calculo_furia_1[alvo]);
                }
                if (alvo == 2)
                {
                    printf("\nA Fúria da Gousma Verde agora é de: %i", calculo_furia_1[alvo]);
                }
            }
            if (calculo_furia_1[alvo] > 5)
            {
                printf("\nMORRREU !! A Gousma morreu por excesso de fúria.");
                calculo_furia_1[alvo] = 0;
            }
            return 0;
        }
    }
}

static int gousmas_war()
{
    int gousma_rodando = 1;

    // REINICIANDO AS VARIÁVEIS

    rodada = 1;
    calculo_furia_1[0] = 0, calculo_furia_1[1] = 1, calculo_furia_1[2] = 1;
    turno_p1 = 1;
    calculo_furia_2[0] = 0, calculo_furia_2[1] = 1, calculo_furia_2[2] = 1;

    limpar_tela();

    printf("A GUERRA DE GOUSMAS VAI COMEÇAR !!\n\n");
    printf("=====REGRAS=====\n- Cada jogador começa com uma Gousma.\n- Cada Gousma começa com 1 de Fúria.\n- Você só pode fazer 1 ação por turno (atacar ou dividir).\n- Atacar uma Gousma adversária aumenta a sua fúria na quantidade de Fúria da Gousma que atacou.\n- Ao dividir você pode reviver a sua Gousma.\n- Você não pode dividir uma Gousma com 1 de Fúria\n- Uma Gousma morre ao passar de 5 de Fúria.");

    while (gousma_rodando)
    {
        if (turno_p1 == 1)
        {
            turno_p1 = 0;

            printf("\n\n======RODADA %i=====\n\n", rodada);
            printf("-- Jogador 1, escolha sua ação --\n\n");
            printf("[1] ATACAR  [2] DIVIDIR\n\n");

            ação = ler_int("Escolha uma opção (1-2): ", 1, 2);

            // CASO ESCOLHA DIVIDIR

            if (ação == 2)
            {
                if (calculo_furia_1[1] >= 2 && calculo_furia_1[1] <= 5 || calculo_furia_1[2] >= 2 && calculo_furia_1[2] <= 5)
                {
                    limpar_tela();
                    turno_p2 = 1; // Evita travamento do jogo
                    divisao1();
                    rodada++;
                }

                else
                {
                    printf("\nAção inválida, escolha outra !!");
                    turno_p1 = 1;
                }
            }

            // CASO ESCOLHA ATACAR

            if (ação == 1)
            {
                limpar_tela();
                turno_p2 = 1; // Evita o travamento do jogo
                ataque1();
                rodada++;
            }

            if (calculo_furia_2[1] == 0 && calculo_furia_2[2] == 0)
            {
                gousma_rodando = 0;

                limpar_tela();
                printf("\n\nJOGADOR 1 GANHOU A GUERRA!!!!\n");

                if (gousma_rodando == 0)
                {
                    printf("\nDeseja jogar novamente?\n1. Sim\n2. Nao\n");
                    int fim = ler_int("Sua escolha: ", 1, 2);
                    if (fim == 1)
                        return 1; // reinicia o jogo
                    else
                        return 0; // volta ao menu
                }
            }
        }
        if (turno_p2 == 1)
        {
            turno_p2 = 0;
            printf("\n\n======RODADA %i=====\n\n", rodada);
            printf("-- Jogador 2, escolha sua ação --\n\n");
            printf("[1] ATACAR  [2] DIVIDIR\n\n");

            ação = ler_int("Escolha uma opcao (1-2): ", 1, 2);

            if (ação == 2)
            {
                if (calculo_furia_2[1] >= 2 && calculo_furia_2[1] <= 5 || calculo_furia_2[2] >= 2 && calculo_furia_2[2] <= 5)
                {
                    limpar_tela();
                    turno_p1 = 1;
                    divisao2();
                    rodada++;
                }

                else
                {
                    printf("\nAção inválida, escolha outra !!");
                    turno_p2 = 1;
                }
            }

            if (ação == 1)
            {
                limpar_tela();
                turno_p1 = 1;
                ataque2();
                rodada++;
            }
            if (calculo_furia_1[1] == 0 && calculo_furia_1[2] == 0)
            {
                gousma_rodando = 0;

                limpar_tela();
                printf("\n\nJOGADOR 2 GANHOU A GUERRA!!!!\n");

                if (gousma_rodando == 0)
                {
                    printf("\nDeseja jogar novamente?\n1. Sim\n2. Nao\n");
                    int fim = ler_int("Sua escolha: ", 1, 2);
                    if (fim == 1)
                        return 1; // reinicia o jogo
                    else
                        return 0; // volta ao menu
                }
            }
        }
    }
}

// MENU

int main()
{
    int menu_ativo = 1;

    while (menu_ativo)
    {
        limpar_tela();
        printf("\n=====GIROTTOS'S GAME=====\n");
        printf("1: Perguntas e Respostas\n");
        printf("2: Cobra na Caixa!\n");
        printf("3: Gousmas War\n");
        printf("4: Sair\n");

        int option = ler_int("Escolha uma opcao (1-4): ", 1, 4);

        if (option == 1)
        {
            int reiniciar = 1;
            while (reiniciar)
                reiniciar = perguntas_e_respostas();
        }
        else if (option == 2)
        {
            int reiniciar = 1;
            while (reiniciar)
                reiniciar = cobra_na_caixa();
        }
        else if (option == 3)
        {
            int reiniciar = 1;
            while (reiniciar)
                reiniciar = gousmas_war();
        }
        else if (option == 4)
        {
            limpar_tela();
            printf("Obrigado por jogar!\n");
            return 0;
        }
    }
    return 0;
}
