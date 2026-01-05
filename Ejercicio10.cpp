/*	//ToDO Un club deportivo necesita organizar sus equipos y jugadores. Cada equipo tiene un entrenador y varios jugadores asociados. El sistema debe permitir gestionar tanto los equipos como los jugadores de manera dinámica.
Requerimientos del programa
El programa debe ofrecer un menú con las siguientes operaciones:
1.	Registrar equipo
o	Datos: id, nombre, entrenador.
o	Inicialmente el equipo se crea con un vector vacío de jugadores.
2.	Agregar jugador a un equipo
o	Datos: id, nombre, posición, edad.
o	Se agrega al vector de jugadores dentro del equipo correspondiente.
3.	Listar equipos con sus jugadores
o	Mostrar todos los equipos y, dentro de cada uno, los jugadores registrados.
4.	Buscar equipo por ID
o	Mostrar detalles del equipo y su lista de jugadores.
5.	Eliminar jugador de un equipo
o	Buscar por ID de jugador y eliminarlo del vector de jugadores del equipo.
6.	Filtrar equipos por entrenador
o	Mostrar solo los equipos dirigidos por un entrenador específico.
7.	Eliminar equipo completo
•	Eliminar un equipo y todos sus jugadores asociados.
Structs sugeridos:


*/
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

struct Jugador {
    int id;
    string nombre;
    string posicion;
    int edad;
};

struct Equipo {
    int id;
    string nombre;
    string entrenador;
    vector<Jugador> jugadores;
};

void registrarEquipo(vector<Equipo>& equipos) {
    Equipo e;
    cout << "ID del equipo: ";
    cin >> e.id;
    cin.ignore();
    cout << "Nombre del equipo: ";
    getline(cin, e.nombre);
    cout << "Entrenador: ";
    getline(cin, e.entrenador);

    equipos.push_back(e);
    cout << "Equipo registrado correctamente\n\n";
}

void agregarJugador(vector<Equipo>& equipos) {
    int idEquipo;
    cout << "ID del equipo: ";
    cin >> idEquipo;

    for (size_t i = 0; i < equipos.size(); i++) {
        if (equipos[i].id == idEquipo) {
            Jugador j;
            cout << "ID del jugador: ";
            cin >> j.id;
            cin.ignore();
            cout << "Nombre: ";
            getline(cin, j.nombre);
            cout << "Posición: ";
            getline(cin, j.posicion);
            cout << "Edad: ";
            cin >> j.edad;

            equipos[i].jugadores.push_back(j);
            cout << "Jugador agregado\n\n";
            return;
        }
    }
    cout << "Equipo no encontrado\n\n";
}

void listarEquipos(const vector<Equipo>& equipos) {
    for (const auto& e : equipos) {
        cout << "\nEquipo: " << e.nombre << " (ID: " << e.id << ")";
        cout << "\nEntrenador: " << e.entrenador << endl;

        if (e.jugadores.empty()) {
            cout << "Sin jugadores registrados\n";
        } else {
            for (const auto& j : e.jugadores) {
                cout << "- " << j.nombre << " | " << j.posicion<< " | Edad: " << j.edad << endl;
            }
        }
    }
    cout << endl;
}

void buscarEquipo(const vector<Equipo>& equipos) {
    int idBuscado;
    cout << "ID del equipo: ";
    cin >> idBuscado;

    for (const auto& e : equipos) {
        if (e.id == idBuscado) {
            cout << "\nEquipo: " << e.nombre << endl;
            cout << "Entrenador: " << e.entrenador << endl;
            cout << "Jugadores:\n";

            for (const auto& j : e.jugadores) {
                cout << j.nombre << " - " << j.posicion << endl;
            }
            return;
        }
    }
    cout << "Equipo no encontrado\n";
}

void eliminarJugador(vector<Equipo>& equipos) {
    int idJugador;
    cout << "ID del jugador a eliminar: ";
    cin >> idJugador;

    for (auto& e : equipos) {
        for (size_t i = 0; i < e.jugadores.size(); i++) {
            if (e.jugadores[i].id == idJugador) {
                e.jugadores.erase(e.jugadores.begin() + i);
                cout << "Jugador eliminado\n\n";
                return;
            }
        }
    }
    cout << "Jugador no encontrado\n";
}

void filtrarPorEntrenador(const vector<Equipo>& equipos) {
    string nombre;
    cin.ignore();
    cout << "Nombre del entrenador: ";
    getline(cin, nombre);

    for (const auto& e : equipos) {
        if (e.entrenador == nombre) {
            cout << "Equipo: " << e.nombre << endl;
        }
    }
    cout << endl;
}

void eliminarEquipo(vector<Equipo>& equipos) {
    int idEquipo;
    cout << "ID del equipo a eliminar: ";
    cin >> idEquipo;

    for (size_t i = 0; i < equipos.size(); i++) {
        if (equipos[i].id == idEquipo) {
            equipos.erase(equipos.begin() + i);
            cout << "Equipo eliminado\n";
            return;
        }
    }
    cout << "Equipo no encontrado\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    vector<Equipo> equipos;
    int opcion;

    do {
        cout << "\n=== MENÚ ===\n";
        cout << "1. Registrar equipo\n";
        cout << "2. Agregar jugador\n";
        cout << "3. Listar equipos\n";
        cout << "4. Buscar equipo\n";
        cout << "5. Eliminar jugador\n";
        cout << "6. Filtrar por entrenador\n";
        cout << "7. Eliminar equipo\n";
        cout << "8. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: 
            registrarEquipo(equipos); 
            break;
        case 2: 
            agregarJugador(equipos); 
            break;
        case 3: 
            listarEquipos(equipos); 
            break;
        case 4: 
            buscarEquipo(equipos); 
            break;
        case 5: 
            eliminarJugador(equipos); 
            break;
        case 6: 
            filtrarPorEntrenador(equipos); 
            break;
        case 7: 
            eliminarEquipo(equipos); 
            break;
        case 8: 
            cout << "Saliendo...\n"; 
            break;
        default: 
            cout << "Opción inválida\n";
        }
    } while (opcion != 8);

    return 0;
}
