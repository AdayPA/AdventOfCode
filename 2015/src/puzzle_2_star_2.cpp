#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

std::vector<std::string> Split (std::string str, std::string delim) {
  /// @brief this func split in 2 the string and store them in vector, 
  //         depending of the char
  std::vector<std::string> tokens;
  size_t prev = 0, pos = 0;
  do {
    pos = str.find(delim, prev);
    if (pos == std::string::npos) pos = str.length();
    std::string token = str.substr(prev, pos-prev);
    if (!token.empty()) tokens.push_back(token);
    prev = pos + delim.length();
  }
  while (pos < str.length() && prev < str.length());
  return tokens;
}

int CalcularCintaTotal(int longitud, int ancho, int altura) {
    // Calcula la longitud necesaria para envolver el regalo (el perímetro más pequeño)
    int longitudEnvolver = 2 * (longitud + ancho + altura - std::max({longitud, ancho, altura}));

    // Calcula la longitud necesaria para el lazo (cúbico de volumen)
    int longitudLazo = longitud * ancho * altura;

    // Retorna la suma total de longitud de cinta requerida
    return longitudEnvolver + longitudLazo;
}


int main()
{
    std::string nombreArchivo = "../input/puzzle_2.txt";
    std::ifstream archivoEntrada(nombreArchivo);
    vector<int> dim;
    if (!archivoEntrada.is_open())
    {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return 1;
    }
    string delimiter = "x";
    std::string linea;
    int sum = 0;
    while (std::getline(archivoEntrada, linea))
    {
        std::vector<std::string> tokens = Split(linea, delimiter);
        dim.push_back(stoi(tokens[0]));
        dim.push_back(stoi(tokens[1]));
        dim.push_back(stoi(tokens[2]));
        sum += CalcularCintaTotal(dim[0], dim[1], dim[2]);
        dim.clear();
    }
    cout << sum;
    archivoEntrada.close();
    return 0;
}

// l*w*h
// 2x3x4
// 2*l*w + 2*w*h + 2*h*l

// 20x3x11
// 2*20*3 + 2*3*11+2*11*20 60 33