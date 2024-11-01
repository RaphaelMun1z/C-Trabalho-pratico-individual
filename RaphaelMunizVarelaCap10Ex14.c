/*
Aluno: Raphael Muniz Varela
Matrícula: 32411BSI003
Uma empresa patrocinadora de regatas deseja ter controle preciso sobre os participantes e os resul-
tados, a fim de realizar adequadamente o pagamento dos prêmios. Dessa maneira, precisa cadastrar
algumas informações, conforme apresentado a seguir:
Regata (número da regata, data, hora de início, código do barco vencedor).
Barco/Regata (número da regata, número do barco participante, hora de chegada).
Barco (número do barco, nome do barco, ano de fabricação).
Crie um programa que realize as seguintes rotinas:
■ Cadastrar os barcos, não permitindo dois barcos com o mesmo número (deve ser definido espaço
para seis barcos).
■ Cadastrar as regatas, não permitindo duas regatas com o mesmo número (deve ser definido espaço
para três regatas).
■ Cadastrar os participantes (não permitindo cadastrar mais de uma vez um barco para a mesma re-
gata, levando-se em consideração que em cada regata podem participar no máximo quatro barcos).
■ Mostrar uma relação das regatas realizadas, junto com o nome do barco vencedor.
■ Mostrar uma relação de todos os barcos que participaram de determinada regata, indicando o
tempo que levaram para chegar ao fim da regata (considere que todas as regatas duram no máximo
24 horas). */
#include <stdio.h>
#include <string.h>

// Declaração de structs
typedef struct
{
    int numero;
    char data[11];
    int horaInicio;
    int codBarcoVencedor;
} regata;

typedef struct
{
    int numero;
    char nome[50];
    int anoFabricacao;
} barco;

typedef struct
{
    int numeroBarco;
    int numeroRegata;
    int horaChegada;
} barcoRegata;

// Declaração de variáveis
barco barcos[6];
regata regatas[3];
barcoRegata participantes[3][4];

// Verifica se existe barco com número...
int existeBarcoComNumero(int numero)
{
    for (int ii = 0; ii < 6; ii++)
    {
        if (barcos[ii].numero == numero)
        {
            return 1;
        }
    }

    return 0;
}

// Cadastrar barcos
void cadastrarBarcos()
{
    printf("============| Cadastrar Barcos |============\n");
    for (int ii = 0; ii < 6; ii++)
    {
        int numero;

        do
        {
            printf("Número do barco: ");
            scanf("%d", &numero);
            setbuf(stdin, NULL);

            if (existeBarcoComNumero(numero))
            {
                printf("-- Já existe um barco com este número!\n\n");
            }
        } while (existeBarcoComNumero(numero));

        barcos[ii].numero = numero;

        printf("Nome do barco: ");
        fgets(barcos[ii].nome, sizeof(barcos[ii].nome), stdin);
        barcos[ii].nome[strcspn(barcos[ii].nome, "\n")] = '\0';

        printf("Ano de Fabricação: ");
        scanf("%d", &barcos[ii].anoFabricacao);
        setbuf(stdin, NULL);

        printf("____________________________________________________\n");
    }
}

// Verifica se existe regata com número...
int existeRegataComNumero(int numero)
{
    for (int ii = 0; ii < 3; ii++)
    {
        if (regatas[ii].numero == numero)
        {
            return 1;
        }
    }

    return 0;
}

// Cadastrar regatas
void cadastrarRegatas()
{
    printf("\n============| Cadastrar Regatas |============\n");
    for (int ii = 0; ii < 3; ii++)
    {
        int numero;

        do
        {
            printf("Número da regata: ");
            scanf("%d", &numero);
            setbuf(stdin, NULL);

            if (existeRegataComNumero(numero))
            {
                printf("-- Já existe uma regata com este número!\n");
            }
        } while (existeRegataComNumero(numero));

        regatas[ii].numero = numero;

        int dia, mes, ano;

        printf("Dia da regata: ");
        scanf("%d", &dia);
        setbuf(stdin, NULL);

        printf("Mês da regata: ");
        scanf("%d", &mes);
        setbuf(stdin, NULL);

        printf("Ano da regata: ");
        scanf("%d", &ano);
        setbuf(stdin, NULL);

        char data[11];
        sprintf(data, "%02d/%02d/%04d", dia, mes, ano);
        strcpy(regatas[ii].data, data);

        printf("Hora início: ");
        scanf("%d", &regatas[ii].horaInicio);
        setbuf(stdin, NULL);

        printf("____________________________________________________\n");
    }
}

// Verifica se regata já foi cadastrada em evento
int regataJaCadastradaEmEvento(int numeroRegata)
{
    for (int ii = 0; ii < 3; ii++)
    {
        if (participantes[ii][0].numeroRegata == numeroRegata)
        {
            return 1;
        }
    }

    return 0;
}

// Verifica se barco já existe na regata
int barcoJaExisteNaRegata(int numeroBarco, int numeroRegata)
{
    for (int ii = 0; ii < 3; ii++)
    {
        for (int jj = 0; jj < 4; jj++)
        {
            if (participantes[ii][jj].numeroBarco == numeroBarco && participantes[ii][jj].numeroRegata == numeroRegata)
            {
                return 1;
            }
        }
    }

    return 0;
}

