//ToDo	Willy Wonka te ha contratado para monitorear una de sus máquinas. La máquina produce tabletas de chocolate de 4x6. Cada celda de la matriz representa un trozo de chocolate y puede tener un número del 1 al 9, que indica su nivel de dulzura. Tu programa debe pedir al usuario que llene la matriz con los niveles de dulzura y luego calcular y mostrar cuál es el nivel de dulzura promedio de toda la tableta.
#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
using namespace std;
const int FILA = 4;
const int COLUMNA = 6;

void agregarNivel(int tableta[FILA][COLUMNA]){
    int nivel;
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            do
            {
            cout<<"Ingrese el nivel de dulzura de la sección "<<"["<<i+1<<"]"<<"["<<j+1<<"] (1-9): "<<endl;
            cin>>nivel;
            } while (nivel> 9 || nivel <1);
            tableta[i][j]=nivel;
        }
    }
}

float promedioNivelDulzura(int tableta[FILA][COLUMNA]){
    int suma=0;
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            suma+=tableta[i][j];
        }
    }
    float promedio = float(suma)/(FILA*COLUMNA);
    return promedio;
}
int main()
{
    
    int tableta[FILA][COLUMNA];
    agregarNivel(tableta);
    float promedio = promedioNivelDulzura(tableta);
    cout<<"El promedio de nivel de dulzura de la barra es: "<<fixed<<setprecision(2)<<promedio;
    return 0;
}
