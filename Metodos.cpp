#include "Metodos.h"


void capturar(vector<Registro>& registros) {
    string nombreDueno, telefono, direccion, nombreMascota, raza, enfermedades, otro, tipoServicio;
    int edad;
    cout << "Ingrese los datos del cliente:\n";
    cout << "Nombre del dueno: ";
    cin.ignore();
    getline(cin, nombreDueno);
    cout << "Numero de telefono: ";
    getline(cin, telefono);
    cout << "Direccion: ";
    getline(cin, direccion);

    Cliente cliente(nombreDueno, telefono, direccion);

    cout << "Ingrese los datos de la mascota:\n";
    cout << "Nombre de la mascota: ";
    getline(cin, nombreMascota);
    cout << "Edad: ";
    cin >> edad;
    cin.ignore();
    cout << "Raza: ";
    getline(cin, raza);
    cout << "Enfermedades: ";
    getline(cin, enfermedades);
    cout << "Otro (caracteristicas, tipo de alimento, manias, etc.): ";
    getline(cin, otro);
    cout << "Tipo de servicio (hotel/hospital): ";
    getline(cin, tipoServicio);

    Mascota mascota(nombreMascota, edad, raza, enfermedades, otro, tipoServicio);

    if (tipoServicio == "hotel") {
        int dias;
        string cuidador;
        cout << "Cuantos dias estara en el hotel: ";
        cin >> dias;
        cin.ignore();
        cout << "Nombre del cuidador: ";
        getline(cin, cuidador);
        mascota.setDiasHotel(dias);
        mascota.setCuidador(cuidador);
    }
    else if (tipoServicio == "hospital") {
        string padecimientos, medico, fechaIngreso;
        cout << "Padecimientos: ";
        getline(cin, padecimientos);
        cout << "Medico a cargo: ";
        getline(cin, medico);
        cout << "Fecha de ingreso (formato: AAAA-MM-DD): ";
        getline(cin, fechaIngreso);
        mascota.setPadecimientos(padecimientos);
        mascota.setMedico(medico);
        mascota.setFechaIngreso(fechaIngreso);
    }
    else {
        cout << "Tipo de servicio invalido.\n";
        return;
    }

    registros.push_back(Registro(cliente, mascota));
    cout << "Registro de mascota agregado exitosamente.\n";
}

void mostrar(const vector<Registro>& registros) {
    string tipoServicio;
    cout << "Ingrese el tipo de servicio a mostrar (hotel/hospital): ";
    cin >> tipoServicio;

    for (const Registro& registro : registros) {
        Mascota mascota = registro.getMascota();
        if (mascota.getTipoServicio() == tipoServicio && mascota.getFechaSalida() == "") {
            Cliente cliente = registro.getCliente();
            cout << "\nDatos del cliente:\n";
            cout << "Nombre del dueno: " << cliente.getNombre() << endl;
            cout << "Numero de telefono: " << cliente.getTelefono() << endl;
            cout << "Direccion: " << cliente.getDireccion() << endl;

            cout << "Datos de la mascota:\n";
            cout << "Nombre de la mascota: " << mascota.getNombre() << endl;
            cout << "Edad: " << mascota.getEdad() << endl;
            cout << "Raza: " << mascota.getRaza() << endl;
            cout << "Enfermedades: " << mascota.getEnfermedades() << endl;
            cout << "Otro: " << mascota.getOtro() << endl;
            cout << "Tipo de servicio: " << mascota.getTipoServicio() << endl;
            if (tipoServicio == "hotel") {
                cout << "Dias en el hotel: " << mascota.getDiasHotel() << endl;
                cout << "Cuidador: " << mascota.getCuidador() << endl;
            }
            else {
                cout << "Padecimientos: " << mascota.getPadecimientos() << endl;
                cout << "Medico a cargo: " << mascota.getMedico() << endl;
                cout << "Fecha de ingreso: " << mascota.getFechaIngreso() << endl;
            }
        }
    }
}

