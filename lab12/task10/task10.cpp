#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int count_triangles(const vector<int>& sticks) {
    vector<int> cnt(100001, 0);
    for (int x : sticks) {
        cnt[x]++;
    }

    int triangles = 0;
    for (int i = 1; i <= 100000; ++i) {
        triangles += cnt[i] / 3;
    }
    return triangles;
}

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

    if (!fin.is_open()) {
        cerr << "Не удалось открыть файл.\n";
        return 1;
    }

    int n;
    fin >> n;
    if (n < 1 || n > 100000) {
        cerr << "Некорректное количество палочек: " << n << endl;
        return 1;
    }

    vector<int> sticks(n);
    for (int i = 0; i < n; ++i) {
        if (!(fin >> sticks[i])) {
            cerr << "Ошибка чтения палочки № " << (i + 1) << endl;
            return 1;
        }
        if (sticks[i] <= 0 || sticks[i] > 100000) {
            cerr << "Некорректная длина палочки: " << sticks[i] << endl;
            return 1;
        }
    }
    fin.close();

    int triangles = count_triangles(sticks);

    ofstream fout("out.txt");
    fout << triangles << endl;
    fout.close();

    ofstream bin_out("data1.bin", ios::binary);
    if (!bin_out.is_open()) {
        cerr << "Не удалось создать бинарный файл.\n";
        return 1;
    }

    bin_out.write(reinterpret_cast<char*>(&n), sizeof(n));
    bin_out.write(reinterpret_cast<char*>(sticks.data()), n * sizeof(int));

    bin_out.write(reinterpret_cast<char*>(&triangles), sizeof(triangles));

    bin_out.close();

    cout << "Количество треугольников: " << triangles << endl;
    cout << "Результат сохранён в out.txt\n";
    cout << "Входные и выходные данные сохранены в data1.bin\n";

    return 0;
}