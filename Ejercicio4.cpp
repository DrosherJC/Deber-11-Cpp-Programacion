//ToDo	Eres un alquimista y tienes un libro de recetas de pociones. Cada poción tiene un nombre, una lista de ingredientes, un tiempo de preparación en minutos y su efecto mágico. Debes definir una estructura PocionMagica y los ingredientes deben ser un vector<string> dentro del propio struct. Pide al usuario que ingrese 3 pociones diferentes con sus recetas (valores quemados). Luego, el programa debe permitir al usuario escribir el nombre de un ingrediente (ej. "Raíz de mandrágora") y mostrar todas las opciones que lo utilizan. 

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

struct PocionMagica
{
    string nombre;
    vector <string> ingredientes;
    int tiempoPreparacion; //en minutos
    string efecto;
};

void buscarIngrediente(vector <PocionMagica> &pociones){
    string ingrediente;
    bool encontrado = false;
    cout<<"Ingrese el ingrediente a buscar: ";
    getline(cin, ingrediente);

    for (auto &&pocion : pociones)
    {
        for (auto &&ingredientes : pocion.ingredientes)
        {
            if (ingredientes == ingrediente)
            {
                cout<<"Pociones encontradas\n";
                cout<<"Nombre: "<<pocion.nombre<<endl;
                cout<<"Tiempo de preparación: "<<pocion.tiempoPreparacion<<" min"<<endl;
                cout<<"Efecto: "<<pocion.efecto<<endl;
                cout<<endl;
                encontrado = true;
                break;
            }
        }
    }
    if(!encontrado){
        cout<<"El ingrediente no se usa para ninguna poción registrada";
    }   
}

int main()
{
    vector <PocionMagica> pocion(3);

    SetConsoleOutputCP(CP_UTF8);

    pocion[0].nombre = "Poción de Fuerza Titánica";
    pocion[0].ingredientes = {"Raíz de mandrágora","Polvo de hueso de dragón","Sangre de ogro","Agua de manantial"};
    pocion[0].tiempoPreparacion = 45;
    pocion[0].efecto = "Aumenta la fuerza física del usuario durante una hora.";

    pocion[1].nombre = "Elixir de Invisibilidad";
    pocion[1].ingredientes = {"Hoja de sombra","Lágrimas de fantasma","Raíz de mandrágora","Esencia de luna"};
    pocion[1].tiempoPreparacion = 30;
    pocion[1].efecto = "Vuelve invisible al usuario por 10 minutos.";
    
    pocion[2].nombre = "Poción de Curación Suprema";
    pocion[2].ingredientes = {"Flor de vida","Miel encantada","Agua bendita","Polvo de unicornio"};
    pocion[2].tiempoPreparacion = 25;
    pocion[2].efecto = "Cura completamente heridas y enfermedades.";

    buscarIngrediente(pocion);

    return 0;
}
