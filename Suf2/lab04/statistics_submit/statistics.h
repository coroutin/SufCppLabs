#pragma once
#include <vector>
#include <limits>
#include <string>
#include <sstream>
#include <exception>
#include <algorithm>
#include <iostream>

class Statistic {
private:
    std::vector<int> sales;

public:
    Statistic(std::vector<int> const& a) : sales(a.begin(), a.end()) {}

    Statistic(std::string const& str) {
        std::istringstream iss(str);
        int val;
        while (iss >> val) sales.push_back(val);
    }

    ~Statistic() { sales.clear(); }

    size_t size() const { return sales.size(); }

    // Задача 3
    int get(size_t i) const {
        if (i >= sales.size()) throw std::exception();
        return sales[i];
    }

    int& get(size_t i) {
        if (i >= sales.size()) throw std::exception();
        return sales[i];
    }

    // Задача 4
    Statistic getSlice(size_t start, size_t finish) const {
        if (start > finish) throw std::runtime_error("invalid data format");
        if (finish >= sales.size()) throw std::exception();
        return Statistic(std::vector<int>(sales.begin() + start, sales.begin() + finish + 1));
    }

    Statistic& operator+=(Statistic const& v) {
        for (int val : v.sales) sales.push_back(val);
        return *this;
    }

    // Задача 5
    friend bool operator==(Statistic const& a, Statistic const& b) {
        std::vector<int> x = a.sales, y = b.sales;
        std::sort(x.begin(), x.end());
        std::sort(y.begin(), y.end());
        return x == y;
    }

    friend bool operator!=(Statistic const& a, Statistic const& b) {
        return !(a == b);
    }

    void deleteSlice(size_t start, size_t finish) {
        if (start > finish) throw std::runtime_error("invalid data format");
        if (finish >= sales.size()) throw std::exception();
        sales.erase(sales.begin() + start, sales.begin() + finish + 1);
    }

    // Задача 6: ввод/вывод
    friend std::ostream& operator<<(std::ostream& os, Statistic const& s) {
        for (size_t i = 0; i < s.sales.size(); i++) {
            os << s.sales[i];
            if (i + 1 < s.sales.size()) os << " ";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Statistic& s) {
        s.sales.clear();
        std::string line;
        std::getline(is, line);
        std::istringstream iss(line);
        int val;
        while (iss >> val) s.sales.push_back(val);
        return is;
    }

    // Задача 6: operator[] для среза
    struct Slicer {
        const Statistic& stat;
        size_t start;

        Slicer(const Statistic& s, size_t start) : stat(s), start(start) {}

        Statistic operator[](size_t finish) const {
            return stat.getSlice(start, finish);
        }
    };

    Slicer operator[](size_t start) const {
        if (start >= sales.size()) throw std::exception();
        return Slicer(*this, start);
    }

    long long sum_sales(const std::vector<int>& vec);
    int average_sales(const std::vector<int>& vec);
    int months_sales_below_average(const std::vector<int>& vec);
    int months_sales_above_average(const std::vector<int>& vec);
    std::vector<int> max_sales(const std::vector<int>& vec);
    std::vector<int> min_sales(const std::vector<int>& vec);
};

void printMenu();
std::vector<int> inp_rand();