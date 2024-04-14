#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Reindeer
{
    int speed, fly_time, rest_time, seconds;
    string name;
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

void obtain_data(vector<Reindeer> &Reindeers)
{
    std::string nombreArchivo = "../../input/puzzle_14.txt";
    std::ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada.is_open())
    {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
    }
    std::string linea;
    while (std::getline(archivoEntrada, linea))
    {
        std::vector<std::string> linea_split = Split(linea, " ");
        Reindeer reindeer;
        reindeer.name = linea_split[0];
        reindeer.speed = stoi(linea_split[3]);
        reindeer.fly_time = stoi(linea_split[6]);
        reindeer.rest_time = stoi(linea_split[13]);
        Reindeers.push_back(reindeer);
    }
}

int calc_distance_flew(int speed, int fly_time, int rest_time, int seconds) {
    int distance = 0;
    int flyingTimeLeft = fly_time;
    int restingTimeLeft = 0;

    for (int t = 1; t <= seconds; ++t) {
        if (flyingTimeLeft > 0) {
            distance += speed;
            flyingTimeLeft--;
            if (flyingTimeLeft == 0) {
                restingTimeLeft = rest_time;
            }
        } else if (restingTimeLeft > 0) {
            restingTimeLeft--;
            if (restingTimeLeft == 0) {
                flyingTimeLeft = fly_time;
            }
        }
    }

    return distance;
}

int main()
{
    vector<Reindeer> Reindeers;
    obtain_data(Reindeers);
    for (int i = 0; i < Reindeers.size(); i++)
    {
        cout << Reindeers[i].name << " " << calc_distance_flew(Reindeers[i].speed, Reindeers[i].fly_time, Reindeers[i].rest_time, 2502) << endl;
    }
    return 0;
}
