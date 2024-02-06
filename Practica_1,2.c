/* 
-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
            PROGRAMA EN C QUE DADA UNA CANTIDAD
            DE EUROS Y EN DOLARES. IMPRIMA EL RESULTADO

                Autor: Diego Leonardo Alejo Cantu
                Matricula: 2013810
                Fecha: 6/02/2024
-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 */

#include <stdio.h>

int main(void)
{
    int dinero_pesos;
    float dinero_euros, dinero_dolares;

    printf("Ingresa el dinero en Pesos a convertir: $ ");
    scanf("%d", &dinero_pesos);

    dinero_dolares = dinero_pesos / 17.21;
    dinero_euros = dinero_pesos / 18.64;

    printf("\nEl dinero convertido a dolares es de: $%.2f", dinero_dolares);
    printf("\nEl dinero convertido a euros es de: $%.2f\n", dinero_euros);


}