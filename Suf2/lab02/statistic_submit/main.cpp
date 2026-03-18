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