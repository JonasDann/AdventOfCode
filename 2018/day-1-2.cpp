#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {
    auto start = clock();
    ifstream input("./inputs/day-1-1.txt");

    if (!input.is_open()) {
        return 1;
    }

    vector<int> frequencyShifts;
    string line;
    while(getline(input, line)) {
        frequencyShifts.emplace_back(stoi(line.substr(1, line.size())) *
                                             ((line[0] == '+') * 2 - 1));
    }

    input.close();

    size_t index = 0;
    auto frequency = 0;
    set<int> frequencies;
    while(frequencies.find(frequency) == frequencies.end()) {
        frequencies.insert(frequency);
        frequency += frequencyShifts[index];
        index = (index + 1) % frequencyShifts.size();
    }

    cout << "frequency: " << frequency << "\n";

    auto duration = (clock() - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << "duration: " << duration << "sec";

    return 0;
}