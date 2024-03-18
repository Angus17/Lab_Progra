/*  
    Desarrolle un programa en C, que lea dos vectores A y B de 20 elementos cada uno y 
    multiplique el primer elemento de A con el último elemento de B y luego el segundo elemento 
    de A por el diecinueveavo elemento de B y así sucesivamente hasta llegar al veinteavo 
    elemento de A por el primer elemento de B. El resultado de la multiplicación almacenarlo 
    en un vector C. Se imprimirá los dos vectores de entrada y el vector C.

    Autor: Diego Leonardo Alejo Cantu
    Matricula: 2013810
    Fecha: 12-03-2024
*/

#include <stdio.h>

int main(void)
{
    int vector_A[20], vector_B[20], vector_C[20], i;

    printf("Valores de vector A: \n");

    for ( i = 0; i < 20; i++)
    {
        printf("Elemento [%d]: ", i + 1);
        scanf("%d", &vector_A[i]);
    }

    printf("\nValores de vector B: \n");

    for ( i = 0; i < 20; i++)
    {
        printf("Elemento [%d]: ", i + 1);
        scanf("%d", &vector_B[i]);
    }

    for ( i = 0; i < 20; i++)
    
        vector_C[i] = vector_A[i] * vector_B[19 - i];
    

    printf("\nVector A: \n");

    for ( i = 0; i < 20; i++)
    
        printf("[%d] ", vector_A[i]);
    

    printf("\nVector B: \n");

    for ( i = 0; i < 20; i++)
    
        printf("[%d] ", vector_B[i]);
    
    printf("\nVector C:\n");

    for ( i = 0; i < 20; i++)
    
        printf("[%d] ", vector_C[i]);
    
    printf("\n");
    return 0;
}