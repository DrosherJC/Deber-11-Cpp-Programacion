/* //ToDo	Un cine necesita organizar su catálogo de películas.Crea un programa en C++ con un menú interactivo que permita cumplir los siguiente requerimientos:
1.	Registrar película: id, título, director, estado (en cartelera / fuera de cartelera).
2.	Listar películas.
3.	Buscar película por id.
4.	Cambiar estado (en cartelera ↔ fuera de cartelera).
5.	Eliminar película.
6.	Filtrar por estado.



*/
#include <iostream>
#include <vector>
#include<windows.h>

using namespace std;

struct Pelicula {
int id;
string titulo;
string director;
bool enCartelera;
};

void registrarPelicula(vector <Pelicula>&p){
    Pelicula peli;
    char respuesta;
    cout<<"\t\nRegistrar Película\n";
    cout<<"Ingrese el ID: ";
    cin>>peli.id;
    cin.ignore();
    cout<<"Ingrese el título: ";
    getline(cin, peli.titulo);
    cout<<"Ingrese el nombre del director: ";
    getline(cin, peli.director);
    cout<<"Está en cartelera? (s/n): ";
    cin>>respuesta;
    if (respuesta == 's')
    {
        peli.enCartelera = true;
    }else{
        peli.enCartelera = false;
    }
    p.push_back(peli);
    cout<<endl;

}


void listarPeliculas(const vector <Pelicula>&p){
    for (size_t i = 0; i < p.size(); i++)
    {
        cout<<"ID: "<<p[i].id<<endl;
        cout<<"Título: "<<p[i].titulo<<endl;
        cout<<"Director: "<<p[i].director<<endl;
        cout<<"Estado: ";
        if(p[i].enCartelera){
            cout<<" En cartelera";
        }else{
            cout<<" Fuera de cartelera";
        }
    }
    cout<<endl;

}


void buscarPelicula(const vector <Pelicula>&p){
    int idBuscado;
    bool encontrado = false;
    cout<<"Ingrese el ID a buscar: ";
    cin>>idBuscado;
    for (size_t i = 0; i < p.size(); i++)
    {
        if (idBuscado == p[i].id)
        {
            cout<<"ID: "<<p[i].id<<endl;
            cout<<"Título: "<<p[i].titulo<<endl;
            cout<<"Director: "<<p[i].director<<endl;
            cout<<"Estado: ";
            if(p[i].enCartelera){
                cout<<" En cartelera";
            }else{
                cout<<" Fuera de cartelera";
            }
            encontrado=true;
        }
    }
        if(!encontrado){
        cout<<"\nId no encontrado!\n";
    }
    cout<<endl;

}


void cambiarEstado(vector <Pelicula>&p){
    int idBuscado;
    bool encontrado = false;
    cout<<"Ingrese el ID a buscar: ";
    cin>>idBuscado;
    for (size_t i = 0; i < p.size(); i++)
    {
        if (idBuscado == p[i].id)
        {
            p[i].enCartelera = !p[i].enCartelera ;
            cout<<"Estado actualizado con éxito!"<<endl;
            encontrado = true;
            break;
        }
    }
    if(!encontrado){
        cout<<"\nId no encontrado!\n";
    }
    cout<<endl;
}

void eliminarPelicula(vector <Pelicula>&p){
    int idBuscado;
    bool encontrado = false;
    cout<<"Ingrese el ID a eliminar: ";
    cin>>idBuscado;
    for (size_t i = 0; i < p.size(); i++)
    {
        if (idBuscado == p[i].id)
        {
            p.erase(p.begin()+i);
            cout<<"Título eliminado con éxito!"<<endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
    {
        cout<<"Id no encontrado";
    }
    cout<<endl;
    
}

void filtrarEstado(const vector <Pelicula>&p){
    int opcion;
    cout<<"1. En cartelera\n";
    cout<<"2. Fuera de cartelera\n";
    cin>>opcion;
    switch (opcion)
    {
    case 1:
        cout<<"\t\n==En cartelera==\n";
        for (size_t i = 0; i < p.size(); i++){
            if (p[i].enCartelera){
                cout<<"ID: "<<p[i].id<<endl;
                cout<<"Título: "<<p[i].titulo<<endl;
                cout<<"Director: "<<p[i].director<<endl;
            }
        }
        break;
    case 2:
    cout<<"\t\n==Fuera de cartelera==\n";
        for (size_t i = 0; i < p.size(); i++){
            if (!p[i].enCartelera){
                cout<<"ID: "<<p[i].id<<endl;
                cout<<"Título: "<<p[i].titulo<<endl;
                cout<<"Director: "<<p[i].director<<endl;
            }
        }
        break;
    default:
        cout<<"Opción No válida!";
        break;
    }
    cout<<endl;

}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    vector <Pelicula> p;
    int opcion;
    do
    {
        cout<<"\t\n==Menú Principal==\n";
        cout<<"1. Registrar película"<<endl;
        cout<<"2. Listar películas"<<endl;
        cout<<"3. Buscar película"<<endl;
        cout<<"4. Cambiar estado (en cartelera ↔ fuera de cartelera)."<<endl;
        cout<<"5. Eliminar película"<<endl;
        cout<<"6. Filtrar por estado"<<endl;
        cout<<"7. Salir"<<endl;
        cout<<"Seleccione una opción: ";
        cin>>opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1:
            registrarPelicula(p);
            break;
        case 2:
            listarPeliculas(p);
            break;
        case 3:
            buscarPelicula(p);
            break;
        case 4:
            cambiarEstado(p);
            break;
        case 5:
            eliminarPelicula(p);
            break;
        case 6:
            filtrarEstado(p);
            break;
        case 7:
            cout<<"Saliendo del programa...!";
            break;
        default:
        cout<<"\nSeleccione una opción válida!\n";
            break;
        }
    } while (opcion !=7);
    

    return 0;
}
