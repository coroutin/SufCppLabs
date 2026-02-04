#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    cout << "Выберите input файл (1-5): ";
    int choice;
    cin >> choice;

    if (choice < 1 || choice > 5) {
        cerr << "Неверный выбор.\n";
        return 1;
    }

    string input_filename = "i_" + to_string(choice) + ".txt";
    ifstream fin(input_filename);

    ofstream fout("out.txt");

    int n, q;
    fin >> n >> q;

    if (n < 1 || n > 100000 || q < 1 || q > 100000) {
        cerr << "Некорректные n или q.\n";
        return 1;
    }

    string s;
    fin >> s;
    if ((int)s.size() != n) {
        cerr << "Длина строки не равна n.\n";
        return 1;
    }

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        fin >> queries[i].first >> queries[i].second;
    }

    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + (s[i - 1] - 'a' + 1);
    }

    vector<long long> answers(q);
    for (int i = 0; i < q; ++i) {
        int l = queries[i].first;
        int r = queries[i].second;

        if (l < 1 || r > n || l > r) {
            fout << "Ошибка\n";
            answers[i] = -1;
        } else {
            long long res = pref[r] - pref[l - 1];
            fout << res << '\n';
            answers[i] = res;
        }
    }

    ofstream bin_out("data1.bin", ios::binary);
    bin_out.write(reinterpret_cast<char*>(&n), sizeof(n));
    bin_out.write(reinterpret_cast<char*>(&q), sizeof(q));
    bin_out.write(s.data(), n);

    for (auto& [l, r] : queries) {
        bin_out.write(reinterpret_cast<char*>(&l), sizeof(l));
        bin_out.write(reinterpret_cast<char*>(&r), sizeof(r));
    }

    for (long long ans : answers) {
        bin_out.write(reinterpret_cast<char*>(&ans), sizeof(ans));
    }

    cout << "Готово. Результаты в out.txt, бинарные данные в data1.bin\n";
    return 0;
}
