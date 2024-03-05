/*  

Desarrollar un programa en C que use un bucle do - while para calcular la potencia de un número 
al que denominaremos base sobre otro número al que denominaremos exponente, 
ambos elegidos por el usuario.

Ejemplo: el usuario elige base el 5 y como exponente el 3. 
El programa debe mostrar el resultado de multiplicar la base por sí misma 3 veces, 
en este ejemplo 5*5*5 =125.


Autor: Diego Leonardo Alejo Cantu
Matricula: 2013810
Fecha: 05-03-2024
*/

#include <stdio.h>

int main(void)
{
    int numero, potencia, resultado = 1;

    
    printf("Ingresa un numero entero: ");
    scanf("%d", &numero);
    
    do
    {
        printf("A que potencia desea elevar el numero %d?: ", numero);
        scanf("%d", &potencia);
    } while (potencia < 0);

    do
    {
        if (potencia == 0)
        
            resultado = 1;
        
        else
        {
            resultado *= numero;
            potencia--;
        }
    } while (potencia != 0);
    
    printf("Resultado: %d\n", resultado);

    return 0;
}