#ifndef INVENTARIO_H
#define INVENTARIO_H

#define MAX_PRODUCTOS 2  //Definir la cantidad de productos a ingresar 
// CAMBIAR ESTE VALOR A 10, SOLO ES PARA PROBAR 

void ingresarDatos(
    char nombres[10][20], 
    float precios[10], 
    int cantidades[10], 
    char sucursal[20]
);

float calcularTotalSucursal(float precios[10], int cantidades[10]);
void encontrarExtremos(char nombres[10][20], float precios[10]);
float calcularPromedio(float precios[10]);
void buscarProducto(char nombres[10][20], float precios[10], int cantidades[10], char sucursal[20]);
int totalUnidades(int cantidades[10]);

#endif