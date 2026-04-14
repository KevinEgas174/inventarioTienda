/*
    Ingeniería de Software - Programación 1
    Proyecto: Gestión de Inventario (Taller 4)
    Integrantes: Kevin Egas, César Yunga, Christian Fiallos, Jardi Caseres
*/

#include <stdio.h>
#include "inventario.h"

int main() {
    // Definimos los arreglos paralelos
    char nombres[MAX_SUCURSALES][MAX_PRODUCTOS][50];
    int cantidades[MAX_SUCURSALES][MAX_PRODUCTOS];
    float precios[MAX_SUCURSALES][MAX_PRODUCTOS];
    int totalProd[MAX_SUCURSALES] = {0};

    // Ejecutamos las funciones paso a paso
    ingresarDatos(nombres, cantidades, precios, totalProd);
    mostrarReporte(totalProd, precios, cantidades, nombres);
    buscarProducto(nombres, precios, totalProd);

    printf("\nPresione cualquier tecla para salir...");
    return 0;
}
