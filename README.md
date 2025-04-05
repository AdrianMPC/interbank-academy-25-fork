# Proyecto INTERBANK-ACADEMY-25-FORK
## EN CASO EL PROGRAMA NO LEE EL CSV, CODIFICARLO EN UTF-8

## Introducción

Este proyecto tiene como propósito resolver el problema propuesto en Codeable provisioanando una buena arquitectura de software.
Se pidió leer un CSV y devolver un reporte final detallando detalles de esta manera:
```bash
Reporte de Transacciones
---------------------------------------------
Balance Final: 325.00
Transacción de Mayor Monto: ID 3 - 200.00
Conteo de Transacciones: Crédito: 3 Débito: 2
```
Adicionalmente, se implementó una estructura de hashing cuckoohashing con el fin de lograr hacer consultas de manera constante (con una complejidad algoritmica O(1)), esto permite hacer consultas de manera rápida mediante la id de transaccion.
La lógica para resolver el problema principal se encuentra en el archivo 
```bash
c_logicareporte.cpp
```
El propósito fue evaluar si tenemos las capacidades para implementar sistemas simples y resolver problemas referente a bancas de manera eficaz.
## Instrucciones de Ejecución
1. Clona este repositorio:
   ```bash
   git clone https://github.com/AdrianMPC/interbank-academy-25-fork.git
    ```
2. Instala CMAKE:
3. Abrelo en Visual Studio Code (o configura el compilador de manera manual si desean hacerlo mediante consola)
4. Si tienes la extensión de cmake en VSCODE, puedes ejecutar el BUILD y RUN de manera integrada. Caso contrario ejecuta los siguientes comandos:
 ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build .
   .\interbank_app
 ```
5. Ya en el programa, ingresa la dirección donde se encuentra el archivo
### Instalación de Dependencias
1. Necesitas CMAKE (https://cmake.org/download/)
2. VSCODE recomendado (https://code.visualstudio.com/)
3. Necesitas un compilador de C++ que soporte C++17 ( aquí hay uno de g++: https://winlibs.com/ ) (añade su carpeta bin a las variables de entorno para que funcione)

## Enfoque y Solución

El programa se realizó con una estructura modular. Se priorizó cumplir el principio de resposabilidad única, donde cada uno de las clases solo realizan una responsabilidad (ej: la clase CSVreader solo realiza lo relacionado a CSVs).
Para resolver el problema se realizó la siguiente lógica:
```bash
-   Si nuestra transaccion es de tipo credito, no debería afectar nuestro balance, pero como nuestro balance_final es 0 al inicio, sumamos el monto para el reporte
-   Si nuestra transaccion es tipo debito, afecta a nuestro balance, debido a eso restamos el balance final
-   Tenemos 2 variables de conteo, uno para credito y otro para debido. Se aumenta un contador depiendo la condicionales definidas en el programa
-   Para mantener track del monto mayor, comparamos con el monto_mayor anterior, si este monto mayor es mayor al antiguo: actualizamos la variable global if (nuevo_monto > m_monto_mayor) 
-   Grabamos la id para facilidad nuestra a la hora de imprimir el reporte (tambien solo podriamos grabar la id y compara haciendo una consulta pero resulta a nuestro hash table)
```
De esta manera, logramos generar el reporte de manera sencilla.

Tambien se implementó una hash table derivada del algoritmo CuckooHashing. Esto nos permite hacer consultas por id con complejidad algoritmica constante O(1). Esto programa esta practicamente listo para ser conectado con un gestor de API y empezar a servir como una API sencilla de consultas de este CSV.

## Estructura del proyecto

La estructura general del proyecto es el siguiente: 
```bash
Proyecto/
├── .gitignore
├── CMakeLists.txt
├── README.md
├── data.csv
├── main.cpp
├── s_data.h
├── c_csvreader.cpp
├── c_csvreader.h
├── c_cuckoohashing.cpp
├── c_cuckoohashing.h
├── c_dbmanager.cpp
├── c_dbmanager.h
├── c_logicareporte.cpp
├── c_logicareporte.h
```
Donde:
- CSVreader tiene la logica del lector de CSV
- CuckooHashing tiene la logica de la tabla hash basada en cuckoohashing
- DBManager conecta tanto CSVreader,CuckooHashing y LogicaReporte y define las funciones del proceso principal, de esta manera. Main no tiene acceso a esta funciones criticas del programa directamente.
- LogicaReporte es donde se evalua la lógica principal del problema y se implementa la solución principal. Tambien se define como se imprimen los reportes.
