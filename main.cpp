#include "./c_dbmanager.h"

#include <iostream>
#include <limits>

void mostrarMenu() {
    std::cout << "\n----- MENU -----\n";
    std::cout << "1. Buscar por ID\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opcion: ";
}


int main(){
    std::string input;
    std::cout << "Ingrese la direccion donde se encuentra el CSV: ";
    std::getline(std::cin, input);

    DBManager o_dbmanager(input,',');
    o_dbmanager.loadData();
    o_dbmanager.genReporte();

    std::cout << "Presiona cualquier tecla para ir al menu de API... ";
    getchar();

    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                unsigned long id;
                std::cout << "Ingrese el ID a buscar: ";
                std::cin >> id;
            
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "ID invalido.\n";
                    break;
                }
                o_dbmanager.searchID(id);
                break;
            case 0:
                std::cout << "Adios.\n";
                break;
            default:
                std::cout << "Ingrese algo correcto...\n";
        }
    } while (opcion != 0);
    return 0;
}