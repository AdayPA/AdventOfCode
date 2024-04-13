#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>
#include <utility>

using namespace std;

std::string lookAndSay(const std::string& sequence) {
    std::string result;
    int count = 1;
    for (size_t i = 1; i < sequence.size(); ++i) {
        if (sequence[i] == sequence[i - 1]) {
            count++;
        } else {
            result += std::to_string(count) + sequence[i - 1];
            count = 1;
        }
    }
    result += std::to_string(count) + sequence.back();
    return result;
}

int main() {
    std::string sequence = "3113322113";
    for (int i = 0; i < 40; ++i) {
        sequence = lookAndSay(sequence);
    }
    std::cout << "Length of the resulting sequence: " << sequence.size() << std::endl;
    return 0;
}