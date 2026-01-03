//ToDo Escribe una función que cuente cuántas palabras contiene una cadena. Considera que las palabras están separadas por espacios. Ejm: “El martes tengo prueba de programacion”.
#include <string>
#include <iostream>
#include <windows.h>
using namespace std;

void contarPalabras(int &contador ,string &oracion){
    bool palabra = false;
    for (char c : oracion )
    {
        if (c != ' ' && !palabra)
        {
            contador++;
            palabra = true;
        }else if(c == ' '){
            palabra = false;
        }
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    string oracion;
    int contador = 0;
    cout<<"Ingrese una oración: ";
    getline(cin, oracion);
    contarPalabras(contador, oracion);
    cout<<"La oración tiene "<<contador<<" palabras";
    return 0;
}

