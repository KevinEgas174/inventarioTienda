# 🛒 Sistema de Gestión de Inventario - Tiendas UDLA

[cite_start]Este proyecto es una solución computacional desarrollada en **C** para la gestión eficiente de inventarios en tres sucursales (Norte, Centro y Sur)[cite: 26]. [cite_start]El sistema permite controlar productos, precios y cantidades bajo un enfoque de programación modular[cite: 40, 41].

## 👥 Integrantes - Grupo de Trabajo
* **Kevin Alexander Egas Pozo**
* **Cesar Yunga**
* **Christian Fiallos**
* **Jardi Caseres**

## 📋 Descripción del Problema
Una tienda requiere gestionar su inventario distribuido en 3 sedes. [cite_start]El programa procesa datos de hasta 10 productos por sucursal, realizando cálculos estadísticos y búsquedas en tiempo real[cite: 25, 26, 39].

## 🚀 Funcionalidades Principales
* [cite_start]**Ingreso Validado:** Captura de nombres, precios y cantidades con protección contra datos erróneos[cite: 26, 40].
* [cite_start]**Análisis de Inventario:** Cálculo del precio total y promedio por sucursal[cite: 27, 29].
* [cite_start]**Detección de Extremos:** Identificación automática del producto más caro y más barato[cite: 28].
* [cite_start]**Buscador:** Localización de productos por nombre para consultar precios[cite: 30].
* [cite_start]**Control de Stock:** Reporte de unidades totales vendidas por sede[cite: 31].

## 🛠️ Detalles Técnicos
Para cumplir con las restricciones académicas de la consigna, el programa:
* [cite_start]**No utiliza estructuras ni punteros**[cite: 42].
* [cite_start]Utiliza **arreglos paralelos** multidimensionales para relacionar los datos[cite: 38].
* [cite_start]Está organizado de forma **modular** en archivos separados (`main.c`, `inventario.c`, `inventario.h`)[cite: 41, 45].

## 💻 Instrucciones de Compilación
Para ejecutar el programa localmente, asegúrese de tener un compilador de C (como GCC) instalado y ejecute:

```bash
gcc main.c inventario.c -o sistema_inventario
./sistema_inventario
