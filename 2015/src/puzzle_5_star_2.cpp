#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

bool is_nice_new_rules(const std::string& s) {
    bool pair_found = false;
    bool repeat_with_one_between = false;

    for (size_t i = 0; i < s.length() - 1; ++i) {
        std::string pair = s.substr(i, 2);

        // Rule 1: It contains a pair of any two letters that appears at least twice in the string without overlapping.
        if (std::count(s.begin(), s.end(), pair[0]) > 1 && s.find(pair) != s.rfind(pair)) {
            pair_found = true;
            break;
        }

        // Rule 2: It contains at least one letter which repeats with exactly one letter between them.
        if (i < s.length() - 2 && s[i] == s[i + 2]) {
            repeat_with_one_between = true;
        }
    }

    return pair_found && repeat_with_one_between;
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
    std::string linea;
    int good = 0;
    while (std::getline(archivoEntrada, linea))
    {
        if (is_nice_new_rules(linea))
            good++;
    }
    cout << good << endl;
    return 0;
}