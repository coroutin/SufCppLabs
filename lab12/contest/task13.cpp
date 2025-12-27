#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long h;
    int n;
    if (!(std::cin >> h >> n)) return 0;

    std::map<long long, int> counts;
    for (int i = 0; i < n; ++i) {
        long long a;
        std::cin >> a;
        if (a <= h) {
            counts[a]++;
        }
    }

    long long total_height = 0;

    for (auto const& [size, count] : counts) {
        long long can_take = h / size;

        long long taken = std::ranges::min((long long)count, can_take);

        total_height += taken * size;
    }

    std::cout << total_height << std::endl;

    return 0;
}