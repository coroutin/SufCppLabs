#include <iostream>
#include <fstream>

int main() {
    std::ifstream fin("input.txt");
    if (!fin.is_open()) {
        return 0;
    }

    int N;
    fin >> N;

    bool found = false;
    for (int i = 0; i < N; ++i) {
        int x;
        fin >> x;
        if (x > 0) {
            if (found) std::cout << " ";
            std::cout << x;
            found = true;
        }
    }

    if (!found) {
        std::cout << "NO";
    }

    return 0;
}