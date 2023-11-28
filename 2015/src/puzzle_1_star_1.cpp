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
    while (archivoEntrada.get(caracter)) {
        if (caracter == '(') result++;
        else if (caracter == ')') result--;
    }
    archivoEntrada.close();
    cout<<result<<endl;
    return 0;
}