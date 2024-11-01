/* 
Aluno: Raphael Muniz Varela
Matrícula: 32411BSI003
Faça um programa para criptografar uma frase dada pelo usuário (a criptografia troca as vogais da
frase por *).
Exemplo:
Frase: EU ESTOU NA ESCOLA
Saída: ** * ST** N* *SC*L* 
*/
programa
{
	inclua biblioteca Tipos
	inclua biblioteca Texto --> T

	// Verifica se é vogal
	funcao logico ehVogal(caracter char){
		se(T.caixa_alta(Tipos.caracter_para_cadeia(char)) == "A" ou T.caixa_alta(Tipos.caracter_para_cadeia(char)) == "E" ou T.caixa_alta(Tipos.caracter_para_cadeia(char)) == "I" ou T.caixa_alta(Tipos.caracter_para_cadeia(char)) == "O" ou T.caixa_alta(Tipos.caracter_para_cadeia(char)) == "U"){
			retorne verdadeiro
		}

		retorne falso
	}
	
	funcao inicio()
	{
		// Declaração de variáveis
		cadeia frase
		caracter fraseSplit[50]
		inteiro length

		// Ler frase
		escreva("Informe a frase: ")
		leia(frase)

		// Tamanho da frase
		length = T.numero_caracteres(frase)

		// Percorre frase
		para(inteiro ii = 0; ii < length; ii++){
			// Se é vogal
			se(ehVogal(T.obter_caracter(frase, ii))){
				fraseSplit[ii] = '*'
			} senao {
				fraseSplit[ii] = T.obter_caracter(frase, ii)
			}
		}

		// Mostra frase
		para(inteiro ii = 0; ii < length; ii++){
			escreva(fraseSplit[ii])
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 749; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */