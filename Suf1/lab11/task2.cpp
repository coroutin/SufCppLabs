#include <fstream>

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int N, M;
    fin >> N >> M;

    for (int i = 0; i < N; ++i) {
        int x, max_val;
        fin >> max_val;

        for (int j = 1; j < M; ++j) {
            fin >> x;
            if (x > max_val) {
                max_val = x;
            }
        }

        fout << max_val;
        if (i != N - 1) {
            fout << " ";
        }
    }

    return 0;
}