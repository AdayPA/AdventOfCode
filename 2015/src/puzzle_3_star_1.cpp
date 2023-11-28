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
    // Coordenadas iniciales de Santa
    int x = 0;
    int y = 0;

    // Utilizamos un conjunto con nuestro propio objeto hash para almacenar las coordenadas únicas
    std::unordered_set<std::pair<int, int>, PairHash> casasConRegalos = {{x, y}};  // Santa entrega un regalo en su ubicación inicial

    // Nombre del archivo que contiene las direcciones
    std::string nombreArchivo = "../input/puzzle_3.txt";

    // Crear un objeto ifstream para leer el archivo
    std::ifstream archivoEntrada(nombreArchivo);

    // Verificar si el archivo se abrió correctamente
    if (!archivoEntrada.is_open()) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return 1;  // Devolver un código de error
    }
    char direccion;
    while (archivoEntrada >> direccion) {
        // Actualizar las coordenadas según la dirección
        switch (direccion) {
            case '^':
                y++;
                break;
            case 'v':
                y--;
                break;
            case '>':
                x++;
                break;
            case '<':
                x--;
                break;
        }
       casasConRegalos.insert({x, y});
    }
    std::cout << "Casas con al menos un regalo: " << casasConRegalos.size() << std::endl;
    archivoEntrada.close();

    return 0;
}
