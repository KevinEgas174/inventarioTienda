/*
    Universidad de las Américas (UDLA)
    Carrera: Ingeniería de Software
    Materia: Programación 1 
    Proyecto: Inventario de Tienda 
    Autores: Kevin Alexander Egas Pozo,
             Cesar Yunga,
             Christian Fiallos,
             Jardi Caseres,
*/

/*
    HISTORIAL DE CAMBIOS:
    2026-04-16    KEG    Creacion de proyecto Inventario Tiendas

*/

/*
    EJECUTAR PROYECTO:
    Ingresa los siguientes comandos en la terminal del proyecto:

    gcc main.c inventario.c -o main.exe
    ./main.exe

    NOTA: Si no tienes el main.exe 
    Escribe este comando primero:  gcc main.c inventario.c -o main.exe

*/

#include <stdio.h>
#include <string.h>
#include "inventario.h"

int main() {

    int i; //Contador del Ciclo For
    char sucursalNorte[20];  //Nombre de la sucursal del Norte
    char sucursalCentro[20];  //Nombre de la sucursal del Norte
    char sucursalSur[20];  //Nombre de la sucursal del Norte

    char nombresNorte[10][20]; // Nombres: Matriz de 10 filas y 20 columnas
    float preciosNorte[10];  // Precios: Arreglo de 10 números decimales
    int cantidadesNorte[10];  // Cantidades: Arreglo de 10 números enteros

    char nombresCentro[10][20]; // Nombres: Matriz de 10 filas y 20 columnas
    float preciosCentro[10];  // Precios: Arreglo de 10 números decimales
    int cantidadesCentro[10];  // Cantidades: Arreglo de 10 números enteros

    char nombresSur[10][20]; // Nombres: Matriz de 10 filas y 20 columnas
    float preciosSur[10];  // Precios: Arreglo de 10 números decimales
    int cantidadesSur[10];  // Cantidades: Arreglo de 10 números enteros

    
    printf("\033[1;32m-----SISTEMA DE INVENTARIO DE TIENDAS-----\033[0m\n");
    do {
        printf("\033[1;32mEscriba el nombre de la sucursal del Norte:\033[0m\n");
        fgets(sucursalNorte, 100, stdin); // Validamos el Bufer
        
        sucursalNorte[strcspn(sucursalNorte, "\n")] = '\0';

        if (strlen(sucursalNorte) > 20 || strlen(sucursalNorte) == 0) {
            printf("\033[1;31mEl nombre debe tener entre 1 y 20 caracteres!\033[0m\n");
        }
    } while (strlen(sucursalNorte) > 20 || strlen(sucursalNorte) == 0);


    do {
        printf("\033[1;32mEscriba el nombre de la sucursal del Centro:\033[0m\n");
        fgets(sucursalCentro, 100, stdin); // Validamos el Bufer
        
        sucursalCentro[strcspn(sucursalCentro, "\n")] = '\0';

        if (strlen(sucursalCentro) > 20 || strlen(sucursalCentro) == 0) {
            printf("\033[1;31mEl nombre debe tener entre 1 y 20 caracteres!\033[0m\n");
        }
    } while (strlen(sucursalCentro) > 20 || strlen(sucursalCentro) == 0);

    do {
        printf("\033[1;32mEscriba el nombre de la sucursal del Sur:\033[0m\n");
        fgets(sucursalSur, 100, stdin); // Validamos el Bufer
        
        sucursalSur[strcspn(sucursalSur, "\n")] = '\0';

        if (strlen(sucursalSur) > 20 || strlen(sucursalSur) == 0) {
            printf("\033[1;31mEl nombre debe tener entre 1 y 20 caracteres!\033[0m\n");
        }
    } while (strlen(sucursalSur) > 20 || strlen(sucursalSur) == 0);


    ingresarDatos(nombresNorte, preciosNorte, cantidadesNorte, sucursalNorte);
    ingresarDatos(nombresCentro, preciosCentro, cantidadesCentro, sucursalCentro);
    ingresarDatos(nombresSur, preciosSur, cantidadesSur, sucursalSur);

    int opcion;  // Variable para el menu que opcion queremos
    do {
        printf("\n\033[1;36m--- MENU DE GESTION DE INVENTARIO ---\033[0m\n");
        printf("1. Calcular precio total por sucursal\n");
        printf("2. Producto mas caro y mas barato\n");
        printf("3. Precio promedio por sucursal\n");
        printf("4. Buscar producto por nombre\n");
        printf("5. Total de unidades vendidas\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        while (getchar() != '\n'); // Limpiar buffer

        switch(opcion) {
            case 1:
                printf("\n\033[1;32m--- PRECIO TOTAL DEL INVENTARIO ---\033[0m\n");
                printf("%s: $%.2f\n", sucursalNorte, calcularTotalSucursal(preciosNorte, cantidadesNorte));
                printf("%s: $%.2f\n", sucursalCentro, calcularTotalSucursal(preciosCentro, cantidadesCentro));
                printf("%s: $%.2f\n", sucursalSur, calcularTotalSucursal(preciosSur, cantidadesSur));
                break;

            case 2:
                printf("\n\033[1;32m--- PRODUCTOS EXTREMOS POR SUCURSAL ---\033[0m\n");
                printf("\033[1;35mSucursal %s:\033[0m\n", sucursalNorte);
                encontrarExtremos(nombresNorte, preciosNorte);
                
                printf("\n\033[1;35mSucursal %s:\033[0m\n", sucursalCentro);
                encontrarExtremos(nombresCentro, preciosCentro);
                
                printf("\n\033[1;35mSucursal %s:\033[0m\n", sucursalSur);
                encontrarExtremos(nombresSur, preciosSur);
                break;

            case 3: // Precio Promedio 
                printf("\n\033[1;32m--- PRECIO PROMEDIO POR SUCURSAL ---\033[0m\n");
                printf("%s: $%.2f\n", sucursalNorte, calcularPromedio(preciosNorte));
                printf("%s: $%.2f\n", sucursalCentro, calcularPromedio(preciosCentro));
                printf("%s: $%.2f\n", sucursalSur, calcularPromedio(preciosSur));
                break;

            case 4: // Buscar Producto 
                printf("\n\033[1;32m--- BUSQUEDA DE PRODUCTOS ---\033[0m\n");
                int opSucursal;
                
                printf("En que sucursal desea buscar?\n");
                printf("1. %s (Norte)\n", sucursalNorte);
                printf("2. %s (Centro)\n", sucursalCentro);
                printf("3. %s (Sur)\n", sucursalSur);
                printf("Seleccione una opción: ");
                scanf("%d", &opSucursal);
                while (getchar() != '\n'); // Limpiamos el buffer

                switch(opSucursal) {
                    case 1:
                        buscarProducto(nombresNorte, preciosNorte, sucursalNorte);
                        break;
                    case 2:
                        buscarProducto(nombresCentro, preciosCentro, sucursalCentro);
                        break;
                    case 3:
                        buscarProducto(nombresSur, preciosSur, sucursalSur);
                        break;
                    default:
                        printf("\033[1;31mOpcion de sucursal no valida.\033[0m\n");
                }
                break;

            case 5: // Total Unidades 
                printf("\n\033[1;32m--- TOTAL DE UNIDADES EN STOCK ---\033[0m\n");
                printf("%s: %d unidades\n", sucursalNorte, totalUnidades(cantidadesNorte));
                printf("%s: %d unidades\n", sucursalCentro, totalUnidades(cantidadesCentro));
                printf("%s: %d unidades\n", sucursalSur, totalUnidades(cantidadesSur));
                break;

            case 6:
                printf("\033[1;33mSaliendo del sistema... Hasta luego!\033[0m\n");
                break;

            default:
                printf("\033[1;31mOpcion no valida. Intente de nuevo.\033[0m\n");
        }
    } while (opcion != 6);

    return 0;
}