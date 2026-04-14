#include <stdio.h>
#include <string.h>
#include "inventario.h"

void ingresarDatos(char nombres[MAX_SUCURSALES][MAX_PRODUCTOS][50], int cantidades[MAX_SUCURSALES][MAX_PRODUCTOS], float precios[MAX_SUCURSALES][MAX_PRODUCTOS], int totalProd[MAX_SUCURSALES]) {
    char sedes[3][10] = {"Norte", "Centro", "Sur"};
    
    for (int s = 0; s < MAX_SUCURSALES; s++) {
        printf("\n--- SUCURSAL: %s ---\n", sedes[s]);
        
        // Validación: No permitir más de 10 productos
        do {
            printf("¿Cuantos productos desea registrar? (1-10): ");
            scanf("%d", &totalProd[s]);
            if (totalProd[s] < 1 || totalProd[s] > MAX_PRODUCTOS)
                printf("Error: Ingrese un numero entre 1 y %d.\n", MAX_PRODUCTOS);
        } while (totalProd[s] < 1 || totalProd[s] > MAX_PRODUCTOS);

        for (int i = 0; i < totalProd[s]; i++) {
            printf("Nombre del producto %d: ", i + 1);
            scanf("%s", nombres[s][i]);

            // Validación: Precio mayor a 0
            do {
                printf("  Precio: ");
                scanf("%f", &precios[s][i]);
                if (precios[s][i] <= 0) printf("  Error: El precio debe ser positivo.\n");
            } while (precios[s][i] <= 0);

            // Validación: Cantidad no negativa
            do {
                printf("  Cantidad: ");
                scanf("%d", &cantidades[s][i]);
                if (cantidades[s][i] < 0) printf("  Error: La cantidad no puede ser negativa.\n");
            } while (cantidades[s][i] < 0);
        }
    }
}

void mostrarReporte(int totalProd[MAX_SUCURSALES], float precios[MAX_SUCURSALES][MAX_PRODUCTOS], int cantidades[MAX_SUCURSALES][MAX_PRODUCTOS], char nombres[MAX_SUCURSALES][MAX_PRODUCTOS][50]) {
    printf("\n\n=== REPORTE FINAL DE INVENTARIO ===\n");
    for (int s = 0; s < MAX_SUCURSALES; s++) {
        float totalSucursal = 0;
        printf("\nSucursal %d:\n", s + 1);
        for (int i = 0; i < totalProd[s]; i++) {
            float subtotal = precios[s][i] * cantidades[s][i];
            printf(" - %s: %d unidades x $%.2f = $%.2f\n", nombres[s][i], cantidades[s][i], precios[s][i], subtotal);
            totalSucursal += subtotal;
        }
        printf("VALOR TOTAL EN SUCURSAL: $%.2f\n", totalSucursal);
    }
}

void buscarProducto(char nombres[MAX_SUCURSALES][MAX_PRODUCTOS][50], float precios[MAX_SUCURSALES][MAX_PRODUCTOS], int totalProd[MAX_SUCURSALES]) {
    char busqueda[50];
    int encontrado = 0;
    printf("\nIngrese el nombre del producto que busca: ");
    scanf("%s", busqueda);

    for (int s = 0; s < MAX_SUCURSALES; s++) {
        for (int i = 0; i < totalProd[s]; i++) {
            if (strcmp(nombres[s][i], busqueda) == 0) {
                printf("¡Encontrado! Sucursal %d, Precio: $%.2f\n", s + 1, precios[s][i]);
                encontrado = 1;
            }
        }
    }
    if (!encontrado) printf("El producto no existe en ninguna sucursal.\n");
}
