/*  
    Desarrollar un programa en C, en cual dado un número por el usuario calcule el cubo de este número
    (hacer uso de funciones para calcular el cubo del número).

    AUTOR: Diego Leonardo Alejo Cantu
    MATRICULA: 2013810
    FECHA: 23-04-2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#ifdef __linux__
    #include <stdio_ext.h>
#endif

void elevar_numero(int *);

void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();

int main(void)
{
    int numero;

    setlocale(LC_CTYPE, "es_MX.UTF-8");

    do
    {
        limpiar_terminal();

        printf("Escribe un número para elevar al cubo (x^3): ");
        limpiar_buffer_STDIN();
    } while (scanf("%d", &numero) != 1);

    elevar_numero(&numero);

    limpiar_terminal();

    printf("El número ingresado, elevado al cubo es de %d\n", numero);

    return EXIT_SUCCESS;
}

void elevar_numero(int *numero_a_elevar)
{
    int numero_nuevo = 1;

    for (int i = 0; i < 3; i++)

        numero_nuevo *= (*numero_a_elevar);


    *numero_a_elevar = numero_nuevo;
}

// Limpia buffer STDIN tanto para sistemas Windows como para UNIX/Linux
void limpiar_buffer_STDIN()
{
    #if defined(_WIN32) || defined(_WIN64)
        rewind(stdin);
    #elif __linux__
        __fpurge(stdin);
    #endif
}

// Limpia terminal tanto para sistemas Windows como para UNIX/Linux
void limpiar_terminal()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}

// Pausa la terminal tanto para sistemas Windows como para UNIX/Linux
void pausar_terminal()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("pause");
    #elif __linux__
        printf("Presiona ENTER para continuar. . .");
        fflush(stdout);
        limpiar_buffer_STDIN();
        getchar();
    #endif
}
