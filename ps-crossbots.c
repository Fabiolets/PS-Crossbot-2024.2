#include <stdio.h>

int main()
{
    int ordem = 0, i, j, matriz[10][10];
    int somaRef = 0, somaLinha = 0, somaColuna = 0, somaDiag1 = 0, somaDiag2 = 0;

    while (ordem < 2 || ordem > 10)
    {
        printf("Digite a ordem da matriz (entre 2 e 10): ");
        scanf("%d", &ordem);

        if (ordem < 2 || ordem > 10)
        {
            printf("Op��o inv�lida\n\n");
        }
    }

    printf("\nDigite os valores da matriz:\n");

    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < ordem; i++)
    {
        somaRef += matriz[0][i]; //Calcula a soma da primeira linha e salva na vari�vel "somaRef" para usar como refer�ncia
    }

    for (int i = 0; i < ordem; i++)
    {
        somaLinha = 0;

        for (int j = 0; j < ordem; j++)
        {
            somaLinha += matriz[i][j];
        }

        if (somaLinha != somaRef) //Verifica se a soma de todas as linhas � igual � "somaRef"
        {
            printf("\nA matriz n�o � um quadrado m�gico."); //Se a verifica��o falhar, retorna que n�o � um quadrado m�gico
            printf("\nResultado da soma = -1\n");
            return 0;
        }
    }

    for (int i = 0; i < ordem; i++)
    {
        somaColuna = 0;

        for (int j = 0; j < ordem; j++)
        {
            somaColuna += matriz[j][i];
        }
        if (somaColuna != somaRef) //Verifica se a soma de todas as colunas � igual � "somaRef"
        {
            printf("\nA matriz n�o � um quadrado m�gico."); //Se a verifica��o falhar, retorna que n�o � um quadrado m�gico
            printf("\nResultado da soma = -1\n");
            return 0;
        }
    }

    for (int i = 0; i < ordem; i++)
    {
        somaDiag1 += matriz[i][i];
    }

    for (int i = 0; i < ordem; i++)
    {
        somaDiag2 += matriz[i][ordem - i - 1];
    }

    if (somaDiag1 != somaRef || somaDiag2 != somaRef) //Verifica se a soma das diagonais � igual � "somaRef"
    {
        printf("\nA matriz n�o � um quadrado m�gico."); //Se a verifica��o falhar, retorna que n�o � um quadrado m�gico
        printf("\nResultado da soma = -1\n");
        return 0;
    }

    printf("\nMatriz:\n"); //Se passou por todas as verifica��es, � um quadrado m�gico e a matriz � mostrada

    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("A matriz � um quadrado m�gico e a soma m�gica �: %d!\n", somaRef);

    return 0;
}