void eliminar(vector<Registro>& registros) {
    string nombreMascota, fechaSalida;
    cout << "Ingrese el nombre de la mascota a eliminar: ";
    cin.ignore();
    getline(cin, nombreMascota);
    cout << "Ingrese la fecha de salida (formato: AAAA-MM-DD): ";
    getline(cin, fechaSalida);

    bool encontrado = false;
    for (Registro& registro : registros) {
        Mascota mascota = registro.getMascota();
        if (mascota.getNombre() == nombreMascota && mascota.getFechaSalida() == "") {
            mascota.setFechaSalida(fechaSalida);
            encontrado = true;
            cout << "Se ha registrado la salida de la mascota.\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro una mascota activa con ese nombre.\n";
    }
}

void buscar(const vector<Registro>& registros) {
    string nombreMascota;
    cout << "Ingrese el nombre de la mascota a buscar: ";
    cin.ignore();
    getline(cin, nombreMascota);

    bool encontrado = false;
    for (const Registro& registro : registros) {
        Mascota mascota = registro.getMascota();
        if (mascota.getNombre() == nombreMascota && mascota.getFechaSalida() == "") {
            Cliente cliente = registro.getCliente();
            cout << "\nDatos del cliente:\n";
            cout << "Nombre del dueno: " << cliente.getNombre() << endl;
            cout << "Numero de telefono: " << cliente.getTelefono() << endl;
            cout << "Direccion: " << cliente.getDireccion() << endl;

            cout << "Datos de la mascota:\n";
            cout << "Nombre de la mascota: " << mascota.getNombre() << endl;
            cout << "Edad: " << mascota.getEdad() << endl;
            cout << "Raza: " << mascota.getRaza() << endl;
            cout << "Enfermedades: " << mascota.getEnfermedades() << endl;
            cout << "Otro: " << mascota.getOtro() << endl;
            cout << "Tipo de servicio: " << mascota.getTipoServicio() << endl;
            if (mascota.getTipoServicio() == "hotel") {
                cout << "Dias en el hotel: " << mascota.getDiasHotel() << endl;
                cout << "Cuidador: " << mascota.getCuidador() << endl;
            }
            else {
                cout << "Padecimientos: " << mascota.getPadecimientos() << endl;
                cout << "Medico a cargo: " << mascota.getMedico() << endl;
                cout << "Fecha de ingreso: " << mascota.getFechaIngreso() << endl;
            }
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro una mascota activa con ese nombre.\n";
    }
}

void modificar(vector<Registro>& registros) {
    string nombreMascota;
    cout << "Ingrese el nombre de la mascota a modificar: ";
    cin.ignore();
    getline(cin, nombreMascota);

    bool encontrado = false;
    for (Registro& registro : registros) {
        Mascota mascota = registro.getMascota();
        if (mascota.getNombre() == nombreMascota && mascota.getFechaSalida() == "") {
            int opcion;
            cout << "Campos que se pueden modificar:\n";
            cout << "1. Nombre de la mascota\n";
            cout << "2. Edad\n";
            cout << "3. Raza\n";
            cout << "4. Enfermedades\n";
            cout << "5. Otro\n";
            cout << "Ingrese el numero de la opcion deseada: ";
            cin >> opcion;

            string nuevoNombre;
            int nuevaEdad;
            string nuevaRaza;
            string nuevasEnfermedades;
            string nuevoOtro;
            switch (opcion) {
            case 1:
                cout << "Nuevo nombre de la mascota: ";
                cin.ignore();
                getline(cin, nuevoNombre);
                mascota.setNombre(nuevoNombre);
                break;
            case 2:
                cout << "Nueva edad: ";
                cin >> nuevaEdad;
                mascota.setEdad(nuevaEdad);
                break;
            case 3:
                cout << "Nueva raza: ";
                cin.ignore();
                getline(cin, nuevaRaza);
                mascota.setRaza(nuevaRaza);
                break;
            case 4:
                cout << "Nuevas enfermedades: ";
                cin.ignore();
                getline(cin, nuevasEnfermedades);
                mascota.setEnfermedades(nuevasEnfermedades);
                break;
            case 5:
                cout << "Nuevo otro (caracteristicas, tipo de alimento, manias, etc.): ";
                cin.ignore();
                getline(cin, nuevoOtro);
                mascota.setOtro(nuevoOtro);
                break;
            default:
                cout << "Opcion invalida.\n";
                return;
            }

            cout << "Registro de mascota modificado exitosamente.\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro una mascota activa con ese nombre.\n";
    }
}

void ordenar(vector<Registro>& registros) {
    sort(registros.begin(), registros.end(), [](const Registro& a, const Registro& b) {
        return a.getMascota().getNombre() < b.getMascota().getNombre();
        });

    cout << "Registros ordenados alfabeticamente por nombre de mascota.\n";
}

void historial(const vector<Registro>& registros) {
    string nombreMascota;
    cout << "Ingrese el nombre de la mascota para consultar el historial: ";
    cin.ignore();
    getline(cin, nombreMascota);

    bool encontrado = false;
    for (const Registro& registro : registros) {
        Mascota mascota = registro.getMascota();
        if (mascota.getNombre() == nombreMascota) {
            Cliente cliente = registro.getCliente();
            cout << "\nDatos del cliente:\n";
            cout << "Nombre del dueno: " << cliente.getNombre() << endl;
            cout << "Numero de telefono: " << cliente.getTelefono() << endl;
            cout << "Direccion: " << cliente.getDireccion() << endl;

            cout << "Datos de la mascota:\n";
            cout << "Nombre de la mascota: " << mascota.getNombre() << endl;
            cout << "Edad: " << mascota.getEdad() << endl;
            cout << "Raza: " << mascota.getRaza() << endl;
            cout << "Enfermedades: " << mascota.getEnfermedades() << endl;
            cout << "Otro: " << mascota.getOtro() << endl;
            cout << "Tipo de servicio: " << mascota.getTipoServicio() << endl;
            cout << "Fecha de ingreso: " << mascota.getFechaIngreso() << endl;
            cout << "Fecha de salida: " << mascota.getFechaSalida() << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontro ninguna mascota con ese nombre.\n";
    }
}