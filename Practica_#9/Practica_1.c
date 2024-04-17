/*  
    Dada una cadena de máximo 50 caracteres, 
    desarrollar un programa en C que identifique todas 
    las vocales que se encuentran en el texto, sean 
    minúsculas o mayúsculas y las imprima en el orden 
    que van apareciendo.

    Autor: Diego Leonardo Alejo Cantu
    Matricula: 2013810
    Fecha: 09/04/2024
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = 0;
    char cadena[50];

    printf("Ingresa una cadena: ");
    fgets(cadena, sizeof(cadena), stdin);

    cadena[strcspn(cadena, "\n")] = '\0';

    while (cadena[i] != '\0')
    {
        if (cadena[i] == 'a' ||
            cadena[i] == 'A' || 
            cadena[i] == 'e' ||
            cadena[i] == 'E' || 
            cadena[i] == 'i' || 
            cadena[i] == 'I' || 
            cadena[i] == 'o' || 
            cadena[i] == 'O' ||  
            cadena[i] == 'u' || 
            cadena[i] == 'U')
        
            printf("%c ", cadena[i]);
        
        i++;
    }

    printf("\n");
}