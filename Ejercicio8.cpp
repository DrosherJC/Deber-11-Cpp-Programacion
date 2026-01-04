/*//ToDo Desarrolle un programa en C++ que permita gestionar estudiantes mediante las siguientes operaciones:
Registrar estudiante: Permite ingresar un nuevo estudiante con su ID, nombre completo, carrera y promedio académico.
Listar estudiantes: Muestra todos los estudiantes registrados con su información completa.
Buscar estudiante: Permite buscar un estudiante por su ID y mostrar sus datos.
Actualizar estudiante: Permite modificar los datos de un estudiante existente buscándolo por su ID.
Eliminar estudiante: Permite eliminar un estudiante del sistema mediante su ID.
Mostrar los estudiantes aprobados promedio >= 14;
Especificaciones Técnicas
•	Utilizar un struct llamado Estudiante con los campos: id (entero), nombre (cadena), carrera (cadena) y promedio (decimal).
•	Almacenar los estudiantes en un vector de tipo Estudiante.
•	La opción 6 debe implementarse mediante una función que retorne un vector con los estudiantes que cumplan el criterio de aprobación
*/

#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

struct Estudiante{
    int id;
    string nombre;
    string carrera;
    float promedio;
};

void registrarEstudiante(vector <Estudiante> &e){

    Estudiante est;
    cout<<"\n\t==Registro de estudiante==\n";
    cout<<"Ingrese el ID del estudiante: ";
    cin>>est.id;
    cin.ignore();
    cout<<"Ingrese el nombre del estudiante: ";
    getline(cin, est.nombre);
    cout<<"Ingrese la carrera: ";
    getline(cin, est.carrera);
    cout<<"Ingrese el promedio del estudiante: ";
    cin>> est.promedio;
    e.push_back(est);
    cout<<endl;
}

void listarEstudiante(const vector <Estudiante> &e){
    cout<<endl;
    for (size_t i = 0; i < e.size(); i++)
    {
        cout<<"ID: "<<e[i].id;
        cout<<endl;
        cout<<"Nombre: "<<e[i].nombre;
        cout<<endl;
        cout<<"Carrera: "<<e[i].carrera;
        cout<<endl;
        cout<<"Promedio: "<<e[i].promedio;
        cout<<endl;
    }
    cout<<endl;
}

void buscarEstudiante(const vector <Estudiante> &e){
    int idBuscado;
    bool encontrado=false;
    cout<<"Ingrese el ID a buscar: ";
    cin>>idBuscado;
    for (size_t i = 0; i < e.size() ; i++)
    {
        if (e[i].id == idBuscado)
        {
            cout<<"ID: "<<e[i].id;
            cout<<endl;
            cout<<"Nombre: "<<e[i].nombre;
            cout<<endl;
            cout<<"Carrera: "<<e[i].carrera;
            cout<<endl;
            cout<<"Promedio: "<<e[i].promedio;
            cout<<endl;
            encontrado = true;
        }
    }
        if (!encontrado)
    {
            cout<<"\nId no encontrado!\n";
    }
    cout<<endl;

}

void actualizarEstudiante(vector <Estudiante> &e){
    cout<<endl;
    int idBuscado;
    bool encontrado=false;
    cout<<"Ingrese el ID del estudiante a actualizar: ";
    cin>>idBuscado;
    for (size_t i = 0; i < e.size() ; i++)
    {
        if (e[i].id == idBuscado)
        {
            cout<<"Nuevo ID: ";
            cin>>e[i].id;
            cin.ignore();
            cout<<endl;
            cout<<"Nombre: ";
            getline(cin,e[i].nombre);
            cout<<endl;
            cout<<"Carrera: ";
            getline(cin,e[i].carrera);
            cout<<endl;
            cout<<"Promedio: ";
            cin>>e[i].promedio;
            cout<<endl;
            encontrado = true;
        }
    }
        if (!encontrado)
    {
            cout<<"\nId no encontrado!\n";
    }
    cout<<endl;

}

void eliminarEstudiante(vector <Estudiante> &e){
    cout<<endl;
    int idBuscado;
    bool encontrado = false;
    cout<<"Ingrese el ID a buscar: ";
    cin>>idBuscado;
    for (size_t i = 0; i < e.size() ; i++){
        if (e[i].id == idBuscado){
            e.erase(e.begin()+i);
            encontrado = true;
            cout<<"Estudiante eliminado con éxito!";
            break;
        }
    }
    if (!encontrado){
        cout<<"\nId no encontrado!\n";
    }
    cout<<endl;

}

vector <Estudiante> estudiantesAprobados(const vector <Estudiante> &e){
    vector <Estudiante> aprobados;
    for (size_t i = 0; i < e.size(); i++)
    {
        if (e[i].promedio>=14)
        {
            aprobados.push_back(e[i]);
        }
    }
    return aprobados;
}

void presentarAprobados(vector <Estudiante> aprobados){
    cout<<endl;
    for (size_t i = 0; i < aprobados.size(); i++)
    {
        cout<<"ID: "<<aprobados[i].id;
        cout<<endl;
        cout<<"Nombre: "<<aprobados[i].nombre;
        cout<<endl;
        cout<<"Carrera: "<<aprobados[i].carrera;
        cout<<endl;
        cout<<"Promedio: "<<aprobados[i].promedio;
        cout<<endl;
    }
    
}

void menu( vector <Estudiante> &e){
    int opcion;
    do
    {
        cout<<"\t\n===Sistema de Gestión de Estudiantes===\n";
        cout<<"1. Registrar Estudiante"<<endl;
        cout<<"2. Listar Estudiantes"<<endl;
        cout<<"3. Buscar Estudiante"<<endl;
        cout<<"4. Actualizar Estudiante"<<endl;
        cout<<"5. Eliminar Estudiante"<<endl;
        cout<<"6. Mostrar Estudiantes Aprobados"<<endl;
        cout<<"7. Salir"<<endl;
        cout<<"Seleccione una opción: ";
        cin>>opcion;
        cin.ignore();

        switch (opcion){
        case 1:
            registrarEstudiante(e);
            break;
        case 2:
            listarEstudiante(e);
            break;
        case 3:
            buscarEstudiante(e);
            break;
        case 4:
            actualizarEstudiante(e);
            break;
        case 5:
            eliminarEstudiante(e);
            break;
        case 6:{
            vector <Estudiante> aprobados = estudiantesAprobados(e);
            presentarAprobados(aprobados);
            break;
        }
        case 7:
            cout<<"Saliendo del sistema!";
            break;
        default:
            break;
        }
        } while (opcion !=7);
}


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    vector <Estudiante> e;
    menu(e);

    return 0;
}

