/* 
    Desarrollar un programa en C que simule un cajero automático, el menú principal está conformado por

    1) Deposito
    2) Retiro 
    3) Consulta de Saldo
    4) Salir

    el saldo inicial es de $1,000, si el usuario desea realizar un depósito elegirá la opción 1 
    y el programa mostrara el saldo y pedirá que ingrese la cantidad después mostrará el saldo 
    actualizado y regresara al menú principal, si desea realizar un retiro elegirá la opción 2
    el programa mostrara el saldo actual y si el retiro es mayor que el saldo del cliente el programa
    notificara al usuario que el saldo es insuficiente, pero si la transacción procede deberá mostrar 
    el saldo y regresar al menú principal, si desea consultar su saldo el usuario elegirá la opción 3 
    y el programa deberá mostrar su saldo y regresar al menú principal y si el usuario desea salir del 
    menú principal elegirá la opción 4, 

    Autor: Diego Leonardo Alejo Cantu
    Matricula: 2013810
    Fecha: 20-02-2024
*/

#include <stdio.h>

int main(void)
{   
    int opcion, saldo = 1000, monto;

    MENU:
    printf("Ingresa una opcion del menu: \n");
    printf("1) Deposito \n");
    printf("2) Retiro \n");
    printf("3) Consulta de saldo \n");
    printf("4) Salir \n: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
        case 1:
            printf("Tu saldo actual es de %d\n Ingrese el monto a depositar: ", saldo);
            scanf("%d", &monto);

            saldo += monto;
            printf("Operacion exitosa! Nuevo Saldo: %d\n", saldo);
            goto MENU;

            break;
        case 2:
            printf("Tu saldo actual es de %d\n Ingrese el monto a retirar: ", saldo);
            scanf("%d", &monto);

            if (monto > saldo)
            
                printf("No puedes retirar mas de lo que tienes\n");
            
            else
            {
                saldo -= monto;
                printf("Operacion exitosa! Nuevo Saldo: %d\n", saldo);
            }

            goto MENU;
            break;
        case 3:
            printf("Tu saldo actual es de %d\n", saldo);

            goto MENU;
            break;
        case 4:
            break;
        
        default:
            printf("No existe la opcion\n");
            goto MENU;
            break;
    }

    return 0;
}