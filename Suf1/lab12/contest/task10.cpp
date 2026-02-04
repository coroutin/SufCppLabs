#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::pmr::vector<int> cnt(100001, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        cnt[x]++;
    }

    int triangles = 0;
    for (int i = 1; i <= 100000; ++i) {
        triangles += cnt[i] / 3;
    }

    std::cout << triangles << std::endl;
    return 0;
}