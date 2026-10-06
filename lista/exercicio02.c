#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    char sexo, olhos, cabelos;
    int idade, total = 0, contador = 0;
    float salario, porcentagem;

    while (1)
    {
        printf("\nIdade (-1 para encerrar): ");
        scanf("%d", &idade);
        while (idade != -1 && (idade < 10 || idade > 100))
        {
            printf("Idade inválida! Digite entre 10 e 100: ");
            scanf("%d", &idade);
        }

        if (idade == -1)
        {
            break;
        }

        printf("Sexo (m/f): ");
        scanf(" %c", &sexo);
        while (sexo != 'm' && sexo != 'f')
        {
            printf("Sexo inválido! Digite m ou f: ");
            scanf(" %c", &sexo);
        }

        printf("Cor dos olhos (a/v/c/p): ");
        scanf(" %c", &olhos);
        while (olhos != 'a' && olhos != 'v' && olhos != 'c' && olhos != 'p')
        {
            printf("Cor inválida! Digite a, v, c ou p: ");
            scanf(" %c", &olhos);
        }

        printf("Cor dos cabelos (l/c/p/r): ");
        scanf(" %c", &cabelos);
        while (cabelos != 'l' && cabelos != 'c' && cabelos != 'p' && cabelos != 'r')
        {
            printf("Cor inválida! Digite l, c, p ou r: ");
            scanf(" %c", &cabelos);
        }

        printf("Salário: ");
        scanf("%f", &salario);
        while (salario < 0)
        {
            printf("Salário inválido! Digite um valor não negativo: ");
            scanf("%f", &salario);
        }

        total++;

        if (sexo == 'f' && idade >= 18 && idade <= 35 && olhos == 'c' && cabelos == 'c')
        {
            contador++;
        }
    }

    if (total > 0)
    {
        porcentagem = contador * 100.0 / total;
    }
    else
    {
        porcentagem = 0;
    }

    printf("\nHabitantes pesquisados: %d\n", total);
    printf("Porcentagem de mulheres entre 18 e 35 anos, olhos e cabelos castanhos: %.2f%%\n", porcentagem);

    return 0;
}
