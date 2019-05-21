#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

size_t ALPHABET_LENGTH = 26;

int main(int argc, char *argv[]) {
    auto start = clock();
    ifstream input("./inputs/day-2.txt");

    if (!input.is_open()) {
        return 1;
    }

    auto twos = 0;
    auto threes = 0;

    string line;
    bool hasTwo = false;
    bool hasThree = false;
    vector<int> characterCounts(ALPHABET_LENGTH);
    while(getline(input, line)) {
        for (auto character : line) {
            characterCounts[character - 97] += 1;
        }
        for (int i = 0; i < ALPHABET_LENGTH; i++) {
            if (characterCounts[i] == 2) {
                hasTwo = true;
            } else if (characterCounts[i] == 3) {
                hasThree = true;
            }
            characterCounts[i] = 0;
        }
        twos += hasTwo;
        threes += hasThree;
        hasTwo = false;
        hasThree = false;
    }

    input.close();

    cout << "checksum: " << twos * threes << "\n";

    auto duration = (clock() - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << "duration: " << duration << "sec";

    return 0;
}