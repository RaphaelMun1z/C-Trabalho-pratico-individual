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
programa
{
	// Declaração de variáveis
	inteiro voo[12], lugares[12]
	cadeia origem[12], destino[12]

	// Define dados
	funcao defineDados(){
		// Acessa as 12 posições do vetor
		para(inteiro ii = 0; ii < 12; ii++){
			escreva("\n========================| " + (ii+1) + "° |========================\n")
			// Ler código do voo
			escreva("Código: ")
			leia(voo[ii])

			// Ler origem do voo
			escreva("Origem: ")
			leia(origem[ii])

			// Ler destino do voo
			escreva("Destino: ")
			leia(destino[ii])

			// Ler quantidade de assentos do voo
			escreva("Número de lugares disponíveis: ")
			leia(lugares[ii])
		}
	}

	// Mostra menu principal
	funcao mostraMenuPrincipal(){
		escreva("\n========================| Menu |========================\n")
		escreva("[1] Consultar\n")
		escreva("[2] Efetuar reserva\n")
		escreva("[3] Sair\n")
		escreva("----------------------------------------------------------\n")
	}

	// Mostra menu consultar
	funcao mostraMenuConsultar(){
		escreva("\n===================| Menu Consultar |===================\n")
		escreva("[1] Consulta por voo\n")
		escreva("[2] Consulta por origem\n")
		escreva("[3] Consulta por destino\n")
		escreva("----------------------------------------------------------\n")
	}

	// Mostra dados de um voo
	funcao dadosVoo(inteiro indice){
		escreva("-- Número do voo: " + voo[indice])
		escreva("\n-- Local de origem: " + origem[indice])
		escreva("\n-- Local de destino: " + destino[indice])
		escreva("\n-- Lugares disponíveis: " + lugares[indice] + "\n")
	}

	// Consulta por voo
	funcao consultaPorVoo(inteiro num_voo){
		para(inteiro ii = 0; ii < 12; ii++){
			se(num_voo == voo[ii]){
				dadosVoo(ii)
				retorne
			}
		}

		escreva("-- Voo inexistente!\n")
	}

	// Consulta por origem
	funcao consultaPorOrigem(cadeia origem_voo){
		para(inteiro ii = 0; ii < 12; ii++){
			se(origem_voo == origem[ii]){
				dadosVoo(ii)
				retorne
			}
		}

		escreva("-- Origem não encontrada!\n")
	}

	// Consulta por destino
	funcao consultaPorDestino(cadeia destino_voo){
		para(inteiro ii = 0; ii < 12; ii++){
			se(destino_voo == destino[ii]){
				dadosVoo(ii)
				retorne
			}
		}

		escreva("-- Destino não encontrado!\n")
	}

	// Retorna índice do voo
	funcao inteiro indiceVoo(inteiro num_voo){	
		para(inteiro ii = 0; ii < 12; ii++){
			se(num_voo == voo[ii]){
				retorne ii
			}
		}

		retorne -1
	}

	// Verifica se há vaga
	funcao logico haVaga(inteiro indice){
		se(lugares[indice] > 0){
			retorne verdadeiro
		}senao{
			retorne falso
		}
	}
	
	funcao inicio()
	{
		// Declaração de variáveis
		inteiro op, num_voo
		cadeia local

		// Define dados
		defineDados()

		// Enquanto a opção for diferente de '3' a repetição continuará
		faca {
			// Mostra menu principal
			mostraMenuPrincipal()
			// Ler opção
			escreva("Digite sua opção: ")
			leia(op)
			escreva("\n")

			// Verifica opção informada
			escolha (op){
				// Consultar
				caso 1:
					mostraMenuConsultar()
					escreva("Digite sua opção: ")
					leia(op)
					escreva("\n")
	
					escolha (op){
						// Por número do voo
						caso 1:
							escreva("Digite o número de voo: ")
							leia(num_voo)
	
							consultaPorVoo(num_voo)
						pare

						// Por origem
						caso 2:
							escreva("Digite a origem: ")
							leia(local)

							consultaPorOrigem(local)
						pare

						// Por destino
						caso 3:
							escreva("Digite o destino: ")
							leia(local)

							consultaPorDestino(local)
						pare
					}

					op = -1
				pare

				// Efetuar reserva
				caso 2:
					// Ler número do voo
					escreva("Digite o número do voo desejado: ")
					leia(num_voo)

					// Verifica se voo existe
					se(indiceVoo(num_voo) != -1){
						// Verifica se há vaga
						se(haVaga(indiceVoo(num_voo))){
							lugares[indiceVoo(num_voo)] = lugares[indiceVoo(num_voo)] - 1
							escreva("-- Reserva confirmada!\n")
						}senao{
							escreva("-- Voo lotado!\n")
						}
					}senao{
						escreva("-- Voo inexistente!\n")
					}
				pare

				// Sair
				caso 3:
					escreva("Saindo...\n")
				pare

				caso contrario:
					escreva("Opção inválida!\n")
			}
		} enquanto (op != 3)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 339; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */