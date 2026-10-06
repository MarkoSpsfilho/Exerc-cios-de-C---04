#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int numero, i, quantidade = 0, impressos = 0;

    printf("Digite um número positivo: ");
    scanf("%d", &numero);
    while (numero <= 0)
    {
        printf("Número inválido! Digite um número positivo: ");
        scanf("%d", &numero);
    }

    for (i = 1; i <= numero; i++)
    {
        if (numero % i == 0)
        {
            quantidade++;
        }
    }

    printf("Os divisores do número %d são: ", numero);

    for (i = 1; i <= numero; i++)
    {
        if (numero % i == 0)
        {
            impressos++;
            if (impressos == quantidade && quantidade > 1)
            {
                printf(" e %d", i);
            }
            else if (impressos == 1)
            {
                printf("%d", i);
            }
            else
            {
                printf(", %d", i);
            }
        }
    }

    printf(".\n");

    return 0;
}
