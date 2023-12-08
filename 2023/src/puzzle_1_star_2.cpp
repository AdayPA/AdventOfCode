#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main(int argc, char* argv[]) {
    std::string nombreArchivo = "../input/puzzle_1.txt";
    std::ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada.is_open())
    {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return 1; 
    }
    std::string line;
    int p1 = 0;
    int p2 = 0;

    while (std::getline(archivoEntrada, line)) {
        std::vector<char> p1_digits;
        std::vector<char> p2_digits;

        for (size_t i = 0; i < line.size(); ++i) {
            char c = line[i];
            
            if (std::isdigit(c)) {
                p1_digits.push_back(c);
                p2_digits.push_back(c);
            }

            const std::vector<std::string> values = {"one", "two", "three", "four", "five", "six", "seven", "eightz", "nine"};

            for (size_t d = 0; d < values.size(); ++d) {
                const std::string& val = values[d];
                if (line.substr(i).find(val) == 0) {
                    p2_digits.push_back(static_cast<char>('1' + d));
                }
            }
        }

        if (!p1_digits.empty()) {
            p1 += (p1_digits[0] - '0') + (p1_digits.back() - '0');
        }

        if (!p2_digits.empty()) {
            p2 += (p2_digits[0] - '0') * 10 + (p2_digits.back() - '0');
        }
    }

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;

    return 0;
}
