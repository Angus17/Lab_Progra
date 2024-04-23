/*
    Desarrollar un programa en C, en el cual dada una matriz de n x m y n es igual a m, el programa generara la matriz mostrándola y además mostrara la misma matriz, pero con sus diagonales invertidas (hacer uso de funciones para invertir las diagonales de la matriz y puede hacer uso de la función rand para llenar la matriz con valores de 1 al 100).



*/
#include <stdio.h>
#include <stdlib.h>
#if defined(__linux__)
    #include <stdio_ext.h>
#endif

void mover_diagonales(int [][5]);

int main(void)
{
    int matriz[5][5], i, j;

    for ( i = 0; i < 5; i++)
    {
        for ( j = 0; j < 5; j++)

            matriz[i][j] = i * 5 + j + 1;
    }

    for ( i = 0; i < 5; i++)
    {
        for ( j = 0; j < 5; j++)

            printf("%5d", *(*(matriz + i) + j) );

        printf("\n");
    }

    mover_diagonales(matriz);

    printf("\n\n");
    for ( i = 0; i < 5; i++)
    {
        for ( j = 0; j < 5; j++)

            printf("%5d", *(*(matriz + i) + j) );

        printf("\n");
    }
}

void mover_diagonales(int matriz[][5])
{
    int i, auxiliar;

    for ( i = 0; i < 5; i++)
    {
        auxiliar = *(*(matriz + i) + i);
        *(*(matriz + i) + i) = *(*(matriz + i) + (4 - i));
        *(*(matriz + i) + (4 - i)) = auxiliar;
    }
}