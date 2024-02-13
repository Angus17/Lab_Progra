/* 

        Desarrollar un programa en C que identifique el tipo de triangulo por sus lados, 
        si es escaleno o isósceles, ingresar sus lados desde teclado e imprimir el tipo de triangulo. 
        Considere que los datos pueden de tipo entero o flotantes. Hacer uso de if/else simple.


    Nombre: Diego Leonardo Alejo Cantu 2013810
    Fecha: 13-02-2024
 */

#include <stdio.h>

int main(void)
{
    float lado_1, lado_2, lado_3;

    printf("Ingresa el primer lado del triangulo (mayor a 0): ");
    scanf(" %f", &lado_1);

    printf("Ingresa el segundo lado del triangulo (mayor a 0): ");
    scanf(" %f", &lado_2);

    printf("Ingresa el tercer lado del triangulo (mayor a 0): ");
    scanf(" %f", &lado_3);

    if (lado_1 != lado_2 && lado_2 != lado_3 && lado_3 != lado_1)
    
        printf("\nEs un triangulo escaleno\n");
    
    else
    
        printf("\nEs un triangulo iscosceles\n");
    
    
    
    return 0;
}