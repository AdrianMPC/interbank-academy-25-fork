# Proyecto INTERBANK-ACADEMY-25-FORK

## Introducción

Este proyecto tiene como propósito [resolver el problema propuesto en Codeable provisioanando una buena arquitectura de software].
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
## Instrucciones de Ejecución
1. Clona este repositorio:
   ```bash
   git clone https://github.com/usuario/repositorio.git
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
3. Necesitas un compilador de C++ que soporte C++17 (aquí hay uno de g++: https://winlibs.com/)(añade su carpeta bin a las variables de entorno para que funcione)
