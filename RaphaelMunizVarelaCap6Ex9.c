/*
Aluno: Raphael Muniz Varela
Matrícula: 32411BSI003
Faça um programa que efetue reserva de passagens aéreas de uma companhia. O programa deverá ler
informações sobre os voos (número, origem e destino) e o número de lugares disponíveis para doze
aviões (um vetor para cada um desses dados). Depois da leitura, o programa deverá apresentar um
menu com as seguintes opções:
■ consultar;
■ efetuar reserva; e
■ sair.
Quando a opção escolhida for Consultar, deverá ser disponibilizado mais um menu com as seguintes
opções:
■ por número do voo;
■ por origem; e
■ por destino.
Quando a opção escolhida for Efetuar reserva, deverá ser perguntado o número do voo em que a pes-
soa deseja viajar. O programa deverá dar as seguintes respostas:
■ reserva confirmada — caso exista o voo e lugar disponível, dando baixa nos lugares disponíveis;
■ voo lotado — caso não exista lugar disponível nesse voo;
■ voo inexistente — caso o código do voo não exista.
A opção Sair é a única que permite encerrar a execução do programa. Sendo assim, após cada operação
de consulta ou reserva, o programa volta ao menu principal. */
#include <stdio.h>
#include <string.h>

// Declaração de variáveis
int voo[12], lugares[12];
char origem[12][50], destino[12][50];

// Define dados
void defineDados()
{
    // Acessa as 12 posições do vetor
    for (int ii = 0; ii < 12; ii++)
    {
        printf("\n========================| %d° |========================\n", (ii + 1));
        // Ler código do voo
        printf("Código: ");
        scanf("%d", &voo[ii]);
        setbuf(stdin, NULL);

        // Ler origem do voo
        printf("Origem: ");
        fgets(origem[ii], sizeof(origem[ii]), stdin);
        origem[ii][strcspn(origem[ii], "\n")] = '\0';

        // Ler destino do voo
        printf("Destino: ");
        fgets(destino[ii], sizeof(destino[ii]), stdin);
        destino[ii][strcspn(destino[ii], "\n")] = '\0';

        // Ler quantidade de assentos do voo
        printf("Número de lugares disponíveis: ");
        scanf("%d", &lugares[ii]);
        setbuf(stdin, NULL);
    }
}

// Mostra menu principal
void mostraMenuPrincipal()
{
    printf("\n========================| Menu |========================\n");
    printf("[1] Consultar\n");
    printf("[2] Efetuar reserva\n");
    printf("[3] Sair\n");
    printf("----------------------------------------------------------\n");
}

// Mostra menu consultar
void mostraMenuConsultar()
{
    printf("\n===================| Menu Consultar |===================\n");
    printf("[1] Consulta por voo\n");
    printf("[2] Consulta por origem\n");
    printf("[3] Consulta por destino\n");
    printf("----------------------------------------------------------\n");
}

// Mostra dados de um voo
void dadosVoo(int indice)
{
    printf("-- Número do voo: %d\n", voo[indice]);
    printf("-- Local de origem: %s\n", origem[indice]);
    printf("-- Local de destino: %s\n", destino[indice]);
    printf("-- Lugares disponíveis: %d\n", lugares[indice]);
}

// Consulta por voo
void consultaPorVoo(int num_voo)
{
    for (int ii = 0; ii < 12; ii++)
    {
        if (num_voo == voo[ii])
        {
            dadosVoo(ii);
            return;
        }
    }

    printf("\n-- Voo inexistente!\n");
}

// Consulta por origem
void consultaPorOrigem(char origem_voo[50])
{
    for (int ii = 0; ii < 12; ii++)
    {
        if (strcmp(origem_voo, origem[ii]) == 0)
        {
            dadosVoo(ii);
            return;
        }
    }

    printf("\n-- Origem não encontrada!\n");
}

// Consulta por destino
void consultaPorDestino(char destino_voo[50])
{
    for (int ii = 0; ii < 12; ii++)
    {
        if (strcmp(destino_voo, destino[ii]) == 0)
        {
            dadosVoo(ii);
            return;
        }
    }

    printf("\n-- Destino não encontrado!\n");
}

// Retorna índice do voo
int indiceVoo(int num_voo)
{
    for (int ii = 0; ii < 12; ii++)
    {
        if (num_voo == voo[ii])
        {
            return ii;
        }
    }

    return -1;
}

// Verifica se há vaga
int haVaga(int indice)
{
    if (lugares[indice] > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // Declaração de variáveis
    int op, num_voo;
    char local[50];

    // Define dados
    defineDados();

    // Enquanto a opção for diferente de '3' a repetição continuará
    do
    {
        // Mostra menu principal
        mostraMenuPrincipal();
        // Ler opção
        printf("Digite sua opção: ");
        scanf("%d", &op);
        setbuf(stdin, NULL);

        // Verifica opção informada
        switch (op)
        {
        // Consultar
        case 1:
            mostraMenuConsultar();
            printf("Digite sua opção: ");
            scanf("%d", &op);
            setbuf(stdin, NULL);

            switch (op)
            {
            // Por número do voo
            case 1:
                printf("\nDigite o número de voo: ");
                scanf("%d", &num_voo);
                setbuf(stdin, NULL);

                consultaPorVoo(num_voo);
                break;

            // Por origem
            case 2:
                printf("\nDigite a origem: ");
                fgets(local, sizeof(local), stdin);
                local[strcspn(local, "\n")] = '\0';

                consultaPorOrigem(local);
                break;

            // Por destino
            case 3:
                printf("\nDigite o destino: ");
                fgets(local, sizeof(local), stdin);
                local[strcspn(local, "\n")] = '\0';

                consultaPorDestino(local);
                break;
            }

            op = -1;
            break;

        // Efetuar reserva
        case 2:
            // Ler número do voo
            printf("Digite o número do voo desejado: ");
            scanf("%d", &num_voo);
            setbuf(stdin, NULL);

            // Verifica se voo existe
            if (indiceVoo(num_voo) != -1)
            {
                // Verifica se há vaga
                if (haVaga(indiceVoo(num_voo)))
                {
                    lugares[indiceVoo(num_voo)] = lugares[indiceVoo(num_voo)] - 1;
                    printf("-- Reserva confirmada!\n");
                }
                else
                {
                    printf("-- Voo lotado!\n");
                }
            }
            else
            {
                printf("-- Voo inexistente!\n");
            }
            break;

        // Sair
        case 3:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida!\n");
        }
    } while (op != 3);

    return 0;
}