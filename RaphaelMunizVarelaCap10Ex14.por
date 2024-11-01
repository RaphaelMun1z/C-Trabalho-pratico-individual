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
programa
{
	inclua biblioteca Util --> U

	// Declaração de variáveis
	// Regata
	inteiro numRegata[3]
	inteiro dataRegata[3][3]
	inteiro horaInicioRegata[3]
	inteiro codBarcoVencedorRegata[3]

	// Barco
	inteiro numBarco[6]
	cadeia nomeBarco[6]
	inteiro anoFabricacaoBarco[6]

	// Participantes
	inteiro codRegataBarco[3][5]
	inteiro tempoRealizado[3][5]
	inteiro vencedor[3]

	inteiro indRegata = 0, indBarco = 0, indEvento = 0

	funcao logico existeBarcoComCodigo(inteiro codigo){
		para(inteiro ii = 0; ii < 6; ii++){
			se(numBarco[ii] == codigo){
				retorne verdadeiro
			}
		}
		
		retorne falso
	}
		
	funcao cadastrarBarcos(){
		escreva("============| Cadastrar Barcos |============\n")
		para(inteiro ii = 0; ii < 6; ii++){
			inteiro codigo

			faca{
				escreva("Número do barco: ")
				leia(codigo)
				se(existeBarcoComCodigo(codigo)){
					escreva("-- Já existe um barco com este código!\n")
				}
			}enquanto(existeBarcoComCodigo(codigo))

			numBarco[ii] = codigo
			
			escreva("Nome do barco: ")
			leia(nomeBarco[ii])
			
			escreva("Ano de Fabricação: ")
			leia(anoFabricacaoBarco[ii])
		}
		escreva("____________________________________________________\n")
	}

	funcao logico existeRegataComCodigo(inteiro codigo){
		para(inteiro ii = 0; ii < 3; ii++){
			se(numRegata[ii] == codigo){
				retorne verdadeiro
			}
		}
		
		retorne falso
	}

	funcao cadastrarRegatas(){
		escreva("\n============| Cadastrar Regatas |============\n")
		para(inteiro ii = 0; ii < 3; ii++){
			inteiro codigo

			faca{
				escreva("Número da regata: ")
				leia(codigo)
				se(existeRegataComCodigo(codigo)){
					escreva("-- Já existe uma regata com este código!\n")
				}
			}enquanto(existeRegataComCodigo(codigo))

			numRegata[ii] = codigo
			
			escreva("Dia da regata: ")
			leia(dataRegata[ii][0])

			escreva("Mês da regata: ")
			leia(dataRegata[ii][1])

			escreva("Ano da regata: ")
			leia(dataRegata[ii][2])
			
			escreva("Hora início: ")
			leia(horaInicioRegata[ii])
		}
		escreva("____________________________________________________\n")
	}

	funcao logico existeDeterminadoBarcoNaRegataComCodigo(inteiro codigoBarco, inteiro codigoRegata){
		para(inteiro ii = 0; ii < 3; ii++){
			se(codRegataBarco[ii][0] == codigoRegata){
				para(inteiro jj = 1; jj <= 4; jj++){
					se(codRegataBarco[ii][jj] == codigoBarco){
						retorne verdadeiro
					}
				}
			}
		}
		
		retorne falso
	}

	funcao logico regataJaConfigurada(inteiro codigo){
		para(inteiro ii = 0; ii < 3; ii++){
			se(codRegataBarco[ii][0] == codigo){
				retorne verdadeiro
			}
		}
		
		retorne falso
	}

	funcao gerarTempoDeEventoAleatorio(){
		para(inteiro ii = 0; ii < 3; ii++){
			tempoRealizado[ii][0] = codRegataBarco[ii][0]
			para(inteiro jj = 1; jj < 5; jj++){
				tempoRealizado[ii][jj] = U.sorteia(10, 24)	
			}
		}
	}

	funcao cadastraEvento(){
		mostrarBarcos()
		mostrarRegatas()
		
		inteiro codReg, codBar
		escreva("\n============| Cadastrar Eventos |============\n")
		para(inteiro ii = 0; ii < 3; ii++){
			escreva("-- " + (ii+1) + "° Evento: \n")
			faca{
				escreva("Código REGATA: ")
				leia(codReg)
				se(regataJaConfigurada(codReg)){
					escreva("-- Regata já configurada!\n")
				}
			}enquanto(regataJaConfigurada(codReg))
			codRegataBarco[ii][0] = codReg
				
			para(inteiro jj = 1; jj <= 4; jj++){
				faca{
					escreva("Código BARCO: ")
					leia(codBar)

					se(existeDeterminadoBarcoNaRegataComCodigo(codBar, codReg)){
						escreva("-- Este barco já está na regata!\n")
					}
				}enquanto(existeDeterminadoBarcoNaRegataComCodigo(codBar, codReg))
				codRegataBarco[ii][jj] = codBar
			}
			escreva("_______________________\n")
		}
		escreva("____________________________________________________\n")
		gerarTempoDeEventoAleatorio()
	}

	funcao inteiro tempoDeConclusaoDoBarco(inteiro codBar, inteiro codReg){
		para(inteiro ii = 0; ii < 3; ii++){
			se(tempoRealizado[ii][0] == codReg){
				para(inteiro jj = 1; jj < 5; jj++){
					se(codRegataBarco[ii][jj] == codBar){
						retorne tempoRealizado[ii][jj]
					}	
				}
			}
		}

		escreva("-- Ocorreu um erro!\n")
		retorne -1
	}

	funcao gerarVencedorRegata(inteiro codReg){
		para(inteiro ii = 0; ii < 3; ii++){
			se(codRegataBarco[ii][0] == codReg){
				inteiro menorTempo = tempoDeConclusaoDoBarco(codRegataBarco[ii][1], codRegataBarco[ii][0])
				inteiro codBarcoMenorTempo = 0
				
				para(inteiro jj = 1; jj <= 4; jj++){
					se(tempoDeConclusaoDoBarco(codRegataBarco[ii][jj], codReg) < menorTempo){
						menorTempo = tempoDeConclusaoDoBarco(codRegataBarco[ii][jj], codReg)
						codBarcoMenorTempo = codRegataBarco[ii][jj]
					}
				}

				vencedor[ii] = codBarcoMenorTempo
				escreva("-- Vencedor da regata " + codReg + " foi o barco de código " + codBarcoMenorTempo + ", com o tempo de " + menorTempo + "h!\n")
				retorne
			}
		}

		escreva("-- Código de regata inválida!\n")
	}

	funcao mostrarBarcos(){
		escreva("\n============| Barcos |============\n")
		para(inteiro ii = 0; ii < 6; ii++){
			escreva((ii+1) + "° Barco: \n")
			escreva("Número: " + numBarco[ii] + "\n")
			escreva("Nome: " + nomeBarco[ii] + "\n")
			escreva("Ano de Fabricação: " + anoFabricacaoBarco[ii] + "\n")
			escreva("____________________________________________________\n")
		}
	}

	funcao mostraBarcoPorCodigo(inteiro codBarco){
		para(inteiro ii = 0; ii < 6; ii++){
			se(numBarco[ii] == codBarco){
				escreva("Número: " + numBarco[ii] + "\n")
				escreva("Nome: " + nomeBarco[ii] + "\n")
				escreva("Ano de Fabricação: " + anoFabricacaoBarco[ii] + "\n")
				escreva("Tempo que levou para chegar ao fim da regata: " + U.sorteia(1, 24) + "h\n")
				escreva("____________________________________________________\n")
				retorne
			}
		}
	}

	funcao mostrarRegatas(){
		escreva("\n=======================| Regatas |=======================\n")
		para(inteiro ii = 0; ii < 3; ii++){
			escreva("Barco Número: " + numRegata[ii] + "\n")
			escreva("Data: " + dataRegata[ii][0] + "/" + dataRegata[ii][1] + "/" + dataRegata[ii][2] + "\n")
			escreva("Hora de Início: " + horaInicioRegata[ii] + "\n")
			se(codBarcoVencedorRegata[ii] != -1){
				escreva("Código Barco Vencedor: " + codBarcoVencedorRegata[ii] + "\n")
			}
			escreva("____________________________________________________\n")
		}
	}

	funcao mostrarBarcosDeRegata(inteiro codReg){
		escreva("\n=======================| Regata Código " + codReg + " |=======================\n")
		para(inteiro ii = 0; ii < 3; ii++){
			se(codRegataBarco[ii][0] == codReg){
				para(inteiro jj = 1; jj <= 4; jj++){
					mostraBarcoPorCodigo(codRegataBarco[ii][jj])
				}
			}
		}	
	}

	funcao relacaoRegataVencedor(){
		escreva("\n=======================| Vencedores Regatas |=======================\n")
		para(inteiro ii = 0; ii < 3; ii++){
			escreva("Regata Número: " + codRegataBarco[ii][0] + "\n")
			escreva("Barco Vencedor: " + nomeBarco[ii] + "\n")
			escreva("____________________________________________________\n")
		}
	}
	
	funcao inicio()
	{
		cadastrarBarcos()
		cadastrarRegatas()
		cadastraEvento()
		gerarVencedorRegata(1)
		gerarVencedorRegata(2)
		gerarVencedorRegata(3)
		mostrarRegatas()
		relacaoRegataVencedor()
		mostrarBarcosDeRegata(1)
		mostrarBarcosDeRegata(2)
		mostrarBarcosDeRegata(3)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1705; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */