#ifndef INVENTARIO_H
#define INVENTARIO_H

#define MAX_PRODUCTOS 10
#define MAX_SUCURSALES 3

// Definimos las funciones que vamos a usar
void ingresarDatos(char nombres[MAX_SUCURSALES][MAX_PRODUCTOS][50], int cantidades[MAX_SUCURSALES][MAX_PRODUCTOS], float precios[MAX_SUCURSALES][MAX_PRODUCTOS], int totalProd[MAX_SUCURSALES]);
void mostrarReporte(int totalProd[MAX_SUCURSALES], float precios[MAX_SUCURSALES][MAX_PRODUCTOS], int cantidades[MAX_SUCURSALES][MAX_PRODUCTOS], char nombres[MAX_SUCURSALES][MAX_PRODUCTOS][50]);
void buscarProducto(char nombres[MAX_SUCURSALES][MAX_PRODUCTOS][50], float precios[MAX_SUCURSALES][MAX_PRODUCTOS], int totalProd[MAX_SUCURSALES]);

#endif
