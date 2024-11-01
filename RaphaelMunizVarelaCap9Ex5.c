/* 
Aluno: Raphael Muniz Varela
Matrícula: 32411BSI003
Faça um programa para criptografar uma frase dada pelo usuário (a criptografia troca as vogais da
frase por *).
Exemplo:
Frase: EU ESTOU NA ESCOLA
Saída: ** * ST** N* *SC*L* 
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Verifica se é vogal
int ehVogal(char letra)
{
    if ((toupper((char)letra) == 'A') || (toupper((char)letra) == 'E') || (toupper((char)letra) == 'I') || (toupper((char)letra) == 'O') || (toupper((char)letra) == 'U')){
        return 1;
    }

    return 0;
}

int main()
{
    // Declaração de variáveis
    char frase[50];
    int length;

    // Ler frase
    printf("Informe a frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    // Tamanho da frase
    length = strlen(frase);

    // Percorre frase
    for (int ii = 0; ii < length; ii++)
    {
        // Se é vogal
        if (ehVogal(frase[ii]) == 1)
        {
            frase[ii] = '*';
        }
    }

    // Mostra frase
    printf("Frase: %s", frase);

    return 0;
}