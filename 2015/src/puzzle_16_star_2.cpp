#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <optional>
#include <new>

using namespace std;

struct Aunt
{
    int id;
    optional<int> children, cats, samoyeds, pomeranians, akitas, vizslas, goldfish, trees, cars, perfumes;

    bool operator<(const Aunt &otra) const
    {
        return id < otra.id; // Comparación basada en el ID
    }
};

std::vector<std::string> Split(std::string str, std::string delim)
{
    /// @brief this func split in 2 the string and store them in vector,
    //         depending of the char
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos)
            pos = str.length();
        std::string token = str.substr(prev, pos - prev);
        if (!token.empty())
            tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

void obtain_data(set<Aunt> &aunts)
{
    std::string nombreArchivo = "../../input/puzzle_16.txt";
    std::ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada.is_open())
    {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
    }
    std::string linea;
    while (std::getline(archivoEntrada, linea))
    {
        std::vector<std::string> linea_split = Split(linea, " ");
        Aunt temp;
        temp.id = stoi(linea_split[1]);
        for (int i = 2; i < linea_split.size(); i++)
        {
            if (linea_split[i] == "children:")
            {
                temp.children = stoi(linea_split[i + 1]);
            }
            else if (linea_split[i] == "cats:")
            {
                temp.cats = stoi(linea_split[i + 1]);
            }
            else if (linea_split[i] == "samoyeds:")
            {
                temp.samoyeds = stoi(linea_split[i + 1]);
            }
            else if (linea_split[i] == "pomeranians:")
            {
                temp.pomeranians = stoi(linea_split[i + 1]);
            }
            else if (linea_split[i] == "akitas:")
            {
                temp.akitas = stoi(linea_split[i + 1]);
            }
            else if (linea_split[i] == "vizslas:")
            {
                temp.vizslas = stoi(linea_split[i + 1]);
            }
            else if (linea_split[i] == "goldfish:")
            {
                temp.goldfish = stoi(linea_split[i + 1]);
            }
            else if (linea_split[i] == "trees:")
            {
                temp.trees = stoi(linea_split[i + 1]);
            }
            else if (linea_split[i] == "cars:")
            {
                temp.cars = stoi(linea_split[i + 1]);
            }
            else if (linea_split[i] == "perfumes:")
            {
                temp.perfumes = stoi(linea_split[i + 1]);
            }
        }
        aunts.insert(temp);
    }
}

int main()
{
    set<Aunt> aunts;
    obtain_data(aunts);
    set<int> tias_a_borrar;
    for (auto it = aunts.begin(); it != aunts.end(); it++)
    {
        if (it->children.has_value() && it->children.value() != 3)
        {
            tias_a_borrar.insert(it->id);
        }
        else if (it->cats.has_value() && it->cats.value() < 7)
        {
            tias_a_borrar.insert(it->id);
        }
        else if (it->samoyeds.has_value() && it->samoyeds.value() != 2)
        {
            tias_a_borrar.insert(it->id);
        }
        else if (it->pomeranians.has_value() && it->pomeranians.value() > 3)
        {
            tias_a_borrar.insert(it->id);
        }
        else if (it->akitas.has_value() && it->akitas.value() != 0)
        {
            tias_a_borrar.insert(it->id);
        }
        else if (it->vizslas.has_value() && it->vizslas.value() != 0)
        {
            tias_a_borrar.insert(it->id);
        }
        else if (it->goldfish.has_value() && it->goldfish.value() > 5)
        {
            tias_a_borrar.insert(it->id);
        }
        else if (it->trees.has_value() && it->trees.value() < 3)
        {
            tias_a_borrar.insert(it->id);
        }
        else if (it->cars.has_value() && it->cars.value() != 2)
        {
            tias_a_borrar.insert(it->id);
        }
        else if (it->perfumes.has_value() && it->perfumes.value() != 1)
        {
            tias_a_borrar.insert(it->id);
        }
    }
    Aunt tia_a_eliminar;
    for (auto it = tias_a_borrar.begin(); it != tias_a_borrar.end(); it++)
    {
        tia_a_eliminar.id = *it;
        aunts.erase(tia_a_eliminar);
    }
    for (const Aunt& tia : aunts) {
        std::cout << "ID: " << tia.id  << std::endl;
    }
    return 0;
}
