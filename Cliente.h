#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Cliente {
private:
    // Miembros de datos privados para almacenar la información del cliente
    string nombre;
    string telefono;
    string direccion;

public:
    // Constructor que inicializa los miembros de datos con los argumentos proporcionados
    Cliente(string nombre, string telefono, string direccion) : nombre(nombre), telefono(telefono), direccion(direccion) {}

    // Métodos getter para obtener los valores de los miembros de datos
    string getNombre() { return nombre; }
    string getTelefono() { return telefono; }
    string getDireccion() { return direccion; }

    // Métodos setter para establecer los valores de los miembros de datos
    void setNombre(string nombre) { this->nombre = nombre; }
    void setTelefono(string telefono) { this->telefono = telefono; }
    void setDireccion(string direccion) { this->direccion = direccion; }
};
