#include <iostream>
#include <set>

int main() {
    int n, m;
    std::set<int> s;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        s.insert(x);
    }

    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        std::cin >> x;
        s.insert(x);
    }

    for (int x : s) {
        std::cout << x << " ";
    }

    return 0;
}