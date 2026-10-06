#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int opcao, quantidade;
    float total = 0;

    do
    {
        printf("\n===== MENU FRUTAS =====\n");
        printf("1 - ABACAXI - R$ 5,00 a unidade\n");
        printf("2 - MAÇA - R$ 1,00 a unidade\n");
        printf("3 - PERA - R$ 4,00 a unidade\n");
        printf("0 - Finalizar compra\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 3)
        {
            printf("Quantidade: ");
            scanf("%d", &quantidade);

            if (opcao == 1)
            {
                total = total + quantidade * 5.00;
            }
            if (opcao == 2)
            {
                total = total + quantidade * 1.00;
            }
            if (opcao == 3)
            {
                total = total + quantidade * 4.00;
            }
        }
        else if (opcao != 0)
        {
            printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    printf("\nValor total da compra: R$ %.2f\n", total);

    return 0;
}
