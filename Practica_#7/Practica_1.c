/*  

Desarrollar un programa en C, el cual Calcule el promedio de n valores almacenados en un vector. 
Determinar además cuantos son mayores que el promedio, imprimir el promedio y una 
lista de valores mayores que el promedio, así como el vector original.


Autor: Diego Leonardo Alejo Cantu
Matricula: 2013810
Fecha: 12-03-2024
*/

#include <stdio.h>

int main(void)
{
    int dimension, i, suma_elementos = 0, promedio;

    do
    {
        printf("Cuantos elementos quieres ingresar?: ");
        scanf("%d", &dimension);
    } while (dimension <= 0);

    int vector[dimension];
    
    for ( i = 0; i < dimension; i++)
    {
        printf("Ingresa elemento [%d]: ", i + 1);
        scanf("%d", &vector[i]);
    }

    printf("\n");
    
    for ( i = 0; i < dimension; i++)
    
        suma_elementos += vector[i];
    
    promedio = suma_elementos / dimension;
    
    printf("Vector ingresado: \n");
    for ( i = 0; i < dimension; i++)
    
        printf("[%d] ", vector[i]);
    
    printf("\nElementos que son mayores al promedio: \n");
    for ( i = 0; i < dimension; i++)
    {
        if (vector[i] > promedio)

            printf("[%d] ", vector[i]);
        
    }

    printf("\nPromedio: %d\n", promedio);
    
    return 0;
}