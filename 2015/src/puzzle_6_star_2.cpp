#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int GRID_SIZE = 1000;

struct data_
{
    int init_x, init_y, end_x, end_y;
    string type_;
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

void obtain_data(vector<data_> &data)
{
    std::string nombreArchivo = "../../input/puzzle_6.txt";
    std::ifstream archivoEntrada(nombreArchivo);
    vector<int> dim;
    if (!archivoEntrada.is_open())
    {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
    }
    std::string linea;
    while (std::getline(archivoEntrada, linea))
    {

        std::vector<std::string> linea_split = Split(linea, " ");
        std::vector<string> number_end = Split(linea_split.back(), ",");
        std::vector<string> number_init = Split(linea_split[linea_split.size() - 3], ",");
        data_ test;
        test.init_x = stoi(number_init[0]);
        test.init_y = stoi(number_init[1]);
        test.end_x = stoi(number_end[0]);
        test.end_y = stoi(number_end[1]);
        test.type_ = linea_split[linea_split.size() - 4];
        data.push_back(test);
    }
}

void turn_on(vector<vector<int>> &grid_, data_ &data)
{
    for (int i = data.init_x; i <= data.end_x; ++i)
    {
        for (int j = data.init_y; j <= data.end_y; ++j)
        {
            grid_[i][j] = grid_[i][j] + 1;
        }
    }
}

void turn_off(vector<vector<int>> &grid_, data_ &data)
{
    for (int i = data.init_x; i <= data.end_x; ++i)
    {
        for (int j = data.init_y; j <= data.end_y; ++j)
        {
            if (grid_[i][j] > 0) {
                grid_[i][j] =grid_[i][j] - 1;
            }
        }
    }
}

void toggle(vector<vector<int>> &grid_, data_ &data)
{
    for (int i = data.init_x; i <= data.end_x; ++i)
    {
        for (int j = data.init_y; j <= data.end_y; ++j)
        {
            grid_[i][j] = grid_[i][j] + 2;
        }
    }
}

int countLightsOn(vector<vector<int>> &grid_)
{
    int count = 0;
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            if (grid_[i][j])
            {
                count += grid_[i][j];
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> grid_(GRID_SIZE, vector<int>(GRID_SIZE, 0));
    vector<data_> data;
    obtain_data(data);
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].type_ == "on")
        {
            turn_on(grid_, data[i]);
        }
        else if (data[i].type_ == "off")
        {

            turn_off(grid_, data[i]);
        }
        else if (data[i].type_ == "toggle")
        {
            toggle(grid_, data[i]);
        }
        else
        {
            std::cout << "error" << std::endl;
        }
    }

    std::cout << countLightsOn(grid_) << std::endl;
    return 0;
}