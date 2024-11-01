/* 
Aluno: Raphael Muniz Varela
Matrícula: 32411BSI003
Capítulo 5 - Estrutura de Repetição - Exercício Proposto: 20
Faça um programa para ler o código, o sexo (M — masculino; F — feminino) e o número de horas/
aula dadas mensalmente pelos professores de uma universidade, sabendo-se que cada hora/aula vale
R$ 30,00. Emita uma listagem contendo o código, o salário bruto e o salário líquido (levando em
consideração os descontos explicados a seguir) de todos os professores. Mostre também a média dos
salários líquidos dos professores do sexo masculino e a média dos salários líquidos dos professores do
sexo feminino. Considere:
- desconto para homens, 10%, e, para mulheres, 5%;
- as informações terminarão quando for lido o código = 99999. */
programa
{
	
	funcao inicio()
	{
		// Declaração de variáveis
		inteiro cod = 0, num_h = 0, sal_b = 0, sal_l = 0, media_m = 0, media_f = 0, cont_m = 0, cont_f = 0
		caracter sexo

		// Ler código
		escreva("Informe o código: ")
		leia(cod)

		// Enquanto o código for diferente de '99999' a repetição continuará
		enquanto (cod != 99999) {
			// Enquanto o Sexo for diferente de 'M' e 'F' a repetição continuará
			faca {
				// Ler Sexo
				escreva("Informe o sexo (M — masculino; F — feminino): ")
				leia(sexo)

				// Mostra erro caso o Sexo seja diferente de 'M' e 'F'
				se(sexo != 'M' e sexo != 'F'){
		          	escreva("Sexo inválido!\n")
		          }
			} enquanto(sexo != 'M' e sexo != 'F')

			// Ler número de horas/aulas
			escreva("Informe o número de horas/aulas: ")
			leia(num_h)

			// Calcula salário bruto
			sal_b = num_h * 30

			// Se Sexo é 'M'
			se (sexo == 'M'){
				// Calcula salário líquido
				sal_l = sal_b - (sal_b * 0.1)
				// Soma o salário líquido a média 'M'
				media_m = media_m + sal_l
				// Contador 'M' ++
				cont_m = cont_m + 1
			} senao se (sexo == 'F'){ // Se Sexo é 'F'
				// Calcula salário líquido
				sal_l = sal_b - (sal_b * 0.05)
				// Soma o salário líquido a média 'F'
				media_f = media_f + sal_l
				// Contador 'F' ++
				cont_f = cont_f + 1
			}

			// Mostra código
			escreva("Código: " + cod)
			// Mostra Salário Bruto
			escreva("\nSalário Bruto: " + sal_b)
			// Mostra salário líquido
			escreva("\nSalário Líquido: " + sal_l)

			// Ler código
			escreva("\nInforme o código: ")
			leia(cod)
		}

		// Se foi informado algum 'M'
		se (cont_m == 0){
			escreva("\nNenhum professor do sexo masculino")
		} senao {
			// Calcula média 'M'
			media_m = media_m / cont_m
			escreva("\nMédia masculino: " + media_m)
		}

		// Se foi informado algum 'F'
		se (cont_f == 0){
			escreva("\nNenhum professor do sexo feminino")
		} senao {
			// Calcula média 'F'
			media_f = media_f / cont_f
			escreva("\nMédia feminino: " + media_f)
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 754; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */