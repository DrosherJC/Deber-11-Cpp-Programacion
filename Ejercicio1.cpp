//ToDo Crea una estructura llamada Vehiculo que contenga los siguientes campos: marca (string), modelo (string), anio (int). Luego, declara un arreglo de 5 vehículos. Escribe un programa que permita al usuario ingresar los datos de cada vehículo y luego muestre la información del vehículo más reciente.
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct vehiculo
{
    string marca;
    string modelo;
    int anio;
};
void vehiculoReciente(vehiculo vehiculos[]){
    int indiceReciente = 0;
    for (int i = 1; i < 5; i++)
    {
        if (vehiculos[i].anio > vehiculos[indiceReciente].anio)
        {
            indiceReciente = i;
        }
    }
        cout<<endl;
        cout<<"El vehiculo más reciente es: "<<vehiculos[indiceReciente].modelo<<endl<<"De la marca: "<<vehiculos[indiceReciente].marca<<endl<<"Del año: "<<vehiculos[indiceReciente].anio<<endl;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    vehiculo vehiculos[5];
    for (int i = 0; i < 5; i++)
    {

        cout<<"Ingrese la marca del vehículo "<<i+1<<": ";
        getline(cin,vehiculos[i].marca);
        cout<<"Ingrese el modelo del vehículo "<<i+1<<": ";
        getline(cin,vehiculos[i].modelo);
        cout<<"Ingrese el anio del vehiculo "<<i+1<<": ";
        cin>>vehiculos[i].anio;
        cin.ignore();
        cout<<endl;
    }
    vehiculoReciente(vehiculos);
    return 0;
}
