#include <iostream>
#include "task.h"
using namespace std;

int main() {
    string original_text;
    string prepared_text;

    cout << "Введите текст: ";
    getline(cin, original_text);

    prepared_text = spaces_around_punctuation(trim(original_text));

    while (true) {
        cout << "\nВыберите способ изменения регистра:\n";
        cout << "1 - Как в предложениях\n";
        cout << "2 - все строчные\n";
        cout << "3 - ВСЕ ПРОПИСНЫЕ\n";
        cout << "4 - Начинать С Прописных\n";
        cout << "5 - иЗМЕНИТЬ РЕГИСТР\n";
        cout << "0 - Выход\n";
        cout << "Ваш выбор: ";

        int choice;
        cin >> choice;
        cin.ignore(10000, '\n');

        if (choice == 0) {
            cout << "Выход из программы.\n";
            break;
        }

        string result = prepared_text;

        switch (choice) {
            case 1: to_sentence_case(result); break;
            case 2: result = to_lower_case(result); break;
            case 3: result = to_upper_case(result); break;
            case 4: result = to_title_case(result); break;
            case 5: result = to_toggle_case(result); break;
            default:
                cout << "Неверный выбор!\n";
                continue;
        }

        cout << "\nРезультат:\n" << result << endl;
    }

    return 0;
}
