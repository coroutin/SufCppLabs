#include <iostream>

int main() {
    long long cur = 1;
    long long pass = 0;
    int k;
    std::cin >> k;

    while (true) {
        std::string n = std::to_string(cur * cur);

        for (int i = 0; i < (int)n.size(); i++) {
            pass++;

            if (pass == k) {
                std::cout << n[i] << "\n";
                return 0;
            }
        }
        cur++;
    }
}