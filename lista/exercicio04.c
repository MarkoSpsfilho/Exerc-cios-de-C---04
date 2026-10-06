#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int cont[3][3] = {0};
    char nomePeriodo[3][12] = {"matutino", "vespertino", "noturno"};
    char nomeElevador[3] = {'A', 'B', 'C'};
    int totalPeriodo[3] = {0, 0, 0};
    int totalElevador[3] = {0, 0, 0};
    int i, e, p;
    char elevador, periodo;
    int maiorPeriodo, menorPeriodo, maiorElevador, menorElevador, medioElevador;
    int elevadorDoPeriodo, periodoDoElevador;
    float diferenca, percMedio;

    for (i = 1; i <= 50; i++)
    {
        printf("\nMorador %d\n", i);

        printf("Elevador mais usado (A/B/C): ");
        scanf(" %c", &elevador);
        if (elevador >= 'a' && elevador <= 'c')
        {
            elevador = elevador - 32;
        }
        while (elevador < 'A' || elevador > 'C')
        {
            printf("Elevador inválido! Digite A, B ou C: ");
            scanf(" %c", &elevador);
            if (elevador >= 'a' && elevador <= 'c')
            {
                elevador = elevador - 32;
            }
        }

        printf("Período (M/V/N): ");
        scanf(" %c", &periodo);
        if (periodo == 'm' || periodo == 'v' || periodo == 'n')
        {
            periodo = periodo - 32;
        }
        while (periodo != 'M' && periodo != 'V' && periodo != 'N')
        {
            printf("Período inválido! Digite M, V ou N: ");
            scanf(" %c", &periodo);
            if (periodo == 'm' || periodo == 'v' || periodo == 'n')
            {
                periodo = periodo - 32;
            }
        }

        e = elevador - 'A';
        if (periodo == 'M')
        {
            p = 0;
        }
        if (periodo == 'V')
        {
            p = 1;
        }
        if (periodo == 'N')
        {
            p = 2;
        }

        cont[e][p]++;
        totalElevador[e]++;
        totalPeriodo[p]++;
    }

    maiorPeriodo = 0;
    menorPeriodo = 0;
    for (p = 1; p < 3; p++)
    {
        if (totalPeriodo[p] > totalPeriodo[maiorPeriodo])
        {
            maiorPeriodo = p;
        }
        if (totalPeriodo[p] < totalPeriodo[menorPeriodo])
        {
            menorPeriodo = p;
        }
    }

    elevadorDoPeriodo = 0;
    for (e = 1; e < 3; e++)
    {
        if (cont[e][maiorPeriodo] > cont[elevadorDoPeriodo][maiorPeriodo])
        {
            elevadorDoPeriodo = e;
        }
    }

    maiorElevador = 0;
    for (e = 1; e < 3; e++)
    {
        if (totalElevador[e] > totalElevador[maiorElevador])
        {
            maiorElevador = e;
        }
    }

    periodoDoElevador = 0;
    for (p = 1; p < 3; p++)
    {
        if (cont[maiorElevador][p] > cont[maiorElevador][periodoDoElevador])
        {
            periodoDoElevador = p;
        }
    }

    diferenca = (totalPeriodo[maiorPeriodo] - totalPeriodo[menorPeriodo]) * 100.0 / 50;

    if (maiorElevador == 0)
    {
        menorElevador = 1;
    }
    else
    {
        menorElevador = 0;
    }
    for (e = 0; e < 3; e++)
    {
        if (e != maiorElevador && totalElevador[e] < totalElevador[menorElevador])
        {
            menorElevador = e;
        }
    }
    medioElevador = 3 - maiorElevador - menorElevador;
    percMedio = totalElevador[medioElevador] * 100.0 / 50;

    printf("\nPeríodo mais usado: %s (elevador %c)\n", nomePeriodo[maiorPeriodo], nomeElevador[elevadorDoPeriodo]);
    printf("Elevador mais frequentado: %c (maior fluxo no período %s)\n", nomeElevador[maiorElevador], nomePeriodo[periodoDoElevador]);
    printf("Diferença percentual entre o horário mais usado e o menos usado: %.2f%%\n", diferenca);
    printf("Percentagem do elevador de média utilização (%c): %.2f%%\n", nomeElevador[medioElevador], percMedio);

    return 0;
}
