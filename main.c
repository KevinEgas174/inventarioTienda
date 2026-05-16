/*
    Universidad de las Américas (UDLA)
    Carrera: Ingeniería de Software
    Materia: Programación 1 
    Proyecto: Examen Progreso 1 
    Autor: Kevin Alexander Egas Pozo
*/

/*
    Universidad de las Américas (UDLA)
    Carrera: Ingeniería de Software
    Materia: Programación 1
    Proyecto: Sistema de Optimización de Producción (SOP)
    Autores: Kevin Alexander Egas Pozo,
             Cesar Yunga,
             Christian Fiallos,
             Jardi Caseres.

    HISTORIAL DE CAMBIOS:
    2026-05-15  KEP  Creación del proyecto SOP, constantes y variables locales.
    2026-05-15  CRF  Implementación de paso por referencia y arreglos paralelos.
    2026-05-15  JAC  Desarrollo de lógica de búsqueda y eliminación sin structs.
    2026-05-15  COY  Corrección de interfaz y cálculo de viabilidad.

    EJECUTAR PROYECTO:
    Ingresa los siguientes comandos en la terminal de Visual Studio Code:
    
    gcc main.c -o main.exe
    ./main.exe

    -------------------------------------------------------------------
    INSTRUCCIONES PARA SUBIR A GITHUB:
    Abre una nueva terminal en la carpeta de tu proyecto y ejecuta paso a paso:
    
    1. git init
    2. git add .
    3. git commit -m "Primer commit: Desarrollo completo del sistema SOP en C"
    4. git branch -M main
    5. git remote add origin https://github.com/KevinEgas174/Sistema-de-Optimizaci-n-de-Producci-n-SOP-.git
    6. git push -u origin main
    -------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

#define MAX_PROD 5
#define MAX_LEN 50

// --- PROTOTIPOS DE FUNCIONES (Modularidad con Punteros) ---
void limpiarBuffer();
void ingresarLimites(float *tiempo_max, int *recursos_max);
void ingresarProducto(char nombres[][MAX_LEN], int *demanda, float *tiempo, int *recursos, int *num_prod);
int buscarProducto(char nombres[][MAX_LEN], int num_prod, const char *nombre_buscar);
void editarProducto(char nombres[][MAX_LEN], int *demanda, float *tiempo, int *recursos, int num_prod);
void eliminarProducto(char nombres[][MAX_LEN], int *demanda, float *tiempo, int *recursos, int *num_prod);
void calcularYVerificar(int *demanda, float *tiempo, int *recursos, int num_prod, float tiempo_max, int recursos_max);
void mostrarInventario(char nombres[][MAX_LEN], int *demanda, float *tiempo, int *recursos, int num_prod);

int main() {
    // ALTERNATIVA 2: Arreglos Paralelos Locales
    char nombres[MAX_PROD][MAX_LEN];
    int demanda[MAX_PROD];
    float tiempo_unidad[MAX_PROD];
    int recursos_unidad[MAX_PROD];
    
    int num_productos = 0; // Controla la cantidad lógica de elementos
    float tiempo_maximo = 0.0;
    int recursos_maximos = 0;
    int opcion;

    printf("\n=== BIENVENIDO AL SISTEMA DE OPTIMIZACION DE PRODUCCION (SOP) ===\n");
    ingresarLimites(&tiempo_maximo, &recursos_maximos);

    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Ingresar un producto\n");
        printf("2. Mostrar productos ingresados\n");
        printf("3. Editar un producto\n");
        printf("4. Eliminar un producto\n");
        printf("5. Calcular totales y verificar viabilidad\n");
        printf("6. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch(opcion) {
            case 1:
                ingresarProducto(nombres, demanda, tiempo_unidad, recursos_unidad, &num_productos);
                break;
            case 2:
                mostrarInventario(nombres, demanda, tiempo_unidad, recursos_unidad, num_productos);
                break;
            case 3:
                editarProducto(nombres, demanda, tiempo_unidad, recursos_unidad, num_productos);
                break;
            case 4:
                eliminarProducto(nombres, demanda, tiempo_unidad, recursos_unidad, &num_productos);
                break;
            case 5:
                calcularYVerificar(demanda, tiempo_unidad, recursos_unidad, num_productos, tiempo_maximo, recursos_maximos);
                break;
            case 6:
                printf("\nSaliendo del sistema SOP... ¡Hasta pronto!\n");
                break;
            default:
                printf("\n[!] Opcion no valida. Intente de nuevo.\n");
        }
    } while(opcion != 6);

    return 0;
}

// --- DESARROLLO DE FUNCIONES ---

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void ingresarLimites(float *tiempo_max, int *recursos_max) {
    printf("\nConfiguracion inicial de la Fabrica:\n");
    printf("Ingrese el tiempo maximo disponible en planta (horas): ");
    scanf("%f", tiempo_max);
    printf("Ingrese los recursos maximos disponibles (unidades): ");
    scanf("%d", recursos_max);
    limpiarBuffer();
    printf("[i] Limites configurados exitosamente.\n");
}

void ingresarProducto(char nombres[][MAX_LEN], int *demanda, float *tiempo, int *recursos, int *num_prod) {
    if (*num_prod >= MAX_PROD) {
        printf("\n[!] Error: Se alcanzo el limite maximo de %d productos permitidos.\n", MAX_PROD);
        return;
    }

    int idx = *num_prod; // Indice actual basado en el puntero

    printf("\n--- Ingreso de Producto %d ---\n", idx + 1);
    printf("Nombre del producto: ");
    fgets(nombres[idx], MAX_LEN, stdin);
    nombres[idx][strcspn(nombres[idx], "\n")] = 0; // Eliminar salto de linea

    printf("Cantidad demandada: ");
    scanf("%d", &demanda[idx]);

    printf("Tiempo de fabricacion por unidad (horas): ");
    scanf("%f", &tiempo[idx]);

    printf("Recursos requeridos por unidad: ");
    scanf("%d", &recursos[idx]);
    limpiarBuffer();

    (*num_prod)++; // Aumentamos la cantidad total de productos usando el puntero
    printf("[i] Producto agregado correctamente.\n");
}

// Lógica propia de búsqueda lineal solicitada en la rúbrica
int buscarProducto(char nombres[][MAX_LEN], int num_prod, const char *nombre_buscar) {
    for (int i = 0; i < num_prod; i++) {
        if (strcmp(nombres[i], nombre_buscar) == 0) {
            return i; // Retorna el índice donde lo encontró
        }
    }
    return -1; // Retorna -1 si no existe
}

void editarProducto(char nombres[][MAX_LEN], int *demanda, float *tiempo, int *recursos, int num_prod) {
    if (num_prod == 0) {
        printf("\n[!] No hay productos ingresados para editar.\n");
        return;
    }

    char nombre_buscar[MAX_LEN];
    printf("\nIngrese el nombre exacto del producto a editar: ");
    fgets(nombre_buscar, MAX_LEN, stdin);
    nombre_buscar[strcspn(nombre_buscar, "\n")] = 0;

    int indice = buscarProducto(nombres, num_prod, nombre_buscar);

    if (indice != -1) {
        printf("\n[Producto Encontrado] - Ingrese los nuevos datos para '%s':\n", nombres[indice]);
        
        printf("Nueva cantidad demandada: ");
        scanf("%d", &demanda[indice]);

        printf("Nuevo tiempo de fabricacion (horas): ");
        scanf("%f", &tiempo[indice]);

        printf("Nuevos recursos requeridos: ");
        scanf("%d", &recursos[indice]);
        limpiarBuffer();
        
        printf("[i] Producto actualizado exitosamente.\n");
    } else {
        printf("\n[!] Producto no encontrado en el sistema.\n");
    }
}

void eliminarProducto(char nombres[][MAX_LEN], int *demanda, float *tiempo, int *recursos, int *num_prod) {
    if (*num_prod == 0) {
        printf("\n[!] No hay productos ingresados para eliminar.\n");
        return;
    }

    char nombre_buscar[MAX_LEN];
    printf("\nIngrese el nombre exacto del producto a eliminar: ");
    fgets(nombre_buscar, MAX_LEN, stdin);
    nombre_buscar[strcspn(nombre_buscar, "\n")] = 0;

    int indice = buscarProducto(nombres, *num_prod, nombre_buscar);

    if (indice != -1) {
        // Desplazamiento de memoria (Shift) para eliminar lógicamente el elemento
        for (int i = indice; i < (*num_prod) - 1; i++) {
            strcpy(nombres[i], nombres[i + 1]);
            demanda[i] = demanda[i + 1];
            tiempo[i] = tiempo[i + 1];
            recursos[i] = recursos[i + 1];
        }
        (*num_prod)--; // Reducimos el tamaño lógico
        printf("\n[i] Producto eliminado exitosamente.\n");
    } else {
        printf("\n[!] Producto no encontrado en el sistema.\n");
    }
}

void calcularYVerificar(int *demanda, float *tiempo, int *recursos, int num_prod, float tiempo_max, int recursos_max) {
    if (num_prod == 0) {
        printf("\n[!] No hay productos ingresados para calcular.\n");
        return;
    }

    float tiempo_total_calculado = 0.0;
    int recursos_totales_calculados = 0;

    for (int i = 0; i < num_prod; i++) {
        tiempo_total_calculado += demanda[i] * tiempo[i];
        recursos_totales_calculados += demanda[i] * recursos[i];
    }

    printf("\n--- RESULTADOS DE PRODUCCION ---\n");
    printf("Tiempo total requerido: %.2f horas (Limite: %.2f)\n", tiempo_total_calculado, tiempo_max);
    printf("Recursos totales requeridos: %d unidades (Limite: %d)\n", recursos_totales_calculados, recursos_max);

    printf("\n>>> CONCLUSION DE VIABILIDAD: ");
    if (tiempo_total_calculado <= tiempo_max && recursos_totales_calculados <= recursos_max) {
        printf("LA FABRICA CUMPLE CON LA DEMANDA. <<<\n");
    } else {
        printf("NO SE CUMPLE CON LA DEMANDA. EXCESO DE LIMITES. <<<\n");
    }
}

void mostrarInventario(char nombres[][MAX_LEN], int *demanda, float *tiempo, int *recursos, int num_prod) {
    if (num_prod == 0) {
        printf("\n[!] El inventario esta vacio.\n");
        return;
    }

    printf("\n--- LISTA DE PRODUCTOS (%d/%d) ---\n", num_prod, MAX_PROD);
    printf("%-20s %-10s %-15s %-15s\n", "NOMBRE", "DEMANDA", "TIEMPO (h)", "RECURSOS");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < num_prod; i++) {
        printf("%-20s %-10d %-15.2f %-15d\n", nombres[i], demanda[i], tiempo[i], recursos[i]);
    }
}