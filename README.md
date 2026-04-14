# 🛒 Sistema de Gestión de Inventario - Tiendas UDLA

Este proyecto es una solución computacional desarrollada en **C** para la gestión eficiente de inventarios en tres sucursales (Norte, Centro y Sur). El sistema permite controlar productos, precios y cantidades bajo un enfoque de programación modular.

## 👥 Integrantes - Grupo de Trabajo
* **Kevin Alexander Egas Pozo**
* **Cesar Yunga**
* **Christian Fiallos**
* **Jardi Caseres**

## 📋 Descripción del Problema
Una tienda requiere gestionar su inventario distribuido en 3 sedes. El programa procesa datos de hasta 10 productos por sucursal, realizando cálculos estadísticos y búsquedas en tiempo real.

## 🚀 Funcionalidades Principales
* **Ingreso Validado:** Captura de nombres, precios y cantidades con protección contra datos erróneos.
* **Análisis de Inventario:** Cálculo del precio total y promedio por sucursal.
* **Detección de Extremos:** Identificación automática del producto más caro y más barato.
* **Buscador:** Localización de productos por nombre para consultar precios.
* **Control de Stock:** Reporte de unidades totales vendidas por sede.

## 🛠️ Detalles Técnicos
Para cumplir con las restricciones académicas de la consigna, el programa:
* **No utiliza estructuras ni punteros**.
* Utiliza **arreglos paralelos** multidimensionales para relacionar los datos.
* Está organizado de forma **modular** en archivos separados (`main.c`, `inventario.c`, `inventario.h`).

## 💻 Instrucciones de Compilación
Para ejecutar el programa localmente, asegúrese de tener un compilador de C (como GCC) instalado y ejecute:

```bash
gcc main.c inventario.c -o sistema_inventario
./sistema_inventario
