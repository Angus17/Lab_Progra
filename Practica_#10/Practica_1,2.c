/*  

    Desarrollar un programa en C el cual, haga uso de estructuras que permita almacenar los datos de los libros que tiene una
    biblioteca. Nos interesa registrar los siguientes datos: Título del libro, precio y fecha de compra. 
    Nos interesa saber el dinero que hemos invertido en libros en los últimos seis meses.

*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#ifdef __linux__
    #include <stdio_ext.h>
#endif 

struct Datos_Libros
{
    char titulo[50];
    int precio, dia, mes, anio;
};

void convertir_cadena_a_minuscula(char *);
bool validar_cadenas(const char *);

void validar_errores_por_SO();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();

int main(void)
{
    time_t tiempo = time(NULL);
    struct tm *time_actual = localtime(&tiempo);

    struct Datos_Libros datos[100];
    int contador = 0, dinero_total = 0, dia, mes, anio;
    bool cadena_valida = false, repetir_fecha = false;
    char respuesta[3];

    setlocale(LC_CTYPE, "es_MX.UTF-8");

    dia = time_actual->tm_mday;
    mes = time_actual->tm_mon + 1;
    anio = time_actual->tm_year + 1900;

    do
    {
        printf("Existen libros? Si/No\n : ");
        limpiar_buffer_STDIN();
        scanf(" %s", respuesta);

        convertir_cadena_a_minuscula(respuesta);

        if (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0)
        
            validar_errores_por_SO();
        

    } while (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0);

    while (strcmp(respuesta , "si") == 0)
    {
        do
        {
            limpiar_terminal();

            printf("Escribe el titulo del libro: ");
            limpiar_buffer_STDIN();
            fgets(datos[contador].titulo, 50, stdin);

            datos[contador].titulo[strcspn(datos[contador].titulo, "\n")] = '\0';

            if (strlen(datos[contador].titulo) != 0)
            
                cadena_valida = validar_cadenas(datos[contador].titulo);
            
            
        } while (strlen(datos[contador].titulo) == 0 || !cadena_valida);

        do
        {
            do
            {
                limpiar_terminal();
                
                printf("Ingresa el precio del libro: ");
                limpiar_buffer_STDIN();
            } while (scanf("%d", &datos[contador].precio) != 1);

            if (datos[contador].precio <= 0)
            {
                validar_errores_por_SO();
            }
            
            
        } while (datos[contador].precio <= 0);

        do
        {
            repetir_fecha = false;

            do
            {
                do
                {
                    limpiar_terminal();
                    
                    printf("Ingresa el dia que se compro: ");
                    limpiar_buffer_STDIN();
                } while (scanf("%d", &datos[contador].dia) != 1);
                
                if (datos[contador].dia < 1 || datos[contador].dia > 31)
                
                    validar_errores_por_SO();
                
            } while (datos[contador].dia < 1 || datos[contador].dia > 31);

            do
            {
                do
                {
                    limpiar_terminal();
                    
                    printf("Ingresa el mes que se compro: ");
                    limpiar_buffer_STDIN();
                } while (scanf("%d", &datos[contador].mes) != 1);
                
                if (datos[contador].mes < 1 || datos[contador].mes > 12)
                
                    validar_errores_por_SO();

            } while (datos[contador].mes < 1 || datos[contador].mes > 12);

            do
            {
                do
                {
                    limpiar_terminal();

                    printf("Ahora el año de compra: ");
                    limpiar_buffer_STDIN();
                } while (scanf("%d", &datos[contador].anio) != 1);
                
                if (datos[contador].anio > anio || datos[contador].anio <= 0)
                
                    validar_errores_por_SO();

            } while (datos[contador].anio > anio || datos[contador].anio <= 0);
            
            if ((datos[contador].mes == 2 && (datos[contador].dia > 29 || (datos[contador].dia == 29 && !(datos[contador].anio % 4 == 0 && (datos[contador].anio % 100 != 0 || datos[contador].anio % 400 == 0)))) ) ||
                ((datos[contador].mes == 4 || datos[contador].mes == 6 || datos[contador].mes == 9 || datos[contador].mes == 11) && datos[contador].dia > 30) ||
                (datos[contador].anio > anio || (datos[contador].anio == anio && (datos[contador].mes > mes || (datos[contador].mes == mes && datos[contador].dia > dia))))) 
            {
                printf("La fecha no es válida. . .");
                repetir_fecha = true;
            }
        } while (repetir_fecha);
        
        contador++;

        do
        {
            limpiar_terminal();

            printf("Existen mas libros? Si/No\n : ");
            limpiar_buffer_STDIN();
            scanf(" %s", respuesta);

            convertir_cadena_a_minuscula(respuesta);

            if (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0)
            
                validar_errores_por_SO();
            

        } while (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0);
    }

    int meses_que_pasaron;
        
    for (int i = 0; i < contador; i++)
    {
        if (anio == datos[i].anio)
        {
            meses_que_pasaron = mes - datos[i].mes;

            if (meses_que_pasaron < 0)
            
                meses_que_pasaron += 12;
            
            if (meses_que_pasaron < 6 || (meses_que_pasaron == 6 && dia >= datos[i].dia))
            
                dinero_total += datos[i].precio;
            
        }
            else if (anio - datos[i].anio == 1)
                {
                    meses_que_pasaron = 12 - datos[i].mes + mes;

                    if (meses_que_pasaron < 6 || (meses_que_pasaron == 6 && dia >= datos[i].dia))
                    {
                        dinero_total += datos[i].precio;
                    }
                }
                
        
        
    }
    
    if (dinero_total > 0)
    {
        printf("DATOS DE LIBROS EN LOS ULTIMOS 6 MESES: \n\n");

        for (int i = 0; i < contador; i++)
        {
            if (anio == datos[i].anio)
            {
                meses_que_pasaron = mes - datos[i].mes;

                if (meses_que_pasaron < 0)
                
                    meses_que_pasaron += 12;

                if (meses_que_pasaron < 6 || (meses_que_pasaron == 6 && dia >= datos[i].dia))
                {
                    printf("Titulo: %s\n", datos[i].titulo);
                    printf("Precio: %d\n", datos[i].precio);
                    
                    if (datos[i].mes < 10)
                    
                        printf("Fecha de compra: %d-0%d-%d\n\n", datos[i].dia, datos[i].mes, datos[i].anio);

                    else

                        printf("Fecha de compra: %d-%d-%d\n\n", datos[i].dia, datos[i].mes, datos[i].anio);
                    
                }
            }
            else if (anio - datos[i].anio == 1)
            {
                meses_que_pasaron = 12 - datos[i].mes + mes;

                if (meses_que_pasaron < 6 || (meses_que_pasaron == 6 && dia >= datos[i].dia))
                {
                    printf("Titulo: %s\n", datos[i].titulo);
                    printf("Precio: %d\n", datos[i].precio);
                    
                    if (datos[i].mes < 10)
                    
                        printf("Fecha de compra: %d-0%d-%d\n\n", datos[i].dia, datos[i].mes, datos[i].anio);

                    else

                        printf("Fecha de compra: %d-%d-%d\n\n", datos[i].dia, datos[i].mes, datos[i].anio);
                    
                }
            }
            
        }

        printf("Total Recaudado: %d", dinero_total);
    }
    

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