#include <iostream>
#include <fstream>
#include <unordered_map>
#include <set>

using namespace std;

size_t ALPHABET_LENGTH = 26;

int main(int argc, char *argv[]) {
    auto start = clock();
    ifstream input("./inputs/day-2.txt");

    if (!input.is_open()) {
        return 1;
    }

    string line;
    unordered_map<string, set<string>> prefixSuffixMap;
    string prefix;
    string suffix;
    string overlap;
    while(getline(input, line)) {
        for (size_t i = 1; i < line.size() - 1; i++) {
            prefix = line.substr(0, i);
            suffix = line.substr(i + 1, line.size() - 1);
            if (prefixSuffixMap[prefix].find(suffix) !=
                    prefixSuffixMap[prefix].end()) {
                overlap = prefix + suffix;
                break;
            } else {
                prefixSuffixMap[prefix].insert(suffix);
            }
        }
        if (!overlap.empty()) {
            break;
        }
    }

    input.close();

    cout << "overlap: " << overlap << "\n";

    auto duration = (clock() - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << "duration: " << duration << "sec";

    return 0;
}