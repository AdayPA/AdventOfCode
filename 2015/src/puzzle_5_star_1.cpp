#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int countVowels(std::string s)
{
    int count = 0;
    for (char c : s)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            count++;
        }
    }
    return count;
}

bool doubleLetter (std::string s) {
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::string nombreArchivo = "../input/puzzle_5.txt";
    std::ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada.is_open())
    {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return 1;
    }
    std::string ab = "ab";
    std::string cd = "cd";
    std::string pq = "pq";
    std::string xy = "xy";
    std::size_t found_ab, found_cd, found_pq, found_xy;
    std::string linea;
    bool vocal = false;
    bool dual = false;
    bool special = false;
    int bad = 0;
    int good = 0;
    while (std::getline(archivoEntrada, linea))
    {
        found_ab = linea.find(ab);
        found_cd = linea.find(cd);
        found_pq = linea.find(pq);
        found_xy = linea.find(xy);
        if (countVowels(linea) > 2 && doubleLetter(linea) && !(found_ab != std::string::npos || found_cd != std::string::npos || found_pq != std::string::npos || found_xy != std::string::npos)) {
            good++;
        }
    }
    cout << good << endl;
    return 0;
}