// Definir vencedor da regata
void definirVencedorRegata(int numeroRegata, int numeroBarco)
{
    for (int ii = 0; ii < 3; ii++)
    {
        if (regatas[ii].numero == numeroRegata)
        {
            regatas[ii].codBarcoVencedor = numeroBarco;
        }
    }
}

// Cadastra evento
void cadastraEvento()
{
    printf("\n============| Cadastrar Evento |============\n");
    for (int ii = 0; ii < 3; ii++)
    {
        int numeroRegata;

        do
        {
            // Ler número da regata
            printf("Número da regata: ");
            scanf("%d", &numeroRegata);
            setbuf(stdin, NULL);

            if (!existeRegataComNumero(numeroRegata))
            {
                printf("-- Não existe regata com este número!\n\n");
            }
            else if (regataJaCadastradaEmEvento(numeroRegata))
            {
                printf("-- Regata já cadastrada em evento!\n\n");
            }
        } while (!existeRegataComNumero(numeroRegata) || regataJaCadastradaEmEvento(numeroRegata));

        int codBarcoMenorTempo, menorTempo = 25;
        for (int jj = 0; jj < 4; jj++)
        {
            participantes[ii][jj].numeroRegata = numeroRegata;

            int numeroBarco;

            do
            {
                // Ler número do barco
                printf("Número do %d° barco: ", (jj + 1));
                scanf("%d", &numeroBarco);
                setbuf(stdin, NULL);

                if (!existeBarcoComNumero(numeroBarco))
                {
                    printf("-- Não existe barco com este número!\n\n");
                }
                else if (barcoJaExisteNaRegata(numeroBarco, numeroRegata))
                {
                    printf("-- Barco já existe na regata!\n\n");
                }
            } while (!existeBarcoComNumero(numeroBarco) || barcoJaExisteNaRegata(numeroBarco, numeroRegata));

            participantes[ii][jj].numeroBarco = numeroBarco;

            // Ler hora de chegada do barco
            printf("Hora de chegada do barco: ");
            scanf("%d", &participantes[ii][jj].horaChegada);
            setbuf(stdin, NULL);

            if (participantes[ii][jj].horaChegada < menorTempo)
            {
                menorTempo = participantes[ii][jj].horaChegada;
                codBarcoMenorTempo = numeroBarco;
            }
        }

        definirVencedorRegata(numeroRegata, codBarcoMenorTempo);

        printf("____________________________________________________\n");
    }
}

// Mostra nome do barco
void nomeBarco(int numeroBarco)
{
    for (int ii = 0; ii < 6; ii++)
    {
        if (barcos[ii].numero == numeroBarco)
        {
            printf("%s", barcos[ii].nome);
            return;
        }
    }
}

// Mostra ano de fabricação do barco
int anoFabricacaoBarco(int numeroBarco)
{
    for (int ii = 0; ii < 6; ii++)
    {
        if (barcos[ii].numero == numeroBarco)
        {
            return barcos[ii].anoFabricacao;
        }
    }
}

// Mostrar relação regatas
void mostrarRelacaoRegatas()
{
    printf("\n============| Relação Regatas |============\n");
    for (int ii = 0; ii < 3; ii++)
    {
        printf("Regata número: %d\n", regatas[ii].numero);
        printf("Nome do barco vencedor: ");
        nomeBarco(regatas[ii].codBarcoVencedor);

        printf("\n____________________________________________________\n");
    }
}

// Tempo do barco
int tempoBarco(int numeroBarco, int numeroRegata)
{
    int inicio, chegada;
    for (int ii = 0; ii < 3; ii++)
    {
        if (regatas[ii].numero == numeroRegata)
        {
            inicio = regatas[ii].horaInicio;
        }

        for (int jj = 0; jj < 4; jj++)
        {
            if (participantes[ii][jj].numeroBarco == numeroBarco && participantes[ii][jj].numeroRegata == numeroRegata)
            {
                chegada = participantes[ii][jj].horaChegada;
            }
        }
    }

    if (chegada - inicio < 0)
    {
        return chegada + (24 - inicio);
    }
    else
    {
        return chegada - inicio;
    }
}

// Mostrar relação barcos de regata
void mostrarRelacaoBarcosDeRegata(int numeroRegata)
{
    if (!existeRegataComNumero(numeroRegata))
    {
        printf("-- Não existe regata com este número!\n\n");
        return;
    }

    printf("\n============| Relação Barcos Da Regata Número %d |============\n", numeroRegata);
    for (int ii = 0; ii < 3; ii++)
    {
        if (participantes[ii][0].numeroRegata == numeroRegata)
        {
            for (int jj = 0; jj < 4; jj++)
            {
                printf("Número do barco: %d\n", participantes[ii][jj].numeroBarco);
                printf("Nome do barco: ");
                nomeBarco(participantes[ii][jj].numeroBarco);
                printf("\n");
                printf("Ano de fabricação do barco: %d\n", anoFabricacaoBarco(participantes[ii][jj].numeroBarco));
                printf("Tempo: %dh\n", tempoBarco(participantes[ii][jj].numeroBarco, numeroRegata));
                printf("\n____________________________________________________\n");
            }
            return;
        }
    }
}

int main()
{
    cadastrarBarcos();
    cadastrarRegatas();

    cadastraEvento();

    mostrarRelacaoRegatas();

    int numRegata;
    printf("Gostaria de acessar a relação de barcos de qual regata? Informe o número da regata. ");
    scanf("%d", &numRegata);
    mostrarRelacaoBarcosDeRegata(numRegata);

    return 0;
}