/* 
Aluno: Raphael Muniz Varela
Matrícula: 32411BSI003
Um elemento Aij de uma matriz é dito ponto de sela da matriz A se, e somente se, Aij for, ao mesmo
tempo, o menor elemento da linha i e o maior elemento da coluna j. Faça um programa que carregue
uma matriz de ordem 5  7, verifique se a matriz possui ponto de sela e, se possuir, mostre seu valor
e sua localização. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declaração de variáveis
    int matriz[5][7];
    int menor_l = 0, maior_c = 0, linha = 0, coluna = 0, tempLinha = 0;

    srand(time(NULL));

    // Define dados
    for(int ii = 0; ii < 5; ii++){
        for(int jj = 0; jj < 7; jj++){
            matriz[ii][jj] = (rand() % 89) + 10;
        }
    }

    // Mostra dados
    printf("   1° 2° 3° 4° 5° 6° 7°\n");
    for(int ii = 0; ii < 5; ii++){
        printf("%d° ", (ii+1));
        for(int jj = 0; jj < 7; jj++){
            printf("%d ", matriz[ii][jj]);
        }
        printf("\n");
    }

    // Verifica as 5 linhas
    for(int ii = 0; ii < 5; ii++){
        printf("----------------------------------------------\n");
        
        // Inicializa o menor elemento da linha
        menor_l = matriz[ii][0];
        linha = ii;
        coluna = 0;

        // Verifica as 7 colunas
        for(int jj = 0; jj < 7; jj++){
            // Se o elemento que está sendo verificado é menor que o menor da linha...
            if(matriz[ii][jj] < menor_l){
                // Menor elemento da linha recebe o elemento verificado
                menor_l = matriz[ii][jj];
                linha = ii;
                coluna = jj;
            }
        }
        printf("Menor elemento da %d° linha é %d, fica na %d° coluna\n", (ii+1), matriz[linha][coluna], (coluna+1));

        // Inicializa o maior elemento da coluna
        maior_c = matriz[0][coluna];
        tempLinha = 0;

        // Verifica as 5 linhas
        for(int ll = 0; ll < 5; ll++){
            // Se o elemento que está sendo verificado é maior que o maior da coluna...
            if(matriz[ll][coluna] > maior_c){
                // Maior elemento da coluna recebe o elemento verificado
                maior_c = matriz[ll][coluna];
                tempLinha = ll;
            }
        }
        printf("Maior elemento da %d° coluna é %d, fica na %d° linha\n", (coluna+1), maior_c, (tempLinha+1));

        // Se, Aij for, ao mesmo tempo, o menor elemento da linha i e o maior elemento da coluna j
        if(matriz[linha][coluna] == matriz[tempLinha][coluna]){
            printf("Ponto de sela em: [%d][%d] = %d\n", linha, coluna, matriz[linha][coluna]);
        }
    }

    return 0;
}