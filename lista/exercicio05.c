#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int n, i;
    long long a = 0, b = 1, c;

    printf("Digite um número inteiro maior ou igual a zero: ");
    scanf("%d", &n);
    while (n < 0)
    {
        printf("Número inválido! Digite um valor maior ou igual a zero: ");
        scanf("%d", &n);
    }

    for (i = 0; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    printf("O termo de ordem %d da sequência de Fibonacci é: %lld\n", n, a);

    return 0;
}
