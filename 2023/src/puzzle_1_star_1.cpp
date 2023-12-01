#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int getNumber(string s) {
    vector<char> charVector;
    for (char c : s) {
        if (c >= '1' && c <= '9') {
            charVector.push_back(c);
        }
    }

    if (charVector.size() == 1) {
        charVector.push_back(charVector[0]);  // Duplicar el único dígito.
    } else if (charVector.size() < 2) {
        cerr << "Error: No hay suficientes dígitos en la cadena." << endl;
        return -1;
    }

    char number[2] = {charVector[0], charVector.back()};
    char *output;
    long result = strtol(number, &output, 10);

    if (*output != '\0') {
        cerr << "Error al convertir a número." << endl;
        return -1;
    }

    return result;
}


int main()
{
    std::string nombreArchivo = "../input/puzzle_1.txt";
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