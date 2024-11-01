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
#include <stdio.h>

int main()
{
    // Declaração de variáveis
    int cod = 0, num_h = 0, cont_m = 0, cont_f = 0;
    double sal_b = 0, sal_l = 0, media_m = 0, media_f = 0;
    char sexo;

    // Ler código
    printf("Informe o código: ");
    scanf("%d", &cod);

    // Enquanto o código for diferente de '99999' a repetição continuará
    while (cod != 99999)
    {
        // Enquanto o Sexo for diferente de 'M' e 'F' a repetição continuará
        do
        {
            // Ler Sexo
            printf("Informe o sexo (M — masculino; F — feminino): ");
            scanf("%s", &sexo);

            // Mostra erro caso o Sexo seja diferente de 'M' e 'F'
            if (sexo != 'M' && sexo != 'F')
            {
                printf("Sexo inválido!\n");
            }
        } while (sexo != 'M' && sexo != 'F');

        // Ler número de horas/aulas
        printf("Informe o número de horas/aulas: ");
        scanf("%d", &num_h);

        // Calcula salário bruto
        sal_b = num_h * 30;

        // Se Sexo é 'M'
        if (sexo == 'M')
        {
            // Calcula salário líquido
            sal_l = sal_b - (sal_b * 0.1);
            // Soma o salário líquido a média 'M'
            media_m = media_m + sal_l;
            // Contador 'M' ++
            cont_m = cont_m + 1;
        }
        else if (sexo == 'F') // Se Sexo é 'F'
        {
            // Calcula salário líquido
            sal_l = sal_b - (sal_b * 0.05);
            // Soma o salário líquido a média 'F'
            media_f = media_f + sal_l;
            // Contador 'F' ++
            cont_f = cont_f + 1;
        }

        // Mostra código
        printf("Código: %d", cod);
        // Mostra Salário Bruto
        printf("\nSalário Bruto: R$%.2f", sal_b);
        // Mostra salário líquido
        printf("\nSalário Líquido: R$%.2f\n", sal_l);

        // Ler código
        printf("\nInforme o código: ");
        scanf("%d", &cod);
    }

    // Se foi informado algum 'M'
    if (cont_m == 0)
    {
        printf("\nNenhum professor do sexo masculino");
    }
    else
    {
        // Calcula média 'M'
        media_m = media_m / cont_m;
        printf("\nMédia masculino: R$%.2f", media_m);
    }

    // Se foi informado algum 'F'
    if (cont_f == 0)
    {
        printf("\nNenhum professor do sexo feminino");
    }
    else
    {
        // Calcula média 'F'
        media_f = media_f / cont_f;
        printf("\nMédia feminino: R$%.2f", media_f);
    }

    return 0;
}