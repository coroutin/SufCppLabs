#include <fstream>
#include <string>

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    long long sum = 0;
    int count = 0;
    int x;

    while (fin >> x) {
        sum += x;
        ++count;
    }

    fout << "count = " << count << '\n'
         << "sum = " << sum << '\n';

    return 0;
}