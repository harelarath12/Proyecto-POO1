#pragma once

// Incluye las bibliotecas necesarias
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Define la clase Mascota
class Mascota {
private:
    // Miembros de datos privados para almacenar la información de la mascota
    string nombre;
    int edad;
    string raza;
    string enfermedades;
    string otro;
    string tipoServicio;
    int diasHotel;
    string cuidador;
    string padecimientos;
    string medico;
    string fechaIngreso;
    string fechaSalida;

public:
    // Constructor que inicializa los miembros de datos con los argumentos proporcionados.

    Mascota(string nombre, int edad, string raza, string enfermedades, string otro, string tipoServicio) :
        nombre(nombre), edad(edad), raza(raza), enfermedades(enfermedades), otro(otro), tipoServicio(tipoServicio), fechaSalida("") {}

    // Métodos getter para obtener los valores de los miembros de datos.
    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    string getRaza() { return raza; }
    string getEnfermedades() { return enfermedades; }
    string getOtro() { return otro; }
    string getTipoServicio() { return tipoServicio; }
    int getDiasHotel() { return diasHotel; }
    string getCuidador() { return cuidador; }
    string getPadecimientos() { return padecimientos; }
    string getMedico() { return medico; }
    string getFechaIngreso() { return fechaIngreso; }
    string getFechaSalida() { return fechaSalida; }

    // Métodos setter para establecer los valores de los miembros de datos
    void setNombre(string nombre) { this->nombre = nombre; }
    void setEdad(int edad) { this->edad = edad; }
    void setRaza(string raza) { this->raza = raza; }
    void setEnfermedades(string enfermedades) { this->enfermedades = enfermedades; }
    void setOtro(string otro) { this->otro = otro; }
    void setTipoServicio(string tipoServicio) { this->tipoServicio = tipoServicio; }
    void setDiasHotel(int diasHotel) { this->diasHotel = diasHotel; }
    void setCuidador(string cuidador) { this->cuidador = cuidador; }
    void setPadecimientos(string padecimientos) { this->padecimientos = padecimientos; }
    void setMedico(string medico) { this->medico = medico; }
    void setFechaIngreso(string fechaIngreso) { this->fechaIngreso = fechaIngreso; }
    void setFechaSalida(string fechaSalida) { this->fechaSalida = fechaSalida; }
};