#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    char jogadoras[5][40] = {"Sam Kerr - Austrália", "Alex Morgan - Estados Unidos", "Dzsenifer Marozsan - Alemanha", "Amandine Henry - França", "Marta Vieira - Brasil"};
    char nomes[300][50];
    int idades[300];
    char sexos[300];
    int votos[300];
    int contagem[5] = {0, 0, 0, 0, 0};
    int total = 0, i, maior, mulheres = 0;
    char continuar;

    while (total < 300)
    {
        printf("\n===== Entrevistado %d =====\n", total + 1);

        printf("Nome: ");
        scanf(" %[^\n]", nomes[total]);

        printf("Idade: ");
        scanf("%d", &idades[total]);
        while (idades[total] <= 12)
        {
            printf("Idade inválida! Digite uma idade maior que 12: ");
            scanf("%d", &idades[total]);
        }

        printf("Sexo (M/F): ");
        scanf(" %c", &sexos[total]);
        if (sexos[total] == 'm' || sexos[total] == 'f')
        {
            sexos[total] = sexos[total] - 32;
        }
        while (sexos[total] != 'M' && sexos[total] != 'F')
        {
            printf("Sexo inválido! Digite M ou F: ");
            scanf(" %c", &sexos[total]);
            if (sexos[total] == 'm' || sexos[total] == 'f')
            {
                sexos[total] = sexos[total] - 32;
            }
        }

        printf("\n");
        for (i = 0; i < 5; i++)
        {
            printf("%d - %s\n", i + 1, jogadoras[i]);
        }
        printf("Voto (1 a 5): ");
        scanf("%d", &votos[total]);
        while (votos[total] < 1 || votos[total] > 5)
        {
            printf("Voto inválido! Digite de 1 a 5: ");
            scanf("%d", &votos[total]);
        }

        contagem[votos[total] - 1]++;
        if (sexos[total] == 'F')
        {
            mulheres++;
        }
        total++;

        if (total >= 50 && total < 300)
        {
            printf("\nDeseja continuar a pesquisa? (S/N): ");
            scanf(" %c", &continuar);
            if (continuar == 'N' || continuar == 'n')
            {
                break;
            }
        }
    }

    printf("\n===== VOTOS DE CADA JOGADORA =====\n");
    for (i = 0; i < 5; i++)
    {
        printf("%s: %d votos\n", jogadoras[i], contagem[i]);
    }

    maior = contagem[0];
    for (i = 1; i < 5; i++)
    {
        if (contagem[i] > maior)
        {
            maior = contagem[i];
        }
    }

    printf("\n===== JOGADORA MAIS VOTADA =====\n");
    for (i = 0; i < 5; i++)
    {
        if (contagem[i] == maior)
        {
            printf("%s (%d votos)\n", jogadoras[i], contagem[i]);
        }
    }

    printf("\n===== HOMENS MAIORES DE IDADE =====\n");
    for (i = 0; i < total; i++)
    {
        if (sexos[i] == 'M' && idades[i] >= 18)
        {
            printf("Nome: %s | Idade: %d | Sexo: %c\n", nomes[i], idades[i], sexos[i]);
        }
    }

    printf("\n===== HOMENS MENORES DE IDADE =====\n");
    for (i = 0; i < total; i++)
    {
        if (sexos[i] == 'M' && idades[i] < 18)
        {
            printf("Nome: %s | Idade: %d | Sexo: %c\n", nomes[i], idades[i], sexos[i]);
        }
    }

    printf("\n===== MULHERES MAIORES DE IDADE =====\n");
    for (i = 0; i < total; i++)
    {
        if (sexos[i] == 'F' && idades[i] >= 18)
        {
            printf("Nome: %s | Idade: %d | Sexo: %c\n", nomes[i], idades[i], sexos[i]);
        }
    }

    printf("\n===== MULHERES MENORES DE IDADE =====\n");
    for (i = 0; i < total; i++)
    {
        if (sexos[i] == 'F' && idades[i] < 18)
        {
            printf("Nome: %s | Idade: %d | Sexo: %c\n", nomes[i], idades[i], sexos[i]);
        }
    }

    printf("\n===== MAIORES DE IDADE QUE VOTARAM NA MARTA VIEIRA =====\n");
    for (i = 0; i < total; i++)
    {
        if (votos[i] == 5 && idades[i] >= 18)
        {
            printf("%s\n", nomes[i]);
        }
    }

    printf("\nQuantidade de mulheres que participaram da pesquisa: %d\n", mulheres);

    return 0;
}
