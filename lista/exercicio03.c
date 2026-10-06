#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int i, idade;
    char nota;
    int otimo = 0, bom = 0, regular = 0, ruim = 0, pessimo = 0;
    int somaRuim = 0;
    int maiorOtimo = 0, maiorRuim = 0, maiorPessimo = 0;
    float percBom, percRegular, diferenca, mediaRuim, percPessimo;
    int diferencaIdade;

    for (i = 1; i <= 100; i++)
    {
        printf("\nEspectador %d\n", i);
        printf("Idade: ");
        scanf("%d", &idade);

        printf("Nota (A/B/C/D/E): ");
        scanf(" %c", &nota);
        if (nota >= 'a' && nota <= 'e')
        {
            nota = nota - 32;
        }
        while (nota < 'A' || nota > 'E')
        {
            printf("Nota inválida! Digite A, B, C, D ou E: ");
            scanf(" %c", &nota);
            if (nota >= 'a' && nota <= 'e')
            {
                nota = nota - 32;
            }
        }

        if (nota == 'A')
        {
            otimo++;
            if (idade > maiorOtimo)
            {
                maiorOtimo = idade;
            }
        }
        if (nota == 'B')
        {
            bom++;
        }
        if (nota == 'C')
        {
            regular++;
        }
        if (nota == 'D')
        {
            ruim++;
            somaRuim = somaRuim + idade;
            if (idade > maiorRuim)
            {
                maiorRuim = idade;
            }
        }
        if (nota == 'E')
        {
            pessimo++;
            if (idade > maiorPessimo)
            {
                maiorPessimo = idade;
            }
        }
    }

    percBom = bom * 100.0 / 100;
    percRegular = regular * 100.0 / 100;
    diferenca = percBom - percRegular;
    if (diferenca < 0)
    {
        diferenca = diferenca * -1;
    }

    if (ruim > 0)
    {
        mediaRuim = (float)somaRuim / ruim;
    }
    else
    {
        mediaRuim = 0;
    }

    percPessimo = pessimo * 100.0 / 100;

    diferencaIdade = maiorOtimo - maiorRuim;
    if (diferencaIdade < 0)
    {
        diferencaIdade = diferencaIdade * -1;
    }

    printf("\nQuantidade de respostas ótimo: %d\n", otimo);
    printf("Diferença percentual entre bom e regular: %.2f%%\n", diferenca);
    printf("Média de idade de quem respondeu ruim: %.2f\n", mediaRuim);
    printf("Percentagem de respostas péssimo: %.2f%%\n", percPessimo);
    printf("Maior idade que respondeu péssimo: %d\n", maiorPessimo);
    printf("Diferença entre a maior idade de ótimo e a maior idade de ruim: %d\n", diferencaIdade);

    return 0;
}
