#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    auto start = clock();
    ifstream input("./inputs/day-1-1.txt");

    if (!input.is_open()) {
        return 1;
    }

    auto frequency = 0;
    string line;
    while(getline(input, line)) {
        auto frequencyShift = stoi(line.substr(1, line.size()));
        if (line[0] == '+') {
            frequency += frequencyShift;
        } else {
            frequency -= frequencyShift;
        }
    }

    input.close();

    cout << "frequency: " << frequency << "\n";

    auto duration = (clock() - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << "duration: " << duration << "sec";

    return 0;
}