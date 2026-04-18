#include <stdio.h>
#include "inventario.h"

char basura; // Variable para detectar decimales en cantidades para no confundirnos

//FUNCIÓN 1: Ingresar datos de las sucursales
void ingresarDatos(char nombres[10][20], float precios[10], int cantidades[10], char sucursal[20]) {
    
    // Imprimimos el nombre de la sucursal que estamos procesando
    printf("\n\033[1;32m--- Ingresando datos para la sucursal: %s ---\033[0m\n", sucursal);
    
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        printf("\nProducto #%d:\n", i + 1);
        
        // 1. INGRESO Y VALIDACIÓN DEL NOMBRE
        printf("\033[1;34m  Nombre: \033[0m");
        // Limitamos a 19 caracteres para dejar espacio al \0 en el arreglo de 20 [cite: 21, 22]
        scanf("%19s", nombres[i]); 
        while (getchar() != '\n'); // Limpia el búfer después del nombre

        // 2. INGRESO DE PRECIO CON VALIDACIÓN DE COMA Y LETRAS
        do {
            printf("\033[1;34m  Precio: \033[0m");
            int leidos = scanf("%f%c", &precios[i], &basura);

            // Detecta si el usuario usó coma en lugar de punto
            if (leidos == 2 && basura == ',') {
                printf("\033[1;31m  Error: Use punto (.) para decimales, no coma (,).\033[0m\n");
                while (getchar() != '\n'); 
                precios[i] = -1; 
            }
            // Detecta si ingresó letras después del número o solo letras
            else if (leidos < 1 || (leidos == 2 && basura != '\n' && basura != ' ')) {
                printf("\033[1;31m  Error: Ingrese un precio valido (solo numeros y punto).\033[0m\n");
                while (getchar() != '\n');
                precios[i] = -1;
            }
            // Detecta precios negativos
            else if (precios[i] < 0) {
                printf("\033[1;31m  Error: El precio no puede ser negativo.\033[0m\n");
                if (leidos == 1) while (getchar() != '\n');
            }
            // Limpieza final si el scanf solo leyó el número (leidos == 1)
            else if (leidos == 1) {
                while (getchar() != '\n');
            }
        } while (precios[i] < 0);

        // 3. INGRESO DE CANTIDAD CON VALIDACIÓN DE ENTEROS
        do {
            printf("\033[1;34m  Cantidad: \033[0m");
            int leidosCant = scanf("%d%c", &cantidades[i], &basura);

            // Detecta si ingresó decimales o letras en la cantidad
            if (leidosCant == 2 && basura != '\n' && basura != ' ') {
                printf("\033[1;31m  Error: Ingrese solo numeros ENTEROS.\033[0m\n");
                while (getchar() != '\n');
                cantidades[i] = -1;
            }
            // Detecta si falló la lectura o el número es menor/igual a 0
            else if (leidosCant < 1 || cantidades[i] <= 0) {
                printf("\033[1;31m  Error: Ingrese una cantidad entera mayor a 0.\033[0m\n");
                if (leidosCant < 1) while (getchar() != '\n');
                cantidades[i] = -1;
            }
            else if (leidosCant == 1) {
                while (getchar() != '\n');
            }
        } while (cantidades[i] < 0);
    }
}

//FUNCIÓN 2: Calcular la suma de todo el inventario
float calcularTotalSucursal(float precios[10], int cantidades[10]) {
    float total = 0;
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        total += precios[i] * cantidades[i];
    }
    return total;
}

//FUNCIÓN 3: Calcular producto mas barato y mas caro
void encontrarExtremos(char nombres[10][20], float precios[10]) {

    float max = precios[0];
    float min = precios[0];
    int idxMax = 0;
    int idxMin = 0;

    for (int i = 1; i < MAX_PRODUCTOS; i++) {
        if (precios[i] > max) {
            max = precios[i];
            idxMax = i;
        }
        if (precios[i] < min) {
            min = precios[i];
            idxMin = i;
        }
    }
    printf("\033[1;33m  - Producto mas caro: %s ($%.2f)\033[0m\n", nombres[idxMax], max);
    printf("\033[1;33m  - Producto mas barato: %s ($%.2f)\033[0m\n", nombres[idxMin], min);
}

// FUNCIÓN 4: Calcular el precio promedio de los productos 
float calcularPromedio(float precios[10]) {
    float suma = 0;
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        suma += precios[i];
    }
    return suma / MAX_PRODUCTOS;
}

// FUNCIÓN 5: Buscar un producto por nombre y mostrar su precio 
void buscarProducto(char nombres[10][20], float precios[10], char sucursal[20]) {
    char nombreBuscar[20];
    int encontrado = 0;

    printf("\n--- Buscando en la sucursal %s ---\n", sucursal);
    printf("Ingrese el nombre del producto: ");
    scanf("%19s", nombreBuscar);
    while (getchar() != '\n'); 

    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        if (strcmp(nombres[i], nombreBuscar) == 0) {
            printf("\033[1;32mEncontrado! El precio de %s es: $%.2f\033[0m\n", nombres[i], precios[i]);
            encontrado = 1;
            break; 
        }
    }
    if (!encontrado) printf("\033[1;31mEl producto '%s' no existe en esta sucursal.\033[0m\n", nombreBuscar);
}

// FUNCIÓN 6: Total de unidades físicas en la sucursal 
int totalUnidades(int cantidades[10]) {
    int sumaUnidades = 0;
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        sumaUnidades += cantidades[i];
    }
    return sumaUnidades;
}