#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    char nome[50];
    char sexo;
    float altura, peso;
    int i, homens = 0, mulheres = 0;
    float somaAlturaH = 0, somaAlturaM = 0, somaPesoH = 0, somaPesoM = 0;
    float mediaAlturaH = 0, mediaAlturaM = 0, mediaPesoH = 0, mediaPesoM = 0;
    float mediaAlturaGrupo, mediaPesoGrupo;

    for (i = 1; i <= 10; i++)
    {
        printf("\nPessoa %d\n", i);

        printf("Nome: ");
        scanf(" %[^\n]", nome);

        printf("Sexo (M/F): ");
        scanf(" %c", &sexo);
        while (sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f')
        {
            printf("Sexo inválido! Digite M ou F: ");
            scanf(" %c", &sexo);
        }

        printf("Altura (em metros): ");
        scanf("%f", &altura);

        printf("Peso (em kg): ");
        scanf("%f", &peso);

        if (sexo == 'M' || sexo == 'm')
        {
            homens++;
            somaAlturaH = somaAlturaH + altura;
            somaPesoH = somaPesoH + peso;
        }
        else
        {
            mulheres++;
            somaAlturaM = somaAlturaM + altura;
            somaPesoM = somaPesoM + peso;
        }
    }

    if (homens > 0)
    {
        mediaAlturaH = somaAlturaH / homens;
        mediaPesoH = somaPesoH / homens;
    }
    if (mulheres > 0)
    {
        mediaAlturaM = somaAlturaM / mulheres;
        mediaPesoM = somaPesoM / mulheres;
    }

    mediaAlturaGrupo = (somaAlturaH + somaAlturaM) / 10;
    mediaPesoGrupo = (somaPesoH + somaPesoM) / 10;

    printf("\nNúmero de homens: %d\n", homens);
    printf("Número de mulheres: %d\n", mulheres);
    printf("Altura média dos homens: %.2f m\n", mediaAlturaH);
    printf("Altura média das mulheres: %.2f m\n", mediaAlturaM);
    printf("Altura média do grupo: %.2f m\n", mediaAlturaGrupo);
    printf("Peso médio dos homens: %.2f kg\n", mediaPesoH);
    printf("Peso médio das mulheres: %.2f kg\n", mediaPesoM);
    printf("Peso médio do grupo: %.2f kg\n", mediaPesoGrupo);

    return 0;
}
