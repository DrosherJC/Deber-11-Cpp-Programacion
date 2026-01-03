/*
ToDo En un tablero de 6x6, un barco enemigo de 3 casillas de largo ha sido colocado horizontalmente en una fila aleatoria. Tu programa debe generar este tablero ('~' para el agua, 'B' para el barco). Luego, pide al usuario que ingrese una coordenada (fila y columna) para disparar un torpedo. El programa debe validar si fue tocado el barco o no. 
~ ~ ~ ~ ~ ~ 
~ ~ ~ ~ ~ ~ 
~ B B B ~ ~ 
~ ~ ~ ~ ~ ~ 
~ ~ ~ ~ ~ ~  
*/

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime> //Incluyo esta libreria para generar el barco aleatoriamente, ya que sin ella el barco se genera pero no cambia de lugar cada que se inicializa el programa.
using namespace std;

const int FILAS = 6;
const int COLUMNAS = 6;

void generarMapa(string mapa[FILAS][COLUMNAS]){
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            mapa[i][j] ="~";
        }
    }
}

void mostrarMapa(string mapa[FILAS][COLUMNAS]){
        for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            cout<<mapa[i][j]<<" ";
        }
        cout<<endl;
    }
}

void generarBarco(string mapa[FILAS][COLUMNAS]){
    int fila = rand()%FILAS;
    int columna = rand()%(COLUMNAS-2);
    for (int i = 0; i < 3; i++) {
    mapa[fila][columna + i] = "B";
}


}
bool disparoValido(string mapa[FILAS][COLUMNAS]){
    int x,y;
    cout<<"Ingrese la coordenada X: ";
    cin>>x;
    cout<<"Ingrese la coordenada y: ";
    cin>>y;
    x--;
    y--;
    if (x <0 || x>=FILAS || y<0 || y>=COLUMNAS)
    {
        cout<<"Ingrese una coordenada válida (1-6) \n";
        return false;
    }
    else
    {
        if (mapa[x][y]=="B")
        {
            return true;
        }else{
            return false;
        }   
    }
}

int main()
{
    srand(time(NULL)); //Función de la librería ctime, sirve para que rand() genere numeros diferentes cada que se ejecute
    SetConsoleCP(CP_UTF8);
    string tablero[FILAS][COLUMNAS];
    generarMapa(tablero);
    generarBarco(tablero);
    mostrarMapa(tablero);
    if (disparoValido(tablero)){
        cout<<"Haz destruido el barco!";
    } else{
        cout<<"Oh no! Fallaste";
    }
    return 0;
}

