/*  

Desarrollar un programa en C que pida al usuario un numero entero positivo, 
al cual ira sumando tres números desde 1 hasta 101(ambos están incluido 1 y 101) 
e imprima la suma. (n+1+4+7+10+…+101) 
hacer uso de while.

*/


#include <stdio.h>

int main(void)
{
    int numero, i = 1, suma;

    printf("Ingresa numero entero positivo: ");
    scanf("%d", &numero);

    suma = numero;

    while (i <= 103)
    {
        if (i == 103)
        
            suma += (i - 2);
        
        else
        
            suma += i;

        i += 3;
    }

    printf("\n%d\n", suma);
    
    return 0;
}