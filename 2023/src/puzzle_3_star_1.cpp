#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int getNumber(int x, int y) {
    
}


int main()
{
    std::string nombreArchivo = "../input/puzzle_3.txt";
    std::ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada.is_open())
    {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return 1; 
    }
    string linea;
    while (std::getline(archivoEntrada, linea)) {

    }
    archivoEntrada.close();
    return 0;
}