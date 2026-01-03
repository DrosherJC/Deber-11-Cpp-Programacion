//ToDo Escriba una función que reciba una expresión matemática y separe sus componentes, por ejemplo al ingresar (2*3)-5=1 el resultado será :
// Números: 2, 3, 5
// Operadores: *, -
// Otros: ( , )
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

void separarNumeros(string &operacion){
    vector <char> numeros;
    vector <char> signos;
    vector <char> otros;

    for (auto &&c : operacion)
    {
        if (isdigit(c))
        {
            numeros.push_back(c);
        }
        else if (c == '+' || c=='-' || c=='/' || c == '*')
        {
            signos.push_back(c);
        }
        else
        {
            otros.push_back(c);
        }
    }
    cout<<"Números: ";
    for (auto &&n : numeros)
    {
        cout<<n<<" ";
    }
    cout<<endl;

    cout<<"Signos: ";
    for (auto &&n : signos)
    {
        cout<<n<<" ";
    }
    cout<<endl;

    cout<<"Otros: ";
    for (auto &&n : otros)
    {
        cout<<n<<" ";
    }
    cout<<endl;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    string operacion;
    cout<<"Ingrese su operación: ";
    getline(cin,operacion);
    separarNumeros(operacion);
    return 0;
}



