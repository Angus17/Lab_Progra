/* 

    Desarrollar un programa en C que pida al usuario ingresar 
    dos números enteros, si los dos números son pares mostrara
    la suma de los números, si uno es par mostrara los dos 
    números y si los dos números son impares mostrara la resta 
    de los números. 
    
    En caso de que se ingrese un cero el programa pedirá que 
    se ingrese un número diferente. 
    Hacer uso de if – else anidados.

    Autor: Diego Leonardo Alejo Cantu
    Matricula: 2013810
    Fecha: 20-02-2024
*/

#include <stdio.h>

int main(void)
{
    int numero_1, numero_2;

    printf("Ingresa el primer numero: ");
    scanf("%d", &numero_1);

    if (numero_1 == 0)
    {
        printf("No puedes manejar 0, ingresa otro numero: ");
        scanf("%d", &numero_1);
    }
    
    printf("Ingresa el segundo numero: ");
    scanf("%d", &numero_2);

    if (numero_2 == 0)
    {
        printf("No puedes manejar 0, ingresa otro numero: ");
        scanf("%d", &numero_2);
    }

    if (numero_1 % 2 == 0 && numero_2 % 2 == 0)
    
        printf("\nComo los numeros son pares, la suma de ambos numeros es de: %d\n", numero_1 + numero_2);
    
    else if (numero_1 % 2 != 0 && numero_2 % 2 != 0)
        
            printf("\nComo los numeros son impares, la resta de ambos numeros es de: %d\n", numero_1 - numero_2);
        
        else if ((numero_1 % 2 == 0 && numero_2 % 2 != 0) || (numero_1 % 2 != 0 && numero_2 % 2 == 0))
            
                printf("\nComo se detecto que uno es par y otro impar, los numeros son %d y %d\n", numero_1, numero_2);
            
    return 0;
}