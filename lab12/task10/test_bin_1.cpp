#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream bin("data1.bin", std::ios::binary);

    int n;
    bin.read(reinterpret_cast<char*>(&n), sizeof(n));

    std::cout << "n = " << n << std::endl;

    std::vector<int> sticks(n);
    bin.read(reinterpret_cast<char*>(sticks.data()), n * sizeof(int));
    bin.close();

    std::cout << "Палочки: ";
    for (int x : sticks) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
