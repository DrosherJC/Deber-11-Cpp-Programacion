//ToDo 7)	Luego de una pericia informática, se han extraído los chats de whatsapp de tu expareja, mismos que vienen en un arreglo con el siguiente formato: 

//* string chat[] = {
//* "08:15//Roberto//Hola perdida, ¿como estas?",
//* "08:17//Belen//Bien, gracias. ¿Y tu?",
//* "08:20//Roberto//Aqui pensandote. ¿Quieres salir al cine hoy?",
//* "08:21//Belen//Tu novia, ¿si te da permiso?",
//* "08:22//Roberto//Cual novia?. Es una amiga nomas",
//* "08:23//Roberto//mejor tu pide permiso a tu novio?"};
// Debes extraer las partes de cada mensaje (hora, usuario, mensaje) y presentarlo en 3 arreglos diferentes , adicional mostrar un reporte de  cuántos mensajes ha enviado Roberto y Belen en total. Necesitaras usar find() y substr().
#include <iostream>
#include<windows.h>
using namespace std;

void separarMensaje(string chat[],int tamanio, string hora[],string usuario[],string mensaje[]){


    for (size_t i = 0; i < tamanio ; i++)
    {
        int posicion = chat[i].find("//");
        int posicion1 = chat[i].find("//",posicion+2);

        if (posicion!=string::npos && posicion1 != string::npos)
        {
            hora[i] = chat[i].substr(0,posicion);
            usuario[i] = chat[i].substr(posicion+2,posicion1-(posicion+2));
            mensaje[i] = chat[i].substr(posicion1+2);
        }
    }
}

void mostrarArrays(string hora[],string usuario[],string mensaje[]){
    cout<<"Hora: ";
    for (int i = 0; i < 6; i++){
        cout<<hora[i]<<" ";
    }
    cout<<endl;
    cout<<endl;


    cout<<"Usuario: ";
    for (int i = 0; i < 6; i++){
        cout<<usuario[i]<<" ";
    }   
    cout<<endl;
    cout<<endl;


    cout<<"Mensaje: ";
    for (int i = 0; i < 6; i++){
        cout<<mensaje[i]<<" ";
    }
    
}


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    string chat[] = {
    "08:15//Roberto//Hola perdida, ¿como estas?",
    "08:17//Belen//Bien, gracias. ¿Y tu?",
    "08:20//Roberto//Aqui pensandote. ¿Quieres salir al cine hoy?",
    "08:21//Belen//Tu novia, ¿si te da permiso?",
    "08:22//Roberto//Cual novia?. Es una amiga nomas",
    "08:23//Roberto//mejor tu pide permiso a tu novio?"
    };
    int tamanio = sizeof(chat)/sizeof(chat[0]);
    string hora[6];
    string usuario[6];
    string mensaje[6];
    separarMensaje(chat,tamanio,hora,usuario,mensaje);
    mostrarArrays(hora,usuario,mensaje);
    return 0;
}
