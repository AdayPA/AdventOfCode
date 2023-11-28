#include <iostream>
#include <fstream>
#include <unordered_set>
#include <utility>

struct PairHash {
    template <typename T1, typename T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int main() {
    int santaX = 0, santaY = 0;
    int roboSantaX = 0, roboSantaY = 0;
    std::unordered_set<std::pair<int, int>, PairHash> casasConRegalos = {{santaX, santaY}};
    std::string nombreArchivo = "../input/puzzle_3.txt";
    std::ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada.is_open()) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return 1;  
    }
    char direccion;
    bool turnoSanta = true;

    while (archivoEntrada >> direccion) {
        if (turnoSanta) {
            switch (direccion) {
                case '^':
                    santaY++;
                    break;
                case 'v':
                    santaY--;
                    break;
                case '>':
                    santaX++;
                    break;
                case '<':
                    santaX--;
                    break;
            }
            casasConRegalos.insert({santaX, santaY});
        } else {
            switch (direccion) {
                case '^':
                    roboSantaY++;
                    break;
                case 'v':
                    roboSantaY--;
                    break;
                case '>':
                    roboSantaX++;
                    break;
                case '<':
                    roboSantaX--;
                    break;
            }
            casasConRegalos.insert({roboSantaX, roboSantaY});
        }
        turnoSanta = !turnoSanta;
    }
    std::cout << "Casas con al menos un regalo: " << casasConRegalos.size() << std::endl;
    archivoEntrada.close();
    return 0;
}
