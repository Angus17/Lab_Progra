/*  

Desarrollar un programa en C que pida al usuario un numero entero positivo, 
al cual ira sumando tres números desde 1 hasta 101(ambos están incluido 1 y 101) 
e imprima la suma. (n+1+4+7+10+…+101) 
hacer uso de while.

*/


#include <stdio.h>

int main(void)
{
    int numero, i = 1, suma = 0;

    printf("Ingresa numero entero positivo: ");
    scanf("%d", &numero);

    while (i <= 102)
    {
        suma += numero + i + ((i == 102) ? i - 1 : 0);

        i += 3;
    }

    printf("\n%d\n", suma);
    
    return 0;
}