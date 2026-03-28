# pragma once
#include <algorithm>
#include <vector>
#include <limits>
#include <sstream>

class Statistic {
private:
    std::vector<int> sales;
public:
    Statistic(std::vector<int> const & a) : sales(a.begin(), a.end()) {
    }

    Statistic(std::string const& str) {
        std::istringstream iss(str);
        int val;
        while (iss >> val) sales.push_back(val);
    }

    //operator[]
    const int operator[](size_t ind) const {
        if (ind >= sales.size()) throw std::exception();
        return sales[ind];
    }

    int& operator[](size_t ind) {
        if (ind >= sales.size()) throw std::exception();
        return sales[ind];
    }

    long long sum_sales(const std::vector<int> & vec);

    int average_sales(const std::vector<int> & vec);

    int months_sales_below_average(const std::vector<int> & vec);

    int months_sales_above_average(const std::vector<int> &vec);

    std::vector<int> max_sales(const std::vector<int> & vec);

    std::vector<int> min_sales(const std::vector<int> & vec);

    size_t size() const { return sales.size(); }

    //срез и объединение
    Statistic getSlice(size_t start, size_t finish) const {
        if (start > finish) throw std::runtime_error("invalid data format");
        if (finish >= sales.size()) throw std::exception();
        std::vector<int> slice(sales.begin() + start, sales.begin() + finish + 1);
        return Statistic(slice);
    }

    Statistic& operator+=(Statistic const& v) {
        for (int val : v.sales) sales.push_back(val);
        return *this;
    }

    //сравнение и удаление среза
    friend bool operator==(Statistic const& a, Statistic const& b) {
        std::vector<int> x = a.sales;
        std::vector<int> y = b.sales;
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
};

void printMenu();

std::vector<int> inp_rand();
