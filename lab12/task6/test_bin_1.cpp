#include <fstream>
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ifstream bin("data1.bin", std::ios::binary);

    int n, q;
    bin.read(reinterpret_cast<char*>(&n), sizeof(n));
    bin.read(reinterpret_cast<char*>(&q), sizeof(q));

    if (!bin) {
        std::cerr << "Ошибка чтения n или q\n";
        return 1;
    }

    std::cout << "n = " << n << ", q = " << q << "\n";

    std::string s(n, ' ');
    bin.read(&s[0], n);
    std::cout << "Строка s: " << s << "\n";

    std::vector<std::pair<int,int>> queries(q);
    for (int i = 0; i < q; ++i) {
        bin.read(reinterpret_cast<char*>(&queries[i].first), sizeof(int));
        bin.read(reinterpret_cast<char*>(&queries[i].second), sizeof(int));
    }

    std::vector<long long> answers(q);
    for (int i = 0; i < q; ++i) {
        bin.read(reinterpret_cast<char*>(&answers[i]), sizeof(long long));
    }

    bin.close();

    std::cout << "\nЗапросы и ответы:\n";
    for (int i = 0; i < q; ++i) {
        std::cout << i + 1 << ") "
                  << "l = " << queries[i].first
                  << ", r = " << queries[i].second
                  << " Ответ: ";

        if (answers[i] == -1) {
            std::cout << "Ошибка\n";
        } else {
            std::cout << answers[i] << "\n";
        }
    }

    return 0;
}
