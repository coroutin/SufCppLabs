#include <iostream>
#include "statistics.h"
#include <vector>

enum class Operation {
    SUM = 1,
    AVERAGE,
    BELOW_AVERAGE,
    ABOVE_AVERAGE,
    MAX_SALES,
    MIN_SALES,
    GET_BY_INDEX,
    GET_SLICE,
    MERGE,
    COMPARE,
    DELETE_SLICE,
    PRINT,
    READ,
    GET_SLICE2,
    EXIT = 0
};



int main() {

    std::vector<int> sales = inp_rand();
    for (size_t i = 0; i < sales.size(); i++) {
        std::cout << sales[i] << " ";
    }

    Statistic stat(sales);

    int choice;
    do {
        printMenu();
        std::cin >> choice;

        Operation op = static_cast<Operation>(choice);

        switch (op) {
            case Operation::SUM:
                std::cout << "Сумма продаж: " << stat.sum_sales(sales) << std::endl;
                break;

            case Operation::AVERAGE:
                std::cout << "Среднее значение: " << stat.average_sales(sales) << std::endl;
                break;

            case Operation::BELOW_AVERAGE:
                std::cout << "Месяцев ниже среднего: "
                          << stat.months_sales_below_average(sales) << std::endl;
                break;

            case Operation::ABOVE_AVERAGE:
                std::cout << "Месяцев выше среднего: "
                          << stat.months_sales_above_average(sales) << std::endl;
                break;

            case Operation::MAX_SALES:
                std::cout << "Месяцы с максимальными продажами (индексы): ";
                for (int i : stat.max_sales(sales)) std::cout << i + 1 << " ";
                std::cout << std::endl;
                break;

            case Operation::MIN_SALES:
                std::cout << "Месяцы с минимальными продажами (индексы): ";
                for (int i : stat.min_sales(sales)) std::cout << i + 1 << " ";
                std::cout << std::endl;
                break;

            case Operation::GET_BY_INDEX: {
                std::cout << "Введите индекс: ";
                size_t idx;
                std::cin >> idx;
                try {
                    std::cout << "Значение: delete" << std::endl;
                } catch (std::exception e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }

            case Operation::GET_SLICE: {
                std::cout << "Введите начало и конец среза: ";
                size_t start, finish;
                std::cin >> start >> finish;
                try {
                    Statistic slice = stat.getSlice(start, finish);
                    std::cout << "Срез: delete";
                    for (size_t i = 0; i < slice.size(); i++)
                        std::cout << " ";
                    std::cout << std::endl;
                } catch (std::exception e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }

            case Operation::MERGE: {
                std::cout << "Введите данные для добавления: ";
                std::string line;
                std::cin.ignore();
                std::getline(std::cin, line);
                Statistic other(line);
                stat += other;
                std::cout << "Объединено." << std::endl;
                break;
            }

            case Operation::COMPARE: {
                std::cout << "Введите данные для сравнения: ";
                std::string line;
                std::cin.ignore();
                std::getline(std::cin, line);
                Statistic other(line);
                std::cout << (stat == other ? "Равны" : "Не равны") << std::endl;
                break;
            }

            case Operation::DELETE_SLICE: {
                std::cout << "Введите начало и конец среза для удаления: ";
                size_t start, finish;
                std::cin >> start >> finish;
                try {
                    stat.deleteSlice(start, finish);
                    std::cout << "Срез удалён." << std::endl;
                } catch (std::exception e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case Operation::PRINT:
                std::cout << stat << std::endl;
                break;

            case Operation::READ: {
                std::cout << "Введите данные: ";
                std::cin.ignore();
                std::cin >> stat;
                std::cout << "Загружено: " << stat << std::endl;
                break;
            }

            case Operation::GET_SLICE2: {
                std::cout << "Введите начало и конец среза: ";
                size_t start, finish;
                std::cin >> start >> finish;
                try {
                    Statistic slice = stat[start][finish];
                    std::cout << "Срез: " << slice << std::endl;
                } catch (std::exception e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }

            case Operation::EXIT:
                std::cout << "Выход." << std::endl;
                return 0;

            default:
                std::cout << "Неверный выбор, попробуйте снова." << std::endl;
                break;
        }
    }
    while (choice != 0);
    return 0;
}