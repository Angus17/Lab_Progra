/*  
    Desarrollar un programa en C, el cual imprima y sume la serie de números 3, 6,9,12,...,99.

    Autor: Diego Leonardo Alejo Cantu
    Matricula: 2013810
    Fecha: 27-02-2024
*/

#include <stdio.h>

int main(void)
{
    int i, suma_serie = 0;

    for ( i = 3; i <= 100; i += 3)
    {
        printf("%d ", i);
        suma_serie += i;
    }
    
    printf("\n\nSuma de la serie: %d\n", suma_serie);

    return 0;
}