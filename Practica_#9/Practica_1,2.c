/*  

    Dada una cadena de máximo 50 caracteres, desarrollar un programa en C que calcule la
    suma de los valores de los caracteres dentro de la cadena 
    
    (los valores están determinados por el código ASCII)

    Autor: Diego Leonardo Alejo Cantu
    Matricula: 2013810
    Fecha: 09/04/2024
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int suma = 0, i = 0;
    char cadena[50];

    puts("Ingresa una cadena: ");
    fgets(cadena, sizeof(cadena), stdin);

    cadena[strcspn(cadena, "\n")] = '\0';

    printf("\n%s ", cadena);

    while (cadena[i] != '\0')
    {
        suma += cadena[i];

        i++;
    }

    printf("\nLa suma de la cadena es de: %d\n", suma);
    
    return 0;
}