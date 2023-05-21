#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Cliente.h"
#include "Mascota.h"
#include "Registro.h"
#include "Metodos.h"

using namespace std;


int main() {
    
    vector<Registro> registros;
    int opcion;


    do {
        cout << "\nMenu de opciones:\n";
        cout << "1. Capturar\n";
        cout << "2. Mostrar\n";
        cout << "3. Eliminar\n";
        cout << "4. Buscar\n";
        cout << "5. Modificar\n";
        cout << "6. Ordenar por nombre\n";
        cout << "7. Consultar historial\n";
        cout << "8. Salir\n";
        cout << "Ingrese el numero de la opcion deseada: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            capturar(registros);
            break;
        case 2:
            mostrar(registros);
            break;
        case 3:
            eliminar(registros);
            break;
        case 4:
            buscar(registros);
            break;
        case 5:
            modificar(registros);
            break;
        case 6:
            ordenar(registros);
            break;
        case 7:
            historial(registros);
            break;
        case 8:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion invalida, intente de nuevo.\n";
            break;
        }
    } while (opcion != 8);

    return 0;
}