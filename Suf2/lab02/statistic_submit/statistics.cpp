#include <iostream>
#include "statistics.h"

long long Statistic::sum_sales(const std::vector<int> & vec) {
    long long sum = 0;
    for (int i : vec) sum += i;
    return sum;
}

int Statistic::average_sales(const std::vector<int> & vec) {
    if (vec.empty()) return 0;
    return sum_sales(vec) / vec.size();
}

int Statistic::months_sales_below_average(const std::vector<int> & vec) {
    int count = 0;
    for (int i : vec) if (i < average_sales(vec)) count++;
    return count;
}

int Statistic::months_sales_above_average(const std::vector<int> & vec) {
    int count = 0;
    for (int i : vec) if (i > average_sales(vec)) count++;
    return count;
}

std::vector<int> Statistic::max_sales(const std::vector<int> & vec) {
    std::vector<int> idx;
    if (vec.empty()) return idx;
    int max_sales = -std::numeric_limits<double>::infinity();
    for (int i : vec) if (i > max_sales) max_sales = i;
    for (int i = 0; i < (int)vec.size(); i++)
        if (vec[i] == max_sales) idx.push_back(i);
    return idx;
}

std::vector<int> Statistic::min_sales(const std::vector<int> & vec) {
    std::vector<int> idx;
    if (vec.empty()) return idx;
    int min_sales = std::numeric_limits<double>::infinity();
    for (int i : vec) if (i < min_sales) min_sales = i;
    for (int i = 0; i < (int)vec.size(); i++)
        if (vec[i] == min_sales) idx.push_back(i);
    return idx;
}

void printMenu() {
    std::cout << "\n=== Меню ===" << std::endl;
    std::cout << "1. Сумма продаж" << std::endl;
    std::cout << "2. Среднее значение продаж" << std::endl;
    std::cout << "3. Месяцев ниже среднего" << std::endl;
    std::cout << "4. Месяцев выше среднего" << std::endl;
    std::cout << "5. Месяцы с максимальными продажами" << std::endl;
    std::cout << "6. Месяцы с минимальными продажами" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Выберите операцию: ";
}

#include <vector>
#include <random>

std::vector<int> inp_rand() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(1, 100);

    std::vector<int>vec(12);
    for (size_t i = 0; i < vec.size(); i++) {
        vec[i] = dist(gen);
    }
    return vec;
}