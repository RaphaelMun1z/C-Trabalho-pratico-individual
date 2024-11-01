/* 
Aluno: Raphael Muniz Varela
Matrícula: 32411BSI003
Um elemento Aij de uma matriz é dito ponto de sela da matriz A se, e somente se, Aij for, ao mesmo
tempo, o menor elemento da linha i e o maior elemento da coluna j. Faça um programa que carregue
uma matriz de ordem 5  7, verifique se a matriz possui ponto de sela e, se possuir, mostre seu valor
e sua localização. */
programa
{
	inclua biblioteca Util --> U
	
	funcao inicio()
	{
		// Declaração de variáveis
		inteiro matriz[5][7]
		inteiro menor_l = 0, maior_c = 0, linha = 0, coluna = 0, tempLinha = 0

		// Define dados
		para(inteiro ii = 0; ii < 5; ii++){
			para(inteiro jj = 0; jj < 7; jj++){
				matriz[ii][jj] = U.sorteia(10, 99)
			}
		}

		// Mostra dados
		escreva("   1° 2° 3° 4° 5° 6° 7°\n")
		para(inteiro ii = 0; ii < 5; ii++){
			escreva((ii+1) + "° ")
			para(inteiro jj = 0; jj < 7; jj++){
				escreva(matriz[ii][jj] + " ")
			}
			escreva("\n")
		}

		// Verifica as 5 linhas
		para(inteiro ii = 0; ii < 5; ii++){
			escreva("----------------------------------------------\n")

			// Inicializa o menor elemento da linha
			menor_l = matriz[ii][0]
			linha = ii
			coluna = 0
			
			// Verifica as 7 colunas
			para(inteiro jj = 0; jj < 7; jj++){
				// Se o elemento que está sendo verificado é menor que o menor da linha...
				se(matriz[ii][jj] < menor_l){
					// Menor elemento da linha recebe o elemento verificado
					menor_l = matriz[ii][jj]
					linha = ii
					coluna = jj
				}
			}
			escreva("Menor elemento da " + (ii+1) + "° linha é " + matriz[linha][coluna] + ", fica na " + (coluna+1) + "° coluna\n")

			// Inicializa o maior elemento da coluna
			maior_c = matriz[0][coluna]
			tempLinha = 0

			// Verifica as 5 linhas
			para(inteiro ll = 0; ll < 5; ll++){
				// Se o elemento que está sendo verificado é maior que o maior da coluna...
				se(matriz[ll][coluna] > maior_c){
					// Maior elemento da coluna recebe o elemento verificado
					maior_c = matriz[ll][coluna]
					tempLinha = ll
				}
			}
			escreva("Maior elemento da " + (coluna+1) + "° coluna é " + maior_c + ", fica na " + (tempLinha+1) + "° linha\n")

			// Se, Aij for, ao mesmo tempo, o menor elemento da linha i e o maior elemento da coluna j
			se(matriz[linha][coluna] == matriz[tempLinha][coluna]){
				escreva("Ponto de sela em: [" + linha + "][" + coluna + "] = " + matriz[linha][coluna] + "\n")
			}
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 540; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */