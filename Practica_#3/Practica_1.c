/* 

        Desarrollar un programa en C que pida al usuario ingresar un número de tipo entero, 
        el programa deberá determinar si el numero ingresado es positivo o negativo 
        (el programa debe indicar al usuario que no puede ingresar el cero). Hacer uso de 
        if/else simple.

    Nombre: Diego Leonardo Alejo Cantu 2013810
    Fecha: 13-02-2024
 */

#include <stdio.h>

int main(void)
{
    int numero;

    printf("Escribe un numero entero diferente de cero: ");
    scanf("%d", &numero);

    if (numero > 0)
    
        printf("\nEl numero es positivo\n");
    
    if (numero < 0)
    
        printf("\nEl numero es negativo\n");
    
    return 0;
}