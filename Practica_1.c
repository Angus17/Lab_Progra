/* 
-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
            Desarrollar un programa en C que calcule el área de dos círculos, 
            con la siguiente información: Diametro = 25 cm y Diametro = 35 cm 

                Autor: Diego Leonardo Alejo Cantu
                Matricula: 2013810
                Fecha: 6/02/2024
-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 */

#include <stdio.h>
#define PI 3.1416

int main(void)
{
    int diametro_1 = 25, diametro_2 = 35;
    float area_1, area_2;

    area_1 = PI * (diametro_1 / 2) * (diametro_1 / 2);
    area_2 = (diametro_2 / 2) * (diametro_2 / 2);

    printf("\nEl area del circulo de diametro 25 : %.2f cm", area_1);
    printf("\nEl area del circulo de diametro 35 : %.2f cm\n", area_2);
}