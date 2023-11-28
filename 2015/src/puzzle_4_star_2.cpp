#include <iostream>
#include <iomanip>
#include <string>
#include <cryptopp/md5.h>
#include <cryptopp/hex.h>

std::string calcularMD5(const std::string& input) {
    CryptoPP::MD5 hash;
    std::string output;

    CryptoPP::StringSource(input, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );
    return output;
}

bool primerosCincoCeros(const std::string& cadena) {
    if (cadena.length() < 6) {
        std::cerr << "La cadena es demasiado corta." << std::endl;
        return false;
    }
    for (size_t i = 0; i < 6; ++i) {
        if (cadena[i] != '0') {
            return false; 
        }
    }
    return true; 
}

int main() {
    std::string claveSecreta = "iwrupvqb";
    int numeroEnDecimal = 0;
    bool find = false;
    while (!find) {
        std::string entrada = claveSecreta + std::to_string(numeroEnDecimal);
        std::string hashMD5 = calcularMD5(entrada);
        if (primerosCincoCeros(hashMD5)) {
            find = true;
            std::cout << "Encontrado: " << entrada << std::endl;
            return 0;
        }
        numeroEnDecimal++;
    }
    return 0;
}
