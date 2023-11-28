#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    std::string nombreArchivo = "../input/puzzle_1.txt";
    std::ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada.is_open())
    {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return 1; 
    }
    char caracter;
    int result;
    int counter = 0;
    while (archivoEntrada.get(caracter)) {
        if (caracter == '(') result++;
        else if (caracter == ')') result--;
        if (result == -1){
            cout << counter;
          return counter;  
        } 
        counter++;
    }
    archivoEntrada.close();
    cout<<result<<endl;
    return 0;
}