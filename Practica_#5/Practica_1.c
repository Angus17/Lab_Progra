/*  
    Desarrollar un programa en C que calcule la suma de todos los números que sean múltiplos de 2 y 
    múltiplos de 7 hasta el 1,000 e imprima el resultado.

    Autor: Diego Leonardo Alejo Cantu
    Matricula: 2013810
    Fecha: 27-02-2024
*/

#include <stdio.h>

int main(void)
{
    int i, suma = 0;

    for ( i = 1; i <= 1000; i++)
    {
        if (i % 2 == 0 && i % 7 == 0)
        
            suma += i;
            
    }
    
    printf("%d\n", suma);

    return 0;
}