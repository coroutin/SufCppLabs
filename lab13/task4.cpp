#include <iostream>
#include <string>
#include <set>
#include <sstream>

int main() {
    int n;
    if (!(std::cin >> n)) return 0;

    std::string line;
    getline(std::cin, line);

    std::set<std::string> common_colors;

    for (int i = 0; i < n; ++i) {
        getline(std::cin, line);
        std::stringstream ss(line);
        std::string color;

        if (i == 0) {
            while (ss >> color) {
                common_colors.insert(color);
            }
        } else {
            std::set<std::string> current_girl_colors;
            while (ss >> color) {
                current_girl_colors.insert(color);
            }

            std::set<std::string> intersection;
            for (const std::string& c : common_colors) {
                if (current_girl_colors.count(c)) {
                    intersection.insert(c);
                }
            }
            common_colors = intersection;
        }
    }

    if (common_colors.empty()) {
        std::cout << "NO" << std::endl;
    } else {
        bool first = true;
        for (const std::string& c : common_colors) {
            if (!first) std::cout << " ";
            std::cout << c;
            first = false;
        }
        std::cout << std::endl;
    }

    return 0;
}