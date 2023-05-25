#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


//////// REGISTRO ////////

class Registro {
private:
    Cliente cliente;
    Mascota mascota;

public:
    Registro(Cliente cliente, Mascota mascota) : cliente(cliente), mascota(mascota) {}
    Cliente getCliente() const { return cliente; }
    Mascota getMascota() const { return mascota; }
};



////////// 
