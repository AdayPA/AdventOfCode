#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;




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
    int counter = 0;
    while (std::getline(archivoEntrada, linea)) {
        counter += getNumber(linea);
    }

    cout << counter << endl;
    archivoEntrada.close();
    return 0;
}