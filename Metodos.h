#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Cliente.h"
#include "Mascota.h"
#include "Registro.h"
	
using namespace std;


void capturar(vector<Registro>& registros);
void mostrar(const vector<Registro>& registros);
void eliminar(vector<Registro>& registros);
void buscar(const vector<Registro>& registros);
void modificar(vector<Registro>& registros);
void ordenar(vector<Registro>& registros);
void historial(const vector<Registro>& registros);