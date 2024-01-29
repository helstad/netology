#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::string text;
    std::cout << "Enter a text: ";
    std::getline(std::cin, text);

    std::map<char, int> charFrequency;

    for (char c: text) {
        charFrequency[c]++;
    }

    std::vector<std::pair<char, int>> charFrequencyVector(charFrequency.begin(), charFrequency.end());

    std::sort(charFrequencyVector.begin(), charFrequencyVector.end(),
              [](const auto &a, const auto &b) { return a.second > b.second; });

    std::cout << "Character frequencies:" << std::endl;
    for (const auto &pair: charFrequencyVector) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
