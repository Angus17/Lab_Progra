/*  
    Crear una estructura llamada alumno que almacene la siguiente información sobre sus calificaciones de tres exámenes parciales:

        Matricula del alumno.

        Nombre del alumno.

        Calif_1, Calif_2, Calif_3

        Promedio.



    Utilizando la estructura calcular el promedio por alumno, dado n alumnos y generar un reporte que muestre todos los datos que se ingresaron y el promedio de los alumnos.

    AUTOR: Diego Leonardo Alejo Cantu
    MATRICULA: 2013810
    FECHA: 16-04-2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#ifdef __linux__
    #include <stdio_ext.h>
#endif 

void convertir_cadena_a_minuscula(char *);
bool validar_cadenas(const char *);

void validar_errores_por_SO();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();

struct Alumnos
{
    int matricula;
    char nombre[50];
    int calificacion_1, calificacion_2, calificacion_3;
};

int main(void)
{
    struct Alumnos *datos = (struct Alumnos *) malloc(sizeof(struct Alumnos) * 1); 
    char respuesta_salida[3];
    bool cadena_valida = false;
    int contador = 0, i, capacidad_nueva = 0;

    setlocale(LC_CTYPE, "es_MX.UTF-8");

    do
    {
        printf("Existen alumnos? Si/No\n : ");
        limpiar_buffer_STDIN();
        scanf(" %s", respuesta_salida);

        convertir_cadena_a_minuscula(respuesta_salida);

        if (strcmp(respuesta_salida, "si") != 0 && strcmp(respuesta_salida, "no") != 0)
        
            validar_errores_por_SO();
        

    } while (strcmp(respuesta_salida, "si") != 0 && strcmp(respuesta_salida, "no") != 0);

    
    while (strcmp(respuesta_salida, "si") == 0)
    {
        do
        {
            do
            {
                limpiar_terminal();

                printf("Ingresa la matrícula del alumno %d: ", contador + 1);
                limpiar_buffer_STDIN();
            } while (scanf("%d", &datos[contador].matricula) != 1);

            if (datos[contador].matricula <= 0)
            
                validar_errores_por_SO();

        } while (datos[contador].matricula <= 0);
        
        do
        {
            
            limpiar_terminal();

            printf("Escribe el nombre del alumno: ");
            limpiar_buffer_STDIN();
            fgets(datos[contador].nombre, 50, stdin);

            datos[contador].nombre[strcspn(datos[contador].nombre, "\n")] = '\0';

            if (strlen(datos[contador].nombre) != 0)
            
                cadena_valida = validar_cadenas(datos[contador].nombre);
            
            
        } while (strlen(datos[contador].nombre) == 0 || !cadena_valida);

        do
        {
            do
            {
                limpiar_terminal();

                printf("Ingresa la calificación 1: ");
                limpiar_buffer_STDIN();
            } while (scanf("%d", &datos[contador].calificacion_1) != 1);
            
            if (datos[contador].calificacion_1 < 0 || datos[contador].calificacion_1 > 100)
            
                validar_errores_por_SO();
            
        } while (datos[contador].calificacion_1 < 0 || datos[contador].calificacion_1 > 100);

        do
        {
            do
            {
                limpiar_terminal();

                printf("Ingresa la calificación 2: ");
                limpiar_buffer_STDIN();
            } while (scanf("%d", &datos[contador].calificacion_2) != 1);
            
            if (datos[contador].calificacion_2 < 0 || datos[contador].calificacion_2 > 100)
            
                validar_errores_por_SO();
            
        } while (datos[contador].calificacion_2 < 0 || datos[contador].calificacion_2 > 100);

        do
        {
            do
            {
                limpiar_terminal();

                printf("Ingresa la calificacion 3: ");
                limpiar_buffer_STDIN();
            } while (scanf("%d", &datos[contador].calificacion_3) != 1);
            
            if (datos[contador].calificacion_3 < 0 || datos[contador].calificacion_3 > 100)
            
                validar_errores_por_SO();
            
        } while (datos[contador].calificacion_3 < 0 || datos[contador].calificacion_3 > 100);
        
        contador++;

        do
        {
            limpiar_terminal();
            
            printf("Existen mas alumnos? Si/No\n: ");
            limpiar_buffer_STDIN();
            scanf(" %s", respuesta_salida);

            convertir_cadena_a_minuscula(respuesta_salida);

            if (strcmp(respuesta_salida, "si") != 0 && strcmp(respuesta_salida, "no") != 0)
            
                validar_errores_por_SO();
            

        } while (strcmp(respuesta_salida, "si") != 0 && strcmp(respuesta_salida, "no") != 0);

        if (strcmp(respuesta_salida, "no") != 0)
        {
            capacidad_nueva++;
            struct Alumnos *auxiliar = (struct Alumnos *) realloc(datos, (capacidad_nueva + 1) * sizeof(struct Alumnos));

            if (auxiliar == NULL)
            {
                fprintf(stderr, "ERROR DE MEMORIA. . .");
                return EXIT_FAILURE;
            }
            
            datos = auxiliar;
        }
        
    }

    limpiar_terminal();

    printf("REPORTE DE ALUMNOS: \n\n");

    for ( i = 0; i < contador; i++)
    {
        printf("Nombre: %s\n", datos[i].nombre);
        printf("Matrícula: %d\n", datos[i].matricula);
        printf("Calificación 1: %d\n", datos[i].calificacion_1);
        printf("Calificación 2: %d\n", datos[i].calificacion_2);
        printf("Calificación 3: %d\n\n", datos[i].calificacion_3);
        printf("Promedio : %d\n\n\n", ((datos[i].calificacion_1 + datos[i].calificacion_2 + datos[i].calificacion_3) / 3));
    }
    
    free(datos);

    return EXIT_SUCCESS;
}

bool validar_cadenas(const char *caracter)
{
    while (*caracter != '\0')
    {
        if (!isalpha(*caracter) && *caracter != 32)
        
            return false;
        
        caracter++;
    }
    
    return true;
}

void convertir_cadena_a_minuscula(char *caracter)
{
    while (*caracter != '\0')
    {
        *caracter = tolower(*caracter);
        caracter++;
    }
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

// Clasifica los mensajes de error tanto para Windows como para UNIX/Linux, cuando se ingresan datos incorrectos
void validar_errores_por_SO()
{
    #if defined(_WIN32) || defined(_WIN64)
        limpiar_terminal();

        printf("Dato/s ingresado/s no válido/s, verificar dato/s\n");
        pausar_terminal();
        limpiar_terminal();
    #elif __linux__
        limpiar_terminal();

        printf("Dato/s ingresado/s no válido/s, verificar dato/s\n");
        fflush(stdout);
        pausar_terminal();
        limpiar_terminal();
    #endif
}