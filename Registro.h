#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Cliente.h"
#include "Mascota.h"

using namespace std;

class Registro {
private:
    Cliente cliente;
    Mascota mascota;

public:
    Registro(Cliente cliente, Mascota mascota) : cliente(cliente), mascota(mascota) {}
    Cliente getCliente() const { return cliente; }
    Mascota getMascota() const { return mascota; }
};